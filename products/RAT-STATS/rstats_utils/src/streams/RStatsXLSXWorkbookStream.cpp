/*
    RStatsXLSXWorkbookStream.cpp
    

*/
//----------------------------------------
//RStatsXLSXWorkbookStream.cpp generated by CBTek Solutions on 02-01-2017 at 11:54:04 PM
//----------------------------------------
#include "RStatsXLSXWorkbookStream.h"

#include "contrib/xlsxwriter/inc/xlsxwriter.h"

#include "RStatsWorksheet.h"

namespace oig {
namespace ratstats {
namespace utils {


RStatsXLSXWorkbookStream::RStatsXLSXWorkbookStream(const std::string &filePath)
{
    m_filePath = filePath;
}

void RStatsXLSXWorkbookStream::write(const RStatsWorkbook &workbook)
{
    lxw_workbook  *workbookTo  = workbook_new(m_filePath.c_str());
    size_t sheetCount = workbook.getNumWorksheets();
    for (size_t a1 = 0; a1 < sheetCount; ++a1)
    {
        const RStatsWorksheet& worksheetFrom = workbook(a1);
        lxw_worksheet *worksheetTo = workbook_add_worksheet(workbookTo, worksheetFrom.getWorksheetTitle().c_str());
        for (const auto& it : worksheetFrom.getCells())
        {
            std::pair<size_t,size_t> index = it.first;
            RStatsCell cell = it.second;
            worksheet_write_string(worksheetTo,index.first,index.second,cell.text.c_str(), NULL);
        }
    }
    workbook_close(workbookTo);
}

RStatsWorkbook RStatsXLSXWorkbookStream::read()
{
}

RStatsXLSXWorkbookStream::~RStatsXLSXWorkbookStream()
{

}




}}}//end namespace


