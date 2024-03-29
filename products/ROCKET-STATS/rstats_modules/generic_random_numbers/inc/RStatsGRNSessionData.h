/*
    RStatsGRNSessionData.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsModuleSessionDataImpl.h"
#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorksheet.h"

namespace cbtek {
namespace rocketstats {
namespace modules {
namespace grn {

static const std::string c_RECENT_SESSION_EXTENSION = "modules_ssrn";

/**
 * @brief The RStatsGRNSessionData class represents the custom session
 * data for single stage random numbers (GRN)
 */
class RStatsGRNSessionData : public utils::RStatsModuleSessionDataImpl
{
public:
    //! Constructor for RStatsGRNSessionData
	/*!
        Detailed description for RStatsGRNSessionData
	*/
    RStatsGRNSessionData();
        /**
    * @brief Setter for m_seed
    * @param value to replace m_seed
    */
    void setSeed(const std::string &value);

    /**
    * @brief Setter for m_order
    * @param value to replace m_order
    */
    void setOrder(const utils::RStatsInteger & value);

    /**
    * @brief Setter for m_spares
    * @param value to replace m_spares
    */
    void setSpares(const utils::RStatsInteger & value);

    /**
    * @brief Setter for m_low
    * @param value to replace m_low
    */
    void setLow(const utils::RStatsInteger & value);

    /**
    * @brief Setter for m_high
    * @param value to replace m_high
    */
    void setHigh(const utils::RStatsInteger & value);


        /**
    * @brief Getter for m_seed
    * @return Return copy of m_seed
    */
    const std::string &getSeed() const;

    /**
    * @brief Getter for m_order
    * @return Return copy of m_order
    */
    const utils::RStatsInteger & getOrder() const;

    /**
    * @brief Getter for m_spares
    * @return Return copy of m_spares
    */
    const utils::RStatsInteger & getSpares() const;

    /**
    * @brief Getter for m_low
    * @return Return copy of m_low
    */
    const utils::RStatsInteger & getLow() const;

    /**
    * @brief Getter for m_high
    * @return Return copy of m_high
    */
    const utils::RStatsInteger & getHigh() const;


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
    ~RStatsGRNSessionData();

private:
    std::string m_seed;
    utils::RStatsInteger m_order;
    utils::RStatsInteger m_spares;
    utils::RStatsInteger m_low;
    utils::RStatsInteger m_high;

};
}}}}//end namespace

