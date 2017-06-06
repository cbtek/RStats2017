/*
    UIRStatsUtils.h
    

*/

#pragma once

#include <QAbstractButton>
#include <QFont>
#include <QIcon>
#include <QApplication>
#include <QStyleFactory>
#include <QFile>
#include <QTableWidget>
#include <QFileDialog>
#include <QCheckBox>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
#include <QPushButton>
#include <QPixmap>
#include <QUrl>
#include <QDesktopServices>
#include <QComboBox>
#include <QListWidget>
#include <QFocusEvent>

#include <map>

#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsModuleSessionDataImpl.h"
#include "rstats_utils/inc/RStatsWorkbook.h"

#include "UIRStatsErrorMessage.h"

#include "utility/inc/SystemUtils.hpp"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/StringUtils.hpp"
#include "utility/inc/XMLUtils.h"

#ifdef __WIN32
    #include <windows.h>
#else
    #include <QDesktopServices>
#endif

namespace cbtek {
namespace rocketstats {
namespace ui {
/**
 * @brief This namespace represents a collection of reusable functions
 * that have access to the Qt classes.
 */
class UIRStatsUtils
{
private:
    UIRStatsUtils();
    UIRStatsUtils(const UIRStatsUtils&);
    UIRStatsUtils& operator=(const UIRStatsUtils&);
    ~UIRStatsUtils();
public:

    /**
     * @brief forceFocus Forces focus on a widget
     * @param widget The widget to force focus on
     */
    static void forceFocus(QWidget* widget)
    {
        // unless set active, no stable set focus here
        widget->activateWindow();
        // the event object is released then in event loop (?)
        QFocusEvent* eventFocus = new QFocusEvent(QEvent::FocusIn);
        // posting event for forcing the focus with low priority
        qApp->postEvent(widget, (QEvent *)eventFocus, Qt::LowEventPriority);
    }


    /**
     * @brief desktopOpen Opens files and web urls on the desktp
     * @param url Location of item to open
     */
    static void desktopOpen(const std::string& url)
    {
        #ifdef __WIN32            
            ShellExecute(NULL,"open",url.c_str(),NULL,NULL,SW_SHOWNORMAL);
        #else
            QDesktopServices::openUrl(QString::fromStdString(url));
        #endif
    }

    /**
     * @brief launchHtml Displays html content in system web browser
     * @param content The html content to display
     */
    static void launchHtml(const std::string& content)
    {
        std::string htmlPath = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserTempDirectory(), cbtek::common::utility::FileUtils::getRandomFileName(10,0)+".html");
        cbtek::common::utility::FileUtils::writeFileContents(htmlPath,content);
        desktopOpen(htmlPath);
    }

    /**
     * @brief launchHelp Builds a url to the pdf item.  Launches system pdf viewer with url as filePath.
     * @param pdf The filename portion of full url path
     */
    static void launchHelp(const std::string& pdf)
    {
        std::string url = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(),"help/"+pdf);
        url = cbtek::common::utility::StringUtils::replace(url,"\\","/");
        if (!cbtek::common::utility::FileUtils::fileExists(url))
        {
            UIRStatsErrorMessage("Could not load help file","Could not open the help file located at \"" + url+ "\"",false).exec();
            return;
        }
        desktopOpen(url);
    }


    /**
     * @brief setCurrentText
     * @param combo
     * @param text
     */
    static void setCurrentText(QComboBox * combo, const std::string & text)
    {
        combo->setCurrentText(QString::fromStdString(text));
    }

    /**
     * @brief getPixmap
     * @param pixmapFileName
     * @return
     */
    static QPixmap getPixmap(const std::string & pixmapFileName)
    {
        if (cbtek::common::utility::FileUtils::fileExists(pixmapFileName))
        {
            return QPixmap(QString::fromStdString(pixmapFileName));
        }

        QPixmap pixmap;
        std::string iconResource = cbtek::common::utility::FileUtils::buildFilePath(utils::RStatsUtils::getResourcePath(),pixmapFileName);
        if (cbtek::common::utility::FileUtils::fileExists(iconResource))
        {
            pixmap = QPixmap(QString::fromStdString(iconResource));
        }

        return pixmap;
    }

    /**
     * @brief getIcon
     * @param iconFileName
     * @return
     */
    static QIcon getIcon(const std::string & iconFileName)
    {
        if (cbtek::common::utility::FileUtils::fileExists(iconFileName))
        {
            return QIcon(QString::fromStdString(iconFileName));
        }

        QIcon icon;
        std::string iconResource = cbtek::common::utility::FileUtils::buildFilePath(utils::RStatsUtils::getResourcePath(),iconFileName);
        if (cbtek::common::utility::FileUtils::fileExists(iconResource))
        {
            icon = QIcon(QString::fromStdString(iconResource));
        }

        return icon;
    }

    /**
     * @brief getCurrentTheme
     * @return
     */
    static std::string getCurrentTheme()
    {
        std::string path = utils::RStatsUtils::getThemeSettingsFilePath();
        cbtek::common::utility::XMLReader xmlReader;
        xmlReader.load(path);
        cbtek::common::utility::XMLDataElement * theme = xmlReader.getElement("theme");
        if (theme)
        {
            cbtek::common::utility::XMLDataElement * style = theme->getChild("style");
            std::string styleStr = cbtek::common::utility::StringUtils::toUpperTrimmed(style->getElementData());
            return styleStr;
        }
        return "DEFAULT";
    }

    /**
     * @brief loadThemeSettings
     * @param app
     */
    static void loadThemeSettings(QApplication * app)
    {

        // set the ROCKET-STATS icon
        app->setWindowIcon(UIRStatsUtils::getIcon("img_logo_icon.png"));
        std::string path = utils::RStatsUtils::getThemeSettingsFilePath();
        cbtek::common::utility::XMLReader xmlReader;
        xmlReader.load(path);

        cbtek::common::utility::XMLDataElement * theme = xmlReader.getElement("theme");
        app->setStyleSheet("QWidget{font-size:12px;} QLineEdit{padding:6px;} QComboBox{padding:6px;} QPushButton{padding:4px;}");

        #ifdef __WIN32
            app->setStyle(QStyleFactory::create("windowsvista"));
        #endif

        if (theme)
        {
            cbtek::common::utility::XMLDataElement * style = theme->getChild("style");
            std::string styleStr = cbtek::common::utility::StringUtils::toUpperTrimmed(style->getElementData());
            if (styleStr == "FUSION")
            {
                app->setStyle(QStyleFactory::create("fusion"));                
            }
            else if (styleStr == "DARK")
            {
                std::string resourcePath = utils::RStatsUtils::getResourcePath();
                resourcePath = cbtek::common::utility::FileUtils::buildFilePath(resourcePath,"dark.qss");
                QString styleSheet = QString::fromStdString(cbtek::common::utility::FileUtils::getFileContents(resourcePath));
                app->setStyleSheet(styleSheet);
            }
        }
    }   


    /**
     * @brief highlightErrorInValidationConsole Ensures that the next error in
     * the validation console is highlighted/focused.
     * @param widget The validation console list widget
     */
    static void highlightErrorInValidationConsole(QListWidget * widget)
    {
        for (int a1 = 0; a1 < widget->count(); ++a1)
        {
            if (widget->item(a1)->text().startsWith("Error",Qt::CaseInsensitive))
            {
                widget->setCurrentItem(widget->item(a1));
                widget->setFocus();
                return;
            }
        }
    }

    /**
    * @brief populateWithColumns Populates combobox widget with column headers
    * @param columns Unique set of columns
    * @param comboBox The combobox widget to populate
    */
    static void populateWithColumns(const std::set<size_t>& columns,
                                    QComboBox *comboBox)
    {
        comboBox->clear();
        for(const auto& column : columns)
        {
            std::string label = utils::RStatsUtils::getColumnLabelFromIndex(column);
            comboBox->addItem(QString::fromStdString(label));
        }
    }

    /**
    * @brief populateWithRows Populates combobox widget with row numbers
    * @param rows Unique set of rows
    * @param comboBox The combobox to populate
    */
    static void populateWithRows(const std::set<size_t>& rows,
                                 QComboBox *comboBox)
    {
        comboBox->clear();
        for(const auto& row : rows)
        {
            comboBox->addItem(QString::number(row+1));
        }
    }

    /**
     * @brief bindUIToSheet
     * @param table
     * @param sheetOut
     */
    static void bindUIToSheet(QTableWidget * table,
                              cbtek::rocketstats::utils::RStatsWorksheet& sheetOut)
    {
        sheetOut.clear();
        size_t rowCount = static_cast<size_t>(table->rowCount());
        size_t columnCount = static_cast<size_t>(table->columnCount());
        for (size_t r = 0; r < rowCount;++r)
        {
            for (size_t c = 0; c < columnCount;++c)
            {
                QTableWidgetItem * item = table->item(static_cast<int>(r),static_cast<int>(c));
                if (item)
                {
                    sheetOut(r,c).text = item->text().toStdString();
                    if (cbtek::common::utility::StringUtils::isNumeric(cbtek::common::utility::StringUtils::remove(sheetOut(r,c).text,",")))
                    {
                        sheetOut(r,c).text = cbtek::common::utility::StringUtils::remove(sheetOut(r,c).text,",");
                    }

                    std::uint8_t fgR = static_cast<std::uint8_t>(item->foreground().color().red());
                    std::uint8_t fgG = static_cast<std::uint8_t>(item->foreground().color().green());
                    std::uint8_t fgB = static_cast<std::uint8_t>(item->foreground().color().blue());
                    std::uint8_t bgR = static_cast<std::uint8_t>(item->background().color().red());
                    std::uint8_t bgG = static_cast<std::uint8_t>(item->background().color().green());
                    std::uint8_t bgB = static_cast<std::uint8_t>(item->background().color().blue());
                    sheetOut(r,c).fgColor.set(fgR,fgB,fgG);
                    sheetOut(r,c).bgColor.set(bgR,bgB,bgG);
                    sheetOut(r,c).font = cbtek::common::utility::Font(item->font().family().toStdString(),
                                              static_cast<size_t>(item->font().pointSize()),
                                              item->font().bold(),
                                              item->font().italic(),
                                              item->font().underline());
                    if (item->textAlignment() == Qt::AlignHCenter)
                    {
                        sheetOut(r,c).alignment = utils::RStatsTextAlignment::AlignMiddle;
                    }
                    else if (item->textAlignment() == Qt::AlignLeft)
                    {
                        sheetOut(r,c).alignment = utils::RStatsTextAlignment::AlignLeft;
                    }
                    else
                    {
                        sheetOut(r,c).alignment = utils::RStatsTextAlignment::AlignRight;
                    }
                }
            }
        }
    }

    /**
     * @brief bindSheetToUI This function copies fields in the model class (RStatsWorksheet)
     * into the view object (QTableWidget)
     * @param sheet The (model) worksheet input
     * @param table The (view) table widget output
     * @param padRows Number of extra (blank) rows to add
     * @param padColumns Number of extra (blank) columns to add
     * @param numDecimalPlaces Number of decimal places to round numeric values
     * @param readOnly Makes the output table cells read only
     * @param disableAllFormatting Overrides any formatting settings in worksheet
     */
    static void bindSheetToUI(const cbtek::rocketstats::utils::RStatsWorksheet &sheetIn,
                              QTableWidget *table,
                              bool checkableHeader = false,
                              int padRows=0,
                              int padColumns=0,
                              int numDecimalPlaces = -1,
                              bool readOnly = false,
                              bool disableAllFormatting = false
                              )
    {
        utils::RStatsWorksheet sheet = sheetIn;
        sheet.setThousandsSeperatorEnabled(true);
        table->clear();
        table->setColumnCount(static_cast<int>(sheet.getNumColumns())+padColumns);
        table->setRowCount(static_cast<int>(sheet.getNumRows())+padRows);
        size_t columnCount = static_cast<size_t>(table->columnCount());
        for (size_t a1 = 0; a1 < columnCount;++a1)
        {
            QTableWidgetItem * header = new QTableWidgetItem;
            header->setText(QString::fromStdString(cbtek::rocketstats::utils::RStatsUtils::getColumnLabelFromIndex(a1)));
            if (checkableHeader)
            {
                header->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
                header->setCheckState(Qt::Unchecked);
            }
            table->setHorizontalHeaderItem(static_cast<int>(a1),header);
        }

        for(const auto& itNext : sheet.getCells())
        {
            std::pair<size_t,size_t> index = itNext.first;
            cbtek::rocketstats::utils::RStatsCell cell = itNext.second;
            QTableWidgetItem * item = new QTableWidgetItem;
            cell.text = cbtek::common::utility::StringUtils::remove(cell.text,",");
            bool hasData = cbtek::common::utility::StringUtils::trimmed(cell.text).size() > 0;

            if (numDecimalPlaces > -1 && cbtek::common::utility::StringUtils::isNumeric(cell.text) &&
                                       !cbtek::common::utility::StringUtils::isSignedInteger(cell.text) &&
                                       !cbtek::common::utility::StringUtils::isUnsignedInteger(cell.text) &&
                                       cbtek::common::utility::StringUtils::isFloat(cell.text))
            {
                    double toFloat = cbtek::common::utility::StringUtils::toFloat64(cell.text);
                    std::string toString;
                    if (std::fabs(toFloat) < 0.01)
                    {
                        toString = cbtek::common::utility::StringUtils::toString(toFloat,16);
                    }
                    else toString = cbtek::common::utility::StringUtils::toString(toFloat,numDecimalPlaces);

                    toString = cbtek::common::utility::StringUtils::removeTrailingZeroes(toString);
                    cell.text = toString;                    

            }


            if (cbtek::common::utility::StringUtils::isNumeric(cell.text))
            {
                cell.text = cbtek::common::utility::StringUtils::formatWithThousandsLabel(cell.text);
            }

            if (hasData && cbtek::common::utility::StringUtils::trimmed(cell.text).size() == 0)
            {
                cell.text = "0";
            }

            item->setText(QString::fromStdString(cell.text));            
            table->setRowHeight(static_cast<int>(index.first),26);
            if (!disableAllFormatting)
            {
                //set colors
                int r,g,b,a;
                if (cbtek::rocketstats::utils::RStatsCell::ms_DefaultBGColor != cell.bgColor)
                {
                    r = cell.bgColor.getRed();
                    g = cell.bgColor.getGreen();
                    b = cell.bgColor.getBlue();
                    a = cell.bgColor.getAlpha();
                    item->setBackground(QBrush(QColor(r,g,b,a)));
                }
                if (cbtek::rocketstats::utils::RStatsCell::ms_DefaultFGColor != cell.fgColor)
                {
                    r = cell.fgColor.getRed();
                    g = cell.fgColor.getGreen();
                    b = cell.fgColor.getBlue();
                    a = cell.fgColor.getAlpha();
                    item->setForeground(QBrush(QColor(r,g,b,a)));
                }

                //set font
                QFont font;
                font.setBold(cell.font.isBold());
                font.setUnderline(cell.font.isUnderlined());
                font.setItalic(cell.font.isItalic());
                font.setFamily(QString::fromStdString(cell.font.getFontFamily()));
                font.setPointSize(static_cast<int>(cell.font.getPointSize()));
                item->setFont(font);
                switch(cell.alignment)
                {
                    case cbtek::rocketstats::utils::RStatsTextAlignment::AlignMiddle:item->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);break;
                    case cbtek::rocketstats::utils::RStatsTextAlignment::AlignRight:item->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);break;
                    case cbtek::rocketstats::utils::RStatsTextAlignment::AlignLeft:item->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft);break;
                    default:break;
                }
            }

            if (readOnly)
            {
                item->setFlags(Qt::ItemIsEnabled);
            }

            table->setItem(static_cast<int>(index.first),
                           static_cast<int>(index.second),
                           item);
        }
        if (readOnly)
        {
            table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }
        table->show();
    }

    /**
     * @brief setOutputFile Common code used by all the modules for saving output file
     * @param checkBox
     * @param title
     * @param extension
     * @return
     */
    static QString setOutputFile(QCheckBox * checkBox,
                              const QString& title,
                              const QString& extension)
    {
        QString file = QFileDialog::getSaveFileName(nullptr,title,"",extension);

        if (!cbtek::common::utility::StringUtils::isEmpty(file.toStdString()))
        {
            std::string ext = cbtek::common::utility::StringUtils::remove(extension.toStdString(),"*");
            checkBox->setToolTip(file);
            if (!cbtek::common::utility::StringUtils::endsWith(file.toStdString(),ext,false))
            {                
                file += QString::fromStdString(ext);
            }
            return file;
        }
        else
        {
            checkBox->setChecked(false);
        }
        return "";
    }

    /**
     * @brief buildRecentSessions Constructs the "Recently Used" menu used by
     * the modules
     * @param parent The parent widget to hold the sessions
     * @param menuRecentAction The "Recently Used" menu item widget
     * @param sessionMapOut The map to hold the session data pointers
     * @param sessionExtension The extension/id using for saving/loading the sessions
     * @return Returns an action group and action pair to be used in module menu bar
     */
    template<typename ModuleType>
    static std::pair<QActionGroup *, QAction*> buildRecentSessions(
                                     QWidget * parent,
                                     QAction * menuRecentAction,
                                     std::map<std::string,utils::RStatsModuleSessionDataPtr> &sessionMapOut,
                                     const std::string& sessionExtension)
    {
        QActionGroup * recentSessionActionGroup = nullptr;
        sessionMapOut.clear();
        std::vector<std::string> sessionUrls = utils::RStatsUtils::getRecentSessions(sessionExtension);
        if (sessionUrls.empty())
        {
            menuRecentAction->setDisabled(true);
            return std::make_pair(nullptr,nullptr);
        }

        menuRecentAction->setDisabled(false);
        recentSessionActionGroup = new QActionGroup(parent);
        QMenu * recentMenu = new QMenu;

        //Load all sessions from disk
        std::map<std::uint64_t,utils::RStatsModuleSessionDataPtr> last10Sessions;
        for (const auto& url : sessionUrls)
        {
            //Create new data instance for "ModuleType"
            std::shared_ptr<ModuleType> data = std::shared_ptr<ModuleType>(new ModuleType);

            //Load the data instance from file
            data->load(url);

            //If data is valid then...
            if (data.get())
            {
                //Cast the interface pointer to base implementation object
                utils::RStatsModuleSessionDataImpl * impl = dynamic_cast<utils::RStatsModuleSessionDataImpl*>(data.get());
                if (impl)
                {
                    //Get the date object
                    cbtek::common::utility::DateEntity dateEntity = impl->getCreationDate();

                    //Get the time object
                    cbtek::common::utility::TimeEntity timeEntity = impl->getCreationTime();

                    //Create integer timestamp
                    std::uint64_t value = cbtek::common::utility::DateTimeUtils::getTimeStampInteger(dateEntity,timeEntity);

                    //Add data to last10Sessions map
                    //items should be sorted by
                    last10Sessions[value] = data;
                }
            }
        }

        //Loop over last ten sessions and add to sessionMapOut
        size_t sessionCount = 0;
        for (auto it = last10Sessions.rbegin();it != last10Sessions.rend(); ++it)
        {
            utils::RStatsModuleSessionDataImpl * impl = dynamic_cast<utils::RStatsModuleSessionDataImpl*>(it->second.get());
            if (impl)
            {
                std::string sessionId = impl->getSessionId();
                sessionMapOut[sessionId] = it->second;
                std::string dateTimeStr = cbtek::common::utility::DateTimeUtils::getDisplayTimeStamp(cbtek::common::utility::DateEntity(it->second->getCreationDate()),
                                                                                                     cbtek::common::utility::TimeEntity(it->second->getCreationTime()));
                QAction * action = new QAction(QString::fromStdString(it->second->getAuditName()+" from "+dateTimeStr), recentMenu);
                action->setToolTip("Created on "+QString::fromStdString(dateTimeStr));
                action->setProperty("id",QString::fromStdString(sessionId));
                recentSessionActionGroup->addAction(action);
                recentMenu->addAction(action);
                ++sessionCount;
                if (sessionCount == 10)
                {
                    break;
                }
            }
        }
        recentMenu->addSeparator();
        QAction * clearRecentSessionsAction = new QAction(recentMenu);
        clearRecentSessionsAction->setText("Clear History");
        recentMenu->addAction(clearRecentSessionsAction);
        menuRecentAction->setMenu(recentMenu);
        return std::make_pair(recentSessionActionGroup,clearRecentSessionsAction);
    }

    /**
     * @brief initAction
     * @param action
     * @param icon
     * @param shortcut
     * @param font
     */
    static void initAction(QAction* action,
                           const QString& icon,
                           const QString& shortcut,
                           const QFont& font = QFont())
    {
        action->setIcon(UIRStatsUtils::getIcon(icon.toStdString()));
        action->setShortcut(QKeySequence(shortcut));
        action->setFont(font);
    }

    /**
     * @brief initButton
     * @param button
     * @param icon
     * @param font
     * @param height
     */
    static void initButton(QPushButton* button,
                           const QString& icon,
                           const QFont& font = QFont(),
                           int height = 32)
    {
        button->setIcon(UIRStatsUtils::getIcon(icon.toStdString()));
        button->setIconSize(QSize(height-8,height-8));
        button->setMinimumHeight(height + 8);
        button->setMaximumHeight(height + 8);
        button->setFont(font);
    }
};
}}}//end namespace

