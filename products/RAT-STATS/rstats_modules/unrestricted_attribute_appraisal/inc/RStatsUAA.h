/*
    RStatsUAA.h
    

*/

#pragma once

#include "rstats_utils/inc/RStatsUtils.hpp"

namespace oig {
namespace ratstats {
namespace modules {
namespace uaa {

class RStatsUAA 
{
public:
	//! Constructor for RStatsUAA
	/*!
		Detailed description for RStatsUAA
	*/
	RStatsUAA();
      
	//! Static instance method for this singleton
    static RStatsUAA & inst();

    void execute(utils::RStatsInteger sampleSize, utils::RStatsInteger universeSize, utils::RStatsInteger coiSize, bool computeOneSided);
	//! Destructor
	~RStatsUAA();	

private:
    bool m_isActive;

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


    void processFindLower();
    void processResults();
    void processSumHypergeometric();
    void processFindBottomUpper();
    void processFindBottomLower();
    void processCloseInUpper();
    void processCloseInLower();
    void processFinalUpper();
    void processFinalLower();
    void processExit();
    void reset();

    static RStatsUAA m_instance;
    
};
}}}}//end namespace

