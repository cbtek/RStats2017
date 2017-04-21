/*
    RStatsDIFWorkbookStream.h
    

*/


#pragma once

#include <string>

#include "rstats_utils/inc/RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {
namespace streams {

class RStatsDIFWorkbookStream : public RStatsWorkbookStream
{
public:
    //! Constructor for RStatsDIFWorkbookStream
	/*!
        Detailed description for RStatsDIFWorkbookStream
	*/
    RStatsDIFWorkbookStream(const std::string& filePath);


    /**
     * @brief RStatsDIFWorkbookStream
     * @param filePaths
     */
    RStatsDIFWorkbookStream(const std::vector<std::string>& filePaths);
    
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

	//! Destructor
    ~RStatsDIFWorkbookStream();

private:

    void writeHeader(const RStatsWorksheet& sheet,
                     std::ostream& out);

    void writeCell(const RStatsCell& cell,
                   std::ostream& out);

    std::vector<std::string> m_filePaths;
    
};
}}}}//end namespace
