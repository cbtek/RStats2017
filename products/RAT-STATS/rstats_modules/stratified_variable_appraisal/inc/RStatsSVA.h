/*
    RStatsSVA.h
    

*/

#pragma once

#include <vector>
#include "rstats_utils/inc/RStatsObjectList.hpp"
#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorkbook.h"

namespace oig {
namespace ratstats {
namespace modules {
namespace sva {


/**
 * @brief The RStatsSVAInputData struct
 */
struct RStatsSVAInputData
{
    oig::ratstats::utils::RStatsInteger sampleSize;
    oig::ratstats::utils::RStatsInteger universeSize;
    oig::ratstats::utils::RStatsInteger interestSize;
    oig::ratstats::utils::RStatsFloatList samples;
    oig::ratstats::utils::RStatsDataFormatTypeIndex typeIndex;
    oig::ratstats::utils::RStatsInteger count;
    oig::ratstats::utils::RStatsInteger offset;
};

struct RStatsSVAOutputData
{
    oig::ratstats::utils::RStatsDataFormatType type;
    bool isDisplaySummary;
    cbtek::common::utility::DateEntity createDate;
    cbtek::common::utility::TimeEntity createTime;
    std::string auditName;
    oig::ratstats::utils::RStatsInteger populationSize;
    oig::ratstats::utils::RStatsInteger sampleSize;
    oig::ratstats::utils::RStatsInteger nonZeroCount;
    oig::ratstats::utils::RStatsFloat mean;
    oig::ratstats::utils::RStatsFloat standardDeviation;
    oig::ratstats::utils::RStatsFloat skewness;
    oig::ratstats::utils::RStatsFloat standardErrorMean;
    oig::ratstats::utils::RStatsFloat standardErrorTotal;
    oig::ratstats::utils::RStatsFloat kurtosis;
    oig::ratstats::utils::RStatsFloat pointEstimate;
    oig::ratstats::utils::RStatsFloat lower80;
    oig::ratstats::utils::RStatsFloat lower90;
    oig::ratstats::utils::RStatsFloat lower95;
    oig::ratstats::utils::RStatsFloat upper80;
    oig::ratstats::utils::RStatsFloat upper90;
    oig::ratstats::utils::RStatsFloat upper95;
    oig::ratstats::utils::RStatsFloat precisionAmount80;
    oig::ratstats::utils::RStatsFloat precisionAmount90;
    oig::ratstats::utils::RStatsFloat precisionAmount95;
    oig::ratstats::utils::RStatsFloat tValue80;
    oig::ratstats::utils::RStatsFloat tValue90;
    oig::ratstats::utils::RStatsFloat tValue95;
    oig::ratstats::utils::RStatsFloat precisionPercent80;
    oig::ratstats::utils::RStatsFloat precisionPercent90;
    oig::ratstats::utils::RStatsFloat precisionPercent95;
    RStatsSVAOutputData()
    {
        this->isDisplaySummary = false;
    }
};

typedef std::vector<RStatsSVAOutputData> RStatsSVAOutputDataList;
typedef std::vector<RStatsSVAInputData> RStatsSVAInputDataList;
typedef oig::ratstats::utils::RStatsObjectList<int> RStatsSVAFlagList;

/**
 * @brief The RStatsSVA class
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
    RStatsSVAOutputDataList execute(const std::string &auditName, const oig::ratstats::utils::RStatsWorksheet& dataSheet,
                                    const oig::ratstats::utils::RStatsWorksheet& sizeSheet,
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
    void saveToWorkbook(oig::ratstats::utils::RStatsWorkbook& workbookOut);


	//! Destructor
	~RStatsSVA();	

private:


    /**
     * @brief execute
     * @param dataFormatType
     * @param strataDataList
     * @return
     */
    RStatsSVAInputDataList buildInputDataList(const oig::ratstats::utils::RStatsWorksheet& dataSheet,
                                              const oig::ratstats::utils::RStatsWorksheet& sizeSheet,
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
    void onUpdateSums(const oig::ratstats::utils::RStatsFloatList &auditValues,
                      const oig::ratstats::utils::RStatsFloatList &examValues,
                      const oig::ratstats::utils::RStatsFloatList &differenceValues);

    /**
     * @brief initializeDataTypeFormat
     * @param data
     */
    void initializeDataTypeFormat(oig::ratstats::utils::RStatsDataFormatType dataTypeFormat,
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
    void calculateOverallPrecision(const RStatsSVAInputData& data);

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
    void processFindProbVal(oig::ratstats::utils::RStatsFloat tempValue);

    /**
     * @brief processSummaryTotals
     * @param data
     */
    void processSummaryTotals(RStatsSVAOutputDataList &outputData);



    void buildOutputData(RStatsSVAOutputDataList &outputDataList,
                         const RStatsSVAInputData& inputData,
                         oig::ratstats::utils::RStatsDataFormatType type);

    void copyOutputData(RStatsSVAOutputData& outputData,
                        const RStatsSVAInputData& inputData,
                        oig::ratstats::utils::RStatsDataFormatType type,
                        size_t dataFormatIndex);

    std::string m_auditName;
    oig::ratstats::utils::RStatsInteger m_auditZeroCount;
    oig::ratstats::utils::RStatsInteger m_conditionCount;
    oig::ratstats::utils::RStatsInteger m_conditionUsage;
    oig::ratstats::utils::RStatsInteger m_currentIteration;
    oig::ratstats::utils::RStatsInteger m_differenceZeroCount;
    oig::ratstats::utils::RStatsInteger m_examineZeroCount;
    oig::ratstats::utils::RStatsInteger m_maxIterations;
    oig::ratstats::utils::RStatsInteger m_numStrata;
    oig::ratstats::utils::RStatsInteger m_numTerms;
    oig::ratstats::utils::RStatsInteger m_outputNonZeroSize;
    oig::ratstats::utils::RStatsInteger m_totalSampleSize;
    oig::ratstats::utils::RStatsInteger m_currentNonZero;

    oig::ratstats::utils::RStatsInteger m_summaryTotalSum;
    oig::ratstats::utils::RStatsInteger m_summaryPopulationSize;
    oig::ratstats::utils::RStatsInteger m_summarySampleSize;
    oig::ratstats::utils::RStatsInteger m_summaryNonZero;

    oig::ratstats::utils::RStatsFloat m_auditSum;
    oig::ratstats::utils::RStatsFloat m_cumaltiveProbability;
    oig::ratstats::utils::RStatsFloat m_currentProbability;
    oig::ratstats::utils::RStatsFloat m_difference;
    oig::ratstats::utils::RStatsFloat m_differenceSum;
    oig::ratstats::utils::RStatsFloat m_eps;
    oig::ratstats::utils::RStatsFloat m_examineSum;
    oig::ratstats::utils::RStatsFloat m_formulaVarA;
    oig::ratstats::utils::RStatsFloat m_formulaVarB;
    oig::ratstats::utils::RStatsFloat m_formulaVarC0;
    oig::ratstats::utils::RStatsFloat m_formulaVarPI;
    oig::ratstats::utils::RStatsFloat m_formulaVarT;
    oig::ratstats::utils::RStatsFloat m_formulaVarTLast;
    oig::ratstats::utils::RStatsFloat m_formulaVarX;
    oig::ratstats::utils::RStatsFloat m_frontValue;
    oig::ratstats::utils::RStatsFloat m_highProbability;
    oig::ratstats::utils::RStatsFloat m_highValue;
    oig::ratstats::utils::RStatsFloat m_lastLogValue;
    oig::ratstats::utils::RStatsFloat m_logValue1;
    oig::ratstats::utils::RStatsFloat m_logValue2;
    oig::ratstats::utils::RStatsFloat m_logValue3;
    oig::ratstats::utils::RStatsFloat m_logValue4;
    oig::ratstats::utils::RStatsFloat m_lowProbability;
    oig::ratstats::utils::RStatsFloat m_lowValue;
    oig::ratstats::utils::RStatsFloat m_newProbability;
    oig::ratstats::utils::RStatsFloat m_outputDOF;
    oig::ratstats::utils::RStatsFloat m_outputSampleError80;
    oig::ratstats::utils::RStatsFloat m_outputSampleError90;
    oig::ratstats::utils::RStatsFloat m_outputSampleError95;
    oig::ratstats::utils::RStatsFloat m_outputSEFIN;
    oig::ratstats::utils::RStatsFloat m_temporary80;
    oig::ratstats::utils::RStatsFloat m_temporary90;
    oig::ratstats::utils::RStatsFloat m_temporary95;
    oig::ratstats::utils::RStatsFloat m_totalAmount;
    oig::ratstats::utils::RStatsFloat m_outputTValue80;
    oig::ratstats::utils::RStatsFloat m_outputTValue90;
    oig::ratstats::utils::RStatsFloat m_outputTValue95;

    oig::ratstats::utils::RStatsFloat m_summaryPointEstimate;
    oig::ratstats::utils::RStatsFloat m_summaryStandardErrorMean;
    oig::ratstats::utils::RStatsFloat m_summaryStandardErrorTotal;
    oig::ratstats::utils::RStatsFloat m_summaryLowerLimit80;
    oig::ratstats::utils::RStatsFloat m_summaryLowerLimit90;
    oig::ratstats::utils::RStatsFloat m_summaryLowerLimit95;
    oig::ratstats::utils::RStatsFloat m_summaryUpperLimit80;
    oig::ratstats::utils::RStatsFloat m_summaryUpperLimit90;
    oig::ratstats::utils::RStatsFloat m_summaryUpperLimit95;
    oig::ratstats::utils::RStatsFloat m_summaryPrecisionAmount80;
    oig::ratstats::utils::RStatsFloat m_summaryPrecisionAmount90;
    oig::ratstats::utils::RStatsFloat m_summaryPrecisionAmount95;
    oig::ratstats::utils::RStatsFloat m_summaryPrecisionPercent80;
    oig::ratstats::utils::RStatsFloat m_summaryPrecisionPercent90;
    oig::ratstats::utils::RStatsFloat m_summaryPrecisionPercent95;
    oig::ratstats::utils::RStatsFloat m_summaryZValue80;
    oig::ratstats::utils::RStatsFloat m_summaryZValue90;
    oig::ratstats::utils::RStatsFloat m_summaryZValue95;
    oig::ratstats::utils::RStatsFloat m_summaryTValue80;
    oig::ratstats::utils::RStatsFloat m_summaryTValue90;
    oig::ratstats::utils::RStatsFloat m_summaryTValue95;
    oig::ratstats::utils::RStatsFloat m_summaryStandardDeviation;
    oig::ratstats::utils::RStatsFloatList m_auditValues;
    oig::ratstats::utils::RStatsFloatList m_differenceValues;
    oig::ratstats::utils::RStatsFloatList m_examValues;
    oig::ratstats::utils::RStatsFloatList m_outputKurtosisAmount;
    oig::ratstats::utils::RStatsFloatList m_outputKurtosisVAmount;
    oig::ratstats::utils::RStatsFloatList m_outputMean;
    oig::ratstats::utils::RStatsFloatList m_outputNonZero;
    oig::ratstats::utils::RStatsFloatList m_outputNonZeroTemp;
    oig::ratstats::utils::RStatsFloatList m_outputPNTest;
    oig::ratstats::utils::RStatsFloatList m_outputPrecision80;
    oig::ratstats::utils::RStatsFloatList m_outputPrecision90;
    oig::ratstats::utils::RStatsFloatList m_outputPrecision95;
    oig::ratstats::utils::RStatsFloatList m_outputPrecisionTemp80;
    oig::ratstats::utils::RStatsFloatList m_outputPrecisionTemp90;
    oig::ratstats::utils::RStatsFloatList m_outputPrecisionTemp95;
    oig::ratstats::utils::RStatsFloatList m_outputVPrecision80;
    oig::ratstats::utils::RStatsFloatList m_outputVPrecision90;
    oig::ratstats::utils::RStatsFloatList m_outputVPrecision95;
    oig::ratstats::utils::RStatsFloatList m_outputPNTestTemp;
    oig::ratstats::utils::RStatsFloatList m_outputSkewAmount;
    oig::ratstats::utils::RStatsFloatList m_outputSkewVAmount;
    oig::ratstats::utils::RStatsFloatList m_outputStdDev;
    oig::ratstats::utils::RStatsFloatList m_outputStdDevTemp;
    oig::ratstats::utils::RStatsFloatList m_outputStdErr;
    oig::ratstats::utils::RStatsFloatList m_outputStdErrTemp;
    oig::ratstats::utils::RStatsFloatList m_outputSum;
    oig::ratstats::utils::RStatsFloatList m_outputSumCbrt;
    oig::ratstats::utils::RStatsFloatList m_outputSumQdrt;
    oig::ratstats::utils::RStatsFloatList m_outputSumSqrt;
    oig::ratstats::utils::RStatsFloatList m_outputTermSE;
    oig::ratstats::utils::RStatsFloatList m_outputVMean;
    oig::ratstats::utils::RStatsFloatList m_outputVProjectNumber;
    oig::ratstats::utils::RStatsFloatList m_outputVStdDev;
    oig::ratstats::utils::RStatsFloatList m_valuesC;
    oig::ratstats::utils::RStatsFloatList m_outputUpperLimitTemp80;
    oig::ratstats::utils::RStatsFloatList m_outputUpperLimitTemp90;
    oig::ratstats::utils::RStatsFloatList m_outputUpperLimitTemp95;
    oig::ratstats::utils::RStatsFloatList m_outputLowerLimitTemp80;
    oig::ratstats::utils::RStatsFloatList m_outputLowerLimitTemp90;
    oig::ratstats::utils::RStatsFloatList m_outputLowerLimitTemp95;
    oig::ratstats::utils::RStatsFloatList m_outputUpperLimit80;
    oig::ratstats::utils::RStatsFloatList m_outputUpperLimit90;
    oig::ratstats::utils::RStatsFloatList m_outputUpperLimit95;
    oig::ratstats::utils::RStatsFloatList m_outputLowerLimit80;
    oig::ratstats::utils::RStatsFloatList m_outputLowerLimit90;
    oig::ratstats::utils::RStatsFloatList m_outputLowerLimit95;
    oig::ratstats::utils::RStatsFloatList m_outputVUpperLimit80;
    oig::ratstats::utils::RStatsFloatList m_outputVUpperLimit90;
    oig::ratstats::utils::RStatsFloatList m_outputVUpperLimit95;
    oig::ratstats::utils::RStatsFloatList m_outputVLowerLimit80;
    oig::ratstats::utils::RStatsFloatList m_outputVLowerLimit90;
    oig::ratstats::utils::RStatsFloatList m_outputVLowerLimit95;
    oig::ratstats::utils::RStatsFloatList m_outputVStdErr;
    RStatsSVAFlagList m_dataFormatTypeAvailableFlag;
    RStatsSVAOutputDataList m_outputDataList;
};
}}}}//end namespace
