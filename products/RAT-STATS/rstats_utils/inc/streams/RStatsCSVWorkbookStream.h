/*
    RStatsCSVWorkbookStream.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {
namespace streams {


class RStatsCSVWorkbookStream :public RStatsWorkbookStream
{
public:

    /**
     * @brief RStatsCSVWorkbookStream (Constructor) Sets the path for input/output
     * @param filePath The path to the input/output file
     */
    RStatsCSVWorkbookStream(const std::string& filePath);

    /**
     * @brief write Writes a workbook out to file. Note that this will only write the first sheet
     * to the CSV file and add it to the workbook since CSV does not support mulitple sheets.
     * @param workbook The workbook object to write
     */
    virtual void write(const RStatsWorkbook& workbook);

    /**
     * @brief read Reads a workbook from file. Note that this will only read a single sheet from
     * the CSV file and add it to the workbook since CSV does not support mulitple sheets
     * @return Return constructed Workbook object
     */
    virtual RStatsWorkbook read();

	//! Destructor
	~RStatsCSVWorkbookStream();	

private:    
    std::string m_filePath;
    /**
     * @brief readRow Parses a single CSV data line
     * @param line The line of data items seperated by commas
     * @param sheetOut The current sheet to write to
     * @param currentRow The current row
     */
    void readRow(const std::string& line,
                 RStatsWorksheet& sheetOut, size_t currentRow);

    /**
     * @brief readCell Parses a single CSV data item
     * @param line The line of data items seperated by commas
     * @param startIndex Offset index into the line of data
     * @param dataOut The cell data to be read
     * @return Return true if readCell was completed, false if end of line was reached
     */
    bool readCell(const std::string& line,
                  size_t& startIndex,
                  std::string& dataOut);

    /**
     * @brief parseLastCellOnRow Parses the last cell on the row
     * @param dataOut The cell to be written to
     */
    void parseLastCellOnRow(std::string &dataOut);


};
}}}}//end namespace
