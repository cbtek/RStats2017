#include <QApplication>
#include <bitset>
#include <iostream>
#include <cfloat>
#include <map>

#include "RStatsSSRN.h"
#include "UISSRN.h"

using namespace oig::ratstats::utils;
using namespace oig::ratstats::ssrn;

int main(int argc, char ** argv)
{           
    QApplication a(argc,argv);
    UISSRN form;
    form.resize(640,480);
    return form.exec();
}
