/*
    RStatsUVASessionData.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsModuleSessionDataImpl.h"
#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorksheet.h"

namespace oig {
namespace ratstats {
namespace modules {
namespace uva {

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
    * @param Value to replace m_dataFormat
    */
    void setDataFormat(const utils::RStatsDataFormatType & value);

    /**
    * @brief Setter for m_universeSize
    * @param Value to replace m_universeSize
    */
    void setUniverseSize(const utils::RStatsInteger & value);

    /**
    * @brief Setter for m_dataRowStart
    * @param Value to replace m_dataRowStart
    */
    void setDataRowStart(const utils::RStatsInteger & value);

    /**
    * @brief Setter for m_dataTable
    * @param Value to replace m_dataTable
    */
    void setDataTable(const utils::RStatsWorksheet & value);

    /**
    * @brief Setter for m_examineColumn
    * @param Value to replace m_examineColumn
    */
    void setExamineColumn(const std::string & value);

    /**
    * @brief Setter for m_auditColumn
    * @param Value to replace m_auditColumn
    */
    void setAuditColumn(const std::string & value);

    /**
    * @brief Setter for m_differenceColumn
    * @param Value to replace m_differenceColumn
    */
    void setDifferenceColumn(const std::string & value);


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
    * @brief Getter for m_dataRowStart
    * @return Return copy of m_dataRowStart
    */
    const utils::RStatsInteger & getDataRowStart() const;

    /**
    * @brief Getter for m_dataTable
    * @return Return copy of m_dataTable
    */
    const utils::RStatsWorksheet & getDataTable() const;

    /**
    * @brief Getter for m_examineColumn
    * @return Return copy of m_examineColumn
    */
    const std::string & getExamineColumn() const;

    /**
    * @brief Getter for m_auditColumn
    * @return Return copy of m_auditColumn
    */
    const std::string & getAuditColumn() const;

    /**
    * @brief Getter for m_differenceColumn
    * @return Return copy of m_differenceColumn
    */
    const std::string & getDifferenceColumn() const;

    std::string getType() const;

	//! Destructor
	~RStatsUVASessionData();	

private:
    utils::RStatsDataFormatType m_dataFormat;
    utils::RStatsInteger m_universeSize;
    utils::RStatsInteger m_dataRowStart;
    utils::RStatsWorksheet m_dataTable;
    std::string m_examineColumn;
    std::string m_auditColumn;
    std::string m_differenceColumn;

};
}}}}//end namespace

