/*
    RStatsConditionLogger.cpp
    

*/
//----------------------------------------
//RStatsConditionLogger.cpp generated by CBTek Solutions on 01-27-2017 at 03:18:07 PM
//----------------------------------------
#include "RStatsConditionLogger.h"

#include "utility/inc/StringUtils.hpp"

using namespace cbtek::common::utility;

namespace oig {
namespace ratstats {
namespace utils {

RStatsConditionLogger::RStatsConditionLogger()
{
//    m_informationQSS = "<font style='padding:2px; border-bottom:1px solid gray;color:black;background:77FF77;font-weight: true;'>INFORMATION: %MESSAGE%</font>";
//    m_warningQSS = "<font style='padding:2px; border-bottom:1px solid gray;color:black;background:#ffff77;font-weight: true;'>WARNING: %MESSAGE%</font>";
//    m_errorQSS = "<font style='padding:2px; border-bottom:1px solid gray;color:black;background:#ff7777;font-weight: true;'>ERROR: %MESSAGE%</font>";

    m_informationQSS = "INFORMATION: %MESSAGE%";
    m_warningQSS = "WARNING: %MESSAGE%";
    m_errorQSS = "ERROR: %MESSAGE%";
}

void RStatsConditionLogger::addWarning(bool condition,
                                       const std::string &message)
{
    if (condition)
    {        
        m_messages.push_back(StringUtils::replace(m_warningQSS,"%MESSAGE%",message));
        m_conditionSet.push_back(ConditionType::WARNING);
    }
}

void RStatsConditionLogger::addInformation(bool condition,
                                           const std::string &message)
{
    if (condition)
    {
        m_messages.push_back(StringUtils::replace(m_informationQSS,"%MESSAGE%",message));
        m_conditionSet.push_back(ConditionType::INFORMATION);
    }
}

void RStatsConditionLogger::addError(bool condition,
                                     const std::string &message)
{
    if (condition)
    {
        m_messages.push_back(StringUtils::replace(m_errorQSS,"%MESSAGE%",message));
        m_conditionSet.push_back(ConditionType::ERROR);
    }
}

const std::vector<std::string> &RStatsConditionLogger::getMessages() const
{
    return m_messages;
}

bool RStatsConditionLogger::hasMessages() const
{
    return m_messages.size() > 0;
}

bool RStatsConditionLogger::hasError() const
{
    for (size_t a1 = 0; a1 < m_conditionSet.size(); ++a1)
    {
        if (m_conditionSet[a1] == ConditionType::ERROR)
        {
            return true;
        }
    }
    return false;

}

bool RStatsConditionLogger::hasWarning() const
{
    for (size_t a1 = 0; a1 < m_conditionSet.size(); ++a1)
    {
        if (m_conditionSet[a1] == ConditionType::WARNING)
        {
            return true;
        }
    }
    return false;
}

bool RStatsConditionLogger::hasInformation() const
{
    for (size_t a1 = 0; a1 < m_conditionSet.size(); ++a1)
    {
        if (m_conditionSet[a1] == ConditionType::INFORMATION)
        {
            return true;
        }
    }
    return false;
}

void RStatsConditionLogger::clear()
{
    m_messages.clear();
    m_conditionSet.clear();
}

void RStatsConditionLogger::setWarningQSS(const std::string &qss)
{
    m_warningQSS = qss;
}

void RStatsConditionLogger::setErrorQSS(const std::string &qss)
{
    m_errorQSS = qss;
}

void RStatsConditionLogger::setInformationQSS(const std::string &qss)
{
    m_informationQSS = qss;
}

bool RStatsConditionLogger::isError(size_t index) const
{
    return index < m_conditionSet.size() && m_conditionSet[index] == ConditionType::ERROR;
}

bool RStatsConditionLogger::isWarning(size_t index) const
{
    return index < m_conditionSet.size() && m_conditionSet[index] == ConditionType::WARNING;
}

bool RStatsConditionLogger::isInformation(size_t index) const
{
    return index < m_conditionSet.size() && m_conditionSet[index] == ConditionType::INFORMATION;
}

RStatsConditionLogger::~RStatsConditionLogger()
{

}
}}}//end namespace


