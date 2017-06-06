/*
    RStatsUAA.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorksheet.h"

namespace cbtek {
namespace rocketstats {
namespace modules {
namespace uaa {

/**
 * @brief The RStatsUAAConfidenceIntervalType enum
 */
enum class RStatsUAAConfidenceIntervalType
{
    OneSidedUpper,
    OneSidedLower,
    TwoSided
};

/**
 * @brief The RStatsUAAOutputData struct represents the output produced
 * by the unrestricted attribute appraisal function
 */
struct RStatsUAAOutputData
{
    RStatsUAAOutputData()
    {
        universeSize = 0;
        sampleSize = 0;
        coiSize = 0;
        projectedTotal = 0;
        projectedTotalPercent = 0;
        variance = 0;
        standardError = 0;
        standardErrorPercent = 0;
        upperLimitPercentList.initialize(3);
        lowerLimitQuantityList.initialize(3);
        upperLimitQuantityList.initialize(3);
        lowerLimitPercentList.initialize(3);
    }
    cbtek::common::utility::DateEntity createDate;
    cbtek::common::utility::TimeEntity createTime;
    std::string auditName;
    RStatsUAAConfidenceIntervalType confidenceIntervalType;
    cbtek::rocketstats::utils::RStatsInteger universeSize;
    cbtek::rocketstats::utils::RStatsInteger sampleSize;
    cbtek::rocketstats::utils::RStatsInteger coiSize;
    cbtek::rocketstats::utils::RStatsFloat projectedTotal;
    cbtek::rocketstats::utils::RStatsFloat projectedTotalPercent;
    cbtek::rocketstats::utils::RStatsFloat variance;
    cbtek::rocketstats::utils::RStatsFloat standardError;
    cbtek::rocketstats::utils::RStatsFloat standardErrorPercent;
    cbtek::rocketstats::utils::RStatsFloatList upperLimitPercentList;
    cbtek::rocketstats::utils::RStatsFloatList lowerLimitQuantityList;
    cbtek::rocketstats::utils::RStatsFloatList upperLimitQuantityList;
    cbtek::rocketstats::utils::RStatsFloatList lowerLimitPercentList;
};

/**
 * @brief The RStatsUAA class represents the unrestricted attribute appraisal
 * function. In the model-view-controller paradigm, this class represents the
 * controller.
 */
class RStatsUAA 
{
public:
	//! Constructor for RStatsUAA
	/*!
		Detailed description for RStatsUAA
	*/
	RStatsUAA();
      	
    /**
     * @brief execute This function executes the main unrestricted
     * attribute appraisal function
     * @param auditName The name of the audit
     * @param sampleSize The input sample size
     * @param universeSize The input universe size
     * @param coiSize The characteristic of interest count
     * @param type The data format type
     * @return
     */
    RStatsUAAOutputData execute(const std::string& auditName,
                                utils::RStatsInteger sampleSize,
                                utils::RStatsInteger universeSize,
                                utils::RStatsInteger coiSize,
                                RStatsUAAConfidenceIntervalType type=RStatsUAAConfidenceIntervalType::TwoSided);

    /**
     * @brief saveToCSVWorksheetFile Saves output result to CSV file
     * @param filePath
     */
    void saveToCSVFile(const std::string& filePath);

    /**
     * @brief saveToWorksheet Saves output results to worksheet object
     * @param worksheetOut The worksheet to save to
     */
    void saveToWorksheet(cbtek::rocketstats::utils::RStatsWorksheet& worksheetOut);

    /**
     * @brief saveToTextFile Saves output result to text file
     * @param filePath
     */
    void saveToTextFile(const std::string& filePath);

	//! Destructor
	~RStatsUAA();	

private:

    /**
     * @brief processResults Processes the results per iteration
     */
    void processResults();

    /**
     * @brief processSumHypergeometric Finds the hypergeometric sum
     */
    void processSumHypergeometric();


    /**
     * The following functions are used for finding
     * the upper and lower limits
     */
    void processFindLower();
    void processFindUpper();
    void processFindBottomUpper();
    void processFindBottomLower();
    void processCloseInUpper();
    void processCloseInLower();
    void processFinalUpper();
    void processFinalLower();

    /**
     * @brief reset Resets the data structures used
     */
    void reset();

    /**
     * @brief start
     */
    void start();

    RStatsUAAConfidenceIntervalType m_confidenceIntervalType;
    cbtek::rocketstats::utils::RStatsInteger m_numCompare;
    cbtek::rocketstats::utils::RStatsInteger m_coiSize;
    cbtek::rocketstats::utils::RStatsInteger m_numExponents;
    cbtek::rocketstats::utils::RStatsInteger m_sampleSize;
    cbtek::rocketstats::utils::RStatsInteger m_numItems;
    cbtek::rocketstats::utils::RStatsInteger m_numItemsInSample;
    cbtek::rocketstats::utils::RStatsInteger m_conditionLevel;
    cbtek::rocketstats::utils::RStatsInteger m_iter;
    cbtek::rocketstats::utils::RStatsInteger m_universeSize;
    cbtek::rocketstats::utils::RStatsInteger m_kOld;
    cbtek::rocketstats::utils::RStatsInteger m_kUpper;
    cbtek::rocketstats::utils::RStatsInteger m_kSt;
    cbtek::rocketstats::utils::RStatsInteger m_kAdd;
    cbtek::rocketstats::utils::RStatsInteger m_k;
    cbtek::rocketstats::utils::RStatsInteger m_kBottom;
    cbtek::rocketstats::utils::RStatsInteger m_kSub;
    cbtek::rocketstats::utils::RStatsInteger m_kLower;
    cbtek::rocketstats::utils::RStatsInteger m_kTop;
    cbtek::rocketstats::utils::RStatsInteger m_lower80;
    cbtek::rocketstats::utils::RStatsInteger m_lower90;
    cbtek::rocketstats::utils::RStatsInteger m_lower95;
    cbtek::rocketstats::utils::RStatsInteger m_upper80;
    cbtek::rocketstats::utils::RStatsInteger m_upper90;
    cbtek::rocketstats::utils::RStatsInteger m_upper95;
    cbtek::rocketstats::utils::RStatsInteger m_minBad;
    cbtek::rocketstats::utils::RStatsInteger m_popGood;
    cbtek::rocketstats::utils::RStatsInteger m_pb;
    cbtek::rocketstats::utils::RStatsInteger m_pg;
    cbtek::rocketstats::utils::RStatsInteger m_ss;
    cbtek::rocketstats::utils::RStatsInteger m_sb;    

    cbtek::rocketstats::utils::RStatsFloat m_phat;
    cbtek::rocketstats::utils::RStatsFloat m_term;
    cbtek::rocketstats::utils::RStatsFloat m_max;
    cbtek::rocketstats::utils::RStatsFloat m_min;
    cbtek::rocketstats::utils::RStatsFloat m_ratio;
    cbtek::rocketstats::utils::RStatsFloat m_zValue;
    cbtek::rocketstats::utils::RStatsFloat m_tail;
    cbtek::rocketstats::utils::RStatsFloat m_cumalativeProbability;
    cbtek::rocketstats::utils::RStatsFloat m_sSum;
    cbtek::rocketstats::utils::RStatsFloat m_sumNew;
    cbtek::rocketstats::utils::RStatsFloat m_z;

    bool m_isFinished;
    RStatsUAAOutputData m_outputData;

};
}}}}//end namespace

