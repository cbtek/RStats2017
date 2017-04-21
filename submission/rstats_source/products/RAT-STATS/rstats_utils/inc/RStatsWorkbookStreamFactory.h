/*
    RStatsWorkbookStreamFactory.h
*/

#pragma once

#include "rstats_utils/inc/RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {


class RStatsWorkbookStreamFactory
{
public:
    static RStatsWorkbookStreamPtr create(const std::string& filePath);

private:
    //! Private constructor for RStatsWorkbookStreamFactory
    RStatsWorkbookStreamFactory();

    //! Private copy constructor for RStatsWorkbookStreamFactory
    RStatsWorkbookStreamFactory(const RStatsWorkbookStreamFactory &);

    //! Private destructor for RStatsWorkbookStreamFactory
    ~RStatsWorkbookStreamFactory();
};
}}}//end namespace


