#include <QApplication>
#include <bitset>
#include <iostream>
#include <cfloat>
#include <map>

#include "RStatsSSRN.h"
#include "UIRStatsSSRN.h"
#include "rstats_ui/inc/UIRStatsUtils.hpp"
#include "utility/inc/Random.h"

using namespace cbtek::common::utility;

using namespace cbtek::rocketstats::utils;
using namespace cbtek::rocketstats::ui;
using namespace cbtek::rocketstats::modules::ssrn;

int main(int argc, char ** argv)
{    
//    std::cerr << TimeUtils::getSecondsNow()<<std::endl;

//    RStatsSSRNOutputData output  = RStatsSSRN::inst().execute("test",41983.64,100,1,0,101);
//    std::cerr << "sum="<<output.sum<<std::endl;
//    RStatsWorksheet sheet;
//    int r = 0;
//    for(const RStatsSSRNValue& value : output.values)
//    {
//         sheet(r,0) = value.orderIndex;
//         sheet(r,1) = value.value;
//         ++r;
//    }
//    std::cerr << sheet.toEvenlySpacedString() << std::endl;
//    return 0;
    QApplication a(argc,argv);
    UIRStatsUtils::loadThemeSettings(&a);
    UIRStatsSSRN form;        
    form.resize(1024,768);
    form.show();
    return a.exec();
}
