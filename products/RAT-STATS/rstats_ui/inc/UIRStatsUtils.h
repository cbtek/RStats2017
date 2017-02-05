/*
    UIRStatsUtils.h
    

*/

#pragma once

#include <QAbstractButton>
#include <QFont>
#include <QIcon>

#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsSettingsManager.h"

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

}
}}}//end namespace

