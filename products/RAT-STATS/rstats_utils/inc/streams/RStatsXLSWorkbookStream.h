/*
    RStatsXLSWorkbookStream.h
    

*/
#pragma once
#include "rstats_utils/inc/RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {
namespace streams {

class RStatsXLSWorkbookStream :public oig::ratstats::utils::RStatsWorkbookStream
{
public:
   /*
    * @brief RStatsXLSWorkbookStream
    *
	*/
    RStatsXLSWorkbookStream(const std::string& filePath);
    
    /**
     * @brief write
     * @param input
     */
    virtual void write(const RStatsWorkbook& workbook);

    /**
     * @brief read
     * @return
     */
    virtual RStatsWorkbook read();

	/*
	 * @brief RStatsXLSWorkbookStream (Descructor)
     *
	 */
	~RStatsXLSWorkbookStream();	

private:
    std::string m_filePath;
    
};
}}}}//end namespace

