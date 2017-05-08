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

/**
 * @brief The RStatsDIFParseStates enum List of DIF parse states
 */
enum class RStatsDIFParseStates
{
    Start,
    ReadColumnCount,
    ReadRowCount,
    ReadDummyData,
    ReadRowData,
    ReadStringData,
    End
};


/**
 * @brief The RStatsDIFWorkbookStream class provides support for
 * reading from and writing to the data interchange format. 
 */
class RStatsDIFWorkbookStream : public RStatsWorkbookStream
{
public:

    /**
     * @brief RStatsDIFWorkbookStream (Constructor)
     * @param filePath The path for reading/writing
     */
    RStatsDIFWorkbookStream(const std::string& filePath);  
    
    /**
     * @brief write Writes a workbook object to DIF at m_filePath
     * NOTE: For a multisheet workbook, only the first sheet is written
     * @param workbook The workbook to write
     * @throws GenericException if file could not be written to
     *
     */
    virtual void write(const RStatsWorkbook& workbook);

    /**
     * @brief read Reads a DIF file at m_filePath into
     * a workbook object
     * @return Returs workbook object of parsed DIF file
     * @throws GenericException if file could not be read from
     */
    virtual RStatsWorkbook read();

	//! Destructor
    ~RStatsDIFWorkbookStream();

private:

    /**
     * @brief writeHeader
     * @param sheet The worksheet to write
     * @param out Thesstream to write to
     */
    void writeHeader(const RStatsWorksheet& sheet,
                     std::ostream& out);

    /**
     * @brief writeCell Writes DIF cell object
     * @param cell The worksheet cell to write
     * @param out The stream to write to
     */
    void writeCell(const RStatsCell& cell,
                   std::ostream& out);

    /**
     * @brief m_filePath The file to read/write
     */
    std::string m_filePath;
    
};
}}}}//end namespace
