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

#include <map>

#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsModuleSessionDataImpl.h"
#include "rstats_utils/inc/RStatsWorkbook.h"

#include "rstats_utils/inc/RStatsSettingsManager.h"

#include "utility/inc/SystemUtils.hpp"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/XMLReader.h"

namespace oig {
namespace ratstats {
namespace ui {

namespace UIRStatsUtils
{
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
        app->setStyleSheet("");
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
                    if (StringUtils::isNumeric(StringUtils::remove(sheetOut(r,c).text,",")))
                    {
                        sheetOut(r,c).text = StringUtils::remove(sheetOut(r,c).text,",");
                    }

                    std::uint8_t fgR = static_cast<std::uint8_t>(item->foreground().color().red());
                    std::uint8_t fgG = static_cast<std::uint8_t>(item->foreground().color().green());
                    std::uint8_t fgB = static_cast<std::uint8_t>(item->foreground().color().blue());

                    std::uint8_t bgR = static_cast<std::uint8_t>(item->background().color().red());
                    std::uint8_t bgG = static_cast<std::uint8_t>(item->background().color().green());
                    std::uint8_t bgB = static_cast<std::uint8_t>(item->background().color().blue());
                    sheetOut(r,c).fgColor.set(fgR,fgB,fgG);
                    sheetOut(r,c).bgColor.set(bgR,bgB,bgG);
                    sheetOut(r,c).font = Font(item->font().family().toStdString(),
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
    inline void bindSheetToUI(const oig::ratstats::utils::RStatsWorksheet &sheetIn, QTableWidget *table, bool checkableHeader = false,int padRows=10,int padColumns=10)
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


    /**
     * @brief setOutputFile
     * @param checkBox
     * @param title
     * @param extension
     * @return
     */
    inline QString setOutputFile(QCheckBox * checkBox,
                              const QString& title,
                              const QString& extension)
    {
        QString file = QFileDialog::getSaveFileName(nullptr,title,"",extension);

        if (!cbtek::common::utility::StringUtils::isEmpty(file.toStdString()))
        {
            std::string ext = cbtek::common::utility::StringUtils::remove(extension.toStdString(),"*");
            checkBox->setToolTip(file);
            if (!StringUtils::endsWith(file.toStdString(),ext,false))
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
     * @brief buildRecentSessions
     * @param parent
     * @param menuRecentAction
     * @param sessionMapOut
     * @param sessionExtension
     * @return
     */
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
            QAction * action = new QAction(QString::fromStdString(it->second->getAuditName()) +"(Created on "+QString::fromStdString(dateTimeStr)+")", recentMenu);
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
     * @brief customUISetup
     * @param executeButton
     * @param exitButton
     * @param helpButton
     * @param folderBrowse1Button
     * @param folderBrowse2Button
     * @param folderBrowse3Button
     * @param addRowButton1
     * @param addColumnButton1
     * @param addRowButton2
     * @param addColumnButton2
     * @param executeAction
     * @param exitAction
     * @param helpAction
     * @param aboutAction
     * @param recentAction
     * @param buttonHeight
     * @param font
     */
    inline void customUISetup(QPushButton* executeButton = nullptr,
                            QPushButton* exitButton = nullptr,
                            QPushButton* helpButton = nullptr,
                            QPushButton* folderBrowse1Button = nullptr,
                            QPushButton* folderBrowse2Button = nullptr,
                            QPushButton* folderBrowse3Button = nullptr,
                            QPushButton* addRowButton1 = nullptr,
                            QPushButton* addColumnButton1 = nullptr,
                            QPushButton* addRowButton2 = nullptr,
                            QPushButton* addColumnButton2 = nullptr,
                            QAction* executeAction = nullptr,
                            QAction* exitAction = nullptr,
                            QAction* helpAction = nullptr,
                            QAction* aboutAction = nullptr,
                            QAction* recentAction = nullptr,
                            int buttonHeight = 32,
                            QFont font = QFont())
    {
        QIcon iconFolder = UIRStatsUtils::getIcon("img_folder.png");
        QIcon iconHelp = UIRStatsUtils::getIcon("img_help.png");
        QIcon iconExit = UIRStatsUtils::getIcon("img_exit.png");
        QIcon iconRun = UIRStatsUtils::getIcon("img_run.png");
        QIcon iconAdd = UIRStatsUtils::getIcon("img_add.png");
        if (recentAction)
        {
            recentAction->setIcon(UIRStatsUtils::getIcon("img_clock.png"));
        }
        if (aboutAction)
        {
            aboutAction->setIcon(UIRStatsUtils::getIcon("img_about.png"));
            aboutAction->setShortcut(QKeySequence("Alt+A"));
        }
        if (helpAction)
        {
            helpAction->setIcon(iconHelp);
            helpAction->setShortcut(QKeySequence("Alt+H"));
        }
        if (exitAction)
        {
            exitAction->setIcon(iconExit);
            exitAction->setShortcut(QKeySequence("Alt+Q"));
        }
        if (executeAction)
        {
            executeAction->setIcon(iconRun);
            executeAction->setShortcut(QKeySequence("Alt+R"));
        }
        if (executeButton)
        {
            UIRStatsUtils::setButtonStyle(executeButton,font,iconRun,buttonHeight,false);
        }

        if (helpButton)
        {
            UIRStatsUtils::setButtonStyle(helpButton,font,iconHelp,buttonHeight,false);
        }

        if (exitButton)
        {
            UIRStatsUtils::setButtonStyle(exitButton,font,iconExit,buttonHeight,false);
        }


        if (folderBrowse1Button)
        {
            UIRStatsUtils::setButtonStyle(folderBrowse1Button,font,iconFolder,buttonHeight,false);
        }

        if (folderBrowse2Button)
        {
            UIRStatsUtils::setButtonStyle(folderBrowse2Button,font,iconFolder,buttonHeight,false);
        }

        if (folderBrowse3Button)
        {
            UIRStatsUtils::setButtonStyle(folderBrowse3Button,font,iconFolder,buttonHeight,false);
        }

        if (addRowButton1)
        {
            UIRStatsUtils::setButtonStyle(addRowButton1,font,iconAdd,buttonHeight,false);
        }

        if (addColumnButton1)
        {
            UIRStatsUtils::setButtonStyle(addColumnButton1,font,iconAdd,buttonHeight,false);
        }
        if (addRowButton2)
        {
            UIRStatsUtils::setButtonStyle(addRowButton2,font,iconAdd,buttonHeight,false);
        }

        if (addColumnButton2)
        {
            UIRStatsUtils::setButtonStyle(addColumnButton2,font,iconAdd,buttonHeight,false);
        }

    }
}
}}}//end namespace

