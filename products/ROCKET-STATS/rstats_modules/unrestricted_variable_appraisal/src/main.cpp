#include <QApplication>

#include "UIRStatsUVA.h"
#include "rstats_ui/inc/UIRStatsUtils.hpp"

using namespace cbtek::rocketstats::modules::uva;
using namespace cbtek::rocketstats::ui;

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
    UIRStatsUtils::loadThemeSettings(&a);
    UIRStatsUVA form;
    form.resize(1024,768);
    form.show();
    return a.exec();
}

