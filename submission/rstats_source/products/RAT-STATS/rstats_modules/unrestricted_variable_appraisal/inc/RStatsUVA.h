/*
    RStatsUVA.h    
*/

#pragma once

#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorkbook.h"

namespace oig {
namespace ratstats {
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
    oig::ratstats::utils::RStatsInteger populationSize;
    oig::ratstats::utils::RStatsInteger sampleSize;
    oig::ratstats::utils::RStatsInteger nonZeroSize;
    oig::ratstats::utils::RStatsFloat mean;
    oig::ratstats::utils::RStatsFloat standardDeviation;
    oig::ratstats::utils::RStatsFloat standardErrorMean;
    oig::ratstats::utils::RStatsInteger standardErrorTotal;
    oig::ratstats::utils::RStatsInteger pointEstimate;
    oig::ratstats::utils::RStatsFloat lower80;
    oig::ratstats::utils::RStatsFloat lower90;
    oig::ratstats::utils::RStatsFloat lower95;
    oig::ratstats::utils::RStatsFloat upper80;
    oig::ratstats::utils::RStatsFloat upper90;
    oig::ratstats::utils::RStatsFloat upper95;
    oig::ratstats::utils::RStatsFloat kurtosis;
    oig::ratstats::utils::RStatsFloat skewness;
    oig::ratstats::utils::RStatsFloat precisionAmount80;
    oig::ratstats::utils::RStatsFloat precisionAmount90;
    oig::ratstats::utils::RStatsFloat precisionAmount95;
    oig::ratstats::utils::RStatsFloat precisionPercent80;
    oig::ratstats::utils::RStatsFloat precisionPercent90;
    oig::ratstats::utils::RStatsFloat precisionPercent95;
    oig::ratstats::utils::RStatsFloat tValue80;
    oig::ratstats::utils::RStatsFloat tValue90;
    oig::ratstats::utils::RStatsFloat tValue95;
    oig::ratstats::utils::RStatsFloat totalAmount;

};

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
     * @param dataSheetInput Datasheet containing all the values
     * @param dfIndex Structure that contains column information for the sheet as well as data output format
     */
    void execute(const std::string& auditName,
                 size_t universeSize,
                 const oig::ratstats::utils::RStatsWorksheet& dataSheetInput,
                 size_t dataSheetRowOffset,
                 const oig::ratstats::utils::RStatsDataFormatTypeIndex& dataSheetDatasetColumnTypeIndex);

    /**
     * @brief saveToWorksheet This function saves each data output structure to a worksheet
     * @param worksheet The worksheet to write to
     */
    void saveToWorkbook(oig::ratstats::utils::RStatsWorkbook& workbook);


	//! Destructor
	~RStatsUVA();	

private:      


    std::vector<RStatsUVAOutputData> m_outputDataList;
    std::string m_auditName;
    oig::ratstats::utils::RStatsFloat m_currentProbability;
    oig::ratstats::utils::RStatsFloat m_currentLowProbability;
    oig::ratstats::utils::RStatsFloat m_currentHighProbability;
    oig::ratstats::utils::RStatsFloat m_currentLowValue;
    oig::ratstats::utils::RStatsFloat m_currentHighValue;
    oig::ratstats::utils::RStatsFloat m_currentDOF;
    oig::ratstats::utils::RStatsFloat m_cumalativeProbability;
    oig::ratstats::utils::RStatsFloat m_tValue;
    oig::ratstats::utils::RStatsFloat m_xValue;
    oig::ratstats::utils::RStatsFloat m_lastTValue;
    oig::ratstats::utils::RStatsFloat m_temporary80;
    oig::ratstats::utils::RStatsFloat m_temporary90;
    oig::ratstats::utils::RStatsFloat m_temporary95;
    oig::ratstats::utils::RStatsFloat m_formulaC0;
    oig::ratstats::utils::RStatsFloat m_formulaPI;
    oig::ratstats::utils::RStatsFloat m_formulaB;
    oig::ratstats::utils::RStatsFloat m_formulaA;
    oig::ratstats::utils::RStatsFloat m_eps;
    oig::ratstats::utils::RStatsFloat m_sefin;
    oig::ratstats::utils::RStatsFloat m_front;
    oig::ratstats::utils::RStatsFloat m_temporaryValue;
    oig::ratstats::utils::RStatsInteger m_conditionalUsage;
    oig::ratstats::utils::RStatsInteger m_conditionalCounter;
    oig::ratstats::utils::RStatsInteger m_totalNumberOfTerms;    
    oig::ratstats::utils::RStatsInteger m_conditionalIterator;
    oig::ratstats::utils::RStatsInteger m_sampleSize;
    oig::ratstats::utils::RStatsInteger m_universeSize;
    oig::ratstats::utils::RStatsInteger m_totalNumberOfConditionalIterations;
    oig::ratstats::utils::RStatsFloatList m_kurtosis;
    oig::ratstats::utils::RStatsFloatList m_means;
    oig::ratstats::utils::RStatsFloatList m_pointEstimates;
    oig::ratstats::utils::RStatsFloatList m_standardError;
    oig::ratstats::utils::RStatsFloatList m_standardDeviation;
    oig::ratstats::utils::RStatsFloatList m_skewAmount;
    oig::ratstats::utils::RStatsFloatList m_precision80;
    oig::ratstats::utils::RStatsFloatList m_precision90;
    oig::ratstats::utils::RStatsFloatList m_precision95;
    oig::ratstats::utils::RStatsIntegerList m_nonZeroCount;
    oig::ratstats::utils::RStatsFloatList m_upper80;
    oig::ratstats::utils::RStatsFloatList m_upper90;
    oig::ratstats::utils::RStatsFloatList m_upper95;
    oig::ratstats::utils::RStatsFloatList m_lower80;
    oig::ratstats::utils::RStatsFloatList m_lower90;
    oig::ratstats::utils::RStatsFloatList m_lower95;
    oig::ratstats::utils::RStatsFloatList m_tValue80;
    oig::ratstats::utils::RStatsFloatList m_tValue90;
    oig::ratstats::utils::RStatsFloatList m_tValue95;
    oig::ratstats::utils::RStatsFloatList m_totalPointEstimates;
    oig::ratstats::utils::RStatsFloatList m_totalStandardError;
    oig::ratstats::utils::RStatsFloatList m_totalStandardDeviation;
    oig::ratstats::utils::RStatsFloatList m_totalAmount;
    oig::ratstats::utils::RStatsFloatList m_totalPowerOfTwoAmount;
    oig::ratstats::utils::RStatsFloatList m_totalPowerOfThreeAmount;
    oig::ratstats::utils::RStatsFloatList m_totalPowerOfFourAmount;
    oig::ratstats::utils::RStatsFloatList m_totalNonZeroCount;


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
    void execute(const oig::ratstats::utils::RStatsFloatList& values,
                 size_t sampleSize,
                 size_t universeSize,
                 oig::ratstats::utils::RStatsDataFormatType type);


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

};
}}}}//end namespace


