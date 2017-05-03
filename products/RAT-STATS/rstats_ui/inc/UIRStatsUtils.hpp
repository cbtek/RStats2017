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

#include <map>

#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsModuleSessionDataImpl.h"
#include "rstats_utils/inc/RStatsWorkbook.h"
#include "rstats_utils/inc/RStatsSettingsManager.h"

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

namespace oig {
namespace ratstats {
namespace ui {

namespace UIRStatsUtils
{

    /**
     * @brief desktopOpen Opens files and web urls on the desktp
     * @param url Location of item to open
     */
    inline void desktopOpen(const std::string& url)
    {
        #ifdef __WIN32
            ShellExecute(NULL,"open",url.c_str(),NULL,NULL,SW_SHOWNORMAL);
        #else
            QDesktopServices::openUrl(QString::fromStdString(url));
        #endif
    }

    /**
     * @brief launchHelp
     * @param pdf
     */
    inline void launchHelp(const std::string& pdf)
    {
        QUrl url = QUrl(QString::fromStdString(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(),"rstats_help/"+pdf)));
        if (!QFile::exists(url.toString()) || !QDesktopServices::openUrl(url))
        {
            UIRStatsErrorMessage("Could not load help file","Could not open the help file located at \"" + url.toString().toStdString() + "\"",false).exec();
        }
    }


    /**
     * @brief setCurrentText
     * @param combo
     * @param text
     */
    inline void setCurrentText(QComboBox * combo, const std::string & text)
    {
        int index = -1;
        for (int a1 = 0; a1 < combo->count(); ++a1)
        {
            if (combo->itemText(a1).toUpper().toStdString() == cbtek::common::utility::StringUtils::toUpper(text))
            {
                index = a1;
                break;
            }
        }
        if (index > -1)
        {
            combo->setCurrentIndex(index);
        }
        else
        {
            combo->addItem(QString::fromStdString(text));
            combo->setCurrentIndex(combo->count()-1);
        }
    }

    /**
     * @brief setButtonStyle
     * @param button
     * @param font
     * @param icon
     * @param buttonHeight
     * @param squareButton
     */
    inline void setButtonStyle(QAbstractButton * button,
                                 const QFont& font,
                                 const QIcon& icon,
                                 oig::ratstats::utils::RStatsInteger buttonHeight,
                                 bool squareButton = false)
    {
        button->setFont(font);
        button->setIcon(icon);
        button->setIconSize(QSize(static_cast<int>(buttonHeight-8),static_cast<int>(buttonHeight-8)));
        button->setMaximumHeight(static_cast<int>(buttonHeight));
        button->setMinimumHeight(static_cast<int>(buttonHeight));
        if (squareButton)
        {
            button->setMaximumWidth(static_cast<int>(buttonHeight));
            button->setMinimumWidth(static_cast<int>(buttonHeight));
        }
    }

    /**
     * @brief getPixmap
     * @param pixmapFileName
     * @return
     */
    inline QPixmap getPixmap(const std::string & pixmapFileName)
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
    inline QIcon getIcon(const std::string & iconFileName)
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
    inline std::string getCurrentTheme()
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
    inline void loadThemeSettings(QApplication * app)
    {

        // set the RAT-STATS icon
        app->setWindowIcon(UIRStatsUtils::getIcon("img_ratstats_icon.png"));
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
     * @brief bindUIToSheet
     * @param table
     * @param sheetOut
     */
    inline void bindUIToSheet(QTableWidget * table,
                              oig::ratstats::utils::RStatsWorksheet& sheetOut)
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
     * @brief bindSheetToUI
     * @param sheet
     * @param table
     * @param padRows
     * @param padColumns
     */
    inline void bindSheetToUI(const oig::ratstats::utils::RStatsWorksheet &sheetIn, QTableWidget *table, bool checkableHeader = false,int padRows=0,int padColumns=0)
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
            header->setText(QString::fromStdString(oig::ratstats::utils::RStatsUtils::getColumnLabelFromIndex(a1)));
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
            oig::ratstats::utils::RStatsCell cell = itNext.second;
            QTableWidgetItem * item = new QTableWidgetItem;           
            item->setText(QString::fromStdString(cell.text));
            table->setRowHeight(static_cast<int>(index.first),30);
            //set colors
            int r,g,b,a;
            if (oig::ratstats::utils::RStatsCell::ms_DefaultBGColor != cell.bgColor)
            {
                r = cell.bgColor.getRed();
                g = cell.bgColor.getGreen();
                b = cell.bgColor.getBlue();
                a = cell.bgColor.getAlpha();
                item->setBackground(QBrush(QColor(r,g,b,a)));
            }
            if (oig::ratstats::utils::RStatsCell::ms_DefaultFGColor != cell.fgColor)
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
                case oig::ratstats::utils::RStatsTextAlignment::AlignMiddle:item->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);break;
                case oig::ratstats::utils::RStatsTextAlignment::AlignRight:item->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);break;
                case oig::ratstats::utils::RStatsTextAlignment::AlignLeft:item->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft);break;
                default:break;
            }
            table->setItem(static_cast<int>(index.first),
                           static_cast<int>(index.second),
                           item);
        }
        table->show();
    }

    inline QString setOutputFile(QCheckBox * checkBox,
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



    template<typename ModuleType>
    inline std::pair<QActionGroup *, QAction*> buildRecentSessions(
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
        std::map<std::uint64_t,utils::RStatsModuleSessionDataPtr> last10Sessions;
        for (const auto& url : sessionUrls)
        {
            std::shared_ptr<ModuleType> data = std::shared_ptr<ModuleType>(new ModuleType);
            data->load(url);
            if (data.get())
            {
                utils::RStatsModuleSessionDataImpl * impl = dynamic_cast<utils::RStatsModuleSessionDataImpl*>(data.get());
                if (impl)
                {
                    std::uint64_t value = cbtek::common::utility::DateTimeUtils::getTimeStampInteger(impl->getCreationDate(),
                                                                                                 impl->getCreationTime());
                    last10Sessions[value] = data;
                }
            }
        }

        size_t sessionCount = 0;
        for (auto it = last10Sessions.rbegin();it != last10Sessions.rend(); ++it)
        {
            sessionMapOut[it->second->getAuditName()] = it->second;
            std::string dateTimeStr = cbtek::common::utility::DateTimeUtils::getDisplayTimeStamp(cbtek::common::utility::DateEntity(it->second->getCreationDate()),
                                                                                                 cbtek::common::utility::TimeEntity(it->second->getCreationTime()));
            QAction * action = new QAction(QString::fromStdString(it->second->getAuditName()), recentMenu);
            action->setToolTip("Created on "+QString::fromStdString(dateTimeStr));
            action->setProperty("name",QString::fromStdString(it->second->getAuditName()));
            recentSessionActionGroup->addAction(action);
            recentMenu->addAction(action);
            ++sessionCount;
            if (sessionCount == 10)
            {
                break;
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
    inline void initAction(QAction* action,
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
    inline void initButton(QPushButton* button,
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
}
}}}//end namespace

