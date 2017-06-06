#include "UIRStatsSVA.h"
#include "rstats_ui/inc/UIRStatsUtils.hpp"

#include <iostream>

#include <QApplication>

using namespace cbtek::rocketstats::modules::sva;
using namespace cbtek::rocketstats::ui;

int main(int argc, char ** argv)
{    

    QApplication a(argc,argv);
    UIRStatsUtils::loadThemeSettings(&a);
    UIRStatsSVA form;
    form.resize(1024,768);
    form.show();
    return a.exec();
}
