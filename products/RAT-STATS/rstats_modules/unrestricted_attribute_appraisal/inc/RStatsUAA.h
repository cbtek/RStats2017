/*
    RStatsUAA.h
    

*/

#pragma once

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

	//! Destructor
	~RStatsUAA();	

private:
    static RStatsUAA m_instance;
    
};
}}}}//end namespace

