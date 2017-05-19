/*
    RStatsXLSWorkbookStream.h
    

*/
#pragma once
#include "rstats_utils/inc/RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {
namespace streams {

/**
 * @brief The RStatsXLSWorkbookStream class Provides read/write support for XLS files 
 */
class RStatsXLSWorkbookStream :public RStatsWorkbookStream
{
public:
   /*
    * @brief RStatsXLSWorkbookStream (Constructor)
    * @param filePath The path to read/write to/from
	*/
    RStatsXLSWorkbookStream(const std::string& filePath);
    
    /**
     * @brief write Saves workbook object to XLS file
     * @param workbook The workbook to save
     */
    virtual void write(const RStatsWorkbook& workbook);

    /**
     * @brief read Parses XLS file and returns workbook
     * @return Return fully constructed workbook object from
     * XLS file
     */
    virtual RStatsWorkbook read();

	/*
     * @brief RStatsXLSWorkbookStream (Destructor)
     *
	 */
	~RStatsXLSWorkbookStream();	

private:
    std::string m_filePath;
    
};
}}}}//end namespace

