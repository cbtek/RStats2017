#include <QApplication>

#include "RStatsUAA.h"
#include "UIRStatsUAA.h"

#include "rstats_ui/inc/UIRStatsUtils.hpp"

using namespace cbtek::rocketstats::modules::uaa;
using namespace cbtek::rocketstats::utils;
using namespace cbtek::rocketstats::ui;

using namespace cbtek::common::utility;

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
    UIRStatsUtils::loadThemeSettings(&a);
    UIRStatsUAA form;
    form.resize(1024,768);
    form.show();
    return a.exec();
}
