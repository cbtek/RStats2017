/*
    RStatsModuleSessionData.hpp
    

*/

#pragma once

#include <string>
#include <memory>

#include "utility/inc/DateTimeUtils.hpp"

namespace cbtek {
namespace rocketstats {
namespace utils {

/**
 * @brief The RStatsModuleSessionData interface is used
 * by each of the modules to provide custom session data
 * for the "Recently Used" feature.  This interface represents
 * the common functions that have to be implemented for each
 * module.
 */
class RStatsModuleSessionData 
{
public:

    /**
     * @brief getSessionId Returns unique id associated with this session
     * @return
     */
    virtual std::string getSessionId() const = 0;

    /**
     * @brief getType The type of child class session data
     * @return Return type of session data
     */
    virtual std::string getType() const = 0;

    /**
     * @brief save Called by sub-classes for saving custom fields
     * @param url The location to save the file to
     */
    virtual void save(const std::string& url) = 0;

    /**
     * @brief load Called by sub-classes for loading custom fields
     * @param url The location to load the file from
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

    /**
     * @brief isViewableInBrowser Flag to determine if module
     * results are visible within a web browser
     * @return
     */
    virtual bool isViewableInBrowser() const = 0;

    //! Virtual Destructor
    virtual ~RStatsModuleSessionData(){}
};
typedef std::shared_ptr<RStatsModuleSessionData>RStatsModuleSessionDataPtr;
}}}//end namespace

