#include <QApplication>

#include "RStatsUAA.h"
#include "UIRStatsUAA.h"

#include "rstats_ui/inc/UIRStatsUtils.hpp"

using namespace oig::ratstats::modules::uaa;
using namespace oig::ratstats::utils;
using namespace oig::ratstats::ui;

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
