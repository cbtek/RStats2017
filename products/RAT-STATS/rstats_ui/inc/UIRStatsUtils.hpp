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
    static void setButtonStyle(QAbstractButton * button,
                                 const QFont& font,
                                 const QIcon& icon,
                                 size_t buttonHeight,
                                 bool squareButton = false)
    {
        button->setFont(font);
        button->setIcon(icon);
        button->setIconSize(QSize(buttonHeight-8,buttonHeight-8));
        button->setMaximumHeight(buttonHeight);
        button->setMinimumHeight(buttonHeight);
        if (squareButton)
        {
            button->setMaximumWidth(buttonHeight);
            button->setMinimumWidth(buttonHeight);
        }
    }

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

    static void loadThemeSettings(QApplication * app)
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
    static void bindSheetToUI(const oig::ratstats::utils::RStatsWorksheet &sheet, QTableWidget *table, bool checkableHeader = false,int padRows=10,int padColumns=10)
    {
        table->clear();
        table->setColumnCount(sheet.getNumColumns()+padColumns);
        table->setRowCount(sheet.getNumRows()+padRows);
        for (size_t a1 = 0; a1 < table->columnCount();++a1)
        {
            QTableWidgetItem * header = new QTableWidgetItem;
            header->setText(QString::fromStdString(oig::ratstats::utils::RStatsUtils::getColumnLabelFromIndex(a1)));
            if (checkableHeader)
            {
                header->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
                header->setCheckState(Qt::Unchecked);
            }
            table->setHorizontalHeaderItem(a1,header);
        }

        for(const auto& itNext : sheet.getCells())
        {
            std::pair<size_t,size_t> index = itNext.first;
            oig::ratstats::utils::RStatsCell cell = itNext.second;
            QTableWidgetItem * item = new QTableWidgetItem;
            item->setText(QString::fromStdString(cell.text));
            table->setRowHeight(index.first,30);
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
            font.setPointSize(cell.font.getPointSize());
            item->setFont(font);
            switch(cell.alignment)
            {
                case oig::ratstats::utils::RStatsTextAlignment::AlignMiddle:item->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);break;
                case oig::ratstats::utils::RStatsTextAlignment::AlignRight:item->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);break;
                default:item->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft);break;
            }
            table->setItem(index.first,index.second,item);
        }
        table->show();
    }
}

}}}//end namespace

