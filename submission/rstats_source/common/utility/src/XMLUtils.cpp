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
#include "utility/inc/StringUtils.hpp"

namespace cbtek {
namespace common {
namespace utility {

XMLDataElement::XMLDataElement()
{
    m_Parent=0;
    m_LocalIndex=0;
}

XMLDataElement::XMLDataElement(const XMLDataElement &element)
{
    m_Attributes = element.getAttributes();
    m_Name=element.getElementName();
    m_Data=element.getElementData();
    m_LocalIndex=element.getLocalIndex();
    m_Parent=0;
    for (size_t a1 = 0;a1<element.getNumChildren();++a1)
    {
        m_ChildElementVector.push_back(new XMLDataElement(*element.getChildAt(a1)));
    }
}

XMLDataElement::~XMLDataElement()
{
    for (size_t a1 = 0;a1<m_ChildElementVector.size();a1++)
    {
        XMLDataElement * child= m_ChildElementVector[a1];
        if (child)
        {
            delete child;
            child=0;
        }
    }

    m_ChildElementVector.clear();
}

const std::string &XMLDataElement::getElementName() const
{
    return m_Name;
}

const AttributeVector &XMLDataElement::getAttributes() const
{
    return m_Attributes;
}

size_t XMLDataElement::getNumAttributes() const
{
    return m_Attributes.size();
}

std::string XMLDataElement::getAttributeName(size_t index) const
{
    if (index<m_Attributes.size())
    {
        return m_Attributes[index].first;
    }
    return "";
}

std::string XMLDataElement::getAttributeValue(size_t index) const
{
    if (index<m_Attributes.size())
    {
        return m_Attributes[index].second;
    }
    return "";
}

bool XMLDataElement::attributeExists(const std::string & attributeName, bool caseSensitive) const
{
    for(size_t a1 = 0;a1<m_Attributes.size();a1++)
    {
        if (caseSensitive)
        {
            if (m_Attributes[a1].first==attributeName)
            {
                return true;
            }
        }
        else
        {
            if (StringUtils::toUpper(m_Attributes[a1].first)==StringUtils::toUpper(attributeName))
            {
                return true;
            }
        }
    }
    return false;
}


std::string XMLDataElement::getElementData(bool trimmed) const
{
    return trimmed ? StringUtils::trimmed(m_Data) : m_Data;
}

int64_t XMLDataElement::getElementDataAsInteger() const
{
    return StringUtils::toInt(StringUtils::trimmed(getElementData()));
}

double XMLDataElement::getElementDataAsFloat() const
{
    return StringUtils::toFloat64(StringUtils::trimmed(getElementData()));
}

std::string XMLDataElement::getAttributeValue(const std::string & attributeName,
                                              bool caseSensitive) const
{

    for(size_t a1 = 0;a1<m_Attributes.size();a1++)
    {
        if (caseSensitive)
        {
            if (m_Attributes[a1].first==attributeName)
            {
                return m_Attributes[a1].second;
            }
        }
        else
        {
            if (StringUtils::toUpper(m_Attributes[a1].first)==StringUtils::toUpper(attributeName))
            {
                return m_Attributes[a1].second;
            }
        }
    }
    return "";
}

const ChildElementVector &XMLDataElement::getChildren() const
{
    return m_ChildElementVector;
}

bool XMLDataElement::hasChildren() const
{
    return m_ChildElementVector.size()>0;
}

XMLDataElement *XMLDataElement::getChildAt(size_t index) const
{
    return (index < m_ChildElementVector.size())?m_ChildElementVector[index]:NULL;
}

XMLDataElement *XMLDataElement::getChild(const std::string &name) const
{
    for(XMLDataElement * element: m_ChildElementVector)
    {
        if (StringUtils::equals(element->getElementName(),name))
        {
            return element;
        }
    }
    return NULL;
}

std::string XMLDataElement::getChildElementData(const std::string &name) const
{
    XMLDataElement * child = getChild(name);
    if (child)
    {
        return child->getElementData(true);
    }
    return "";
}

bool XMLDataElement::childExists(const std::string &name, bool caseSensitive)
{
    for (size_t a1 = 0;a1<m_ChildElementVector.size();a1++)
    {
        XMLDataElement * child= m_ChildElementVector[a1];
        if (caseSensitive)
        {
            if (child->getElementName()==name)
            {
                return true;
            }
        }
        else
        {
            if (StringUtils::toUpper(child->getElementName())==StringUtils::toUpper(name))
            {
                return true;
            }
        }
    }
    return false;

}

size_t XMLDataElement::getNumChildren() const
{
    return m_ChildElementVector.size();
}

void XMLDataElement::setElementData(const std::string &data)
{
    m_Data=data;
}

void XMLDataElement::setElementName(const std::string &name)
{
    m_Name=name;
}

void XMLDataElement::addAttribute(const std::string &attributeName,
                                  const std::string &attributeValue)
{
    m_Attributes.push_back(std::make_pair(attributeName,attributeValue));
}

void XMLDataElement::addChild(XMLDataElement *child)
{
    m_ChildElementVector.push_back(child);
}

void XMLDataElement::setParent(XMLDataElement *parent)
{
    m_Parent=parent;
}

XMLDataElement *XMLDataElement::getParent() const
{
    return m_Parent;
}

size_t XMLDataElement::getLocalIndex() const
{
    return m_LocalIndex;
}

size_t XMLDataElement::getChildIndex(const XMLDataElement *child) const
{
    for (size_t a1 = 0;a1<m_ChildElementVector.size();++a1)
    {
        if (child==m_ChildElementVector[a1])
        {
            return a1;
        }
    }
    return 0;
}

void XMLDataElement::setLocalIndex(size_t index)
{
    m_LocalIndex=index;
}

const XMLDataElement *XMLDataElement::find(const std::string &name,
                                           const bool &caseSensitive) const
{
    return findInSubTree(name,this,caseSensitive);
}

XMLDataElement *XMLDataElement::find(const std::string &name,
                                     const bool &caseSensitive)
{
    return findInSubTree(name,this,caseSensitive);
}

void XMLDataElement::addAttribute(const std::string &attributeName,
                                  const float &attributeValue)
{
    m_Attributes.push_back(std::make_pair(attributeName,StringUtils::toString(attributeValue)));
}

void XMLDataElement::addAttribute(const std::string &attributeName,
                                  const double &attributeValue)
{
    m_Attributes.push_back(std::make_pair(attributeName,StringUtils::toString(attributeValue)));
}

bool XMLDataElement::getAttributeValueAsBool(const std::string &attributeName) const
{
    std::string value = getAttributeValue(attributeName);
    if (StringUtils::toUpperTrimmed(value) == "TRUE")
    {
        return true;
    }
    else return false;
}

XMLDataElement *XMLDataElement::findInSubTree(const std::string & name,
                                              const XMLDataElement * element,
                                              const bool &caseSensitive)
{
    for (size_t a1 = 0;a1<element->getNumChildren();++a1)
    {
        XMLDataElement * child = element->getChildAt(a1);
        if (caseSensitive)
        {
            if (name==child->getElementName())
            {
                return child;
            }
        }
        else
        {
            if (StringUtils::toUpper(name)==StringUtils::toUpper(child->getElementName()))
            {
                return child;
            }
        }

        if (child->getNumChildren()>0)
        {
            XMLDataElement * subChild = findInSubTree(name,child,caseSensitive);
            if (subChild)
            {
                return subChild;
            }
        }
    }
    return NULL;
}


const XMLDataElement *XMLDataElement::findInSubTree(const std::string & name,
                                                    const XMLDataElement * element,
                                                    const bool &caseSensitive) const
{
    for (size_t a1 = 0;a1<element->getNumChildren();++a1)
    {
        const XMLDataElement * child = element->getChildAt(a1);
        if (caseSensitive)
        {
            if (name==child->getElementName())
            {
                return child;
            }
        }
        else
        {
            if (StringUtils::toUpper(name)==StringUtils::toUpper(child->getElementName()))
            {
                return child;
            }
        }

        if (child->getNumChildren()>0)
        {
            const XMLDataElement * subChild = findInSubTree(name,child,caseSensitive);
            if (subChild)
            {
                return subChild;
            }
        }
    }
    return NULL;
}

XMLDataElement *XMLDataElement::getNextSibling() const
{
    if (m_Parent)
    {
        size_t ndx = m_Parent->getChildIndex(this);
        return m_Parent->getChildAt(ndx+1);
    }
    return NULL;
}

XMLReader::XMLReader()
{
    this->m_Index=0;
    this->m_LineCount=0;
    this->m_Depth=0;
    this->m_ColumnCount=0;
    this->m_LineCount=0;
    this->m_Current=NULL;
    this->m_Root.setElementName("ROOT");
    this->m_Root.setParent(0);
    this->m_Initialized=false;
}


XMLReader::~XMLReader()
{
}

XMLDataElement *XMLReader::getRoot()
{
    return &this->m_Root;
}

const XMLDataElement *XMLReader::getRoot() const
{
    return &this->m_Root;
}


void XMLReader::reset()
{
    this->m_Current=&this->m_Root;
}

bool XMLReader::isValid() const
{
    return this->m_Initialized;
}

size_t XMLReader::getDepth() const
{
    return this->m_Depth;
}

void XMLReader::clear()
{
    this->m_ParseString.clear();
    this->m_PeekToken=0;
    this->m_Index=0;
    this->m_LineCount=0;
    this->m_Depth=0;
    this->m_ColumnCount=0;
    this->m_LineCount=0;
    this->m_Current=NULL;
    this->m_Root.setElementName("ROOT");
    this->m_Root.setParent(NULL);
    this->m_Initialized=false;
}

XMLDataElement *XMLReader::getFirstElement()
{
    if (this->m_Root.getNumChildren()>0)
    {
        return this->m_Root.getChildAt(0);
    }
    else return &this->m_Root;
}

XMLDataElement *XMLReader::find(const std::string &name,
                                const bool & caseSensitive)
{
    return m_Root.find(name,caseSensitive);
}

bool XMLReader::exists(const std::string &tagName,
                       const bool &caseSensitive)
{
    return this->getElement(tagName,caseSensitive)?true:false;
}

size_t XMLReader::getNumElements(const std::string &tagName,
                                 const bool & caseSensitive)
{
    const XMLDataElement * element = this->getElement(tagName,caseSensitive);
    if (element)
    {
        return element->getNumChildren();
    }
    std::string errMsg="(FATAL_XMLDataElement::getNumElements) : ";
    errMsg+="Could not find element with tag name equal to \""+tagName+"\"";
    throw InvalidOperationException(errMsg);
}

XMLDataElement *XMLReader::getElement(const std::string &dotNotation,
                                      const bool &caseSensitive)
{
    std::string tag;
    if (caseSensitive)
    {
        tag="ROOT."+dotNotation;
    }
    else
    {
        tag=StringUtils::toUpper("ROOT."+dotNotation);
    }

    std::vector<std::string> items = StringUtils::split(tag,".");
    std::string tagValue;
    XMLDataElement * element=&m_Root;

    if (caseSensitive)
    {
        tagValue=StringUtils::trimmed(dotNotation);
    }
    else
    {
        items[1]=StringUtils::toUpper(items[1]);
        tagValue=StringUtils::trimmed(dotNotation);
        tagValue=StringUtils::toUpper(tagValue);
    }


    if (items[0]==tagValue)
    {
        return element;
    }

    for(unsigned int a1=1;a1<items.size();a1++)
    {
        element = this->getChild(element,items[a1]);
        if (element)
        {
            std::string elementName =
                    StringUtils::toUpper(element->getElementName());
            std::string searchName =
                    StringUtils::toUpper(items[a1]);

            bool isValid = (elementName==searchName);
            if (!isValid)
            {
                return NULL;
            }
        }
        else
        {
            return NULL;
        }
    }

    if (items.size()>0)
    {
        return element;
    }
    return NULL;
}

bool XMLReader::load(const std::string & url)
{
    return loadFromString(FileUtils::getFileContents(url));
}

bool XMLReader::loadFromString(const std::string &data)
{

    this->m_ParseString=data;
    m_Initialized=true;
    this->parse();
    return true;
}

void XMLReader::printToString()
{
    this->m_Depth=0;
    this->printTree(&this->m_Root,this->m_Depth);
}

std::string XMLReader::toString() const
{
    return this->m_ParseString;
}

size_t XMLReader::getNumLines() const
{
    return this->m_LineCount;
}

void XMLReader::processCloseTag()
{
    if (!this->m_Current)
    {
        return;
    }
    this->m_Current = this->m_Current->getParent();
}

void XMLReader::processOpenTag(const std::string &data)
{
    std::vector<std::string> items = StringUtils::split(data," ");
    if (items.size()>0)
    {

            if (!this->m_Current)
            {
                this->m_Current=new XMLDataElement;
                this->m_Root.addChild(this->m_Current);
                this->m_Current->setParent(&this->m_Root);
                this->m_Current->setLocalIndex(this->m_Root.getNumChildren());
                this->m_Current->setElementName(items[0]);
            }
            else
            {
                XMLDataElement * child=new XMLDataElement;
                child->setLocalIndex(this->m_Current->getNumChildren());
                this->m_Current->addChild(child);
                child->setParent(this->m_Current);
                child->setElementName(items[0]);
                this->m_Current=child;
            }

        /*Process attributes*/
        //remove tag and get only the attributes
            StringUtils::trimmed(data.substr(items[0].size(),
                                 data.size()-items[0].size()));
        this->parseAttributes(StringUtils::trimmed(
                                  data.substr(items[0].size(),
                                  data.size()-items[0].size())),
                                  this->m_Current);
    }
}

void XMLReader::printTree(XMLDataElement *element, size_t level)
{
    std::string tag = StringUtils::toUpper(element->getElementName());
    XMLDataElement * searchElement = this->getFirst(this->getRoot(),tag);

    for (size_t a1=0;a1<level;a1++)
    {
        this->m_OutputStream<<"----";
    }
    this->m_OutputStream  <<"-> "
                         <<element->getElementName()
                        <<(searchElement?" YES":" NO")<<"\n";

    level++;
    if (level>this->m_Depth)
    {
        this->m_Depth=level;
    }

    for (size_t a1 = 0;a1<element->getNumChildren();a1++)
    {
        this->printTree(element->getChildAt(a1),level);
    }

}

XMLDataElement *XMLReader::getFirst(XMLDataElement * node,
                                    const std::string name,
                                    const bool &caseSensitive)
{
    std::string tag;
    std::string childName;
    if (caseSensitive)
    {
        tag = node->getElementName();
        childName = name;
    }
    else
    {
        tag = StringUtils::toUpper(node->getElementName());
        childName = StringUtils::toUpper(name);
    }


    if (tag == childName)
    {
        return node;
    }
    else
    {
        size_t childCount  = node->getNumChildren();
        if (childCount == 0)
        {
            node = node->getParent();
            return node;
        }
        else
        {
            return this->getFirst(node->getChildAt(0),
                                  childName,
                                  caseSensitive);
        }

    }
    return NULL;
}

XMLDataElement *XMLReader::getChild(XMLDataElement *parent,
                                    const std::string & childName,
                                    const bool &caseSensitive)
{
    for (size_t a1 = 0;a1<parent->getNumChildren();a1++)
    {
        std::string childTag;
        std::string searchTag;
        if (caseSensitive)
        {
            childTag=childName;
            searchTag=parent->getChildAt(a1)->getElementName();
        }
        else
        {
            childTag = StringUtils::toUpper(childName);
            searchTag =
                    StringUtils::toUpper(parent->getChildAt(a1)->getElementName());
        }

        if (childTag==searchTag)
        {
            return parent->getChildAt(a1);
        }
    }
    return NULL;
}

void XMLReader::parse()
{
    std::string data;
    this->m_Token = this->m_ParseString[this->m_Index];
    this->m_PeekToken = this->m_ParseString[this->m_Index+1];
    while(isParsingValid())
    {
        std::string openTag;
        std::string closeTag;
        if(m_Token=='<' && m_PeekToken=='/')
        {
            this->consume();
            this->consume();
            if (m_Current)
            {
                data = StringUtils::remove(data,"<");
                data = StringUtils::remove(data,">");
                m_Current->setElementData(StringUtils::trimmed(data));
                data.clear();
            }
            while(this->isParsingValid())
            {
                if (m_Token=='>')
                {
                    break;
                }
                closeTag.push_back(m_Token);
                this->consume();
            }
            this->processCloseTag();
        }
        else if(m_Token=='<' && m_PeekToken=='!')
        {
            while(this->isParsingValid())
            {
                if (m_Token=='>')
                {
                    break;
                }
                this->consume();
            }
        }
        else if (m_Token=='<' && m_PeekToken=='?')
        {
            while(this->isParsingValid())
            {
                if (m_Token=='>')
                {
                    break;
                }
                this->consume();
            }
        }
        else if (m_Token=='<')
        {
            this->consume();
            bool closeTagNeedsProcessing=false;
            size_t quoteCount=0;
            while(this->isParsingValid())
            {
                if (m_Token=='/' && m_PeekToken=='>')
                {
                    closeTagNeedsProcessing=true;
                    break;
                }

                if (m_Token=='\''||m_Token=='"')
                {
                    ++quoteCount;
                }

                if (m_Token=='>' && quoteCount%2==0)
                {
                    break;
                }

                openTag.push_back(m_Token);
                this->consume();
            }
            this->processOpenTag(openTag);
            if (closeTagNeedsProcessing)
            {
                this->processCloseTag();
            }
        }
        else
        {
            data.push_back(m_Token);
        }
        this->consume();
    }

}


void XMLReader::parseAttributes(const std::string& attributes,
                                XMLDataElement* element)
{
    if (attributes.length() > 0)
    {
        unsigned int attrCounter=0;
        std::string attributeName;
        std::string attributeValue;
        bool storeName=true;
        bool storeValue=false;
        bool attributeStored=false;
        char valueStopChar=' ';

        while (attrCounter < attributes.length())
        {
            char token = attributes[attrCounter];
            if (token=='\n' || token=='\t' || token=='\r')
            {

            }

            //Parses out the attribute name
            if (storeName)
            {
                while(attrCounter<attributes.size())
                {
                    token = attributes[attrCounter];
                    if (token=='=')
                    {
                        storeName=false;
                        storeValue=true;
                        break;
                    }
                    else
                    {
                        attributeName.push_back(token);
                    }
                    ++attrCounter;
                }

            }


            //parses out the attribute value
            else if (storeValue)
            {

                while(attrCounter<attributes.size())
                {
                    token = attributes[attrCounter];
                    if (token=='\"' || token=='\'')
                    {
                        valueStopChar=token;
                        ++attrCounter;
                        while(attrCounter<attributes.size())
                        {
                            token = attributes[attrCounter];
                            if (token==valueStopChar)
                            {
                                attributeStored=true;
                                break;
                            }
                            attributeValue.push_back(token);
                            ++attrCounter;
                        }

                        break;
                    }
                    ++attrCounter;
                }
            }
            if (attributeStored)
            {

                element->addAttribute(StringUtils::trimmed(attributeName),
                                      StringUtils::trimmed(attributeValue));
                attributeName.clear();
                attributeValue.clear();
                attributeStored=false;
                storeName=true;
                storeValue=false;

            }
            ++attrCounter;
        }
    }
}


void XMLReader::consume()
{
    ++this->m_Index;
    if (this->m_Index >= m_ParseString.length())
    {
        return;
    }
    this->m_Token=m_ParseString[this->m_Index];
    if (this->m_Token =='\n')
    {
        this->m_LineCount++;
        this->m_ColumnCount=0;
    }
    this->m_ColumnCount++;
    if (this->m_Index+1 <m_ParseString.length())
    {
        this->m_PeekToken = m_ParseString[m_Index+1];
    }
}

bool XMLReader::isParsingValid()
{
    return (m_Index<m_ParseString.length());
}

std::string XMLUtils::getEncodedString(const std::string &rawString)
{
    std::string retStr;
    retStr=StringUtils::replace(rawString,"&","&amp;",true);
    retStr=StringUtils::replace(retStr,"\"","&quot;",true);
    retStr=StringUtils::replace(retStr,"<","&lt;",true);
    retStr=StringUtils::replace(retStr,">","&gt;",true);
    retStr=StringUtils::replace(retStr,"\n","&nl;",true);
    retStr=StringUtils::replace(retStr,"\t","&tab;",true);
    return retStr;
}

std::string XMLUtils::getDecodedString(const std::string &xmlString)
{
    std::string retStr;
    retStr=StringUtils::replace(xmlString,"&amp;","&",true);
    retStr=StringUtils::replace(retStr,"&quot;","\"",true);
    retStr=StringUtils::replace(retStr,"&lt;","<",true);
    retStr=StringUtils::replace(retStr,"&gt;",">",true);
    retStr=StringUtils::replace(retStr,"&nl;","\n",true);
    retStr=StringUtils::replace(retStr,"&tab;","\n",true);
    return retStr;
}



XMLStreamWriter::XMLStreamWriter(std::ostream &out)
    : m_out(out)
{
    m_currentTab = 0;
}

void XMLStreamWriter::writeStartDocument(const std::string &version, bool flag)
{
    m_out << "<?xml version=\""<<version<<"\" encoding=\"UTF-8\" standalone=\""<<(flag?"yes":"no")<<"\"?>"<<std::endl;
}

void XMLStreamWriter::writeStartElementNoAttributes(const std::string &tag)
{
    writeTabs();
    m_out <<"<"<<tag<<">\n";
    m_currentTab++;
}

void XMLStreamWriter::writeStartElement(const std::string &tag)
{
    writeTabs();
    m_out <<"<"<<tag;
    m_currentTab++;
}

void XMLStreamWriter::writeEndElement()
{
     m_out<<"/>"<<std::endl;
     if (m_currentTab > 0)
     {
         m_currentTab--;
     }
}

void XMLStreamWriter::writeEndElement(const std::string &tag)
{
    if (m_currentTab > 0)
    {
        m_currentTab--;
    }
    writeTabs();
    m_out<<"</"<<tag<<">"<<std::endl;
}

void XMLStreamWriter::writeTextElement(const std::string &tag, const std::string &text)
{
    writeTabs();
    m_out<<"<"<<tag<<">"<<text<<"</"<<tag<<">"<<std::endl;

}

void XMLStreamWriter::writeText(const std::string &text)
{
    m_out << text;
}

XMLStreamWriter::~XMLStreamWriter()
{

}

void XMLStreamWriter::writeTabs()
{
    for (size_t a1 = 0;a1<m_currentTab;++a1)
    {
        m_out << "    ";
    }
}
}}}//namespace
