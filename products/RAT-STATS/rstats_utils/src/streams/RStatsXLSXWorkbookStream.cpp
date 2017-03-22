/*
    RStatsXLSXWorkbookStream.cpp
    

*/
//----------------------------------------
//RStatsXLSXWorkbookStream.cpp generated by CBTek Solutions on 02-01-2017 at 11:54:04 PM
//----------------------------------------
#include "RStatsXLSXWorkbookStream.h"

#include "RStatsWorksheet.h"
#include "utility/inc/DateTimeUtils.hpp"
#include "utility/inc/SystemUtils.hpp"
#include "utility/inc/XMLReader.h"
#include "rstats_utils/inc/RStatsUtils.hpp"

using namespace oig::ratstats::utils;
using namespace cbtek::common::utility;

namespace oig {
namespace ratstats {
namespace utils {
namespace streams {

static int s_SHEET_COUNT = 1;

RStatsXLSXWorkbookStream::RStatsXLSXWorkbookStream(const std::string &filePath)
{
    m_filePath = filePath;
}

void RStatsXLSXWorkbookStream::write(const RStatsWorkbook &workbook)
{
    THROW_GENERIC_EXCEPTION("The XLSX writing feature has not been added")
}

RStatsWorkbook RStatsXLSXWorkbookStream::read()
{
    RStatsWorkbook workbook;
    std::string outputPath = SystemUtils::getUserTempDirectory();
    outputPath = FileUtils::buildFilePath(outputPath,".gov.oig.ratstats.xlsxstream.extract_"+DateTimeUtils::getTimeStamp());
    std::string unzipPath = RStatsUtils::getUnzipCommandPath();
    std::ostringstream args;
    FileUtils::createDirectory(outputPath);
    if (FileUtils::isDirectoryWritable(outputPath))
    {
        args << " -o -q -d \""<<outputPath<<"\" \""<<m_filePath<<"\"";
        SystemUtils::execute(unzipPath+args.str());
    }
    std::string worksheetsPath = FileUtils::buildFilePath(outputPath,"xl/worksheets");
    std::string workbookPath = FileUtils::buildFilePath(outputPath,"xl/workbook.xml");
    std::string workbookRelationshipPath = FileUtils::buildFilePath(outputPath,"xl/_rels/workbook.xml.rels");
    std::string sharedStringsPath = FileUtils::buildFilePath(outputPath,"xl/sharedStrings.xml");

    std::map<std::string,RStatsXLSXWorkbookStream::XLSXWorksheetDefinition> sheetDefs = getWorksheetDefinitions(workbookPath,workbookRelationshipPath);
    std::map<size_t, std::string> sharedStringsMap = getSharedStrings(sharedStringsPath);
    std::vector<std::string> sheetFileList = FileUtils::getFileEntries(worksheetsPath,"xml");
    for (const std::string& sheetFile : sheetFileList)
    {
        RStatsWorksheet sheet;
        XMLReader reader;
        reader.load(sheetFile);
        std::string sheetFileKey = StringUtils::toUpperTrimmed(FileUtils::getFileName(sheetFile));
        XLSXWorksheetDefinition def = sheetDefs[sheetFileKey];
        if (StringUtils::isEmpty(def.sheetName))
        {
            def.sheetName = "Sheet"+std::to_string(s_SHEET_COUNT);
            s_SHEET_COUNT++;
        }
        sheet.setWorksheetTitle(def.sheetName);
        XMLDataElement * sheetXML = reader.getElement("worksheet");
        if (sheetXML)
        {
            XMLDataElement * sheetDataXML = sheetXML->getChild("sheetData");
            if (sheetDataXML)
            {
                for (size_t a1 = 0; a1 < sheetDataXML->getNumChildren();++a1)
                {
                    XMLDataElement * rowDataXML = sheetDataXML->getChildAt(a1);
                    if (rowDataXML)
                    {
                        for (size_t a2 = 0; a2 < rowDataXML->getNumChildren();++a2)
                        {
                            XMLDataElement* columnDataXML = rowDataXML->getChildAt(a2);
                            if (columnDataXML)
                            {
                                bool isSharedString = (StringUtils::equals(columnDataXML->getAttributeValue("t"),"s"));
                                std::string cellLabel = columnDataXML->getAttributeValue("r");
                                auto index = RStatsUtils::getCellIndexFromAddress(cellLabel);
                                XMLDataElement * cellDataXML = columnDataXML->getChild("v");
                                if (cellDataXML)
                                {
                                    if (isSharedString)
                                    {
                                        size_t sharedStringIndex = StringUtils::toUInt(cellDataXML->getElementData());
                                        sheet(index.first,index.second) = sharedStringsMap[sharedStringIndex];
                                    }
                                    else
                                    {
                                        sheet(index.first,index.second) = cellDataXML->getElementData();
                                    }
                                }
                            }
                        }
                    }
                }
            }
            workbook.addWorksheet(sheet);
        }
    }
    FileUtils::deleteFolder(outputPath);
    return workbook;
}

RStatsXLSXWorkbookStream::~RStatsXLSXWorkbookStream()
{

}

std::map<std::string, RStatsXLSXWorkbookStream::XLSXWorksheetDefinition> RStatsXLSXWorkbookStream::getWorksheetDefinitions(const std::string& workbookFilePath,
                                                                                                                           const std::string& workbookRelationshipFilePath) const
{
    std::map<std::string, RStatsXLSXWorkbookStream::XLSXWorksheetDefinition> defintionMap;
    std::map<std::string,std::string> ridSheetNameMap;
    if (FileUtils::fileExists(workbookRelationshipFilePath))
    {
        XMLReader reader;
        reader.load(workbookRelationshipFilePath);
        XMLDataElement* workbookRelationshipXML = reader.getElement("Relationships");
        if (workbookRelationshipXML)
        {
            for (size_t a1 = 0; a1 <  workbookRelationshipXML->getNumChildren();++a1)
            {
                XMLDataElement* sheetDefXML = workbookRelationshipXML->getChildAt(a1);
                if (sheetDefXML)
                {
                    std::string type = sheetDefXML->getAttributeValue("Type");
                    if (StringUtils::contains(type,"worksheet",false))
                    {
                        XLSXWorksheetDefinition def;

                        def.sheetFile = sheetDefXML->getAttributeValue("Target");
                        def.sheetFile = FileUtils::getFileName(def.sheetFile);
                        def.id = StringUtils::toUpperTrimmed(sheetDefXML->getAttributeValue("id"));
                        ridSheetNameMap[def.id]=def.sheetFile;
                        defintionMap[StringUtils::toUpperTrimmed(def.sheetFile)] = def;
                    }
                }
            }
        }
    }

    if (FileUtils::fileExists(workbookFilePath))
    {
        XMLReader reader;
        reader.load(workbookFilePath);
        XMLDataElement* workbookXML = reader.getElement("workbook");
        if (workbookXML)
        {
            XMLDataElement* sheetsXML = workbookXML->getChild("sheets");
            if (sheetsXML)
            {
                for (size_t a1 = 0; a1 < sheetsXML->getNumChildren();++a1)
                {
                    XMLDataElement* sheetXML = sheetsXML->getChildAt(a1);
                    if (sheetXML)
                    {
                        std::string name = sheetXML->getAttributeValue("name");
                        std::string rid = sheetXML->getAttributeValue("r:id");
                        std::string sheetFile = StringUtils::toUpperTrimmed(ridSheetNameMap[StringUtils::toUpperTrimmed(rid)]);
                        if (defintionMap.count(sheetFile))
                        {
                           defintionMap[sheetFile].sheetName = name;
                        }
                    }
                }
            }
        }
    }
    return defintionMap;
}

std::map<size_t, std::string> RStatsXLSXWorkbookStream::getSharedStrings(const std::string &sharedStringsFilePath) const
{
    std::map<size_t, std::string> sharedStringsMap;
    if (FileUtils::fileExists(sharedStringsFilePath))
    {
        XMLReader reader;
        reader.load(sharedStringsFilePath);
        XMLDataElement* sstXML = reader.getElement("sst");
        if (sstXML)
        {
            for (size_t a1 = 0; a1 <  sstXML->getNumChildren();++a1)
            {
                XMLDataElement* siXML = sstXML->getChildAt(a1);
                if (siXML)
                {
                    XMLDataElement* tXML = siXML->getChild("t");
                    if (tXML)
                    {
                        sharedStringsMap[a1] = tXML->getElementData();
                    }
                }
            }
        }
    }
    return sharedStringsMap;
}
}}}}//end namespace


