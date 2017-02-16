#include "RStatsUVA.h"

using namespace oig::ratstats::modules::uva;
using namespace oig::ratstats::utils;

int main(int argc, char ** argv)
{
   RStatsFloatList values(4);
   values(0) = 44;
   values(1) = 22;
   values(2) = 33;
   values(3) = 44;
    RStatsUVA::inst().execute(values,4,4,oig::ratstats::utils::RStatsDataFormatType::Examine);
	return 0;
}

