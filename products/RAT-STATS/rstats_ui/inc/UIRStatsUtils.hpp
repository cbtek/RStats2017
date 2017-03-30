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

#include "rstats_utils/inc/RStatsUtils.hpp"
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

    inline void loadThemeSettings(QApplication * app)
    {
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
     * @brief bindSheetToUI
     * @param sheet
     * @param table
     * @param padRows
     * @param padColumns
     */
    inline void bindSheetToUI(const oig::ratstats::utils::RStatsWorksheet &sheet, QTableWidget *table, bool checkableHeader = false,int padRows=10,int padColumns=10)
    {
        table->clear();
        table->setColumnCount(static_cast<int>(sheet.getNumColumns())+padColumns);
        table->setRowCount(static_cast<int>(sheet.getNumRows())+padRows);

        for (size_t a1 = 0; a1 < table->columnCount();++a1)
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

            cell.applyFormat(sheet.getCellFormatSet());
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
            checkBox->setToolTip(file);
            return file;
        }
        else
        {
            checkBox->setChecked(false);
        }
        return "";
    }
}

}}}//end namespace

