/*
    RStatsAccessWorkbookStream.h
    

*/

#ifndef _OIG_RATSTATS_UTILS_RSTATSACCESSWORKBOOKSTREAM_H
#define _OIG_RATSTATS_UTILS_RSTATSACCESSWORKBOOKSTREAM_H
#include "RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {


class RStatsAccessWorkbookStream :public RStatsWorkbookStream
{
public:
	//! Constructor for RStatsAccessWorkbookStream
	/*!
		Detailed description for RStatsAccessWorkbookStream
	*/
    RStatsAccessWorkbookStream(const std::string& filePath);
    
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
	~RStatsAccessWorkbookStream();	

private:
    std::string m_filePath;
    
};
}}}//end namespace

#endif // _OIG_RATSTATS_UTILS_RSTATSACCESSWORKBOOKSTREAM_H

