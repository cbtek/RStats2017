/*
    RStatsWorkbookStreamFactory.h
*/

#pragma once

#include "rstats_utils/inc/RStatsWorkbookStream.hpp"

namespace oig {
namespace ratstats {
namespace utils {

/**
 * @brief The RStatsWorkbookStreamFactory static class provides
 * a method for instantiating workbook streams for reading/writing.
 * The extension on the filePath is used to determine which workbook
 * stream implementation to use.
 *
 */
class RStatsWorkbookStreamFactory
{
public:
    /**
     * @brief create Creates a initialization of a workbook stream object
     * @param filePath The path to file for reading/writing from/to
     * @return Return a shared pointer instance of a workbook stream object
     */
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


