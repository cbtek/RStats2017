/*
    RStatsUVASessionData.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsModuleSessionDataImpl.h"
#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorksheet.h"

namespace cbtek {
namespace rocketstats {
namespace modules {
namespace uva {

const static std::string c_RECENT_SESSION_EXTENSION = "modules_uva";

/**
 * @brief The RStatsUVASessionData class represents the custom session
 * data for unrestricted variable appraisal (UVA)
 */
class RStatsUVASessionData : public utils::RStatsModuleSessionDataImpl
{
public:
	//! Constructor for RStatsUVASessionData
	/*!
		Detailed description for RStatsUVASessionData
	*/
	RStatsUVASessionData();
        /**
    * @brief Setter for m_dataFormat
    * @param value to replace m_dataFormat
    */
    void setDataFormat(const utils::RStatsDataFormatType& value);

    /**
    * @brief Setter for m_universeSize
    * @param value to replace m_universeSize
    */
    void setUniverseSize(const utils::RStatsInteger& value);

    /**
    * @brief Setter for m_dataRowStart
    * @param value to replace m_dataRowStart
    */
    void setDataRowStart(const utils::RStatsInteger& value);

    /**
    * @brief Setter for m_dataTable
    * @param value to replace m_dataTable
    */
    void setDataTableFilePath(const std::string& value);

    /**
    * @brief Setter for m_dataTable
    * @param value to replace m_dataTable
    */
    void setDataTableSheetName(const std::string& value);

    /**
    * @brief Setter for m_examineColumn
    * @param value to replace m_examineColumn
    */
    void setExamineColumn(const std::string& value);

    /**
    * @brief Setter for m_auditColumn
    * @param value to replace m_auditColumn
    */
    void setAuditColumn(const std::string& value);

    /**
    * @brief Setter for m_differenceColumn
    * @param value to replace m_differenceColumn
    */
    void setDifferenceColumn(const std::string& value);


        /**
    * @brief Getter for m_dataFormat
    * @return Return copy of m_dataFormat
    */
    const utils::RStatsDataFormatType& getDataFormat() const;

    /**
    * @brief Getter for m_universeSize
    * @return Return copy of m_universeSize
    */
    const utils::RStatsInteger& getUniverseSize() const;

    /**
    * @brief Getter for m_dataRowStart
    * @return Return copy of m_dataRowStart
    */
    const utils::RStatsInteger& getDataRowStart() const;

    /**
    * @brief Getter for m_dataTable
    * @return Return url of data table
    */
    const std::string& getDataTableFilePath() const;


    /**
    * @brief Getter for m_dataTable
    * @return Return url of data table
    */
    const std::string& getDataTableSheetName() const;

    /**
    * @brief Getter for m_examineColumn
    * @return Return copy of m_examineColumn
    */
    const std::string& getExamineColumn() const;

    /**
    * @brief Getter for m_auditColumn
    * @return Return copy of m_auditColumn
    */
    const std::string& getAuditColumn() const;

    /**
    * @brief Getter for m_differenceColumn
    * @return Return copy of m_differenceColumn
    */
    const std::string& getDifferenceColumn() const;

    /**
     * @brief getType
     * @return
     */
    std::string getType() const;

    /**
     * @brief save
     * @param url
     */
    void save(const std::string& url);

    /**
     * @brief load
     * @param url
     */
    void load(const std::string& url);

	//! Destructor
	~RStatsUVASessionData();	

private:
    utils::RStatsDataFormatType m_dataFormat;
    utils::RStatsInteger m_universeSize;
    utils::RStatsInteger m_dataRowStart;
    std::string m_dataTableSheetName;
    std::string m_dataTableFilePath;
    std::string m_examineColumn;
    std::string m_auditColumn;
    std::string m_differenceColumn;
};
}}}}//end namespace

