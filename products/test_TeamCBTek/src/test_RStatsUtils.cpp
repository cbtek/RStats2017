
#include "rstats_utils/inc/RStatsUtils.hpp"

#include "utility/inc/VBRoundUtils.hpp"
#include "utility/inc/FileUtils.hpp"

#include "contrib/catch/catch.hpp"
#include <math.h>
#include <stdbool.h>

using namespace cbtek::common::utility;
using namespace oig::ratstats::utils;

TEST_CASE("Testing RStatsUtils::isEqual","[oig::ratstats::utils::RStatsUtils]")
{
    REQUIRE (RStatsUtils::isEqual(0., 0.0000000001) == false);
    REQUIRE (RStatsUtils::isEqual(0.0000001, 0.0000000001) == false);
    REQUIRE (RStatsUtils::isEqual(0.0000000001, 0.0000000001) == true);
    REQUIRE (RStatsUtils::isEqual(0.1, 0.1001) == false);
    REQUIRE (RStatsUtils::isEqual(17000., 0.) == false);
}

TEST_CASE("Testing RStatsUtils::vbRound","[orig::ratstats::utils::RStatsUtils]")
{
    RStatsFloat value = RStatsUtils::vbRound2((1. + 2.) / 2.);
    REQUIRE(RStatsUtils::isEqual(value,1.5));
}
