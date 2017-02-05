/*
    RStatsCSVWorkbookStream.h
    

*/

#ifndef _OIG_RATSTATS_UTILS_RSTATSCSVWORKBOOKSTREAM_H
#define _OIG_RATSTATS_UTILS_RSTATSCSVWORKBOOKSTREAM_H
#include "RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {


class RStatsCSVWorkbookStream :public RStatsWorkbookStream
{
public:
	//! Constructor for RStatsCSVWorkbookStream
	/*!
		Detailed description for RStatsCSVWorkbookStream
	*/
    RStatsCSVWorkbookStream(const std::string& filePath);
    
    /**
     * @brief write
     * @param workbook
     */
    void write(const RStatsWorkbook &workbook);

    /**
     * @brief read
     * @return
     */
    RStatsWorkbook read();

	//! Destructor
	~RStatsCSVWorkbookStream();	

private:
    std::string m_filePath;
    
};
}}}//end namespace

#endif // _OIG_RATSTATS_UTILS_RSTATSCSVWORKBOOKSTREAM_H

