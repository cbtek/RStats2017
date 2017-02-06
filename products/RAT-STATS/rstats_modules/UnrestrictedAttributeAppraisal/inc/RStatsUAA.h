/*
    RStatsUAA.h
    

*/

#ifndef _OIG_RATSTATS_UAA_RSTATSUAA_H
#define _OIG_RATSTATS_UAA_RSTATSUAA_H


namespace oig {
namespace ratstats {
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

	//! Destructor
	~RStatsUAA();	

private:
    static RStatsUAA m_instance;
    
};
}}}//end namespace

#endif

