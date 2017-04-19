/*
    RStatsUAASessionData.cpp   
*/
//----------------------------------------
//RStatsUAASessionData.cpp generated by cbtek on 03-31-2017 at 01:36:35 AM
//----------------------------------------
#include "RStatsUAASessionData.h"

using namespace cbtek::common::utility;
using namespace oig::ratstats::utils;

namespace oig {
namespace ratstats {
namespace modules {
namespace uaa {


RStatsUAASessionData::RStatsUAASessionData() :
    m_dataFormat(RStatsDataFormatType::Examine),
    m_universeSize(0),
    m_sampleSize(0),
    m_coiSize(0){}

RStatsUAASessionData::~RStatsUAASessionData()
{

}

void RStatsUAASessionData::setDataFormat(const utils::RStatsDataFormatType & value)
{
    m_dataFormat=value;
}

void RStatsUAASessionData::setUniverseSize(const utils::RStatsInteger & value)
{
    m_universeSize=value;
}

void RStatsUAASessionData::setSampleSize(const utils::RStatsInteger & value)
{
    m_sampleSize=value;
}

void RStatsUAASessionData::setCoiSize(const utils::RStatsInteger & value)
{
    m_coiSize=value;
}

const utils::RStatsDataFormatType &RStatsUAASessionData::getDataFormat() const
{
    return m_dataFormat;
}

const utils::RStatsInteger &RStatsUAASessionData::getUniverseSize() const
{
    return m_universeSize;
}

const utils::RStatsInteger &RStatsUAASessionData::getSampleSize() const
{
    return m_sampleSize;
}

const utils::RStatsInteger &RStatsUAASessionData::getCoiSize() const
{
    return m_coiSize;
}

std::string RStatsUAASessionData::getType() const
{
    return c_RECENT_SESSION_EXTENSION;
}
void RStatsUAASessionData::load(const std::string &url)
{
    if (!url.empty())
    {
        XMLReader reader;
        reader.load(url);
        XMLDataElement* session = reader.getElement("session");
        if (session)
        {
            RStatsModuleSessionDataImpl::load(session);
            this->setCoiSize(session->getChildElementDataAsType<RStatsInteger>("coi"));
            this->setUniverseSize(session->getChildElementDataAsType<RStatsInteger>("universe"));
            this->setSampleSize(session->getChildElementDataAsType<RStatsInteger>("samples"));
        }
    }
}

void RStatsUAASessionData::save(const std::string& url)
{
    std::ostringstream out;
    XMLStreamWriter xml(out);
    xml.writeStartDocument();
    xml.writeStartElementNoAttributes("session");
    RStatsModuleSessionDataImpl::save(xml);
    xml.writeTextElement("samples",StringUtils::toString(this->getSampleSize()));
    xml.writeTextElement("coi",StringUtils::toString(this->getCoiSize()));
    xml.writeTextElement("universe",StringUtils::toString(this->getUniverseSize()));
    xml.writeEndElement("session");
    FileUtils::writeFileContents(url,out.str());
}


}}}}//end namespace


