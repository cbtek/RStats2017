/*
    RStatsWorksheet.h
    

*/

#ifndef _OIG_RATSTATS_UTILS_RSTATSWORKSHEET_H
#define _OIG_RATSTATS_UTILS_RSTATSWORKSHEET_H

#include <string>
#include <map>

#include "utility/inc/Color.h"
#include "utility/inc/Font.h"
#include "utility/inc/ColorFactory.h"
#include "RStatsUtils.hpp"
#include "utility/inc/StringUtils.hpp"

namespace oig {
namespace ratstats {
namespace utils {

enum class RStatsTextAlignment
{
    AlignLeft,
    AlignMiddle,
    AlignRight
};
class RStatsWorksheet;
struct RStatsCell
{
    static RStatsTextAlignment ms_DefaultAlignment;
    static cbtek::common::utility::Color ms_DefaultBGColor;
    static cbtek::common::utility::Color ms_DefaultFGColor;
    static cbtek::common::utility::Font ms_DefaultFont;
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
        this->text = cbtek::common::utility::StringUtils::toString(number,
                                                                   ms_DefaultFloatingPointDecimals);
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
     * @brief getCells
     * @return
     */
    const std::map<std::pair<size_t, size_t>, RStatsCell> &getCells() const;

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


    std::string toCommaDelimitedString() const;

    std::string toTabDelimitedString() const;
    //! Destructor
	~RStatsWorksheet();	

private:
        RStatsCell m_emptyCell;
        std::string m_worksheetTitle;
        std::map<std::pair<size_t,size_t>, RStatsCell> m_dataTable;
        size_t m_numRows;
        size_t m_numColumns;
        void parseCellAddress(const std::string& address, size_t& r, size_t& c);
        std::string toString(const std::string& prefix,const std::string& seperator, const std::string& postfix) const;

};
typedef std::shared_ptr<RStatsWorksheet> RStatsWorksheetPtr;
}}}//end namespace

#endif // _OIG_RATSTATS_UTILS_RSTATSWORKSHEET_H

