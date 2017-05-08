#include "UIRStatsSVA.h"
#include "rstats_ui/inc/UIRStatsUtils.hpp"

#include <iostream>

#include <QApplication>

using namespace oig::ratstats::modules::sva;
using namespace oig::ratstats::ui;

int main(int argc, char ** argv)
{    

    QApplication a(argc,argv);
    UIRStatsUtils::loadThemeSettings(&a);
    UIRStatsSVA form;
    form.resize(1024,768);
    form.show();
    return a.exec();
}
