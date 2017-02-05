#include "RStatsSVA.h"
#include <iostream>
#include "contrib/xlsxwriter/inc/xlsxwriter.h"
#include <QApplication>

#include "rstats_ui/inc/UIRStatsWorkbook.h"

using namespace oig::ratstats::sva;
using namespace oig::ratstats::ui;
using namespace oig::ratstats::utils;

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
    RStatsSVAInputDataList inputDataList;
    RStatsSVAInputData data1,data2;
    data1.sampleSize = 5;
    data1.universeSize = 5;
    data1.samples.initialize(5);
    data1.samples(0) = 9.10;
    data1.samples(1) = 2.56;
    data1.samples(2) = 4.32;
    data1.samples(3) = 6.72;
    data1.samples(4) = 5.443;

    data2.sampleSize = 10;
    data2.universeSize = 10;
    data2.samples.initialize(10);
    data2.samples(0) = 2.1;
    data2.samples(1) = 2.3;
    data2.samples(2) = 3.4;
    data2.samples(3) = 5.6;
    data2.samples(4) = 7.8;
    data2.samples(5) = 9;
    data2.samples(6) = 8.1;
    data2.samples(7) = 7.2;
    data2.samples(8) = 6.3;
    data2.samples(9) = 5.4;

    inputDataList.push_back(data1);
    inputDataList.push_back(data2);
    RStatsSVAOutputDataList outputDataList;
    outputDataList = RStatsSVA::inst().execute(RStatsSVADataFormatType::Audit, inputDataList);
    RStatsWorkbook workbook;
    RStatsSVA::inst().populateWorkbookFromOutputList(outputDataList,workbook);
    UIRStatsWorkbook * workbookWidget = new UIRStatsWorkbook(workbook);
    workbookWidget->show();
    return a.exec();
}

