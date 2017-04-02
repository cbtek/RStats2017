/*
    RStatsModuleSessionData.hpp
    

*/

#pragma once

#include <string>
#include <memory>

#include "utility/inc/DateTimeUtils.hpp"

namespace oig {
namespace ratstats {
namespace utils {

class RStatsModuleSessionData 
{
public:

    /**
     * @brief getType
     * @return
     */
    virtual std::string getType() const = 0;

    /**
     * @brief save
     * @param url
     */
    virtual void save(const std::string& url) = 0;

    /**
     * @brief load
     * @param url
     */
    virtual void load(const std::string& url) = 0;

   /**
    * @brief Getter for m_creationDate
    * @return Return copy of m_creationDate
    */
    virtual const cbtek::common::utility::DateEntity & getCreationDate() const = 0;

    /**
    * @brief Getter for m_creationTime
    * @return Return copy of m_creationTime
    */
    virtual const cbtek::common::utility::TimeEntity & getCreationTime() const = 0;

    /**
    * @brief Getter for m_csvOutputFile
    * @return Return copy of m_csvOutputFile
    */
    virtual const std::string & getCSVOutputFile() const = 0;

    /**
    * @brief Getter for m_textOutputFile
    * @return Return copy of m_textOutputFile
    */
    virtual const std::string & getTextOutputFile() const = 0;

    /**
    * @brief Getter for m_auditName
    * @return Return copy of m_auditName
    */
    virtual const std::string & getAuditName() const = 0;

    virtual void dummy(){}

    //! Virtual Destructor
    virtual ~RStatsModuleSessionData(){}
};
typedef std::shared_ptr<RStatsModuleSessionData>RStatsModuleSessionDataPtr;
}}}//end namespace

