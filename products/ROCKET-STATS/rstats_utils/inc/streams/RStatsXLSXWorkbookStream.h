/*
    RStatsXLSXWorkbookStream.h
    

*/

#pragma once
#include "rstats_utils/inc/RStatsWorkbookStream.hpp"

namespace cbtek {
namespace rocketstats {
namespace utils {
namespace streams {

/**
 * @brief The RStatsXLSXWorkbookStream class provides read support for
 * XLSX files.  WARNING: The write function is not implemented and will
 * throw an exception if called. 
 */
class RStatsXLSXWorkbookStream :public RStatsWorkbookStream
{
public:

    /**
     * @brief RStatsXLSXWorkbookStream (Constructor)
     * @param filePath The path to read from
     */
    RStatsXLSXWorkbookStream(const std::string& filePath);
    
    /**
     * @brief write In the future this should write a workbook to
     * a xlsx file. WARNING: The write function is not implemented and will
     * throw an exception if called.
     * @param workbook The workbook to write
     * @throws GenericException
     */
    void write(const RStatsWorkbook &workbook);

    /**
     * @brief read Parses XLSX file and returns it as a workbook object
     * @return Returns workbook object of XLSX file
     * @throws GenericException if xlsx file was unable to be opened
     */
    RStatsWorkbook read();

	//! Destructor
	~RStatsXLSXWorkbookStream();	

private:            
    std::string m_filePath;
};
}}}}//end namespace


