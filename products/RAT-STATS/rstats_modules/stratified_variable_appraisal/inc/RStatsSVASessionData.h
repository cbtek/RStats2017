/*
    RStatsSVASessionData.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsModuleSessionDataImpl.h"
#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorksheet.h"

namespace oig {
namespace ratstats {
namespace modules {
namespace sva {

static const std::string c_RECENT_SESSION_EXTENSION = "modules_sva";

/**
 * @brief The RStatsSVASessionData class represents the custom session
 * data for stratified variable appraisal (SVA)
 */
class RStatsSVASessionData : public utils::RStatsModuleSessionDataImpl
{
public:
	//! Constructor for RStatsSVASessionData
	/*!
		Detailed description for RStatsSVASessionData
	*/
	RStatsSVASessionData();
        /**
    * @brief Setter for m_dataFormat
    * @param value to replace m_dataFormat
    */
    void setDataFormat(const utils::RStatsDataFormatType&  value);

    /**
    * @brief Setter for m_sizeTable
    * @param value to replace m_sizeTable
    */
    void setSizeTableFilePath(const std::string& value);

    /**
    * @brief Setter for m_dataTable
    * @param value to replace m_dataTable
    */
    void setDataTableFilePath(const std::string& value);

    /**
    * @brief Setter for m_sizeTableRowStart
    * @param value to replace m_sizeTableRowStart
    */
    void setSizeTableRowStart(const utils::RStatsInteger&  value);

    /**
    * @brief Setter for m_dataTableRowStart
    * @param value to replace m_dataTableRowStart
    */
    void setDataTableRowStart(const utils::RStatsInteger&  value);

    /**
    * @brief Setter for m_universeColumn
    * @param value to replace m_universeColumn
    */
    void setUniverseColumn(const std::string&  value);

    /**
    * @brief Setter for m_sampleColumn
    * @param value to replace m_sampleColumn
    */
    void setSampleColumn(const std::string&  value);

    /**
    * @brief Setter for m_differenceColumn
    * @param value to replace m_differenceColumn
    */
    void setDifferenceColumn(const std::string&  value);

    /**
    * @brief Setter for m_auditColumn
    * @param value to replace m_auditColumn
    */
    void setAuditColumn(const std::string&  value);

    /**
    * @brief Setter for m_examineColumn
    * @param value to replace m_examineColumn
    */
    void setExamineColumn(const std::string&  value);


        /**
    * @brief Getter for m_dataFormat
    * @return Return copy of m_dataFormat
    */
    const utils::RStatsDataFormatType&  getDataFormat() const;

    /**
    * @brief Getter for m_sizeTable
    * @return Return copy of m_sizeTable
    */
    const std::string& getSizeTableFilePath() const;

    /**
    * @brief Getter for m_dataTable
    * @return Return copy of m_dataTable
    */
    const std::string& getDataTableFilePath() const;

    /**
    * @brief Getter for m_sizeTableRowStart
    * @return Return copy of m_sizeTableRowStart
    */
    const utils::RStatsInteger&  getSizeTableRowStart() const;

    /**
    * @brief Getter for m_dataTableRowStart
    * @return Return copy of m_dataTableRowStart
    */
    const utils::RStatsInteger&  getDataTableRowStart() const;

    /**
    * @brief Getter for m_universeColumn
    * @return Return copy of m_universeColumn
    */
    const std::string&  getUniverseColumn() const;

    /**
    * @brief Getter for m_sampleColumn
    * @return Return copy of m_sampleColumn
    */
    const std::string&  getSampleColumn() const;

    /**
    * @brief Getter for m_differenceColumn
    * @return Return copy of m_differenceColumn
    */
    const std::string&  getDifferenceColumn() const;

    /**
    * @brief Getter for m_auditColumn
    * @return Return copy of m_auditColumn
    */
    const std::string&  getAuditColumn() const;

    /**
    * @brief Getter for m_examineColumn
    * @return Return copy of m_examineColumn
    */
    const std::string&  getExamineColumn() const;

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

    /**
     * @brief setSizeTableSheetName
     * @param name
     */
    void setSizeTableSheetName(const std::string& name);

    /**
     * @brief setDataTableSheetName
     * @param name
     */
    void setDataTableSheetName(const std::string& name);

    /**
     * @brief getDataTableSheetName
     * @return
     */
    std::string getDataTableSheetName() const;

    /**
     * @brief getSizeTableSheetName
     * @return
     */
    std::string getSizeTableSheetName() const;

	//! Destructor
	~RStatsSVASessionData();	

private:
    utils::RStatsDataFormatType m_dataFormat;
    std::string m_sizeTableFilePath;
    std::string m_dataTableFilePath;
    utils::RStatsInteger m_sizeTableRowStart;
    utils::RStatsInteger m_dataTableRowStart;
    std::string m_universeColumn;
    std::string m_sampleColumn;
    std::string m_dataTableSheetName;
    std::string m_sizeTableSheetName;
    std::string m_differenceColumn;
    std::string m_auditColumn;
    std::string m_examineColumn;

};
}}}}//end namespace

