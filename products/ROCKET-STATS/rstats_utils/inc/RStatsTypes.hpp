#include "RStatsObjectList.hpp"

#pragma once

namespace cbtek {
namespace rocketstats {
namespace utils {
/**
  *@brief Provides typedef for commonly used types in ROCKET-STATS
  */
/**/
/**/    typedef cbtek::rocketstats::utils::float64_t RStatsFloat;
/**/    typedef std::int64_t RStatsInteger;
/**/    typedef cbtek::rocketstats::utils::RStatsObjectList<RStatsFloat> RStatsFloatList;
/**/    typedef cbtek::rocketstats::utils::RStatsObjectList<RStatsInteger> RStatsIntegerList;
/**/

/**
 * @brief The RStatsCalculationType enumeration provides states
 * for adding, multipling, subtracting and dividing.
 */
enum class RStatsCalculationType
{
    Subtract,
    Multiply,
    Add,
    Divide
};


/**
 * @brief The RStatsDataFormatType enumeration provides types to
 * represent the data formats used by the SVA and UVA modules
 */
enum class RStatsDataFormatType
{
    Examine,
    Audit,
    Difference,
    ExamineAndAudit,
    ExamineAndDifference,
    AuditAndDifference
};

/**
 * @brief The RStatsDataFormatTypeIndex struct
 */
struct RStatsDataFormatTypeIndex
{
    RStatsDataFormatType type;
    size_t primaryDatasetColumnIndex;
    size_t secondaryDatasetColumnIndex;
};

/**
 * @brief The RStatsConditionalOperatorType enum
 */
enum class RStatsConditionalOperatorType
{
    Equal,
    NotEqual,
    LessThan,
    LessThanOrEqualTo,
    GreaterThan,
    GreaterThanOrEqualTo
};
}}}//namespace
