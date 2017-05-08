/*
    RStatsModuleSessionDataImpl.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsModuleSessionData.hpp"

#include "utility/inc/DateTimeUtils.hpp"
#include "utility/inc/XMLUtils.h"

namespace oig {
namespace ratstats {
namespace utils {

/**
 * @brief The RStatsModuleSessionDataImpl abstract class is a partial
 * base implementation of the RStatsModuleSessionData interface.
 * It implements getters/setters for the common values 
 */
class RStatsModuleSessionDataImpl : public RStatsModuleSessionData
{
public:

    /**
     * @brief RStatsModuleSessionDataImpl
     */
	RStatsModuleSessionDataImpl();

    /**
     * @brief getType Get a string representing the subclass type
     * @return Return string for type (m_type)
     */
    virtual std::string getType() const = 0;

    /**
     * @brief save Calls virtual subclass method for saving
     * @param url Path to file to save
     */
    virtual void save(const std::string& url) = 0;

    /**
     * @brief load Calls virtual subclass method for loading
     * @param url Path to file to load
     */
    virtual void load(const std::string& url) = 0;

    /**
     * @brief getSessionId Return unique id associated with this session
     * @return
     */
    virtual std::string getSessionId() const;

    /**
    * @brief Setter for m_creationDate
    * @param Value to replace m_creationDate
    */
    void setCreationDate(const cbtek::common::utility::DateEntity & value);

    /**
    * @brief Setter for m_creationTime
    * @param Value to replace m_creationTime
    */
    void setCreationTime(const cbtek::common::utility::TimeEntity & value);

    /**
    * @brief Setter for m_csvOutputFile
    * @param Value to replace m_csvOutputFile
    */
    void setCSVOutputFile(const std::string & value);

    /**
    * @brief Setter for m_xlsOutputFile
    * @param Value to replace m_xlsOutputFile
    */
    void setXLSOutputFile(const std::string & value);

    /**
    * @brief Setter for m_textOutputFile
    * @param Value to replace m_textOutputFile
    */
    void setTextOutputFile(const std::string & value);

    /**
    * @brief Setter for m_auditName
    * @param Value to replace m_auditName
    */
    void setAuditName(const std::string & value);

   /**
    * @brief Getter for m_creationDate
    * @return Return copy of m_creationDate
    */
    const cbtek::common::utility::DateEntity & getCreationDate() const;

    /**
    * @brief Getter for m_creationTime
    * @return Return copy of m_creationTime
    */
    const cbtek::common::utility::TimeEntity & getCreationTime() const;

    /**
    * @brief Getter for m_csvOutputFile
    * @return Return copy of m_csvOutputFile
    */
    const std::string & getCSVOutputFile() const;

    /**
    * @brief Getter for m_xlsOutputFile
    * @return Return copy of m_xlsOutputFile
    */
    const std::string & getXLSOutputFile() const;

    /**
    * @brief Getter for m_textOutputFile
    * @return Return copy of m_textOutputFile
    */
    const std::string & getTextOutputFile() const;

    /**
    * @brief Getter for m_auditName
    * @return Return copy of m_auditName
    */
    const std::string & getAuditName() const;

    /**
     * @brief setViewInBrowserFlag
     * @param flag
     */
    void setViewInBrowserFlag(bool flag);

    /**
     * @brief isViewableInBrowser
     * @return
     */
    bool isViewableInBrowser() const;

    /**
     * @brief createSessionId Generates new session id
     */
    void createSessionId();

	//! Destructor
	~RStatsModuleSessionDataImpl();	
protected:

    /**
     * @brief save Provides XML save support for common values. This
     * is usually called by implementing modules.
     * @param writer Reference to the XML outout writer
     */
    void save(cbtek::common::utility::XMLStreamWriter& writer);

    /**
     * @brief load Provides XML load support for common values. This
     * is usually called by implementing modules.
     * @param element Pointer to XML parse element
     */
    void load(cbtek::common::utility::XMLDataElement *element);

private:
    cbtek::common::utility::DateEntity m_creationDate;
    cbtek::common::utility::TimeEntity m_creationTime;
    bool m_viewInBrowser;
    std::string m_csvOutputFile;
    std::string m_sessionId;
    std::string m_xlsOutputFile;
    std::string m_textOutputFile;
    std::string m_auditName;

};
}}}//end namespace
