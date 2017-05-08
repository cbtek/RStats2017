/*
    RStatsUAA.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorksheet.h"

namespace oig {
namespace ratstats {
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
    oig::ratstats::utils::RStatsInteger universeSize;
    oig::ratstats::utils::RStatsInteger sampleSize;
    oig::ratstats::utils::RStatsInteger coiSize;
    oig::ratstats::utils::RStatsFloat projectedTotal;
    oig::ratstats::utils::RStatsFloat projectedTotalPercent;
    oig::ratstats::utils::RStatsFloat variance;
    oig::ratstats::utils::RStatsFloat standardError;
    oig::ratstats::utils::RStatsFloat standardErrorPercent;
    oig::ratstats::utils::RStatsFloatList upperLimitPercentList;
    oig::ratstats::utils::RStatsFloatList lowerLimitQuantityList;
    oig::ratstats::utils::RStatsFloatList upperLimitQuantityList;
    oig::ratstats::utils::RStatsFloatList lowerLimitPercentList;
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
    void saveToWorksheet(oig::ratstats::utils::RStatsWorksheet& worksheetOut);

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
    oig::ratstats::utils::RStatsInteger m_numCompare;
    oig::ratstats::utils::RStatsInteger m_coiSize;
    oig::ratstats::utils::RStatsInteger m_numExponents;
    oig::ratstats::utils::RStatsInteger m_sampleSize;
    oig::ratstats::utils::RStatsInteger m_numItems;
    oig::ratstats::utils::RStatsInteger m_numItemsInSample;
    oig::ratstats::utils::RStatsInteger m_conditionLevel;
    oig::ratstats::utils::RStatsInteger m_iter;
    oig::ratstats::utils::RStatsInteger m_universeSize;
    oig::ratstats::utils::RStatsInteger m_kOld;
    oig::ratstats::utils::RStatsInteger m_kUpper;
    oig::ratstats::utils::RStatsInteger m_kSt;
    oig::ratstats::utils::RStatsInteger m_kAdd;
    oig::ratstats::utils::RStatsInteger m_k;
    oig::ratstats::utils::RStatsInteger m_kBottom;
    oig::ratstats::utils::RStatsInteger m_kSub;
    oig::ratstats::utils::RStatsInteger m_kLower;
    oig::ratstats::utils::RStatsInteger m_kTop;
    oig::ratstats::utils::RStatsInteger m_lower80;
    oig::ratstats::utils::RStatsInteger m_lower90;
    oig::ratstats::utils::RStatsInteger m_lower95;
    oig::ratstats::utils::RStatsInteger m_upper80;
    oig::ratstats::utils::RStatsInteger m_upper90;
    oig::ratstats::utils::RStatsInteger m_upper95;
    oig::ratstats::utils::RStatsInteger m_minBad;
    oig::ratstats::utils::RStatsInteger m_popGood;
    oig::ratstats::utils::RStatsInteger m_pb;
    oig::ratstats::utils::RStatsInteger m_pg;
    oig::ratstats::utils::RStatsInteger m_ss;
    oig::ratstats::utils::RStatsInteger m_sb;    

    oig::ratstats::utils::RStatsFloat m_phat;
    oig::ratstats::utils::RStatsFloat m_term;
    oig::ratstats::utils::RStatsFloat m_max;
    oig::ratstats::utils::RStatsFloat m_min;
    oig::ratstats::utils::RStatsFloat m_ratio;
    oig::ratstats::utils::RStatsFloat m_zValue;
    oig::ratstats::utils::RStatsFloat m_tail;
    oig::ratstats::utils::RStatsFloat m_cumalativeProbability;
    oig::ratstats::utils::RStatsFloat m_sSum;
    oig::ratstats::utils::RStatsFloat m_sumNew;
    oig::ratstats::utils::RStatsFloat m_z;

    bool m_isFinished;
    RStatsUAAOutputData m_outputData;

};
}}}}//end namespace

