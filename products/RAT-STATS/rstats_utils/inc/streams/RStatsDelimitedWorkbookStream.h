/*
    RStatsDelimitedWorkbookStream.h
    

*/

#pragma once

#include "RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {
namespace streams {


class RStatsDelimitedWorkbookStream : public RStatsWorkbookStream
{
public:
    //! Constructor for RStatsDelimitedWorkbookStream
	/*!
        Detailed description for RStatsDelimitedWorkbookStream
	*/
    RStatsDelimitedWorkbookStream(const std::string& filePath, bool readHeader = false);
    
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
    ~RStatsDelimitedWorkbookStream();

private:
    std::vector<std::string> splitLine(const std::string &line) const;

    bool m_readHeader;
    std::vector<std::string> m_header;
    std::string m_filePath;
    
};
}}}}//end namespace


