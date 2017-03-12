/*
    RStatsUVA.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsUtils.hpp"

namespace oig {
namespace ratstats {
namespace modules {
namespace uva {

class RStatsUVA 
{

public:
	//! Constructor for RStatsUVA
	/*!
		Detailed description for RStatsUVA
	*/
	RStatsUVA();
        
	//! Static instance method for this singleton
    static RStatsUVA & inst();


    void execute(const oig::ratstats::utils::RStatsFloatList& values, size_t sampleSize, size_t universeSize,
                 oig::ratstats::utils::RStatsDataFormatType type);

	//! Destructor
	~RStatsUVA();	

private:      
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
    oig::ratstats::utils::RStatsFloatList m_means;
    oig::ratstats::utils::RStatsFloatList m_pointEstimates;
    oig::ratstats::utils::RStatsFloatList m_standardError;
    oig::ratstats::utils::RStatsFloatList m_standardDeviation;
    oig::ratstats::utils::RStatsFloatList m_skewAmount;
    oig::ratstats::utils::RStatsFloatList m_intervals80;
    oig::ratstats::utils::RStatsFloatList m_intervals90;
    oig::ratstats::utils::RStatsFloatList m_intervals95;
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

    static RStatsUVA m_instance;

    /**
     * @brief calculateMeans
     */
    void calculateMeans();

    /**
     * @brief calculatePointEstimates
     */
    void calculatePointEstimates();

    /**
     * @brief calculateCorrectionFactor
     */
    void calculateCorrectionFactor();

    /**
     * @brief calculateDegreesOfFreedom
     */
    void calculateDegreesOfFreedom();

    /**
     * @brief calculateStandardDeviation
     */
    void calculateStandardDeviation();

    /**
     * @brief calculateUpperAndLowerLimits
     */
    void calculateUpperAndLowerLimits();

    /**
     * @brief calculateOverallPrecision
     */
    void calculateOverallPrecision();

    /**
     * @brief calculateStandardError
     */
    void calculateStandardError();

    /**
     * @brief calculateSkewness
     */
    void calculateSkewness();

    /**
     * @brief processSamplingError
     */
    void processSamplingError();

    /**
     * @brief processFindIntervals
     */
    void processFindIntervals();

    /**
     * @brief processSetup
     */
    void processSetup();

    /**
     * @brief processConditionalLoop
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


