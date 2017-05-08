/*
    RStatsWorkbook.h
    

*/

#pragma once

#include "RStatsWorksheet.h"

#include <vector>

namespace oig {
namespace ratstats {
namespace utils {

enum class RStatsWorkbookMergeDirection
{
    MergeBottom,
    MergeRight
};

/**
 * @brief The RStatsWorkbook class represents a simple container
 * for multiple worksheet objects
 */
class RStatsWorkbook 
{
public:

    /**
     * @brief RStatsWorkbook (Constructor)
     */
	RStatsWorkbook();

    /**
     * @brief insertWorksheet Inserts a worksheet at any position
     * within worksheet array.
     * @param sheet The worksheet to insert
     * @param index The index to insert the worksheet at
     */
    void insertWorksheet(const RStatsWorksheet &sheet, size_t index);

    /**
     * @brief save Saves the workbook to file.  This function will
     * call the RStatsWorkbookStreamFactory to determine how the file
     * should be saved.
     * @param filePath Path to file to save
     */
    void save(const std::string& filePath);

    /**
     * @brief load Loads a workbook from file. This function will call
     * the RStatsWorkbookStreamFactory to determine how the file
     * should be loaded.
     * @param filePath Path to file to load
     */
    void load(const std::string& filePath);

    /**
     * @brief addWorksheet Appends worksheet to end of worksheet array
     * @param sheet Worksheet object to add
     */
    void addWorksheet(const RStatsWorksheet& sheet);

    /**
     * @brief createWorksheet Creates an empty worksheet object and
     * returns a reference to it.
     * @param name The name of the worksheet
     * @return Returns reference of worksheet created
     */
    RStatsWorksheet &createWorksheet(const std::string& name);

    /**
     * @brief getWorksheets Returns reference vector of worksheets
     * @return
     */
    const std::vector<RStatsWorksheet> &getWorksheets() const;

    /**
     * @brief removeWorksheet Deletes worksheet from workbook
     * @param index Index of worksheet to delete
     */
    void removeWorksheet(size_t index);

    /**
     * @brief getNumWorksheets Gets the number of worksheets
     * @return Return size_t of worksheet count
     */
    size_t getNumWorksheets() const;

    /**
     * @brief operator () Overloaded operator to ease accessing worksheet.
     * @param index Index of worksheet to access
     * @return This function returns reference to worksheet object.
     * @throws GenericException if index is out of range
     */
    RStatsWorksheet& operator()(size_t index);

    /**
     * @brief operator () Overloaded operator to ease accessing worksheet.
     * @param index Index of worksheet to access
     * @return This function returns a const reference to worksheet object.
     * @throws GenericException if index is out of range
     */
    const RStatsWorksheet& operator()(size_t index) const;

    /**
     * @brief getWorksheetNames Get list of all worksheet names
     * @return Return vector containing strings of worksheet names
     */
    std::vector<std::string> getWorksheetNames() const;

    /**
     * @brief mergeSheets This function merges all the sheets in
     * the workbooks into a single sheet.  This is useful for outputing
     * to formats that only support a single sheet.
     * @param direction The direction in which to merge the sheets
     * @param padding Determines how many extra rows/columns of padding
     * to add between each merged sheet in the final output
     * @return Returns merged worksheet object of all sheets in workbook
     */
    RStatsWorksheet mergeSheets(RStatsWorkbookMergeDirection direction = RStatsWorkbookMergeDirection::MergeBottom, size_t padding = 1);

    /**
     * @brief clear Clears all worksheets
     */
    void clear();

	//! Destructor
	~RStatsWorkbook();	

private:
    std::vector<RStatsWorksheet> m_worksheets;
};
}}}//end namespace

