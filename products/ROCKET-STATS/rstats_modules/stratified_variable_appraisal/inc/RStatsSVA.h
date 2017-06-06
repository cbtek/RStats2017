/*
    RStatsSVA.h
    

*/

#pragma once

#include <vector>
#include "rstats_utils/inc/RStatsObjectList.hpp"
#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorkbook.h"

namespace cbtek {
namespace rocketstats {
namespace modules {
namespace sva {


/**
 * @brief The RStatsSVAInputData struct represents the input data
 * to the SVA function
 */
struct RStatsSVAInputData
{
    cbtek::rocketstats::utils::RStatsInteger sampleSize;
    cbtek::rocketstats::utils::RStatsInteger universeSize;
    cbtek::rocketstats::utils::RStatsInteger interestSize;
    cbtek::rocketstats::utils::RStatsFloatList samples;
    cbtek::rocketstats::utils::RStatsDataFormatTypeIndex typeIndex;
    cbtek::rocketstats::utils::RStatsInteger count;
    cbtek::rocketstats::utils::RStatsInteger offset;
};

/**
 * @brief The RStatsSVAOutputData struct represents the output data
 * for the SVA function
 */
struct RStatsSVAOutputData
{
    std::string typeName;
    cbtek::rocketstats::utils::RStatsDataFormatType type;
    bool isDisplaySummary;
    bool isValid;
    cbtek::common::utility::DateEntity createDate;
    cbtek::common::utility::TimeEntity createTime;
    std::string auditName;
    cbtek::rocketstats::utils::RStatsInteger populationSize;
    cbtek::rocketstats::utils::RStatsInteger sampleSize;
    cbtek::rocketstats::utils::RStatsInteger nonZeroCount;
    cbtek::rocketstats::utils::RStatsFloat mean;
    cbtek::rocketstats::utils::RStatsFloat totalSum;
    cbtek::rocketstats::utils::RStatsFloat standardDeviation;
    cbtek::rocketstats::utils::RStatsFloat skewness;
    cbtek::rocketstats::utils::RStatsFloat standardErrorMean;
    cbtek::rocketstats::utils::RStatsFloat standardErrorTotal;
    cbtek::rocketstats::utils::RStatsFloat kurtosis;
    cbtek::rocketstats::utils::RStatsFloat pointEstimate;
    cbtek::rocketstats::utils::RStatsFloat lower80;
    cbtek::rocketstats::utils::RStatsFloat lower90;
    cbtek::rocketstats::utils::RStatsFloat lower95;
    cbtek::rocketstats::utils::RStatsFloat upper80;
    cbtek::rocketstats::utils::RStatsFloat upper90;
    cbtek::rocketstats::utils::RStatsFloat upper95;
    cbtek::rocketstats::utils::RStatsFloat precisionAmount80;
    cbtek::rocketstats::utils::RStatsFloat precisionAmount90;
    cbtek::rocketstats::utils::RStatsFloat precisionAmount95;
    cbtek::rocketstats::utils::RStatsFloat tValue80;
    cbtek::rocketstats::utils::RStatsFloat tValue90;
    cbtek::rocketstats::utils::RStatsFloat tValue95;
    cbtek::rocketstats::utils::RStatsFloat precisionPercent80;
    cbtek::rocketstats::utils::RStatsFloat precisionPercent90;
    cbtek::rocketstats::utils::RStatsFloat precisionPercent95;    
    RStatsSVAOutputData()
    {
        this->isDisplaySummary = false;
        this->isValid = false;
    }
};

/**
 * @brief The RStatsSVAOutputDataTriplet struct
 */
struct RStatsSVAOutputDataTriplet
{
    RStatsSVAOutputData audit,examine,difference;
};

typedef std::vector<RStatsSVAOutputDataTriplet> RStatsSVAOutputDataList;
typedef std::vector<RStatsSVAInputData> RStatsSVAInputDataList;
typedef cbtek::rocketstats::utils::RStatsObjectList<int> RStatsSVAFlagList;

/**
 * @brief The RStatsSVA class represents the stratified variable appraisal
 * function. In the model-view-controller paradigm, this class represents the
 * controller.
 */
class RStatsSVA 
{

public:
	//! Constructor for RStatsSVA
	/*!
		Detailed description for RStatsSVA
	*/
	RStatsSVA();    

    /**
     * @brief execute
     * @param sizeSheet
     * @param inputSheet
     * @param dataFormatType
     * @return
     */
    RStatsSVAOutputDataList execute(const std::string &auditName, const cbtek::rocketstats::utils::RStatsWorksheet& dataSheet,
                                    const cbtek::rocketstats::utils::RStatsWorksheet& sizeSheet,
                                    const utils::RStatsDataFormatTypeIndex &dataSheetIndex,
                                    size_t dataSheetRowStart,
                                    size_t sizeSheetSampleSizeColumn,
                                    size_t sizeSheetUniverseSizeColumn,
                                    size_t sizeSheetRowStart);

    /**
     * @brief saveToWorkbook
     * @param outputList
     * @param workbookOut
     */
    void saveToWorkbook(cbtek::rocketstats::utils::RStatsWorkbook& workbookOut);


	//! Destructor
	~RStatsSVA();	

private:


    /**
     * @brief execute
     * @param dataFormatType
     * @param strataDataList
     * @return
     */
    RStatsSVAInputDataList buildInputDataList(const cbtek::rocketstats::utils::RStatsWorksheet& dataSheet,
                                              const cbtek::rocketstats::utils::RStatsWorksheet& sizeSheet,
                                              const utils::RStatsDataFormatTypeIndex &dataSheetIndex,
                                              size_t dataSheetRowStart,
                                              size_t sizeSheetSampleSizeColumn,
                                              size_t sizeSheetUniverseSizeColumn,
                                              size_t sizeSheetRowStart);

    /**
     * @brief onReset
     */
    void onReset();

    /**
     * @brief onUpdateSums
     * @param auditValues
     * @param examValues
     * @param differenceValues
     */
    void onUpdateSums(const cbtek::rocketstats::utils::RStatsFloatList &auditValues,
                      const cbtek::rocketstats::utils::RStatsFloatList &examValues,
                      const cbtek::rocketstats::utils::RStatsFloatList &differenceValues);

    /**
     * @brief initializeDataTypeFormat
     * @param data
     */
    void initializeDataTypeFormat(cbtek::rocketstats::utils::RStatsDataFormatType dataTypeFormat,
                                  const RStatsSVAInputData &data);

    /**
     * @brief calculateMean
     * @param data
     */
    void calculateMean(const RStatsSVAInputData& data);

    /**
     * @brief calculateStandardDeviation
     * @param data
     */
    void calculateStandardDeviation(const RStatsSVAInputData& data);

    /**
     * @brief calculateStandardError
     * @param data
     */
    void calculateStandardError(const RStatsSVAInputData& data);

    /**
     * @brief calculateCorrectionFactors
     * @param data
     */
    void calculateCorrectionFactors(const RStatsSVAInputData& data);

    /**
     * @brief calculateDegreesOfFreedom
     * @param data
     */
    void calculateDegreesOfFreedom(const RStatsSVAInputData& data);

    /**
     * @brief calculatePointEstimates
     * @param data
     */
    void calculatePointEstimates(const RStatsSVAInputData& data);

    /**
     * @brief calculateUpperAndLowerLimits
     * @param data
     */
    void calculateUpperAndLowerLimits(const RStatsSVAInputData& data);

    /**
     * @brief calculateSkewness
     * @param data
     */
    void calculateSkewness(const RStatsSVAInputData& data);

    /**
     * @brief calculateKurtosis
     * @param data
     */
    void calculateKurtosis(const RStatsSVAInputData& data);

    /**
     * @brief calculateSamplingError
     * @param data
     */
    void calculateSamplingError(const RStatsSVAInputData& data);

    /**
     * @brief calculateIntervals
     * @param data
     */
    void calculateIntervals(const RStatsSVAInputData &data);

    /**
     * @brief calculateOverallPrecision
     * @param data
     */
    void calculateOverallPrecision();

    /**
     * @brief processSamplingError
     */
    void processSamplingError(const RStatsSVAInputData& data);

    /**
     * @brief tVarConLoop
     */
    void processConditionLoop(const RStatsSVAInputData& data);

    /**
     * @brief tVarStartLoop
     */
    void processStartLoop(const RStatsSVAInputData& data);

    /**
     * @brief tVarFindCumProb
     */
    void processFindCumProb(const RStatsSVAInputData& data);

    /**
     * @brief tVarFindTerms
     */
    void processFindTerms(const RStatsSVAInputData& data);

    /**
     * @brief tVarFindProbVal
     * @param tempValue
     */
    void processFindProbVal(cbtek::rocketstats::utils::RStatsFloat tempValue);

    /**
     * @brief processSummaryTotals
     * @param data
     */
    void processSummaryTotals(RStatsSVAOutputData &summary, size_t index);



    void buildOutputData(RStatsSVAOutputDataList &outputDataList,
                         const RStatsSVAInputData& inputData,
                         cbtek::rocketstats::utils::RStatsDataFormatType type);

    void copyOutputData(RStatsSVAOutputData& outputData,
                        const RStatsSVAInputData& inputData,
                        cbtek::rocketstats::utils::RStatsDataFormatType type,
                        size_t dataFormatIndex);


    void saveOutputDataToWorksheet(const RStatsSVAOutputData& data, cbtek::rocketstats::utils::RStatsWorksheet& sheet);

    std::string m_auditName;
    cbtek::rocketstats::utils::RStatsInteger m_auditZeroCount;
    cbtek::rocketstats::utils::RStatsInteger m_conditionCount;    
    cbtek::rocketstats::utils::RStatsInteger m_currentIteration;
    cbtek::rocketstats::utils::RStatsInteger m_differenceZeroCount;
    cbtek::rocketstats::utils::RStatsInteger m_examineZeroCount;
    cbtek::rocketstats::utils::RStatsInteger m_maxIterations;
    cbtek::rocketstats::utils::RStatsInteger m_numStrata;
    cbtek::rocketstats::utils::RStatsInteger m_numTerms;
    cbtek::rocketstats::utils::RStatsInteger m_outputNonZeroSize;
    cbtek::rocketstats::utils::RStatsInteger m_totalSampleSize;
    cbtek::rocketstats::utils::RStatsInteger m_currentNonZero;

    cbtek::rocketstats::utils::RStatsIntegerList m_summaryUniverse;
    cbtek::rocketstats::utils::RStatsIntegerList m_summaryNonZeroCount;
    cbtek::rocketstats::utils::RStatsFloat m_summaryTotalOverallSum;
    cbtek::rocketstats::utils::RStatsInteger m_summaryPopulationSize;
    cbtek::rocketstats::utils::RStatsInteger m_summarySampleSize;
    cbtek::rocketstats::utils::RStatsInteger m_summaryNonZero;

    cbtek::rocketstats::utils::RStatsFloat m_auditSum;
    cbtek::rocketstats::utils::RStatsFloat m_cumaltiveProbability;
    cbtek::rocketstats::utils::RStatsFloat m_currentProbability;
    cbtek::rocketstats::utils::RStatsFloat m_difference;
    cbtek::rocketstats::utils::RStatsFloat m_differenceSum;
    cbtek::rocketstats::utils::RStatsFloat m_eps;
    cbtek::rocketstats::utils::RStatsFloat m_examineSum;
    cbtek::rocketstats::utils::RStatsFloat m_formulaVarA;
    cbtek::rocketstats::utils::RStatsFloat m_formulaVarB;
    cbtek::rocketstats::utils::RStatsFloat m_formulaVarC0;
    cbtek::rocketstats::utils::RStatsFloat m_formulaVarPI;
    cbtek::rocketstats::utils::RStatsFloat m_formulaVarT;
    cbtek::rocketstats::utils::RStatsFloat m_formulaVarTLast;
    cbtek::rocketstats::utils::RStatsFloat m_formulaVarX;
    cbtek::rocketstats::utils::RStatsFloat m_frontValue;
    cbtek::rocketstats::utils::RStatsFloat m_highProbability;
    cbtek::rocketstats::utils::RStatsFloat m_highValue;
    cbtek::rocketstats::utils::RStatsFloat m_lastLogValue;
    cbtek::rocketstats::utils::RStatsFloat m_logValue1;
    cbtek::rocketstats::utils::RStatsFloat m_logValue2;
    cbtek::rocketstats::utils::RStatsFloat m_logValue3;
    cbtek::rocketstats::utils::RStatsFloat m_logValue4;
    cbtek::rocketstats::utils::RStatsFloat m_lowProbability;
    cbtek::rocketstats::utils::RStatsFloat m_lowValue;
    cbtek::rocketstats::utils::RStatsFloat m_newProbability;
    cbtek::rocketstats::utils::RStatsInteger m_outputDOF;
    cbtek::rocketstats::utils::RStatsFloat m_outputSampleError80;
    cbtek::rocketstats::utils::RStatsFloat m_outputSampleError90;
    cbtek::rocketstats::utils::RStatsFloat m_outputSampleError95;
    cbtek::rocketstats::utils::RStatsFloat m_outputSEFIN;
    cbtek::rocketstats::utils::RStatsFloat m_temporary80;
    cbtek::rocketstats::utils::RStatsFloat m_temporary90;
    cbtek::rocketstats::utils::RStatsFloat m_temporary95;
    cbtek::rocketstats::utils::RStatsFloat m_totalAmount;
    cbtek::rocketstats::utils::RStatsFloat m_outputTValue80;
    cbtek::rocketstats::utils::RStatsFloat m_outputTValue90;
    cbtek::rocketstats::utils::RStatsFloat m_outputTValue95;


    cbtek::rocketstats::utils::RStatsFloatList m_summaryPointEstimate;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryStandardErrorMean;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryLowerLimit80;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryLowerLimit90;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryLowerLimit95;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryUpperLimit80;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryUpperLimit90;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryUpperLimit95;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryPrecisionAmount80;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryPrecisionAmount90;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryPrecisionAmount95;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryZValue80;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryZValue90;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryZValue95;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryTValue80;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryTValue90;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryTValue95;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryTotalMean;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryStandardDeviation;
    cbtek::rocketstats::utils::RStatsFloatList m_summaryTotalSum;

    cbtek::rocketstats::utils::RStatsFloatList m_auditValues;
    cbtek::rocketstats::utils::RStatsFloatList m_differenceValues;
    cbtek::rocketstats::utils::RStatsFloatList m_examValues;
    cbtek::rocketstats::utils::RStatsFloatList m_outputKurtosisAmount;
    cbtek::rocketstats::utils::RStatsFloatList m_outputKurtosisVAmount;
    cbtek::rocketstats::utils::RStatsFloatList m_outputMean;
    cbtek::rocketstats::utils::RStatsFloatList m_outputNonZero;
    cbtek::rocketstats::utils::RStatsFloatList m_outputNonZeroTemp;
    cbtek::rocketstats::utils::RStatsFloatList m_outputPNTest;
    cbtek::rocketstats::utils::RStatsFloatList m_outputPrecision80;
    cbtek::rocketstats::utils::RStatsFloatList m_outputPrecision90;
    cbtek::rocketstats::utils::RStatsFloatList m_outputPrecision95;
    cbtek::rocketstats::utils::RStatsFloatList m_outputPrecisionTemp80;
    cbtek::rocketstats::utils::RStatsFloatList m_outputPrecisionTemp90;
    cbtek::rocketstats::utils::RStatsFloatList m_outputPrecisionTemp95;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVPrecision80;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVPrecision90;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVPrecision95;
    cbtek::rocketstats::utils::RStatsFloatList m_outputPNTestTemp;
    cbtek::rocketstats::utils::RStatsFloatList m_outputSkewAmount;
    cbtek::rocketstats::utils::RStatsFloatList m_outputSkewVAmount;
    cbtek::rocketstats::utils::RStatsFloatList m_outputStdDev;
    cbtek::rocketstats::utils::RStatsFloatList m_outputStdDevTemp;
    cbtek::rocketstats::utils::RStatsFloatList m_outputStdErr;
    cbtek::rocketstats::utils::RStatsFloatList m_outputStdErrTemp;
    cbtek::rocketstats::utils::RStatsFloatList m_outputSum;
    cbtek::rocketstats::utils::RStatsFloatList m_outputSumCbrt;
    cbtek::rocketstats::utils::RStatsFloatList m_outputSumQdrt;
    cbtek::rocketstats::utils::RStatsFloatList m_outputSumSqrt;
    cbtek::rocketstats::utils::RStatsFloatList m_outputTermSE;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVMean;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVProjectNumber;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVStdDev;
    cbtek::rocketstats::utils::RStatsFloatList m_valuesC;
    cbtek::rocketstats::utils::RStatsFloatList m_outputUpperLimitTemp80;
    cbtek::rocketstats::utils::RStatsFloatList m_outputUpperLimitTemp90;
    cbtek::rocketstats::utils::RStatsFloatList m_outputUpperLimitTemp95;
    cbtek::rocketstats::utils::RStatsFloatList m_outputLowerLimitTemp80;
    cbtek::rocketstats::utils::RStatsFloatList m_outputLowerLimitTemp90;
    cbtek::rocketstats::utils::RStatsFloatList m_outputLowerLimitTemp95;
    cbtek::rocketstats::utils::RStatsFloatList m_outputUpperLimit80;
    cbtek::rocketstats::utils::RStatsFloatList m_outputUpperLimit90;
    cbtek::rocketstats::utils::RStatsFloatList m_outputUpperLimit95;
    cbtek::rocketstats::utils::RStatsFloatList m_outputLowerLimit80;
    cbtek::rocketstats::utils::RStatsFloatList m_outputLowerLimit90;
    cbtek::rocketstats::utils::RStatsFloatList m_outputLowerLimit95;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVUpperLimit80;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVUpperLimit90;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVUpperLimit95;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVLowerLimit80;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVLowerLimit90;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVLowerLimit95;
    cbtek::rocketstats::utils::RStatsFloatList m_outputVStdErr;
    RStatsSVAFlagList m_dataFormatTypeAvailableFlag;
    RStatsSVAOutputDataList m_outputDataList;
    size_t m_currentIndex;    
};
}}}}//end namespace
