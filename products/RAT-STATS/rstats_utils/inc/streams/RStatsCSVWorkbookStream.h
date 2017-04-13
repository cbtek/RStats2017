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
	//! Constructor for RStatsCSVWorkbookStream
	/*!
		Detailed description for RStatsCSVWorkbookStream
	*/
    RStatsCSVWorkbookStream(const std::string& filePath);

    /**
     * @brief RStatsCSVWorkbookStream
     * @param filePaths
     */
    RStatsCSVWorkbookStream(const std::vector<std::string>& filePaths);
    
    /**
     * @brief write
     * @param workbook
     */
    virtual void write(const RStatsWorkbook& workbook);

    /**
     * @brief read
     * @return
     */
    virtual RStatsWorkbook read();

	//! Destructor
	~RStatsCSVWorkbookStream();	

private:
    std::vector<std::string> m_filePaths;

    void readRow(const std::string& line,
                 RStatsWorksheet& sheetOut, size_t currentRow);

    bool readCell(const std::string& line,
                  size_t& startIndex,
                  std::string& dataOut);

    void parseLastCellOnRow(std::string &dataOut);


};
}}}}//end namespace
