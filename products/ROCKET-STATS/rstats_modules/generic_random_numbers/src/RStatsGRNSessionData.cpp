/*
    RStatsGRNSessionData.cpp
    

*/
//----------------------------------------
//RStatsGRNSessionData.cpp generated by cbtek on 03-31-2017 at 01:28:43 AM
//----------------------------------------
#include "RStatsGRNSessionData.h"

#include "utility/inc/XMLUtils.h"

using namespace cbtek::rocketstats::utils;
using namespace cbtek::common::utility;

namespace cbtek {
namespace rocketstats {
namespace modules {
namespace grn {


RStatsGRNSessionData::RStatsGRNSessionData()
{

}

RStatsGRNSessionData::~RStatsGRNSessionData()
{

}

void RStatsGRNSessionData::setSeed(const std::string & value)
{
    m_seed=value;
}

void RStatsGRNSessionData::setOrder(const RStatsInteger & value)
{
    m_order=value;
}

void RStatsGRNSessionData::setSpares(const RStatsInteger & value)
{
    m_spares=value;
}

void RStatsGRNSessionData::setLow(const RStatsInteger & value)
{
    m_low=value;
}

void RStatsGRNSessionData::setHigh(const RStatsInteger & value)
{
    m_high=value;
}



const std::string &RStatsGRNSessionData::getSeed() const
{
    return m_seed;
}

const RStatsInteger &RStatsGRNSessionData::getOrder() const
{
    return m_order;
}

const RStatsInteger &RStatsGRNSessionData::getSpares() const
{
    return m_spares;
}

const RStatsInteger &RStatsGRNSessionData::getLow() const
{
    return m_low;
}

const RStatsInteger &RStatsGRNSessionData::getHigh() const
{
    return m_high;
}

std::string RStatsGRNSessionData::getType() const
{
    return c_RECENT_SESSION_EXTENSION;
}

void RStatsGRNSessionData::load(const std::string &url)
{
    XMLReader xml;
    xml.load(url);
    XMLDataElement * element = xml.getElement("session");
    if (element)
    {
        RStatsModuleSessionDataImpl::load(element);
        setHigh(element->getChildElementDataAsType<RStatsInteger>("high"));
        setLow(element->getChildElementDataAsType<RStatsInteger>("low"));
        setSpares(element->getChildElementDataAsType<RStatsInteger>("spares"));
        setOrder(element->getChildElementDataAsType<RStatsInteger>("order"));
        setSeed(element->getChildElementData("seed"));
    }
}

void RStatsGRNSessionData::save(const std::string &url)
{
    std::ostringstream out;
    XMLStreamWriter xml(out);
    xml.writeStartDocument();
    xml.writeStartElementNoAttributes("session");
    RStatsModuleSessionDataImpl::save(xml);
    xml.writeTextElement("high",StringUtils::toString(this->getHigh()));
    xml.writeTextElement("low",StringUtils::toString(this->getLow()));
    xml.writeTextElement("spares",StringUtils::toString(this->getSpares()));
    xml.writeTextElement("order",StringUtils::toString(this->getOrder()));
    xml.writeTextElement("seed",StringUtils::toString(this->getSeed()));
    xml.writeEndElement("session");
    FileUtils::writeFileContents(url,out.str());
}


}}}}//end namespace

