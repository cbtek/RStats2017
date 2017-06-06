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
using namespace cbtek::rocketstats::utils;

static const std::string dataFolder = "testData/rstats_utils/";

TEST_CASE("Testing RStatsDelimitedWorkbookStream","[cbtek::rocketstats::utils::streams::RStatsDelimitedWorkbookStream")
{
    std::string tempFolder = FileUtils::buildFilePath(SystemUtils::getUserTempDirectory(),".rstats_unit_tests");
    std::string tempFile = FileUtils::buildFilePath(tempFolder,"test.dat");
    FileUtils::createDirectory(tempFolder);
    RStatsWorkbookStreamPtr stream = RStatsWorkbookStreamFactory::create(tempFile);

    RStatsWorkbook bookOut,bookIn;
    RStatsWorksheet sheetOut,sheetIn;

    FileUtils::deleteFile(tempFile);
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

//    FileUtils::deleteFile(tempFile);
//    sheetOut("A1") = "";
//    sheetOut("B1") = "";
//    sheetOut("C1") = "";
//    bookOut.addWorksheet(sheetOut);
//    stream->write(bookOut);
//    bookIn = stream->read();
//    REQUIRE(bookIn.getNumWorksheets() == 1);
//    sheetIn = bookIn(0);
//    REQUIRE(sheetIn.getNumColumns() == 3);
//    REQUIRE(sheetIn.getNumRows() == 1);
//    REQUIRE(sheetIn("A1").text == "");
//    REQUIRE(sheetIn("B1").text == "");
//    REQUIRE(sheetIn("C1").text == "");
    bookOut.clear();

    FileUtils::deleteFile(tempFile);
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

    FileUtils::deleteFile(tempFile);
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

    FileUtils::deleteFile(tempFile);
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

    FileUtils::deleteFile(tempFile);
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
    sheetOut("A1") = "Sample Number";
    sheetOut("A2") = "1";
    sheetOut("A3") = "2";
    sheetOut("A4") = "3";
    sheetOut("B1") = "Examined Values";
    sheetOut("B2") = StringUtils::toString(963.09,2);
    sheetOut("B3") = StringUtils::toString(667.45,2);
    sheetOut("B4") = " 7,193.89 ";
    sheetOut("C1") = "Difference Values";
    sheetOut("C2") = " (10,000.0)";
    sheetOut("C3") = StringUtils::toString(0.23,2);
    sheetOut("C4") = " 333,400.10 ";


    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 4);

    REQUIRE(sheetIn("A1").text == "Sample Number");
    REQUIRE(sheetIn("A2").text == "1");
    REQUIRE(sheetIn("A3").text == "2");
    REQUIRE(sheetIn("A4").text == "3");
    REQUIRE(sheetIn("B1").text == "Examined Values");
    REQUIRE(sheetIn("B2").text == "963.09");
    REQUIRE(sheetIn("B3").text == "667.45");
    REQUIRE(sheetIn("B4").text == "7193.89");
    REQUIRE(sheetIn("C1").text == "Difference Values");
    REQUIRE(sheetIn("C2").text == "10000.0");
    REQUIRE(sheetIn("C3").text == "0.23");
    REQUIRE(sheetIn("C4").text == "333400.10");

    bookOut.clear();

    FileUtils::deleteFile(tempFile);
    FileUtils::deleteFolder(tempFolder);
}

TEST_CASE("Testing RStatsCSVWorkbookStream","[cbtek::rocketstats::utils::streams::RStatsCSVWorkbookStream")
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

    sheetOut("A1") = "Sample Number";
    sheetOut("A2") = "1";
    sheetOut("A3") = "2";
    sheetOut("A4") = "3";
    sheetOut("B1") = "Examined Values";
    sheetOut("B2") = StringUtils::toString(963.09,2);
    sheetOut("B3") = StringUtils::toString(667.45,2);
    sheetOut("B4") = " 7,193.89 ";
    sheetOut("C1") = "Difference Values";
    sheetOut("C2") = " (10,000.0)";
    sheetOut("C3") = StringUtils::toString(0.23,2);
    sheetOut("C4") = " 333,400.10 ";

    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 4);

    REQUIRE(sheetIn("A1").text == "Sample Number");
    REQUIRE(sheetIn("A2").text == "1");
    REQUIRE(sheetIn("A3").text == "2");
    REQUIRE(sheetIn("A4").text == "3");
    REQUIRE(sheetIn("B1").text == "Examined Values");
    REQUIRE(sheetIn("B2").text == "963.09");
    REQUIRE(sheetIn("B3").text == "667.45");
    REQUIRE(sheetIn("B4").text == "7193.89");
    REQUIRE(sheetIn("C1").text == "Difference Values");
    REQUIRE(sheetIn("C2").text == "10000.0");
    REQUIRE(sheetIn("C3").text == "0.23");
    REQUIRE(sheetIn("C4").text == "333400.10");

    bookOut.clear();

    FileUtils::deleteFile(tempFile);
    FileUtils::deleteFolder(tempFolder);
}


TEST_CASE("Testing RStatsDIFWorkbookStream","[cbtek::rocketstats::utils::streams::RStatsDIFWorkbookStream")
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

TEST_CASE("Testing RStatsXLSXWorkbookStream","[cbtek::rocketstats::utils::streams::RStatsXLSXWorkbookStream")
{
    std::string tempFolder = FileUtils::buildFilePath(SystemUtils::getUserTempDirectory(),".rstats_unit_tests");
    std::string tempFile = FileUtils::buildFilePath(tempFolder,"test.xlsx");
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

    sheetOut("A1") = "1.09223";
    sheetOut("B1") = "0.000013";
    sheetOut("C1") = "88.99";
    sheetOut("A2") = "3.0123";
    sheetOut("B2") = "4.002013";
    sheetOut("C2") = "58.99";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 2);
    REQUIRE(sheetIn("A1").text == "1.09223");
    REQUIRE(sheetIn("B1").text == "0.000013");
    REQUIRE(sheetIn("C1").text == "88.99");
    REQUIRE(sheetIn("A2").text == "3.0123");
    REQUIRE(sheetIn("B2").text == "4.002013");
    REQUIRE(sheetIn("C2").text == "58.99");
    bookOut.clear();

    FileUtils::deleteFile(tempFile);
    FileUtils::deleteFolder(tempFolder);
}

TEST_CASE("Testing RStatsXLSWorkbookStream","[cbtek::rocketstats::utils::streams::RStatsXLSWorkbookStream")
{
    std::string tempFolder = FileUtils::buildFilePath(SystemUtils::getUserTempDirectory(),".rstats_unit_tests");
    std::string tempFile = FileUtils::buildFilePath(tempFolder,"test.xls");
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

    sheetOut("A1") = "1.09223";
    sheetOut("B1") = "0.000013";
    sheetOut("C1") = "88.99";
    sheetOut("A2") = "3.0123";
    sheetOut("B2") = "4.002013";
    sheetOut("C2") = "58.99";
    bookOut.addWorksheet(sheetOut);
    stream->write(bookOut);
    bookIn = stream->read();
    REQUIRE(bookIn.getNumWorksheets() == 1);
    sheetIn = bookIn(0);
    REQUIRE(sheetIn.getNumColumns() == 3);
    REQUIRE(sheetIn.getNumRows() == 2);
    REQUIRE(sheetIn("A1").text == "1.09223");
    REQUIRE(sheetIn("B1").text == "0.000013");
    REQUIRE(sheetIn("C1").text == "88.99");
    REQUIRE(sheetIn("A2").text == "3.0123");
    REQUIRE(sheetIn("B2").text == "4.002013");
    REQUIRE(sheetIn("C2").text == "58.99");
    bookOut.clear();

    FileUtils::deleteFile(tempFile);
    FileUtils::deleteFolder(tempFolder);
}

