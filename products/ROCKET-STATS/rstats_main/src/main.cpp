
#include <QApplication>

#include "UIRStatsMain.h"

#include "rstats_ui/inc/UIRStatsErrorMessage.h"
#include "rstats_ui/inc/UIRStatsUtils.hpp"

#include "utility/inc/Exception.hpp"

using namespace cbtek::common::utility;
using namespace cbtek::rocketstats::ui;
using namespace cbtek::rocketstats::utils;
using namespace cbtek::rocketstats::main;

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
    UIRStatsUtils::loadThemeSettings(&a);
    UIRStatsMain main;
    main.show();
    return a.exec();

}

