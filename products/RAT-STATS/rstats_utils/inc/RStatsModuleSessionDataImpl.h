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


class RStatsModuleSessionDataImpl : public RStatsModuleSessionData
{
public:
	//! Constructor for RStatsModuleSessionDataImpl
	/*!
		Detailed description for RStatsModuleSessionDataImpl
	*/    
	RStatsModuleSessionDataImpl();

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
    * @brief Getter for m_textOutputFile
    * @return Return copy of m_textOutputFile
    */
    const std::string & getTextOutputFile() const;

    /**
    * @brief Getter for m_auditName
    * @return Return copy of m_auditName
    */
    const std::string & getAuditName() const;

	//! Destructor
	~RStatsModuleSessionDataImpl();	
protected:
    void save(cbtek::common::utility::XMLStreamWriter& writer);
    void load(cbtek::common::utility::XMLDataElement *element);

private:
    cbtek::common::utility::DateEntity m_creationDate;
    cbtek::common::utility::TimeEntity m_creationTime;
    std::string m_csvOutputFile;
    std::string m_textOutputFile;
    std::string m_auditName;

};
}}}//end namespace
