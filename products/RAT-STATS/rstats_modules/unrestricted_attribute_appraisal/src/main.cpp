#include <QApplication>

#include "RStatsUAA.h"
#include "UIRStatsUAA.h"

using namespace oig::ratstats::modules::uaa;

int main(int argc, char ** argv)
{
    RStatsUAA::inst().execute(100,1000,12,false);
    return 0;
    QApplication a(argc,argv);
    UIRStatsUAA form;
    form.show();
    return a.exec();
}
