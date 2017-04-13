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
#include "utility/inc/FileUtils.hpp"
#include "contrib/catch/catch.hpp"

using namespace cbtek::common::utility;
static const std::string dataFolder = "testData/utility/";

TEST_CASE("Testing StringUtils::isNumeric","[utility::StringUtils]")
{
    std::string test1 = "1.1234";
    std::string test2 = "-100,231,334.1234";
    std::string test3 = ".";
    std::string test4 = "-";
    std::string test5 = "$-5,000.00";
    std::string test6 = "-$5,000.00";
    std::string test7 = "";

    REQUIRE(StringUtils::isNumeric(test1) == true);
    REQUIRE(StringUtils::isNumeric(test2) == true);
    REQUIRE(StringUtils::isNumeric(test3) == false);
    REQUIRE(StringUtils::isNumeric(test4) == false);
    REQUIRE(StringUtils::isNumeric(test5) == true);
    REQUIRE(StringUtils::isNumeric(test6) == true);
    REQUIRE(StringUtils::isNumeric(test7) == false);
}

TEST_CASE("Testing StringUtils::isWholeWord","[utility::StringUtils]")
{
    std::string data = "The Quick Brown $foxjumped over the $foxxy moon with a $fox and $fox_";
    std::vector<size_t> wholeWords = StringUtils::getWholeWords(data,"$fox");
    REQUIRE(wholeWords.size() == 2);
    REQUIRE(wholeWords[0] == 55);
    REQUIRE(wholeWords[1] == 64);
}

TEST_CASE("Testing StringUtils::findAllThatStartWith","[utility::StringUtils]")
{
    std::vector<std::string> test;
    test.push_back("hello");
    test.push_back("crazy");
    test.push_back("world");
    test.push_back("held");
    StringUtils::removeAllThatStartWith(test,"H",true);
    REQUIRE(test.size()==4);
    StringUtils::removeAllThatStartWith(test,"H",false);
    REQUIRE(test.size()==2);
    StringUtils::removeAllThatStartWith(test,"wo",false);
    REQUIRE(test.size()==1);
    REQUIRE(test[0] == "crazy");
}

TEST_CASE("Testing StringUtils::findAllThatContain","[utility::StringUtils]")
{
    std::vector<std::string> test;
    test.push_back("hello");
    test.push_back("crazy");
    test.push_back("world");
    test.push_back("worldly");
    StringUtils::removeAllThatContain(test,"O",true);
    REQUIRE(test.size()==4);
    StringUtils::removeAllThatContain(test,"O",false);
    REQUIRE(test.size()==1);
    StringUtils::removeAllThatContain(test,"az",false);
    REQUIRE(test.size()==0);
}

TEST_CASE("Testing StringUtils::findAllThatEndWith","[utility::StringUtils]")
{
    std::vector<std::string> test;
    test.push_back("hello");
    test.push_back("crazy");
    test.push_back("world");
    test.push_back("meld");
    StringUtils::removeAllThatEndWith(test,"O",true);
    REQUIRE(test.size()==4);
    StringUtils::removeAllThatEndWith(test,"O",false);
    REQUIRE(test.size()==3);
    StringUtils::removeAllThatEndWith(test,"ld",false);
    REQUIRE(test.size()==1);
    REQUIRE(test[0] == "crazy");
}

TEST_CASE("Testing StringUtils::eraseFromVector","[utility::StringUtils]")
{
    std::vector<std::string> test;
    test.push_back("hello");
    test.push_back("crazy");
    test.push_back("world");
    StringUtils::eraseFromVector(test,"hello2");
    REQUIRE(test.size()==3);
    StringUtils::eraseFromVector(test,"hellO",true);
    REQUIRE(test.size()==3);
    StringUtils::eraseFromVector(test,"krazy");
    REQUIRE(test.size()==3);
    StringUtils::eraseFromVector(test,"crazy");
    REQUIRE(test.size()==2);
    REQUIRE(test[0]=="hello");
    REQUIRE(test[1]=="world");

}


TEST_CASE("Testing StringUtils::removeNonAlphaNumeric","[utility::StringUtils]")
{
    std::string str = "~!@#$%^&T*()_+{}|\"{}|\\:;'\"<,>.?/-=\r\r\n\f\t~E!@#$%^&*()_+{}|\"{}|\\:;'\"<,>.?/-=\r\rS\n\fT\t";
    REQUIRE(StringUtils::removeNonAlphaNumeric(str) == "TEST");
}

TEST_CASE("Testing StringUtils::toString","[utility::StringUtils")
{
    double value1 = 122104432.23456789;
    double value2 = 1.23;    
    std::uint64_t value3 = 99123456789;
    std::uint64_t value4 = 72;    
    std::int64_t value5 = -262315;
    double value6 = -903172.0112;
    double value7 = 102234.00;

    REQUIRE(StringUtils::toString(value1,2,true) == "122,104,432.23");
    REQUIRE(StringUtils::toString(value2,1,true) == "1.2");
    REQUIRE(StringUtils::toString(value3,true) == "99,123,456,789");
    REQUIRE(StringUtils::toString(value4,true) == "72");
    REQUIRE(StringUtils::toString(value5,true) == "-262,315");
    REQUIRE(StringUtils::toString(value6,2,true) == "-903,172.01");
    REQUIRE(StringUtils::toString(value7,2,true) == "102,234.00");

    REQUIRE(StringUtils::toString(value1,2,false) == "122104432.23");
    REQUIRE(StringUtils::toString(value2,1,false) == "1.2");
    REQUIRE(StringUtils::toString(value3,false) == "99123456789");
    REQUIRE(StringUtils::toString(value4,false) == "72");
    REQUIRE(StringUtils::toString(value5,false) == "-262315");
    REQUIRE(StringUtils::toString(value6,2,false) == "-903172.01");
    REQUIRE(StringUtils::toString(value7,2,false) == "102234.00");
}
