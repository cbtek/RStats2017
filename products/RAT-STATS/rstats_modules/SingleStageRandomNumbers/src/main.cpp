#include <QApplication>
#include <bitset>
#include <iostream>
#include <cfloat>
#include <map>

#include "RStatsSSRN.h"
#include "UIRStatsSSRN.h"
#include "rstats_ui/inc/UIRStatsUtils.hpp"

using namespace oig::ratstats::utils;

using namespace oig::ratstats::ui;
using namespace oig::ratstats::modules::ssrn;

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
    UIRStatsUtils::loadThemeSettings(&a);
    UIRStatsSSRN form;
    form.resize(1024,768);
    form.show();
    return a.exec();
}
