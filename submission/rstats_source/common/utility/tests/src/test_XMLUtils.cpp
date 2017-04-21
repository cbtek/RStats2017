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

#include "utility/inc/XMLUtils.h"
#include "utility/inc/FileUtils.hpp"

#include "contrib/catch/catch.hpp"

#include <sstream>

using namespace cbtek::common::utility;
static const std::string dataFolder = "testData/utility/";

TEST_CASE("Testing XMLReader::loadString","[utility::XMLReader]")
{
    XMLReader reader;
    std::string xml = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\r\n<worksheet xmlns=\"http://schemas.openxmlformats.org/spreadsheetml/2006/main\" xmlns:r=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships\" xmlns:mc=\"http://schemas.openxmlformats.org/markup-compatibility/2006\" mc:Ignorable=\"x14ac\" xmlns:x14ac=\"http://schemas.microsoft.com/office/spreadsheetml/2009/9/ac\"><dimension ref=\"A1:B4\"/><sheetViews><sheetView workbookViewId=\"0\"/></sheetViews><sheetFormatPr defaultRowHeight=\"15\" x14ac:dyDescent=\"0.25\"/><sheetData><row r=\"1\" spans=\"1:2\" x14ac:dyDescent=\"0.25\"><c r=\"A1\"><v>500</v></c><c r=\"B1\"><v>10</v></c></row><row r=\"2\" spans=\"1:2\" x14ac:dyDescent=\"0.25\"><c r=\"A2\"><v>100</v></c><c r=\"B2\"><v>100</v></c></row><row r=\"3\" spans=\"1:2\" x14ac:dyDescent=\"0.25\"><c r=\"A3\"><v>100</v></c><c r=\"B3\"><v>2</v></c></row><row r=\"4\" spans=\"1:2\" x14ac:dyDescent=\"0.25\"><c r=\"A4\"><v>888</v></c><c r=\"B4\"><v>887</v></c></row></sheetData><pageMargins left=\"0.7\" right=\"0.7\" top=\"0.75\" bottom=\"0.75\" header=\"0.3\" footer=\"0.3\"/></worksheet>";
    reader.loadFromString(xml);
    XMLDataElement* element = reader.getElement("worksheet");
    REQUIRE(element != NULL);
    XMLDataElement* child = element->getChild("sheetData");
    REQUIRE(child != NULL);
    child = child->getChild("row");
    REQUIRE(child != NULL);
    child = child->getChild("c");
    REQUIRE(child != NULL);
    REQUIRE(child->getChildElementData("v") == "500");
}

TEST_CASE("Testing XMLReader::getElement","[utility::XMLReader")
{
    std::ostringstream xml;
    xml<<"<xml><element id=\"test\"><element_child value=\"child\"/> </element></xml>";
    std::string tempFile = "temp.xml";
    FileUtils::writeFileContents(tempFile,xml.str());
    XMLReader reader;
    reader.load(tempFile);
    FileUtils::deleteFile(tempFile);
    std::string data = FileUtils::getFileContents(tempFile);
    reader.loadFromString(data);
    const XMLDataElement * root = reader.getElement("XML");
    const XMLDataElement * child = reader.getElement("XML.Element");
    REQUIRE(root!=NULL);
    REQUIRE(child!=NULL);
    REQUIRE(StringUtils::equals(root->getElementName(),"XML"));
    REQUIRE(child->getAttributeValue("id") == "test");

}
