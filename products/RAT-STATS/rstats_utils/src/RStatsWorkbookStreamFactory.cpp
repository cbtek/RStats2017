/*
    RStatsStreamFactory.cpp
    

*/
//----------------------------------------
//RStatsWorkbookStreamFactory.cpp generated by CBTek Solutions on 02-01-2017 at 11:46:16 PM
//----------------------------------------

#include "RStatsWorkbookStreamFactory.h"

#include "utility/inc/FileUtils.hpp"
#include "utility/inc/Exception.hpp"

#include "streams/RStatsDelimitedWorkbookStream.h"
#include "streams/RStatsDIFWorkbookStream.h"
#include "streams/RStatsXLSXWorkbookStream.h"
#include "streams/RStatsXLSWorkbookStream.h"
#include "streams/RStatsCSVWorkbookStream.h"
#include "streams/RStatsAccessWorkbookStream.h"

using namespace cbtek::common::utility;

namespace oig {
namespace ratstats {
namespace utils {

RStatsWorkbookStreamPtr RStatsWorkbookStreamFactory::create(const std::string &filePath)
{
    std::string ext = StringUtils::toUpperTrimmed(FileUtils::getFileExtension(filePath));

    if ((ext == "XLSX") || (ext == "XLSM"))
    {
        return RStatsWorkbookStreamPtr(new streams::RStatsXLSXWorkbookStream(filePath));
    }
    else if (ext == "XLS")
    {
        return RStatsWorkbookStreamPtr(new streams::RStatsXLSWorkbookStream(filePath));
    }
    else if (ext == "CSV")
    {
        return RStatsWorkbookStreamPtr(new streams::RStatsCSVWorkbookStream(filePath));
    }
    else if (ext == "DIF")
    {
        return RStatsWorkbookStreamPtr(new streams::RStatsDIFWorkbookStream(filePath));
    }
    else if (ext == "TXT" || ext == "DAT")
    {
        return RStatsWorkbookStreamPtr(new streams::RStatsDelimitedWorkbookStream(filePath));
    }
    else if (ext == "MDB")
    {
        THROW_GENERIC_EXCEPTION("MDB not supported yet")
    }
    else if (ext == "AACDB")
    {
        THROW_GENERIC_EXCEPTION("AACDB not supported yet")
    }
    THROW_GENERIC_EXCEPTION("Invalid type type detected at \""+filePath+"\"")
}



}}}//end namespace


