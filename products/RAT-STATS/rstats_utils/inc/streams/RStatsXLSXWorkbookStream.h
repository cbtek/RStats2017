/*
    RStatsXLSXWorkbookStream.h
    

*/

#ifndef _OIG_RATSTATS_UTILS_RSTATSXLSXWORKBOOKSTREAM_H
#define _OIG_RATSTATS_UTILS_RSTATSXLSXWORKBOOKSTREAM_H
#include "RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {


class RStatsXLSXWorkbookStream :public RStatsWorkbookStream
{
public:
	//! Constructor for RStatsXLSXWorkbookStream
	/*!
		Detailed description for RStatsXLSXWorkbookStream
	*/
    RStatsXLSXWorkbookStream(const std::string& filePath);
    
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
	~RStatsXLSXWorkbookStream();	

private:
    std::string m_filePath;
};
}}}//end namespace

#endif // _OIG_RATSTATS_UTILS_RSTATSXLSXWORKBOOKSTREAM_H

