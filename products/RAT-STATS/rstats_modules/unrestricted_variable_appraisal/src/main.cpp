#include <QApplication>

#include "UIRStatsUVA.h"
#include "rstats_ui/inc/UIRStatsUtils.hpp"

using namespace oig::ratstats::modules::uva;
using namespace oig::ratstats::ui;

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
    UIRStatsUtils::loadThemeSettings(&a);
    UIRStatsUVA form;
    form.resize(1024,768);
    form.show();
    return a.exec();
}

