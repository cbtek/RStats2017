#include <QApplication>
#include <bitset>
#include <iostream>
#include <cfloat>
#include <map>

#include "RStatsSSRN.h"
#include "UIRStatsSSRN.h"

using namespace oig::ratstats::utils;
using namespace oig::ratstats::modules::ssrn;

int main(int argc, char ** argv)
{           
    QApplication a(argc,argv);
    UIRStatsSSRN form;
    form.show();
    return a.exec();
}
