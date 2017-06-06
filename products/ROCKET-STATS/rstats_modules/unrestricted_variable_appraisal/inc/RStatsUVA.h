/*
    RStatsUVA.h    
*/

#pragma once

#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorkbook.h"

namespace cbtek {
namespace rocketstats {
namespace modules {
namespace uva {

/**
 * @brief The RStatsUVAOutputData struct
 * This structure holds data for an single instance of output
 * It is primarly used to populate the worksheet for saving
 */
struct RStatsUVAOutputData
{
    std::string title;
    cbtek::rocketstats::utils::RStatsInteger populationSize;
    cbtek::rocketstats::utils::RStatsInteger sampleSize;
    cbtek::rocketstats::utils::RStatsInteger nonZeroSize;
    cbtek::rocketstats::utils::RStatsFloat mean;
    cbtek::rocketstats::utils::RStatsFloat standardDeviation;
    cbtek::rocketstats::utils::RStatsFloat standardErrorMean;
    cbtek::rocketstats::utils::RStatsInteger standardErrorTotal;
    cbtek::rocketstats::utils::RStatsInteger pointEstimate;
    cbtek::rocketstats::utils::RStatsFloat lower80;
    cbtek::rocketstats::utils::RStatsFloat lower90;
    cbtek::rocketstats::utils::RStatsFloat lower95;
    cbtek::rocketstats::utils::RStatsFloat upper80;
    cbtek::rocketstats::utils::RStatsFloat upper90;
    cbtek::rocketstats::utils::RStatsFloat upper95;
    cbtek::rocketstats::utils::RStatsFloat kurtosis;
    cbtek::rocketstats::utils::RStatsFloat skewness;
    cbtek::rocketstats::utils::RStatsFloat precisionAmount80;
    cbtek::rocketstats::utils::RStatsFloat precisionAmount90;
    cbtek::rocketstats::utils::RStatsFloat precisionAmount95;
    cbtek::rocketstats::utils::RStatsFloat precisionPercent80;
    cbtek::rocketstats::utils::RStatsFloat precisionPercent90;
    cbtek::rocketstats::utils::RStatsFloat precisionPercent95;
    cbtek::rocketstats::utils::RStatsFloat tValue80;
    cbtek::rocketstats::utils::RStatsFloat tValue90;
    cbtek::rocketstats::utils::RStatsFloat tValue95;
    cbtek::rocketstats::utils::RStatsFloat totalAmount;

};

/**
 * @brief The RStatsUVA class represents the unrestricted variable appraisal
 * function. In the model-view-controller paradigm, this class represents the
 * controller.
 */
class RStatsUVA 
{

public:
	//! Constructor for RStatsUVA
	/*!
		Detailed description for RStatsUVA
	*/
    RStatsUVA();

    /**
     * @brief execute This function executes the unrestricted variable appraisal algorithm
     * @param auditName Name of the audit
     * @param universeSize Universe/Population size
     * @param dataSheetInput Datasheet containing all the values
     * @param dataSheetRowOffset Starting row for the data
     * @param dataSheetDatasetColumnTypeIndex Structure that contains column information for the sheet as well as data output format
     */
    void execute(const std::string& auditName,
                 size_t universeSize,
                 const cbtek::rocketstats::utils::RStatsWorksheet& dataSheetInput,
                 size_t dataSheetRowOffset,
                 const cbtek::rocketstats::utils::RStatsDataFormatTypeIndex& dataSheetDatasetColumnTypeIndex);

    /**
     * @brief saveToWorkbook This function saves all data output into a
     * workbook structure
     * @param workbook The workbook to write to
     */
    void saveToWorkbook(cbtek::rocketstats::utils::RStatsWorkbook& workbook);


	//! Destructor
	~RStatsUVA();	

private:      

    /**
     * @brief createOutputData This function is called after main processing to build the output data
     * @param title Name of the output data format (e.g. Audit, Examine, Difference)
     * @param index The index of the output data format
     */
    void createOutputData(const std::string& title,size_t index);

    /**
     * @brief execute This function performs primary algorithm for unrestricted variable appraisal
     * @param values Array containing all the values read from worksheet
     * @param sampleSize Total size of the sample
     * @param universeSize Total size of the universe
     * @param type The data format type
     */
    void execute(const cbtek::rocketstats::utils::RStatsFloatList& values,
                 size_t sampleSize,
                 size_t universeSize,
                 cbtek::rocketstats::utils::RStatsDataFormatType type);


    /**
     * @brief calculateMeans Calculates the mean value
     */
    void calculateMeans();

    /**
     * @brief calculatePointEstimates Calculates the point estimate
     */
    void calculatePointEstimates();

    /**
     * @brief calculateCorrectionFactor Calculates the correction factor
     */
    void calculateCorrectionFactor();

    /**
     * @brief calculateDegreesOfFreedom Calculates degrees of freedom
     */
    void calculateDegreesOfFreedom();

    /**
     * @brief calculateStandardDeviation Calculates standard deviation
     */
    void calculateStandardDeviation();

    /**
     * @brief calculateUpperAndLowerLimits Calculates Upper and Lower limits
     */
    void calculateUpperAndLowerLimits();

    /**
     * @brief calculateKurtosis
     * @param inputData
     */
    void calculateKurtosis();

    /**
     * @brief calculateOverallPrecision Calculates Overall precision
     */
    void calculateOverallPrecision();

    /**
     * @brief calculateStandardError Calculates Standard Error
     */
    void calculateStandardError();

    /**
     * @brief calculateSkewness Calculates the Skewness
     */
    void calculateSkewness();

    /**
     * @brief processSamplingError Begin processing the sampling error
     */
    void processSamplingError();

    /**
     * @brief processFindIntervals Begin processing the intervals
     */
    void processFindIntervals();

    /**
     * @brief processSetup Begin primary processing
     */
    void processSetup();

    /**
     * @brief processConditionalLoop Begin processing the conditional loop
     */
    void processConditionalLoop();

    /**
     * @brief processStartLoop
     */
    void processStartLoop();

    /**
     * @brief processFindCumaltiveProbability
     */
    void processFindCumaltiveProbability();

    /**
     * @brief processFindCurrentProbability
     */
    void processFindCurrentProbability();

    /**
     * @brief processFindTerms
     */
    void processFindTerms();

    /**
     * @brief reset
     */
    void reset();

    std::vector<RStatsUVAOutputData> m_outputDataList;
    std::string m_auditName;
    cbtek::rocketstats::utils::RStatsFloat m_currentProbability;
    cbtek::rocketstats::utils::RStatsFloat m_currentLowProbability;
    cbtek::rocketstats::utils::RStatsFloat m_currentHighProbability;
    cbtek::rocketstats::utils::RStatsFloat m_currentLowValue;
    cbtek::rocketstats::utils::RStatsFloat m_currentHighValue;
    cbtek::rocketstats::utils::RStatsFloat m_currentDOF;
    cbtek::rocketstats::utils::RStatsFloat m_cumalativeProbability;
    cbtek::rocketstats::utils::RStatsFloat m_tValue;
    cbtek::rocketstats::utils::RStatsFloat m_xValue;
    cbtek::rocketstats::utils::RStatsFloat m_lastTValue;
    cbtek::rocketstats::utils::RStatsFloat m_temporary80;
    cbtek::rocketstats::utils::RStatsFloat m_temporary90;
    cbtek::rocketstats::utils::RStatsFloat m_temporary95;
    cbtek::rocketstats::utils::RStatsFloat m_formulaC0;
    cbtek::rocketstats::utils::RStatsFloat m_formulaPI;
    cbtek::rocketstats::utils::RStatsFloat m_formulaB;
    cbtek::rocketstats::utils::RStatsFloat m_formulaA;
    cbtek::rocketstats::utils::RStatsFloat m_eps;
    cbtek::rocketstats::utils::RStatsFloat m_sefin;
    cbtek::rocketstats::utils::RStatsFloat m_front;
    cbtek::rocketstats::utils::RStatsFloat m_temporaryValue;
    cbtek::rocketstats::utils::RStatsInteger m_conditionalUsage;
    cbtek::rocketstats::utils::RStatsInteger m_conditionalCounter;
    cbtek::rocketstats::utils::RStatsInteger m_totalNumberOfTerms;
    cbtek::rocketstats::utils::RStatsInteger m_conditionalIterator;
    cbtek::rocketstats::utils::RStatsInteger m_sampleSize;
    cbtek::rocketstats::utils::RStatsInteger m_universeSize;
    cbtek::rocketstats::utils::RStatsInteger m_totalNumberOfConditionalIterations;
    cbtek::rocketstats::utils::RStatsFloatList m_kurtosis;
    cbtek::rocketstats::utils::RStatsFloatList m_means;
    cbtek::rocketstats::utils::RStatsFloatList m_pointEstimates;
    cbtek::rocketstats::utils::RStatsFloatList m_standardError;
    cbtek::rocketstats::utils::RStatsFloatList m_standardDeviation;
    cbtek::rocketstats::utils::RStatsFloatList m_skewAmount;
    cbtek::rocketstats::utils::RStatsFloatList m_precision80;
    cbtek::rocketstats::utils::RStatsFloatList m_precision90;
    cbtek::rocketstats::utils::RStatsFloatList m_precision95;
    cbtek::rocketstats::utils::RStatsIntegerList m_nonZeroCount;
    cbtek::rocketstats::utils::RStatsFloatList m_upper80;
    cbtek::rocketstats::utils::RStatsFloatList m_upper90;
    cbtek::rocketstats::utils::RStatsFloatList m_upper95;
    cbtek::rocketstats::utils::RStatsFloatList m_lower80;
    cbtek::rocketstats::utils::RStatsFloatList m_lower90;
    cbtek::rocketstats::utils::RStatsFloatList m_lower95;
    cbtek::rocketstats::utils::RStatsFloatList m_tValue80;
    cbtek::rocketstats::utils::RStatsFloatList m_tValue90;
    cbtek::rocketstats::utils::RStatsFloatList m_tValue95;
    cbtek::rocketstats::utils::RStatsFloatList m_totalPointEstimates;
    cbtek::rocketstats::utils::RStatsFloatList m_totalStandardError;
    cbtek::rocketstats::utils::RStatsFloatList m_totalStandardDeviation;
    cbtek::rocketstats::utils::RStatsFloatList m_totalAmount;
    cbtek::rocketstats::utils::RStatsFloatList m_totalPowerOfTwoAmount;
    cbtek::rocketstats::utils::RStatsFloatList m_totalPowerOfThreeAmount;
    cbtek::rocketstats::utils::RStatsFloatList m_totalPowerOfFourAmount;
    cbtek::rocketstats::utils::RStatsFloatList m_totalNonZeroCount;

};
}}}}//end namespace


