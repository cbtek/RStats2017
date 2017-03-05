/*
    UIRStatsUtils.h
    

*/

#pragma once

#include <QAbstractButton>
#include <QFont>
#include <QIcon>

#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsSettingsManager.h"
#include "utility/inc/SystemUtils.hpp"
#include "utility/inc/FileUtils.hpp"

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
        std::string exeDir = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(),"resx/"+iconFileName);
        std::string appDir = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserAppDirectory(),"resx/"+iconFileName);
        std::string homeDir = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserHomeDirectory(),"resx/"+iconFileName);
        if (cbtek::common::utility::FileUtils::fileExists(exeDir))
        {
            icon = QIcon(QString::fromStdString(exeDir));
        }
        else if (cbtek::common::utility::FileUtils::fileExists(appDir))
        {
            icon = QIcon(QString::fromStdString(appDir));
        }
        else if (cbtek::common::utility::FileUtils::fileExists(homeDir))
        {
            icon = QIcon(QString::fromStdString(homeDir));
        }
        return icon;
    }



}
}}}//end namespace

