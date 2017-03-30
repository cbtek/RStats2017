/*
    RStatsWorksheet.cpp
    

*/
//----------------------------------------
//RStatsWorksheet.cpp generated by CBTek Solutions on 02-01-2017 at 06:31:40 PM
//----------------------------------------
#include "RStatsWorksheet.h"

#include "utility/inc/StringUtils.hpp"

using namespace cbtek::common::utility;

namespace oig {
namespace ratstats {
namespace utils {

RStatsTextAlignment RStatsCell::ms_DefaultAlignment = RStatsTextAlignment::AlignLeft;
Color RStatsCell::ms_DefaultBGColor = ColorFactory::create(colors::TRANSPARENT_1);
Color RStatsCell::ms_DefaultFGColor = Color(0,0,0);
Font RStatsCell::ms_DefaultFont = cbtek::common::utility::Font("arial");
size_t RStatsCell::ms_DefaultFloatingPointDecimals = 6;

CREATE_EXCEPTION_NO_MSG(WorksheetCellOutOfRange)

RStatsWorksheet::RStatsWorksheet(const std::string &name)
{
    m_numColumns = 0;
    m_numRows = 0;
    m_worksheetTitle = name;
}

RStatsCell& RStatsWorksheet::operator()(const std::string &address)
{
    size_t r,c;
    parseCellAddress(address,r,c);
    return this->operator ()(r,c);
}

size_t RStatsWorksheet::getNumRows() const
{
    return m_numRows;
}

size_t RStatsWorksheet::getNumColumns() const
{
    return m_numColumns;
}

std::pair<size_t,size_t> RStatsWorksheet::getLastDataRowAndColumn() const
{
    size_t rows = getNumRows();
    size_t cols = getNumColumns();
    if (rows == 0 || cols == 0)
    {
        return std::make_pair(0,0);
    }

    for (int r = rows-1; r >= 0;++r)
    {
        for (int c = cols-1; c >= 0;++c)
        {
            if (!StringUtils::isEmpty(getCell(r,c).text))
            {
                return std::make_pair(r,c);
            }
        }
    }
    return std::make_pair(0,0);
}

const std::map<std::pair<size_t, size_t>, RStatsCell>& RStatsWorksheet::getCells() const
{
    return m_dataTable;
}

void RStatsWorksheet::setDefaultTextAlignment(RStatsTextAlignment alignment)
{
    RStatsCell::ms_DefaultAlignment = alignment;
}

void RStatsWorksheet::setDefaultBGColor(const Color &bgColor)
{
    RStatsCell::ms_DefaultBGColor = bgColor;
}

void RStatsWorksheet::setDefaultFGColor(const Color &fgColor)
{
    RStatsCell::ms_DefaultFGColor = fgColor;
}

void RStatsWorksheet::setDefaultFont(const Font &font)
{
    RStatsCell::ms_DefaultFont = font;
}

void RStatsWorksheet::setDefaultFloatingPointDecimals(size_t count)
{
    RStatsCell::ms_DefaultFloatingPointDecimals = count;
}

void RStatsWorksheet::resetDefaults()
{
    RStatsCell::ms_DefaultAlignment = RStatsTextAlignment::AlignLeft;
    RStatsCell::ms_DefaultBGColor = ColorFactory::create(colors::TRANSPARENT_1);
    RStatsCell::ms_DefaultFGColor = Color(0,0,0);
    RStatsCell::ms_DefaultFont = cbtek::common::utility::Font("arial");
    RStatsCell::ms_DefaultFloatingPointDecimals = 6;
}

std::set<RStatsCellFormat> RStatsWorksheet::getCellFormatSet() const
{
    return m_formatSet;
}

std::string RStatsWorksheet::toCommaDelimitedString() const
{
    return toString("\"",",","\"");
}

std::string RStatsWorksheet::toTabDelimitedString() const
{
    return toString("","\t","");
}

std::string RStatsWorksheet::toEvenlySpacedString() const
{
    return toEvenlySpacedString("","","");
}

bool RStatsWorksheet::isEmpty() const
{
    return (this->m_dataTable.size() == 0);
}

void RStatsWorksheet::findDataRowsAndColumns(std::set<size_t> &rowsOut,
                                             std::set<size_t> &columnsOut) const
{
    size_t cols = getNumColumns();
    size_t rows = getNumRows();
    std::ostringstream out;
    for(size_t r = 0;r<rows;++r)
    {
        bool hasData = false;
        for(size_t c = 0;c<cols;++c)
        {
            std::string data = getCell(r,c).text;
            if (!StringUtils::isEmpty(data))
            {
                hasData = true;
                columnsOut.insert(c);
            }
        }

        if (hasData)
        {
            rowsOut.insert(r);
        }
    }
}

void RStatsWorksheet::setFormatEnabled(RStatsCellFormat format,
                                       bool flag)
{
    if (flag)
    {
        m_formatSet.insert(format);
    }
    else
    {
        m_formatSet.erase(format);
    }
}

RStatsCell& RStatsWorksheet::operator()(size_t row, size_t column)
{
    if (row >= m_numRows)
    {
        m_numRows = row + 1;
    }
    if (column >= m_numColumns)
    {
        m_numColumns = column + 1;
    }
    return m_dataTable[std::make_pair(row,column)];
}

const RStatsCell &RStatsWorksheet::operator()(size_t row, size_t column) const
{
    return getCell(row,column);
}

const RStatsCell &RStatsWorksheet::getCell(size_t row, size_t column) const
{
    const auto& it = m_dataTable.find(std::make_pair(row,column));
    if (it != m_dataTable.end())
    {
        return it->second;
    }
    else if (row < getNumRows() && column < getNumColumns())
    {
        return m_emptyCell;
    }
    throw WorksheetCellOutOfRange(EXCEPTION_TAG_LINE+"The row/column is out of range for this cell.\n"+
                                  std::to_string(row)+" should be less than "+std::to_string(getNumRows())+
                                  +"\n"+std::to_string(column)+" should be less than "+std::to_string(getNumColumns()));
    //throw exception
}

RStatsWorksheet::~RStatsWorksheet()
{

}


void RStatsWorksheet::parseCellAddress(const std::string &address, size_t &r, size_t &c)
{
    std::string colLabel;
    std::string rowLabel;
    for (char i : address)
    {
        if (std::isalpha(i))
        {
            colLabel.push_back(i);
        }
        else if (std::isdigit(i))
        {
            rowLabel.push_back(i);
        }
    }
    r = StringUtils::toInt(rowLabel) - 1;
    c = RStatsUtils::getColumnIndexFromLabel(colLabel);
}

std::string RStatsWorksheet::toString(const std::string &prefix,
                               const std::string &seperator,
                               const std::string &postfix) const
{
    size_t cols = getNumColumns();
    size_t rows = getNumRows();
    std::ostringstream out;
    for(size_t r = 0;r<rows;++r)
    {
        for(size_t c = 0;c<cols;++c)
        {
            RStatsCell cell = getCell(r,c);
            cell.applyFormat(this->m_formatSet);
            std::string data = cell.text;
            out << prefix << data << postfix << ((c<(cols-1))?seperator:"\n");
        }
    }
    return out.str();
}

std::string RStatsWorksheet::toEvenlySpacedString(const std::string &prefix,
                                                  const std::string &seperator,
                                                  const std::string &postfix) const
{
    size_t cols = getNumColumns();
    size_t rows = getNumRows();
    std::vector<size_t> columnWidths(cols);
    for(size_t r = 0;r<rows;++r)
    {
        for(size_t c = 0;c<cols;++c)
        {
            RStatsCell cell = getCell(r,c);
            cell.applyFormat(this->m_formatSet);
            std::string data = cell.text;
            if (columnWidths[c] < data.size()+4)
            {
                columnWidths[c]=data.size()+4;
            }
        }
    }

    std::ostringstream out;
    for(size_t r = 0;r<rows;++r)
    {
        for(size_t c = 0;c<cols;++c)
        {
            RStatsCell cell = getCell(r,c);
            cell.applyFormat(this->m_formatSet);
            std::string data = cell.text;
            std::string space;
            if (columnWidths[c] > data.size())
            {
                space = StringUtils::repeat(" ", (columnWidths[c] - data.size()));
            }
            out <<space << prefix << data << postfix << ((c<(cols-1))?seperator:"\n");
        }
    }
    return out.str();
}

void RStatsWorksheet::setWorksheetTitle(const std::string & value)
{
    m_worksheetTitle=value;
}

const std::string &RStatsWorksheet::getWorksheetTitle() const
{
    return m_worksheetTitle;
}

}}}//end namespace


