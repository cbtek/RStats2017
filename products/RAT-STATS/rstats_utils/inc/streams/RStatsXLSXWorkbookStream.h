/*
    RStatsXLSXWorkbookStream.h
    

*/

#pragma once
#include "rstats_utils/inc/RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {
namespace streams {

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
    struct XLSXWorksheetDefinition
    {
        std::string sheetName;
        std::string id;
        std::string sheetFile;
    };

    std::map<std::string, XLSXWorksheetDefinition> getWorksheetDefinitions(const std::string &workbookFilePath, const std::string &workbookRelationshipFilePath) const;
    std::map<size_t, std::string> getSharedStrings(const std::string& sharedStringsFilePath) const;
    std::string m_filePath;
};
}}}}//end namespace


