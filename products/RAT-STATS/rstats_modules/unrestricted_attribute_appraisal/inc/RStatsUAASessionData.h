/*
    RStatsUAASessionData.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsModuleSessionDataImpl.h"
#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorksheet.h"

namespace oig {
namespace ratstats {
namespace modules {
namespace uaa {

static const std::string c_RECENT_SESSION_EXTENSION = "modules_uaa";

/**
 * @brief The RStatsUAASessionData class represents the custom session
 * data for unrestricted attribute appraisal (UAA)
 */
class RStatsUAASessionData : public utils::RStatsModuleSessionDataImpl
{
public:
	//! Constructor for RStatsUAASessionData
	/*!
		Detailed description for RStatsUAASessionData
	*/
	RStatsUAASessionData();
        /**
    * @brief Setter for m_dataFormat
    * @param value to replace m_dataFormat
    */
    void setDataFormat(const utils::RStatsDataFormatType & value);

    /**
    * @brief Setter for m_universeSize
    * @param value to replace m_universeSize
    */
    void setUniverseSize(const utils::RStatsInteger & value);

    /**
    * @brief Setter for m_sampleSize
    * @param value to replace m_sampleSize
    */
    void setSampleSize(const utils::RStatsInteger & value);

    /**
    * @brief Setter for m_coiSize
    * @param value to replace m_coiSize
    */
    void setCoiSize(const utils::RStatsInteger & value);


        /**
    * @brief Getter for m_dataFormat
    * @return Return copy of m_dataFormat
    */
    const utils::RStatsDataFormatType & getDataFormat() const;

    /**
    * @brief Getter for m_universeSize
    * @return Return copy of m_universeSize
    */
    const utils::RStatsInteger & getUniverseSize() const;

    /**
    * @brief Getter for m_sampleSize
    * @return Return copy of m_sampleSize
    */
    const utils::RStatsInteger & getSampleSize() const;

    /**
    * @brief Getter for m_coiSize
    * @return Return copy of m_coiSize
    */
    const utils::RStatsInteger & getCoiSize() const;

    /**
     * @brief getType
     * @return
     */
    std::string getType() const;

    /**
     * @brief load
     * @param url
     */
    void load(const std::string& url);

    /**
     * @brief save
     * @param url
     */
    void save(const std::string& url);

	//! Destructor
	~RStatsUAASessionData();	

private:
    utils::RStatsDataFormatType m_dataFormat;
    utils::RStatsInteger m_universeSize;
    utils::RStatsInteger m_sampleSize;
    utils::RStatsInteger m_coiSize;

};
}}}}//end namespace

