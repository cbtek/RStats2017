/*
    RStatsWorkbook.h
    

*/

#pragma once

#include "RStatsWorksheet.h"

#include <vector>

namespace oig {
namespace ratstats {
namespace utils {

class RStatsWorkbook 
{
public:
	//! Constructor for RStatsWorkbook
	/*!
		Detailed description for RStatsWorkbook
	*/
	RStatsWorkbook();

    /**
     * @brief save
     * @param filePath
     */
    void save(const std::string& filePath);

    /**
     * @brief load
     * @param filePath
     */
    void load(const std::string& filePath);

    /**
     * @brief addWorksheet
     * @param sheet
     */
    void addWorksheet(const RStatsWorksheet& sheet);

    /**
     * @brief createWorksheet
     * @param name
     * @return
     */
    RStatsWorksheet &createWorksheet(const std::string& name);

    /**
     * @brief removeWorksheet
     * @param index
     */
    const std::vector<RStatsWorksheet> &getWorksheets() const;

    /**
     * @brief removeWorksheet
     * @param index
     */
    void removeWorksheet(size_t index);

    /**
     * @brief getNumWorksheets
     * @return
     */
    size_t getNumWorksheets() const;

    /**
     * @brief operator ()
     * @param index
     * @return
     */
    RStatsWorksheet& operator()(size_t index);

    /**
     * @brief operator ()
     * @param index
     * @return
     */
    const RStatsWorksheet& operator()(size_t index) const;

    /**
     * @brief getWorksheetNames
     * @return
     */
    std::vector<std::string> getWorksheetNames() const;

    /**
     * @brief clear
     */
    void clear();

	//! Destructor
	~RStatsWorkbook();	

private:
    std::vector<RStatsWorksheet> m_worksheets;
};
}}}//end namespace

