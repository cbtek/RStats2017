/*
    RStatsUAA.cpp
    

*/
//----------------------------------------
//RStatsUAA.cpp generated by snow on 02-05-2017 at 08:44:03 PM
//----------------------------------------

#include "RStatsUAA.h"

#include "rstats_utils/inc/RStatsUtils.hpp"

#include "utility/inc/StringUtils.hpp"

using namespace oig::ratstats::utils;
using namespace cbtek::common::utility;
namespace oig {
namespace ratstats {
namespace modules {
namespace uaa {

RStatsUAA RStatsUAA::m_instance = RStatsUAA();


RStatsUAA & RStatsUAA::inst()
{
    return m_instance;
}

void RStatsUAA::saveToCSVFile(const std::string &filePath)
{
    RStatsWorksheet sheet;
    saveToWorksheet(sheet);
    FileUtils::writeFileContents(filePath,sheet.toCommaDelimitedString());
}

void RStatsUAA::saveToTextFile(const std::string &filePath)
{
    RStatsWorksheet sheet;
    saveToWorksheet(sheet);
    FileUtils::writeFileContents(filePath,sheet.toEvenlySpacedString());
}

RStatsUAA::RStatsUAA()
{

}

RStatsUAA::~RStatsUAA()
{

}

RStatsUAAOutputData RStatsUAA::execute(const std::string& auditName,
                                       RStatsInteger sampleSize,
                                       RStatsInteger universeSize,
                                       RStatsInteger coiSize,
                                       RStatsUAAConfidenceIntervalType type)
{
    m_outputData.auditName = auditName;
    m_confidenceIntervalType = type;
    //std::cout << "start:\n";
    m_isFinished = false;
    reset();
    m_sampleSize = sampleSize;
    m_universeSize = universeSize;
    m_numItems = coiSize;
    m_numItemsInSample = coiSize;
    m_max = 1000000000000.;
    m_min = 1 / m_max;
    m_ratio = RStatsUtils::divideValues(m_numItems,m_sampleSize);    
    m_conditionLevel = 1;
    start();
    m_outputData.createDate = DateUtils::getCurrentDate();
    m_outputData.createTime = TimeUtils::getCurrentTime();

    RStatsFloat sampleSizeFloat = static_cast<RStatsFloat>(m_sampleSize);
    m_outputData.sampleSize = m_sampleSize;
    m_outputData.universeSize = m_universeSize;
    m_outputData.coiSize = coiSize;
    m_outputData.projectedTotal = m_ratio * static_cast<RStatsFloat>(m_universeSize);
    m_outputData.projectedTotalPercent = 100. * m_ratio;
    RStatsFloat fractional = sampleSizeFloat / static_cast<RStatsFloat>(m_universeSize);
    m_outputData.variance = sampleSizeFloat * m_ratio * (1. - m_ratio) * (1. - fractional);
    m_outputData.standardError = std::sqrt(m_outputData.variance);
    RStatsFloat stdErr = m_outputData.standardError;
    m_outputData.standardError = std::round((stdErr * (std::sqrt(sampleSizeFloat / static_cast<RStatsFloat>(m_sampleSize  - 1 ))) / fractional));
    m_outputData.standardErrorPercent = 100. * (stdErr / (std::sqrt(sampleSizeFloat * (sampleSizeFloat - 1))));

    m_outputData.lowerLimitQuantityList(0) = m_lower80;
    m_outputData.lowerLimitQuantityList(1) = m_lower90;
    m_outputData.lowerLimitQuantityList(2) = m_lower95;

    m_outputData.upperLimitQuantityList(0) = m_upper80;
    m_outputData.upperLimitQuantityList(1) = m_upper90;
    m_outputData.upperLimitQuantityList(2) = m_upper95;

    m_outputData.lowerLimitPercentList(0) = 100. * (static_cast<RStatsFloat>(m_lower80) / static_cast<RStatsFloat>(m_universeSize));
    m_outputData.lowerLimitPercentList(1) = 100. * (static_cast<RStatsFloat>(m_lower90) / static_cast<RStatsFloat>(m_universeSize));
    m_outputData.lowerLimitPercentList(2) = 100. * (static_cast<RStatsFloat>(m_lower95) / static_cast<RStatsFloat>(m_universeSize));

    m_outputData.upperLimitPercentList(0) = 100. * (static_cast<RStatsFloat>(m_upper80) / static_cast<RStatsFloat>(m_universeSize));
    m_outputData.upperLimitPercentList(1) = 100. * (static_cast<RStatsFloat>(m_upper90) / static_cast<RStatsFloat>(m_universeSize));
    m_outputData.upperLimitPercentList(2) = 100. * (static_cast<RStatsFloat>(m_upper95) / static_cast<RStatsFloat>(m_universeSize));

    return m_outputData;
}

void RStatsUAA::saveToWorksheet(RStatsWorksheet &worksheetOut)
{
    worksheetOut.setDefaultFont(Font("arial",12,true));
    worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignRight);

    worksheetOut("A1")= "Audit/Review:";
    worksheetOut("A2")= "Applicaton:";
    worksheetOut("A3")= "Module:";
    worksheetOut("A4")= "Author:";
    worksheetOut("A5")= "Date:";
    worksheetOut("A6")= "Time:";
    worksheetOut("A7")= "Population size:";
    worksheetOut("A8")= "Sample size:";
    worksheetOut("A9")= "Characteristic of interest:";
    worksheetOut("A10")= "Projected Total:";
    worksheetOut("A11")= "Projected Percent:";
    worksheetOut("A12")= "Standard Error(Total):";
    worksheetOut("A13")= "Standard Error(Percent):";

    worksheetOut.setDefaultFont(Font("arial",12,true));
    worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignMiddle);    
//    /worksheetOut("E5")= "Confidence Level";

    worksheetOut("D6")= "80%";
    worksheetOut("D6").bgColor.set("#FFAAAA");
    worksheetOut("D6").fgColor.set("#101001");

    worksheetOut("E6")= "90%";
    worksheetOut("E6").bgColor.set("#FFFFAA");
    worksheetOut("E6").fgColor.set("#101001");

    worksheetOut("F6")= "95%";
    worksheetOut("F6").bgColor.set("#AAFFAA");
    worksheetOut("F6").fgColor.set("#101001");
    worksheetOut.resetDefaults();

    worksheetOut.setDefaultFont(Font("arial",12));
    worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignLeft);
    worksheetOut("B1") = m_outputData.auditName;
    worksheetOut("B2") = RStatsUtils::getApplicationName();
    worksheetOut("B3") = "Unrestricted Attribute Appraisal";
    worksheetOut("B4") = SystemUtils::getUserName();
    worksheetOut("B5") = DateUtils::toLongDateString(m_outputData.createDate);
    worksheetOut("B6") = TimeUtils::to12HourTimeString(m_outputData.createTime);
    worksheetOut("B7") = StringUtils::toString(m_outputData.universeSize);
    worksheetOut("B8") = StringUtils::toString(m_outputData.sampleSize);
    worksheetOut("B9") = StringUtils::toString(m_outputData.coiSize);
    worksheetOut("B10") = StringUtils::toString(m_outputData.projectedTotal,0);
    worksheetOut("B11") = StringUtils::toString(m_outputData.projectedTotalPercent,3)+"%";
    worksheetOut("B12") = StringUtils::toString(m_outputData.standardError,0);
    worksheetOut("B13") = StringUtils::toString(m_outputData.standardErrorPercent,3)+"%";
    worksheetOut.resetDefaults();

        if (m_confidenceIntervalType == RStatsUAAConfidenceIntervalType::OneSidedLower)
        {
            worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignRight);
            worksheetOut.setDefaultFont(Font("arial",12,true));
            worksheetOut("C7")= "Lower Total";
            worksheetOut("C8")= "Lower Percent";
            worksheetOut.setDefaultFont(Font("arial",12));
            worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignMiddle);
            worksheetOut("D7") = StringUtils::toString(m_outputData.lowerLimitQuantityList(0),0);
            worksheetOut("E7") = StringUtils::toString(m_outputData.lowerLimitQuantityList(1),0);
            worksheetOut("F7") = StringUtils::toString(m_outputData.lowerLimitQuantityList(2),0);
            worksheetOut("D8") = StringUtils::toString(m_outputData.lowerLimitPercentList(0),3)+"%";
            worksheetOut("E8") = StringUtils::toString(m_outputData.lowerLimitPercentList(1),3)+"%";
            worksheetOut("F8") = StringUtils::toString(m_outputData.lowerLimitPercentList(2),3)+"%";
            worksheetOut.resetDefaults();
        }
        else if (m_confidenceIntervalType == RStatsUAAConfidenceIntervalType::OneSidedUpper)
        {
            worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignRight);
            worksheetOut.setDefaultFont(Font("arial",12,true));
            worksheetOut("C7")= "Upper Total:";
            worksheetOut("C8")= "Upper Percent:";
            worksheetOut.setDefaultFont(Font("arial",12));
            worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignMiddle);
            worksheetOut("D7") = StringUtils::toString(m_outputData.upperLimitQuantityList(0),0);
            worksheetOut("E7") = StringUtils::toString(m_outputData.upperLimitQuantityList(1),0);
            worksheetOut("F7") = StringUtils::toString(m_outputData.upperLimitQuantityList(2),0);
            worksheetOut("D8") = StringUtils::toString(m_outputData.upperLimitPercentList(0),3)+"%";
            worksheetOut("E8") = StringUtils::toString(m_outputData.upperLimitPercentList(1),3)+"%";
            worksheetOut("F8") = StringUtils::toString(m_outputData.upperLimitPercentList(2),3)+"%";
            worksheetOut.resetDefaults();
        }
        else
        {
            worksheetOut.setDefaultFont(Font("arial",12,true));
            worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignRight);
            worksheetOut("C7")= "Lower Total:";
            worksheetOut("C8")= "Lower Percent:";
            worksheetOut("C9")= "Upper Total:";
            worksheetOut("C10")= "Upper Percent:";
            worksheetOut.setDefaultFont(Font("arial",12));
            worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignMiddle);
            worksheetOut("D7") = StringUtils::toString(m_outputData.lowerLimitQuantityList(0),0);
            worksheetOut("E7") = StringUtils::toString(m_outputData.lowerLimitQuantityList(1),0);
            worksheetOut("F7") = StringUtils::toString(m_outputData.lowerLimitQuantityList(2),0);
            worksheetOut("D8") = StringUtils::toString(m_outputData.lowerLimitPercentList(0),3)+"%";
            worksheetOut("E8") = StringUtils::toString(m_outputData.lowerLimitPercentList(1),3)+"%";
            worksheetOut("F8") = StringUtils::toString(m_outputData.lowerLimitPercentList(2),3)+"%";
            worksheetOut("D9") = StringUtils::toString(m_outputData.upperLimitQuantityList(0),0);
            worksheetOut("E9") = StringUtils::toString(m_outputData.upperLimitQuantityList(1),0);
            worksheetOut("F9") = StringUtils::toString(m_outputData.upperLimitQuantityList(2),0);
            worksheetOut("D10") = StringUtils::toString(m_outputData.upperLimitPercentList(0),3)+"%";
            worksheetOut("E10") = StringUtils::toString(m_outputData.upperLimitPercentList(1),3)+"%";
            worksheetOut("F10") = StringUtils::toString(m_outputData.upperLimitPercentList(2),3)+"%";
            worksheetOut.resetDefaults();
        }
}

void RStatsUAA::start()
{
    while(m_conditionLevel <= 3)
    {
        m_numItems = m_numItemsInSample;
        if (m_conditionLevel == 1)
        {
            m_zValue = 1.28155;
            m_tail = (m_confidenceIntervalType == RStatsUAAConfidenceIntervalType::TwoSided) ? .1 : .2;
        }
        else if (m_conditionLevel == 2)
        {
            m_zValue = 1.64485;
            m_tail = (m_confidenceIntervalType == RStatsUAAConfidenceIntervalType::TwoSided) ? .05 : .1;
        }
        else
        {
            m_zValue = 1.95996;
            m_tail = (m_confidenceIntervalType == RStatsUAAConfidenceIntervalType::TwoSided) ? .025 : .05;
        }

        m_phat = (static_cast<RStatsFloat>(m_numItems) / static_cast<RStatsFloat>(m_sampleSize));
        m_term = m_phat * (1 - m_phat) * m_universeSize * (m_universeSize - m_sampleSize) / (m_sampleSize - 1);
        m_kOld = 0;
        m_iter = 1;
        processFindUpper();
        if (m_isFinished)
        {
            return;
        }
    }
}

void RStatsUAA::processFindUpper()
{
    //std::cout << "Find Upper:\n";
    if (m_numItems == m_sampleSize)
    {
        m_kUpper = m_universeSize;
        processFindLower();
    }

    RStatsFloat univ = static_cast<RStatsFloat>(m_universeSize);
    m_kSt = static_cast<RStatsInteger>((univ * m_phat) + std::round(m_zValue * std::sqrt(m_term)));
    if (m_kSt > (.95 * m_universeSize))
    {
        m_kSt = m_universeSize;
    }
    for (size_t i = 1; i <= 11; ++i)
    {
        if (m_isFinished)
        {
            return;
        }
        RStatsFloat kst = static_cast<RStatsFloat>(m_kSt);
        m_kAdd = static_cast<RStatsInteger>(RStatsUtils::vbRound((univ - kst) * .1 * (i - 1)));
        if (m_numItems == 0 || m_numItems == m_sampleSize)
        {
            m_kAdd = static_cast<RStatsInteger>(univ * .1 * (i - 1));
        }
        m_k = m_kSt + m_kAdd;
        if (m_k > m_universeSize)
        {
            m_k = m_universeSize;
        }
        processSumHypergeometric();
        if (m_cumalativeProbability < 1e-05)
        {
            m_cumalativeProbability = 0.;
        }
        m_sSum = m_cumalativeProbability - m_tail;
        if (m_sSum < 0)
        {
            processFindBottomUpper();
        }
    }
}

void RStatsUAA::processFindLower()
{
    //std::cout << "FindLower:"<<std::endl;
    --m_numItems;
    m_kSt = static_cast<RStatsInteger>((static_cast<RStatsFloat>(m_universeSize) * m_phat) - std::ceil(m_zValue * std::sqrt(m_term)));
    if (m_kSt < m_numItems)
    {
        m_kSt = m_numItems;
    }

    m_k = m_kSt;
    for (int i = 1; i <= 11; ++i)
    {
        if (m_isFinished)
        {
            return;
        }
        RStatsFloat univ = static_cast<RStatsFloat>(m_universeSize);
        RStatsFloat kst = static_cast<RStatsFloat>(m_kSt);
        m_kAdd = static_cast<RStatsInteger>((univ * m_phat - kst) * .1 * (i - 1));

        if (m_numItems == 0 || m_numItems == m_sampleSize)
        {
            m_kAdd = static_cast<RStatsInteger>(univ * .1 * (i - 1));
        }

        m_k = m_kSt + m_kAdd;

        if (m_k > m_universeSize)
        {
            m_k = m_universeSize;
        }

        processSumHypergeometric();

        if (m_cumalativeProbability < 1e-05)
        {
            m_cumalativeProbability = 0.;
        }
        m_sSum = 1 - m_cumalativeProbability - m_tail;

        if (m_sSum > 0)
        {
            processFindBottomLower();
        }
    }
}



void RStatsUAA::processResults()
{
    //std::cout << "Results:"<<std::endl;
    if (m_conditionLevel == 1)
    {
        m_lower80 = m_kLower;
        m_upper80 = m_kUpper;
        ++m_conditionLevel;
        start();
    }
    else if (m_conditionLevel == 2)
    {
        m_lower90 = m_kLower;
        m_upper90 = m_kUpper;
        ++m_conditionLevel;
        start();
    }
    else
    {
        m_lower95 = m_kLower;
        m_upper95 = m_kUpper;
        m_isFinished = true;
        ++m_conditionLevel;
        start();
    }    
}

void RStatsUAA::processSumHypergeometric()
{    
    m_numExponents = 0;
    m_popGood = m_universeSize - m_k;
    m_minBad = m_sampleSize - m_popGood;
    if (m_numItems < m_minBad)
    {
        m_cumalativeProbability = 0;
        //std::cout << "SumHyp:"<<m_cumalativeProbability<<std::endl;
        return;
    }

    if (m_minBad < 0)
    {
        m_minBad = 0;
    }
    m_z = 1;
    if (m_minBad > 0)
    {
        for (int j = 0; j < m_sampleSize; ++j)
        {
            if (j < m_minBad)
            {
               m_z = m_z * static_cast<RStatsFloat>(m_k - j) / static_cast<RStatsFloat>(m_universeSize - j);
            }
            else
            {
               m_z = m_z * static_cast<RStatsFloat>(j + 1) / static_cast<RStatsFloat>(m_universeSize - j);
            }
            if (m_z < m_min)
            {
               m_z = m_z * m_max;
               --m_numExponents;
            }
            if (m_z >= m_max)
            {
               m_z = m_z * m_min;
               ++m_numExponents;
            }
        }
    }
   else
   {
       for (int j = 0; j < m_sampleSize; ++j)
       {
           m_z = m_z * static_cast<RStatsFloat>(m_popGood - j) / static_cast<RStatsFloat>(m_universeSize - j);
           if (m_z < m_min)
           {
               m_z = m_z * m_max;
               --m_numExponents;
           }
       }
    }
    if (m_numExponents < -1)
    {
        m_cumalativeProbability = 0;
    }
    else
    {
        m_cumalativeProbability = m_z * std::pow(m_max, m_numExponents);
    }

//    '
//    '  COMPUTE PROB OF MINBAD TO X ERRORS IN THE SAMPLE
//    '

    if (m_minBad > 0)
    {
        m_pb = m_k - m_minBad;
        m_pg = m_popGood + m_minBad;
        m_ss = m_sampleSize - m_minBad;
        m_sb = m_numItems - m_minBad;
    }
    else
    {
        m_pb = m_k;
        m_pg = m_popGood;
        m_ss = m_sampleSize;
        m_sb = m_numItems;
    }

    for (int j = 1; j <= m_sb; ++j)
    {
        m_z = m_z * static_cast<RStatsFloat>(m_pb - j + 1) * static_cast<RStatsFloat>(m_ss - j + 1);
        RStatsFloat denominator = (static_cast<RStatsFloat>(j + m_minBad) * static_cast<RStatsFloat>(m_pg - m_sampleSize + j));
        m_z = m_z / denominator;
        if (m_z > m_max)
        {
            m_z = m_z / m_max;
            ++m_numExponents;
        }
        if (std::abs(m_numExponents) < 2)
        {
            m_cumalativeProbability +=  m_z * std::pow(m_max, m_numExponents);
        }
    }

    //std::cout << "SumHyp:"<<m_cumalativeProbability<<std::endl;
}

void RStatsUAA::processFindBottomUpper()
{
    //std::cout << "FindBottomUpper:\n";
    m_kTop = m_k;
    RStatsFloat univ = static_cast<RStatsFloat>(m_universeSize);
    m_kSt = static_cast<RStatsInteger>((univ* m_phat) + std::ceil(m_zValue * std::sqrt(m_term)));
    if (m_kSt > (.95 * m_universeSize))
    {
        m_kSt = m_universeSize;
    }
    for (int i = 0; i <= 11; ++i)
    {
        if (m_isFinished)
        {
            return;
        }
        RStatsFloat kst = static_cast<RStatsFloat>(m_kSt);
        m_kSub = static_cast<RStatsInteger>((kst - univ * m_phat) * .1 * ((i+1) - 1));
        m_k = m_kSt - m_kSub;
        processSumHypergeometric();
        if (m_cumalativeProbability < 1e-05)
        {
            m_cumalativeProbability = 0.;
        }
        m_sSum = m_cumalativeProbability - m_tail;
        if (m_sSum > 0)
        {
            m_kBottom = m_k;
            m_kOld = m_k;
            processCloseInUpper();
        }
    }
    processCloseInUpper();
}

void RStatsUAA::processFindBottomLower()
{
    //std::cout << "FindBottomLower:\n";
    m_kTop = m_k;
    RStatsFloat univ = static_cast<RStatsFloat>(m_universeSize);
    m_kSt = static_cast<RStatsInteger>((univ * m_phat) - std::ceil(m_zValue * std::sqrt(m_term)));
    if (m_kSt <= 0)
    {
        m_kSt = 0;
    }

    m_k = m_kSt;

    for (int i = 1; i <=  11; ++i)
    {
        if (m_isFinished)
        {
            return;
        }
        RStatsFloat kst = static_cast<RStatsFloat>(m_kSt);
        m_kSub = static_cast<RStatsInteger>((kst * .1) * (i - 1));
        m_k = m_kSt - m_kSub;
        if (m_k < 0)
        {
            m_k = 0;
        }

        processSumHypergeometric();

        if (m_cumalativeProbability < 1e-05)
        {
            m_cumalativeProbability = 0.;
        }
        m_sSum = 1 - m_cumalativeProbability - m_tail;
        if (m_sSum < 0)
        {
            m_kBottom = m_k;
            processCloseInLower();
        }
    }

}

void RStatsUAA::processCloseInUpper()
{  
    if (m_kTop - m_kBottom == 1)
    {
        processFinalUpper();
    }

    if (m_isFinished)
    {
        return;
    }

    double value = (static_cast<RStatsFloat>(m_kTop) - static_cast<RStatsFloat>(m_kBottom)) / 2.0;
    m_k = RStatsUtils::vbRound(static_cast<RStatsFloat>(m_kBottom) + value);

    processSumHypergeometric();
    m_sSum = m_cumalativeProbability - m_tail;
    if (m_sSum <= 0)
    {
        m_kTop = m_k;
    }
    else
    {
        m_kBottom = m_k;
    }
    m_iter = m_iter + 1;
    if (m_iter > 100)
    {
        //THROW_GENERIC_EXCEPTION("Number of Iterations is greater than 100. Exiting");
        //processExit();
        return;
    }
    m_kOld = m_k;
    m_sumNew = m_sSum;
    processCloseInUpper();
}

void RStatsUAA::processCloseInLower()
{
    //std::cout << "CloseInLower:\n";
    if ((m_kTop - m_kBottom) == 1)
    {
        processFinalLower();
    }    

    if (m_isFinished)
    {
        return;
    }

    double value = (static_cast<RStatsFloat>(m_kTop) - static_cast<RStatsFloat>(m_kBottom)) / 2.0;
    m_k = RStatsUtils::vbRound(static_cast<RStatsFloat>(m_kBottom) + value);
    processSumHypergeometric();
    if (m_cumalativeProbability < 1e-05)
    {
        m_cumalativeProbability = 0;
    }

    m_sSum = 1 - m_cumalativeProbability - m_tail;

    if (m_sSum <= 0)
    {
        m_kBottom = m_k;
    }
    else
    {
        m_kTop = m_k;
    }
    ++m_iter;
    if (m_iter  > 100)
    {
        //Print "NO. OF ITERATIONS > 100 -- EXITING"
        return;
    }
    m_kOld = m_k;
//  SUM1NEW# = SSUM1#
    processCloseInLower();
}

void RStatsUAA::processFinalUpper()
{
    //std::cout << "FinalUpper:\n";
    if (m_numItems == 0)
    {
        m_kUpper = m_kBottom;
        m_kLower = 0.;
        processResults();
        return;
    }

    if (m_isFinished)
    {
        return;
    }

    m_kUpper = m_kBottom;

    if (m_kUpper > (m_universeSize - m_sampleSize + m_numItems))
    {
        m_kUpper = m_universeSize - m_sampleSize + m_numItems;
    }
    processFindLower();
}

void RStatsUAA::processFinalLower()
{
    //std::cout << "FinalLower:\n";
    if (m_numItems == m_sampleSize)
    {
        m_kLower = m_kTop;
        processResults();
        return;
    }

    if (m_isFinished)
    {
        return;
    }

    m_kLower = m_kTop;

    if (m_kLower < m_numItems)
    {
        m_kLower = m_numItems;
    }
    processResults();
}

void RStatsUAA::reset()
{
     m_numCompare = 0;
     m_numExponents = 0;
     m_sampleSize = 0;
     m_numItems = 0;
     m_numItemsInSample = 0;
     m_conditionLevel = 0;
     m_iter = 0;
     m_universeSize = 0;
     m_phat = 0;
     m_term = 0;
     m_kUpper = 0;
     m_kAdd = 0;
     m_kOld = 0;
     m_kLower = 0;
     m_kTop = 0;
     m_kBottom = 0;
     m_kSt = 0;
     m_max = 0;
     m_min = 0;
     m_ratio = 0;
     m_lower80 = 0;
     m_lower90 = 0;
     m_lower95 = 0;
     m_upper80 = 0;
     m_upper90 = 0;
     m_upper95 = 0;
     m_zValue = 0;
     m_k = 0;
     m_kSub = 0;
     m_tail = 0;
     m_cumalativeProbability = 0;
     m_sSum = 0;
     m_sumNew = 0;
     m_minBad = 0;
     m_popGood = 0;
     m_z = 0;
     m_pb = 0;
     m_pg = 0;
     m_ss = 0;
     m_sb = 0;
}


}}}}//end namespace

