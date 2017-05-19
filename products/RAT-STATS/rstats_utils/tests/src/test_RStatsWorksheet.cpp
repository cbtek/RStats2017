/**
MIT License

Copyright (c) 2016 cbtek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include "utility/inc/StringUtils.hpp"
#include "utility/inc/SystemUtils.hpp"
#include "utility/inc/FileUtils.hpp"
#include "contrib/catch/catch.hpp"

#include "rstats_utils/inc/RStatsWorkbookStreamFactory.h"

using namespace cbtek::common::utility;
using namespace oig::ratstats::utils;

static const std::string dataFolder = "testData/rstats_utils/";

TEST_CASE("Testing RStatsWorksheet remove empty row/column functions","[oig::ratstats::utils::RStatsWorksheet")
{
    RStatsWorksheet sheet;
    sheet("A1") = "a1";
    sheet("B1") = "b1";
    sheet("C1") = "c1";
    sheet("D1") = "";
    sheet("E1") = "e1";

    sheet("A2") = "a2";
    sheet("B2") = "b2";
    sheet("C2") = "c2";
    sheet("D2") = "";
    sheet("E2") = "e2";

    sheet("A3") = "a3";
    sheet("B3") = "b3";
    sheet("C3") = "c3";
    sheet("D3") = "";
    sheet("E3") = "e3";

    sheet("A4") = "";
    sheet("B4") = "";
    sheet("C4") = "";
    sheet("D4") = "";
    sheet("E4") = "";

    sheet("A5") = "a5";
    sheet("B5") = "b5";
    sheet("C5") = "c5";
    sheet("D5") = "";
    sheet("E5") = "e5";
    sheet.removeEmptyRows();
    REQUIRE(sheet.getNumRows() == 4);
    REQUIRE(sheet("A4").text == "a5");
    REQUIRE(sheet("B4").text == "b5");
    REQUIRE(sheet("C4").text == "c5");
    REQUIRE(sheet("D4").text == "");
    REQUIRE(sheet("E4").text == "e5");

    std::cerr << "before============================="<<std::endl;
    std::cerr << sheet.toCommaDelimitedString() << std::endl;
    sheet.removeEmptyColumns();
    std::cerr << "after============================="<<std::endl;
    std::cerr << sheet.toCommaDelimitedString() << std::endl;
    REQUIRE(sheet.getNumColumns() == 4);
    REQUIRE(sheet("D1").text == "e1");
    REQUIRE(sheet("D2").text == "e2");
    REQUIRE(sheet("D3").text == "e3");
    REQUIRE(sheet("D4").text == "e5");
}


TEST_CASE("Testing RStatsWorksheet remove row/column functions","[oig::ratstats::utils::RStatsWorksheet")
{
    RStatsWorksheet sheet;
    sheet("A1") = "a1";
    sheet("B1") = "b1";
    sheet("C1") = "c1";
    sheet("D1") = "";
    sheet("E1") = "e1";

    sheet("A2") = "a2";
    sheet("B2") = "b2";
    sheet("C2") = "c2";
    sheet("D2") = "";
    sheet("E2") = "e2";

    sheet("A3") = "a3";
    sheet("B3") = "b3";
    sheet("C3") = "c3";
    sheet("D3") = "";
    sheet("E3") = "e3";

    sheet("A4") = "";
    sheet("B4") = "";
    sheet("C4") = "";
    sheet("D4") = "";
    sheet("E4") = "e4";

    sheet("A5") = "a5";
    sheet("B5") = "b5";
    sheet("C5") = "c5";
    sheet("D5") = "d5";
    sheet("E5") = "e5";

    sheet.removeRow(3);
    REQUIRE(sheet("A4").text == "a5");
    REQUIRE(sheet("B4").text == "b5");
    REQUIRE(sheet("C4").text == "c5");
    REQUIRE(sheet("D4").text == "d5");
    REQUIRE(sheet("E5").text == "");

    sheet.removeColumn(3);
    REQUIRE(sheet("D1").text == "e1");
    REQUIRE(sheet("D2").text == "e2");
    REQUIRE(sheet("D3").text == "e3");
    REQUIRE(sheet("D4").text == "e5");
}
