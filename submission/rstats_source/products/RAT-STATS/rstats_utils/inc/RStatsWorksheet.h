/*
    RStatsWorksheet.h
    

*/

#pragma once

#include <string>
#include <map>

#include "utility/inc/StringUtils.hpp"
#include "utility/inc/ColorUtils.h"
#include "utility/inc/FontUtils.h"
#include "RStatsUtils.hpp"

namespace oig {
namespace ratstats {
namespace utils {

enum class RStatsTextAlignment
{
    AlignLeft,
    AlignMiddle,
    AlignRight
};

enum class RStatsCellFormat
{
    ThousandsSeperator
};

class RStatsWorksheet;
struct RStatsCell
{
    static RStatsTextAlignment ms_DefaultAlignment;
    static cbtek::common::utility::Color ms_DefaultBGColor;
    static cbtek::common::utility::Color ms_DefaultFGColor;
    static cbtek::common::utility::Font ms_DefaultFont;
    static RStatsCellFormat ms_DefaultFormat;
    static size_t ms_DefaultFloatingPointDecimals;
    cbtek::common::utility::Font font;
    cbtek::common::utility::Color bgColor;
    cbtek::common::utility::Color fgColor;
    RStatsTextAlignment alignment;
    std::string text;

    void operator=(const std::string& text)
    {
        this->text = text;
    }

    void operator=(RStatsFloat number)
    {
        this->text = cbtek::common::utility::StringUtils::toString(number,                                                                   ms_DefaultFloatingPointDecimals);
    }

    void operator=(RStatsInteger number)
    {
        this->text = cbtek::common::utility::StringUtils::toString(number);
    }

    RStatsCell(const std::string& text = "")
    {
        this->text = text;
        this->bgColor = ms_DefaultBGColor;
        this->fgColor = ms_DefaultFGColor;
        this->alignment = ms_DefaultAlignment;
        this->font = ms_DefaultFont;
    }
};

struct RStatsMergeCellRange
{
    size_t startRow,startColumn;
    size_t rowOffset,columnOffset;
    bool contains(size_t row, size_t column) const
    {
        return (row >= startRow && row < (startRow + rowOffset) &&
            column >= startColumn && column < (startColumn + columnOffset));
    }
    bool operator<(const RStatsMergeCellRange& value) const
    {
        return rowOffset < value.rowOffset && columnOffset < value.columnOffset;
    }
};

typedef std::map<std::pair<size_t, size_t>, RStatsCell> RStatsCellMap;

typedef std::map<RStatsMergeCellRange, RStatsCell> RStatsMergedCellMap;

class RStatsWorksheet 
{
public:
	//! Constructor for RStatsWorksheet
	/*!
		Detailed description for RStatsWorksheet
	*/
    RStatsWorksheet(const std::string& name="NewSheet");

   /**
    * @brief Setter for m_worksheetTitle
    * @param Value to replace m_worksheetTitle
    */
    void setWorksheetTitle(const std::string & value);


   /**
    * @brief Getter for m_worksheetTitle
    * @return Return copy of m_worksheetTitle
    */
    const std::string & getWorksheetTitle() const;


    /**
     * @brief operator ()
     * @param row
     * @param column
     * @return
     */
   RStatsCell& operator()(size_t row, size_t column);


   /**
    * @brief operator ()
    * @param row
    * @param column
    * @return
    */
  const RStatsCell& operator()(size_t row, size_t column) const;

   /**
    * @brief getCell
    * @param row
    * @param column
    * @return
    */
   const RStatsCell& getCell(size_t row, size_t column) const;


    /**
     * @brief operator ()
     * @param address
     * @return
     */
    RStatsCell& operator()(const std::string& address);


    /**
     * @brief getNumRows
     * @return
     */
    size_t getNumRows() const;

    /**
     * @brief getNumColumns
     * @return
     */
    size_t getNumColumns() const;

    /**
     * @brief getLastDataRow
     * @return
     */
    std::pair<size_t, size_t> getLastDataRowAndColumn() const;

    /**
     * @brief getCells
     * @return
     */
    const RStatsCellMap &getCells() const;

    /**
     * @brief setDefaultTextAlignment
     * @param alignment
     */
    void setDefaultTextAlignment(RStatsTextAlignment alignment);

    /**
     * @brief setDefaultBGColor
     * @param bgColor
     */
    void setDefaultBGColor(const cbtek::common::utility::Color& bgColor);

    /**
     * @brief setDefaultFGColor
     * @param fgColor
     */
    void setDefaultFGColor(const cbtek::common::utility::Color& fgColor);

    /**
     * @brief setDefaultFont
     * @param font
     */
    void setDefaultFont(const cbtek::common::utility::Font& font);

    /**
     * @brief setDefaultFloatingPointDecimals
     * @param count
     */
    void setDefaultFloatingPointDecimals(size_t count);

    /**
     * @brief resetDefaults
     */
    void resetDefaults();

    std::set<RStatsCellFormat> getCellFormatSet() const;
    /**
     * @brief toCommaDelimitedString
     * @return
     */
    std::string toCommaDelimitedString() const;

    /**
     * @brief toTabDelimitedString
     * @return
     */
    std::string toTabDelimitedString() const;

    /**
     * @brief toHTMLTableString
     * @return
     */
    std::string toHTMLTableString() const;

    /**
     * @brief toCommaDelimitedString
     * @return
     */
    std::string toEvenlySpacedString() const;

    /**
     * @brief isEmpty
     * @return
     */
    bool isEmpty() const;


    /**
     * @brief findDataRowsAndColumns
     * @param rowsOut
     * @param columnsOut
     */
    void findDataRowsAndColumns(std::set<size_t>& rowsOut,
                                std::set<size_t>& columnsOut) const;

    /**
     * @brief setFormatEnabled
     * @param format
     * @param flag
     */
    void setFormatEnabled(RStatsCellFormat format,
                          bool flag);

    /**
     * @brief setThousandsSeperatorEnabled
     * @param flag
     */
    void setThousandsSeperatorEnabled(bool flag);


    /**
     * @brief setRowBackgroundColor
     * @param row
     * @param color
     */
    void setRowBackgroundColor(size_t row, const cbtek::common::utility::Color& color);


    /**
     * @brief setColumnBackgroundColor
     * @param row
     * @param color
     */
    void setColumnBackgroundColor(size_t column, const cbtek::common::utility::Color& color);


    /**
     * @brief clear
     */
    void clear();

    //! Destructor
	~RStatsWorksheet();	


    /**
     * @brief setRowBorderColor
     * @param row
     * @param color
     */
    void setRowBorderColor(size_t row, const cbtek::common::utility::Color& color);

    /**
     * @brief setColumnBorderColor
     * @param row
     * @param color
     */
    void setColumnBorderColor(size_t column, const cbtek::common::utility::Color& color);

private:

        std::set<std::pair<size_t,size_t> > m_thousandsSeperatorToggleSet;
        RStatsCell m_emptyCell;
        std::string m_worksheetTitle;
        RStatsCellMap m_dataTable;
        RStatsMergedCellMap m_mergedCellTable;
        size_t m_numRows;
        size_t m_numColumns;
        void parseCellAddress(const std::string& address, size_t& r, size_t& c);
        std::string toString(const std::string& prefix,const std::string& seperator, const std::string& postfix) const;        
        std::string toEvenlySpacedString(const std::string& prefix,const std::string& seperator, const std::string& postfix) const;

        /**
         * @brief isCellInMergedCellRange
         * @param r
         * @param c
         * @return
         */
        bool isCellInMergedCellRange(size_t r, size_t c) const;

        /**
         * @brief getCellInMergedCellRange
         * @param r
         * @param c
         * @return
         */
        RStatsCell& getCellInMergedCellRange(size_t r, size_t c);

        /**
         * @brief getMergedCellRangeThatContains
         * @param r
         * @param c
         * @param range
         * @return
         */
        bool getMergedCellRangeThatContains(size_t r, size_t c, RStatsMergeCellRange& range);

        /**
         * @brief getCellCSSStyle
         * @param cell
         * @return
         */
        std::string getCellCSSStyle(const RStatsCell& cell) const;
};
typedef std::shared_ptr<RStatsWorksheet> RStatsWorksheetPtr;
}}}//end namespace


