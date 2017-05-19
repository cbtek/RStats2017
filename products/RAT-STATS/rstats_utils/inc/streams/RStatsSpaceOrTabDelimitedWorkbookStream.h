/*
    RStatsSpaceOrTabDelimitedWorkbookStream.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {
namespace streams {

/**
 * @brief The RStatsSpaceOrTabDelimitedWorkbookStream class provides support for
 * reading and writing to space and tab delimited files 
 */
class RStatsSpaceOrTabDelimitedWorkbookStream :public RStatsWorkbookStream
{
public:

    /**
     * @brief RStatsSpaceOrTabDelimitedWorkbookStream (Constructor) Sets the path for input/output
     * @param filePath The path to the input/output file
     */
    RStatsSpaceOrTabDelimitedWorkbookStream(const std::string& filePath);

    /**
     * @brief write Writes a workbook out to file. Note that this will only write the first sheet
     * to the ssv,txt or dat file and add it to the workbook since CSV does not support mulitple sheets.
     * @param workbook The workbook object to write
     */
    virtual void write(const RStatsWorkbook& workbook);

    /**
     * @brief read Reads a workbook from file. Note that this will only read a single sheet from
     * the ssv,txt or dat file and add it to the workbook since they do not support mulitple sheets
     * @return Return constructed Workbook object
     */
    virtual RStatsWorkbook read();

	//! Destructor
    ~RStatsSpaceOrTabDelimitedWorkbookStream();

private:    
    std::string m_filePath;

};
}}}}//end namespace
