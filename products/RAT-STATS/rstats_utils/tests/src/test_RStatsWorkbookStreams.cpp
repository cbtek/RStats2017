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

TEST_CASE("Testing RStatsCSVWorkbookStream","[oig::ratstats::utils::streams::RStatsCSVWorkbookStream")
{
    std::string tempFolder = FileUtils::buildFilePath(SystemUtils::getUserTempDirectory(),".rstats_unit_tests");
    std::string tempFile = FileUtils::buildFilePath(tempFolder,"test.csv");
    FileUtils::createDirectory(tempFolder);
    RStatsWorkbookStreamPtr stream = RStatsWorkbookStreamFactory::create(tempFile);

    RStatsWorkbook bookOut,bookIn;
    RStatsWorksheet sheetOut,sheetIn;

    sheetOut("A1") = "x";
    sheetOut("B1") = "y";
    sheetOut("C1") = "z";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "x");
    REQUIRE(sheetIn("B1").text == "y");
    REQUIRE(sheetIn("C1").text == "z");
    bookOut.clear();

    sheetOut("A1") = "";
    sheetOut("B1") = "";
    sheetOut("C1") = "";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "");
    REQUIRE(sheetIn("B1").text == "");
    REQUIRE(sheetIn("C1").text == "");
    bookOut.clear();

    sheetOut("A1") = "1";
    sheetOut("B1") = "2";
    sheetOut("C1") = "3";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "1");
    REQUIRE(sheetIn("B1").text == "2");
    REQUIRE(sheetIn("C1").text == "3");
    bookOut.clear();

    sheetOut("A1") = "\"1\"";
    sheetOut("B1") = "\"2\"";
    sheetOut("C1") = "\"3\"";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "\"1\"");
    REQUIRE(sheetIn("B1").text == "\"2\"");
    REQUIRE(sheetIn("C1").text == "\"3\"");
    bookOut.clear();

    sheetOut("A1") = "\"1\"";
    sheetOut("B1") = "2";
    sheetOut("C1") = "\"3\"";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "\"1\"");
    REQUIRE(sheetIn("B1").text == "2");
    REQUIRE(sheetIn("C1").text == "\"3\"");
    bookOut.clear();

    sheetOut("A1") = "\"1,2 and 3\"";
    sheetOut("B1") = "\"4,5 and 6\"";
    sheetOut("C1") = "\"Hello\", \"World\"";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "\"1,2 and 3\"");
    REQUIRE(sheetIn("B1").text == "\"4,5 and 6\"");
    REQUIRE(sheetIn("C1").text == "\"Hello\", \"World\"");
    bookOut.clear();
    FileUtils::deleteFile(tempFile);
    FileUtils::deleteFolder(tempFolder);
}


TEST_CASE("Testing RStatsDIFWorkbookStream","[oig::ratstats::utils::streams::RStatsDIFWorkbookStream")
{
    std::string tempFolder = FileUtils::buildFilePath(SystemUtils::getUserTempDirectory(),".rstats_unit_tests");
    std::string tempFile = FileUtils::buildFilePath(tempFolder,"test.dif");
    FileUtils::createDirectory(tempFolder);
    RStatsWorkbookStreamPtr stream = RStatsWorkbookStreamFactory::create(tempFile);

    RStatsWorkbook bookOut,bookIn;
    RStatsWorksheet sheetOut,sheetIn;

    sheetOut("A1") = "x";
    sheetOut("B1") = "y";
    sheetOut("C1") = "z";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "x");
    REQUIRE(sheetIn("B1").text == "y");
    REQUIRE(sheetIn("C1").text == "z");
    bookOut.clear();

    sheetOut("A1") = "";
    sheetOut("B1") = "";
    sheetOut("C1") = "";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "");
    REQUIRE(sheetIn("B1").text == "");
    REQUIRE(sheetIn("C1").text == "");
    bookOut.clear();

    sheetOut("A1") = "1";
    sheetOut("B1") = "2";
    sheetOut("C1") = "3";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "1");
    REQUIRE(sheetIn("B1").text == "2");
    REQUIRE(sheetIn("C1").text == "3");
    bookOut.clear();

    sheetOut("A1") = "\"1\"";
    sheetOut("B1") = "\"2\"";
    sheetOut("C1") = "\"3\"";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "\"1\"");
    REQUIRE(sheetIn("B1").text == "\"2\"");
    REQUIRE(sheetIn("C1").text == "\"3\"");
    bookOut.clear();

    sheetOut("A1") = "\"1\"";
    sheetOut("B1") = "2";
    sheetOut("C1") = "\"3\"";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "\"1\"");
    REQUIRE(sheetIn("B1").text == "2");
    REQUIRE(sheetIn("C1").text == "\"3\"");
    bookOut.clear();

    sheetOut("A1") = "\"1,2 and 3\"";
    sheetOut("B1") = "\"4,5 and 6\"";
    sheetOut("C1") = "\"Hello\", \"World\"";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 1);
    REQUIRE(sheetIn("A1").text == "\"1,2 and 3\"");
    REQUIRE(sheetIn("B1").text == "\"4,5 and 6\"");
    REQUIRE(sheetIn("C1").text == "\"Hello\", \"World\"");
    bookOut.clear();
    FileUtils::deleteFile(tempFile);
    FileUtils::deleteFolder(tempFolder);
}
