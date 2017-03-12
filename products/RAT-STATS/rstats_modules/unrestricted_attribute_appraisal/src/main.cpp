#include <QApplication>

#include "RStatsUAA.h"
#include "UIRStatsUAA.h"

using namespace oig::ratstats::modules::uaa;

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
    UIRStatsUAA form;
    form.show();
    return a.exec();
}
