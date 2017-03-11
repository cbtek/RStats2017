/*
    RStatsDataFileParser.h
    

*/

#ifndef _OIG_RATSTATS_UTILS_RSTATSDATAFILEPARSER_H
#define _OIG_RATSTATS_UTILS_RSTATSDATAFILEPARSER_H

#include "RStatsWorksheet.h"

namespace oig {
namespace ratstats {
namespace utils {


class RStatsDataFileParser 
{
public:
	//! Constructor for RStatsDataFileParser
	/*!
		Detailed description for RStatsDataFileParser
	*/
    RStatsDataFileParser(const std::string& filePath);

    void load();

    void write(const RStatsWorksheet& sheet);

	//! Destructor
	~RStatsDataFileParser();	

private:
    std::string m_filePath;

    std::vector<std::string> splitLine(const std::string& line);
};
}}}//end namespace

#endif // _OIG_RATSTATS_UTILS_RSTATSDATAFILEPARSER_H

