#include "RStatsSVA.h"
#include <iostream>
#include <QApplication>

#include "rstats_ui/inc/UIRStatsWorkbook.h"
#include "UIRStatsSVA.h"
#include "rstats_utils/inc/RStatsDataFileParser.h"
#include "rstats_utils/inc/RStatsWorksheet.h"
#include "rstats_utils/inc/streams/RStatsXLSXWorkbookStream.h"

#include "rstats_ui/inc/UIRStatsUtils.hpp"

#include "utility/inc/SystemUtils.hpp"

using namespace oig::ratstats::modules::sva;
using namespace oig::ratstats::ui;
using namespace oig::ratstats::utils;
using namespace cbtek::common::utility;

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
    UIRStatsUtils::loadThemeSettings(&a);
    UIRStatsSVA form;
    form.resize(1024,768);
    form.show();
    return a.exec();
//
    streams::RStatsXLSXWorkbookStream stream("/home/cbtek/dev/bin/TeamCBTek/debug/example.xlsx");
    RStatsWorkbook workbook = stream.read();
    UIRStatsWorkbook * workbookWidget = new UIRStatsWorkbook(workbook);
    workbookWidget->resize(1024,768);
    workbookWidget->show();
    return a.exec();
    std::cerr << RStatsUtils::getUnzipCommandPath()<<std::endl;
    if (FileUtils::fileExists(RStatsUtils::getUnzipCommandPath()))
    {
        SystemUtils::execute(RStatsUtils::getUnzipCommandPath()+" --help");
    }
    return 0;
    RStatsDataFileParser parser("/home/cbtek/dev/bin/TeamCBTek/debug/theone.txt");
    oig::ratstats::utils::RStatsWorksheet sheet1 = parser.load();
    parser.write(sheet1);
    return 0;    
      RStatsSVAInputDataList inputDataList;
//    RStatsSVAInputData data1,data2;
//    data1.sampleSize = 5;
//    data1.universeSize = 5;
//    data1.samples.initialize(5);
//    data1.samples(0) = 9.10;
//    data1.samples(1) = 2.56;
//    data1.samples(2) = 4.32;
//    data1.samples(3) = 6.72;
//    data1.samples(4) = 5.443;

//    data2.sampleSize = 10;
//    data2.universeSize = 10;
//    data2.samples.initialize(10);
//    data2.samples(0) = 2.1;
//    data2.samples(1) = 2.3;
//    data2.samples(2) = 3.4;
//    data2.samples(3) = 5.6;
//    data2.samples(4) = 7.8;
//    data2.samples(5) = 9;
//    data2.samples(6) = 8.1;
//    data2.samples(7) = 7.2;
//    data2.samples(8) = 6.3;
//    data2.samples(9) = 5.4;

//    inputDataList.push_back(data1);
//    inputDataList.push_back(data2);
//    RStatsSVAOutputDataList outputDataList;
//    outputDataList = RStatsSVA::inst().execute(RStatsDataFormatType::Audit, inputDataList);
//    RStatsWorkbook workbook;
//    RStatsSVA::inst().populateWorkbookFromOutputList(outputDataList,workbook);
//    UIRStatsWorkbook * workbookWidget = new UIRStatsWorkbook(workbook);
//    workbookWidget->show();
//    return a.exec();
}

