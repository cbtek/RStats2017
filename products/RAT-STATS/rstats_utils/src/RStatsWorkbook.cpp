/*
    RStatsWorkbook.cpp
    

*/
//----------------------------------------
//RStatsWorkbook.cpp generated by CBTek Solutions on 02-01-2017 at 11:34:00 PM
//----------------------------------------
#include "RStatsWorkbook.h"

#include "utility/inc/Exception.hpp"

#include "RStatsWorkbookStreamFactory.h"

namespace oig {
namespace ratstats {
namespace utils {

CREATE_EXCEPTION_NO_MSG(RStatsWorkbookException)

RStatsWorkbook::RStatsWorkbook()
{

}

void RStatsWorkbook::save(const std::string &filePath)
{
    RStatsWorkbookStreamPtr stream = RStatsWorkbookStreamFactory::create(filePath);
    if (stream.get())
    {
        stream->write(*this);
    }
}

void RStatsWorkbook::load(const std::string &filePath)
{
    RStatsWorkbookStreamPtr stream = RStatsWorkbookStreamFactory::create(filePath);
    if (stream.get())
    {
        (*this) = stream->read();
    }
}

void RStatsWorkbook::addWorksheet(const RStatsWorksheet &sheet)
{
    m_worksheets.push_back(sheet);
}

RStatsWorksheet& RStatsWorkbook::createWorksheet(const std::string &name)
{
    m_worksheets.push_back(RStatsWorksheet(name));
    return m_worksheets.back();
}

const std::vector<RStatsWorksheet> &RStatsWorkbook::getWorksheets() const
{
    return m_worksheets;
}

void RStatsWorkbook::removeWorksheet(size_t index)
{
    if (index < m_worksheets.size())
    {
        m_worksheets.erase(m_worksheets.begin()+index);
    }
}

size_t RStatsWorkbook::getNumWorksheets() const
{
    return m_worksheets.size();
}

RStatsWorksheet& RStatsWorkbook::operator()(size_t index)
{
    if (index < m_worksheets.size())
    {
        return m_worksheets[index];
    }
    throw RStatsWorkbookException(EXCEPTION_TAG_LINE+"Index at "+std::to_string(index)+" is out of range!");
}

const RStatsWorksheet &RStatsWorkbook::operator()(size_t index) const
{
    if (index < m_worksheets.size())
    {
        return m_worksheets[index];
    }
    throw RStatsWorkbookException(EXCEPTION_TAG_LINE+"Index at "+std::to_string(index)+" is out of range!");
}

std::vector<std::string> RStatsWorkbook::getWorksheetNames() const
{
    std::vector<std::string> names;
    for(const RStatsWorksheet& sheet : m_worksheets)
    {
        names.push_back(sheet.getWorksheetTitle());
    }
    return names;
}

RStatsWorksheet RStatsWorkbook::mergeSheets(RStatsWorkbookMergeDirection direction,size_t padding)
{
    RStatsWorksheet mergedSheet;
    if (direction == RStatsWorkbookMergeDirection::MergeBottom)
    {
        size_t currentRow = 0;
        for (const auto& currentSheet : m_worksheets)
        {
            for (size_t r = 0; r < currentSheet.getNumRows(); ++r)
            {
                for (size_t c = 0; c < currentSheet.getNumColumns(); ++c)
                {
                    mergedSheet(currentRow,c) = currentSheet(r,c);
                }
                ++currentRow;
            }
            currentRow += padding;
        }
    }

    if (direction == RStatsWorkbookMergeDirection::MergeRight)
    {
        size_t currentColumn = 0;
        for (const auto& currentSheet : m_worksheets)
        {
            for (size_t c = 0; c <currentSheet.getNumColumns(); ++c)
            {
                for (size_t r = 0; r < currentSheet.getNumRows(); ++r)
                {
                    mergedSheet(r,currentColumn) = currentSheet(r,c);
                }
                ++currentColumn;
            }
            currentColumn += padding;
        }
    }
    return mergedSheet;
}

void RStatsWorkbook::clear()
{
    m_worksheets.clear();
}

RStatsWorkbook::~RStatsWorkbook()
{

}

void oig::ratstats::utils::RStatsWorkbook::insertWorksheet(const RStatsWorksheet &sheet, size_t index)
{
    if (index >= m_worksheets.size())
    {
        m_worksheets.resize(index + 1);
        m_worksheets[index] = sheet;
    }
    else
    {
        m_worksheets.insert(m_worksheets.begin() + static_cast<long>(index),sheet);
    }
}
}}}//end namespace


