/*
    RStatsUVA.cpp
    

*/
//----------------------------------------
//RStatsUVA.cpp generated by CBTek Solutions on 02-07-2017 at 01:15:14 AM
//----------------------------------------

#include "RStatsUVA.h"

#include "utility/inc/StringUtils.hpp"

using namespace oig::ratstats::utils;
using namespace cbtek::common::utility;

namespace oig {
namespace ratstats {
namespace modules {
namespace uva {

void RStatsUVA::execute(const std::string &auditName,
                        size_t universeSize,
                        const RStatsWorksheet &dataSheetInput,
                        size_t dataSheetRowOffset,
                        const RStatsDataFormatTypeIndex &dataSheetDatasetColumnTypeIndex)
{
    if (dataSheetInput.getNumColumns() < 1)
    {
        return;
    }

    m_auditName = auditName;
    std::vector<RStatsFloat> primaryDataset,secondaryDataset;



    bool hasSecondaryDataset = ((dataSheetDatasetColumnTypeIndex.type == RStatsDataFormatType::AuditAndDifference ||
                                dataSheetDatasetColumnTypeIndex.type == RStatsDataFormatType::ExamineAndDifference ||
                                dataSheetDatasetColumnTypeIndex.type == RStatsDataFormatType::ExamineAndAudit) &&
                                dataSheetInput.getNumColumns() > 1);

    std::pair<std::string,std::string> typePair = RStatsUtils::getDataFormatTypeStr(dataSheetDatasetColumnTypeIndex.type);
    std::string primaryTypeStr = typePair.first;
    std::string secondaryTypeStr = typePair.second;

    for (size_t r = dataSheetRowOffset; r < dataSheetInput.getNumRows(); ++r)
    {
        std::string value1 = dataSheetInput(r,dataSheetDatasetColumnTypeIndex.primaryDatasetColumnIndex).text;
        std::string value2;
        StringUtils::removeInPlace(value1, "$");
        StringUtils::removeInPlace(value1, "(");
        StringUtils::removeInPlace(value1, ")");
        StringUtils::removeInPlace(value1, ",");
        if (!StringUtils::isNumeric(value1))
        {
            THROW_GENERIC_EXCEPTION("The "+primaryTypeStr+" value \""+value1+"\" in row \""+std::to_string(r+1)+"\" is not a valid number!");
        }
        if (hasSecondaryDataset)
        {
            value2 = dataSheetInput(r,dataSheetDatasetColumnTypeIndex.secondaryDatasetColumnIndex).text;
            StringUtils::removeInPlace(value2, "$");
            StringUtils::removeInPlace(value2, "(");
            StringUtils::removeInPlace(value2, ")");
            StringUtils::removeInPlace(value2, ",");
            if (!StringUtils::isNumeric(value2))
            {
                THROW_GENERIC_EXCEPTION("The "+secondaryTypeStr+" value \""+value2+"\" in row \""+std::to_string(r+1)+"\" is not a valid number!");
            }
            secondaryDataset.push_back(StringUtils::toFloat64(value2));
        }
        primaryDataset.push_back(StringUtils::toFloat64(value1));
    }

    RStatsFloatList values;
    values.addValues(primaryDataset);
    if (hasSecondaryDataset)
    {
        values.addValues(secondaryDataset);
    }
    execute(values,values.size(),universeSize,dataSheetDatasetColumnTypeIndex.type);
}

void RStatsUVA::saveToWorkbook(RStatsWorkbook& workbook)
{
    //std::cerr << "Done\n";
    for (const auto& outputData : m_outputDataList)
    {
        RStatsWorksheet sheet;
        sheet.setWorksheetTitle(m_auditName);
        sheet.setDefaultTextAlignment(RStatsTextAlignment::AlignRight);
        sheet.setDefaultFont(cbtek::common::utility::Font("arial",11,true));

        sheet("A1")= "Sample Type:";
        sheet("A2") = "Audit Name:";
        sheet("A3") = "Universe Size:";
        sheet("A4") = "Sample Size:";
        sheet("A5") = "Nonzero Count:";
        sheet("A6") = "Creation Date:";
        sheet("A7") = "Creation Time:";
        sheet("A8") = "Created By:";        

        sheet("C1") = "Kurtosis:";
        sheet("C2") = "Mean:";
        sheet("C3") = "Skewness:";
        sheet("C4") = "Total Sum:";
        sheet("C5") = "Std. Deviation:";
        sheet("C6") = "Std. Err. Mean:";
        sheet("C7") = "Std. Err. Total:";
        sheet("C8") = "Point Estimate:";        

        sheet("A12") = "Lower:";
        sheet("A13") = "Upper:";
        sheet("A14")= "Precision Amount:";
        sheet("A15")= "Precision Percent:";

        sheet.setDefaultTextAlignment(RStatsTextAlignment::AlignMiddle);
        sheet("C10") = "Confidence Levels";
        sheet("B11") = "80%";
        sheet("C11") = "90%";
        sheet("D11") = "95%";
        sheet("B11").bgColor.set(255,127,127);
        sheet("C11").bgColor.set(255,255,127);
        sheet("D11").bgColor.set(127,255,127);
        sheet("B11").fgColor.set(1,1,1);
        sheet("C11").fgColor.set(1,1,1);
        sheet("D11").fgColor.set(1,1,1);
        sheet.setDefaultFont(cbtek::common::utility::Font("arial",10,false));
        sheet.setDefaultTextAlignment(RStatsTextAlignment::AlignLeft);
        sheet("B1") = outputData.title;
        sheet("B2") = m_auditName;
        sheet("B3") = m_universeSize;
        sheet("B4") = m_sampleSize;
        sheet("B5") = StringUtils::toString(static_cast<size_t>(outputData.nonZeroSize));
        sheet("B6") = DateUtils::toLongDateString(DateUtils::getCurrentDate());
        sheet("B7") = TimeUtils::to12HourTimeString(TimeUtils::getCurrentTime());
        sheet("B8") = SystemUtils::getUserName();

        sheet("D1") = StringUtils::toString(outputData.kurtosis,2);
        sheet("D2") = StringUtils::toString(outputData.mean,2);
        sheet("D3") = StringUtils::toString(outputData.skewness,2);
        sheet("D4") = StringUtils::toString(outputData.totalAmount,2);
        sheet("D5") = StringUtils::toString(outputData.standardDeviation,2);
        sheet("D6") = StringUtils::toString(outputData.standardErrorMean,2);
        sheet("D7") = StringUtils::toString(outputData.standardErrorTotal);
        sheet("D8") = StringUtils::toString(outputData.pointEstimate);
        sheet.resetDefaults();
        sheet.setDefaultTextAlignment(RStatsTextAlignment::AlignMiddle);
        sheet.setDefaultFont(Font("arial",11));
        sheet.setDefaultFloatingPointDecimals(2);
        sheet.setDefaultFloatingPointDecimals(0);

        std::string percent80 = StringUtils::toString(outputData.precisionPercent80*100.,2)+"%";
        std::string percent90 = StringUtils::toString(outputData.precisionPercent90*100.,2)+"%";
        std::string percent95 = StringUtils::toString(outputData.precisionPercent95*100.,2)+"%";

        sheet("B12") = outputData.lower80;
        sheet("C12") = outputData.lower90;
        sheet("D12") = outputData.lower95;

        sheet("B13") = outputData.upper80;
        sheet("C13") = outputData.upper90;
        sheet("D13") = outputData.upper95;

        sheet("B14") = outputData.precisionAmount80;
        sheet("C14") = outputData.precisionAmount90;
        sheet("D14") = outputData.precisionAmount95;

        sheet("B15") = percent80;
        sheet("C15") = percent90;
        sheet("D15") = percent95;

        sheet.setDefaultTextAlignment(RStatsTextAlignment::AlignRight);
        sheet.setDefaultFont(cbtek::common::utility::Font("arial",11,true));
        sheet("A16") = "t-Value:";
        sheet.setDefaultFloatingPointDecimals(12);
        sheet.setDefaultTextAlignment(RStatsTextAlignment::AlignMiddle);
        sheet("B16") = outputData.tValue80;
        sheet("C16") = outputData.tValue90;
        sheet("D16") = outputData.tValue95;
        sheet.setRowBackgroundColor(16,Color("#111111"));
        workbook.addWorksheet(sheet);
    }
}

void RStatsUVA::execute(const utils::RStatsFloatList &values,
                        size_t sampleSize,
                        size_t universeSize,
                        RStatsDataFormatType type)
{
    //std::cerr << "Start\n";
    this->reset();
    m_sampleSize = static_cast<RStatsInteger>(sampleSize);
    m_universeSize = static_cast<RStatsInteger>(universeSize);
    RStatsFloatList auditValues,examineValues,differenceValues;
    if (type == RStatsDataFormatType::Examine)
    {
        examineValues = values;
    }
    else if (type == RStatsDataFormatType::Audit)
    {
        auditValues = values;
    }
    else if (type == RStatsDataFormatType::Difference)
    {
        differenceValues = values;
    }
    else if (type == RStatsDataFormatType::ExamineAndAudit)
    {
        examineValues = values.getValues(0);
        auditValues = values.getValues(1);
        differenceValues = RStatsUtils::getNumbersSubtracted(examineValues,auditValues);
    }
    else if (type == RStatsDataFormatType::ExamineAndDifference)
    {
        examineValues = values.getValues(0);
        differenceValues = values.getValues(1);
        auditValues = RStatsUtils::getNumbersSubtracted(examineValues,differenceValues);
    }
    else if (type == RStatsDataFormatType::AuditAndDifference)
    {
        auditValues = values.getValues(0);
        differenceValues = values.getValues(1);
        examineValues = RStatsUtils::getNumbersAdded(auditValues,differenceValues);
    }

    for (size_t a1 = 0; a1 < sampleSize; ++a1)
    {
        double value = 0.;
        if (type == RStatsDataFormatType::Examine)
        {
            value = examineValues(a1);
            m_totalAmount(0) += value;
            m_totalPowerOfTwoAmount(0) += std::pow(value,2);
            m_totalPowerOfThreeAmount(0) += std::pow(value,3);
            m_totalPowerOfFourAmount(0) += std::pow(value,4);
            if (!RStatsUtils::isEqual(value,0.))
            {
                m_totalNonZeroCount(0)++;
            }
        }
        else if (type == RStatsDataFormatType::Audit)
        {
            value = auditValues(a1);
            m_totalAmount(1) += value;
            m_totalPowerOfTwoAmount(1) += std::pow(value,2);
            m_totalPowerOfThreeAmount(1) += std::pow(value,3);
            m_totalPowerOfFourAmount(1) += std::pow(value,4);
            if (!RStatsUtils::isEqual(value,0.))
            {
                m_totalNonZeroCount(1)++;
            }
        }
        else if (type == RStatsDataFormatType::Difference)
        {
            value = differenceValues(a1);
            m_totalAmount(2) += value;
            m_totalPowerOfTwoAmount(2) += std::pow(value,2);
            m_totalPowerOfThreeAmount(2) += std::pow(value,3);
            m_totalPowerOfFourAmount(2) += std::pow(value,4);
            if (!RStatsUtils::isEqual(value,0.))
            {
                m_totalNonZeroCount(2)++;
            }
        }
        else
        {
            value = examineValues(a1);
            m_totalAmount(0) += value;
            m_totalPowerOfTwoAmount(0) += std::pow(value,2);
            m_totalPowerOfThreeAmount(0) += std::pow(value,3);
            m_totalPowerOfFourAmount(0) += std::pow(value,4);
            if (!RStatsUtils::isEqual(value,0.))
            {
                m_totalNonZeroCount(0)++;
            }

            value = auditValues(a1);
            m_totalAmount(1) += value;
            m_totalPowerOfTwoAmount(1) += std::pow(value,2);
            m_totalPowerOfThreeAmount(1) += std::pow(value,3);
            m_totalPowerOfFourAmount(1) += std::pow(value,4);
            if (value > 0 || value < 0 || !RStatsUtils::isEqual(value,0.))
            {
                m_totalNonZeroCount(1)++;
            }

            value = differenceValues(a1);
            m_totalAmount(2) += value;
            m_totalPowerOfTwoAmount(2) += std::pow(value,2);
            m_totalPowerOfThreeAmount(2) += std::pow(value,3);
            m_totalPowerOfFourAmount(2) += std::pow(value,4);
            if (!RStatsUtils::isEqual(value,0.))
            {
                m_totalNonZeroCount(2)++;
            }
        }
    }


    calculateMeans();
    calculatePointEstimates();
    calculateCorrectionFactor();
    calculateDegreesOfFreedom();
    calculateStandardDeviation();
    calculateStandardError();

    if (type == RStatsDataFormatType::Audit)
    {
        createOutputData("Summary for Audit Values",1);
    }
    else if (type == RStatsDataFormatType::Difference)
    {
        createOutputData("Summary for Difference Values",2);
    }
    else if (type == RStatsDataFormatType::Examine)
    {
        createOutputData("Summary for Examine Values",0);
    }
    else
    {
        createOutputData("Summary for Examine Values",0);
        createOutputData("Summary for Audit Values",1);
        createOutputData("Summary for Difference Values",2);
    }    
}

//'----------CALCULATE KURTOSIS-------------
void RStatsUVA::calculateKurtosis()
{
    for (size_t a1 = 0; a1 < 3; ++a1)
    {
        if (m_sampleSize > 0 &&
            m_totalNonZeroCount(a1) > 0)
        {

            RStatsFloat cubeRt = m_totalPowerOfThreeAmount(a1);
            RStatsFloat quadRt = m_totalPowerOfFourAmount(a1);
            RStatsFloat sqRt = m_totalPowerOfTwoAmount(a1);
            RStatsFloat sampSize = static_cast<RStatsFloat>(m_sampleSize);
            RStatsFloat mean = m_means(a1);

            RStatsFloat temp1 = quadRt / sampSize;
            temp1 -= (4 * (cubeRt / sampSize)) * mean;
            temp1 += (6 * (sqRt / sampSize) * std::pow(mean,2));
            temp1 -= (3 * std::pow(mean,4));
            RStatsFloat temp2 = 0.;
            if (sqRt / sampSize > std::pow(mean,2))
            {
                temp2 = std::sqrt(sqRt / sampSize - std::pow(mean,2));
            }
            else
            {
                temp2 = 0;
            }
            if (temp2 > 1 || RStatsUtils::isEqual(temp2,1.))
            {
                m_kurtosis(a1) = temp1 / std::pow(temp2,4);
            }
        }
    }
}

void RStatsUVA::createOutputData(const std::string &title, size_t index)
{
    RStatsUVAOutputData outputData;
    outputData.title = title;
    outputData.pointEstimate = static_cast<RStatsInteger>(std::round(m_totalPointEstimates(index)));
    outputData.standardDeviation = m_standardDeviation(index);
    outputData.standardErrorMean = m_standardError(index);
    outputData.standardErrorTotal = std::roundl((m_standardError(index) * static_cast<RStatsFloat>(m_universeSize)));
    outputData.skewness = m_skewAmount(index);
    outputData.mean = m_means(index);
    outputData.nonZeroSize = static_cast<RStatsInteger>(m_totalNonZeroCount(index));
    outputData.kurtosis = m_kurtosis(index);
    if (outputData.pointEstimate < 0)
    {


    }
    outputData.lower80 = m_lower80(index);
    outputData.lower90 = m_lower90(index);
    outputData.lower95 = m_lower95(index);

    outputData.upper80 = m_upper80(index);
    outputData.upper90 = m_upper90(index);
    outputData.upper95 = m_upper95(index);

    outputData.tValue80 = m_temporary80;
    outputData.tValue90 = m_temporary90;
    outputData.tValue95 = m_temporary95;    
    outputData.populationSize = m_universeSize;
    outputData.precisionPercent80 = m_precision80(index) * m_universeSize;
    outputData.precisionPercent90 = m_precision90(index) * m_universeSize;
    outputData.precisionPercent95 = m_precision95(index) * m_universeSize;
    outputData.totalAmount = m_totalAmount(index);
    if (m_means(index) > 0)
    {
        outputData.precisionPercent80 = m_precision80(index) / m_means(index);
        outputData.precisionPercent90 = m_precision90(index) / m_means(index);
        outputData.precisionPercent95 = m_precision95(index) / m_means(index);
    }
    outputData.precisionAmount80 = m_precision80(index) * (m_universeSize);
    outputData.precisionAmount90 = m_precision90(index) * (m_universeSize);
    outputData.precisionAmount95 = m_precision95(index) * (m_universeSize);
    m_outputDataList.push_back(outputData);
}


RStatsUVA::RStatsUVA()
{

}

RStatsUVA::~RStatsUVA()
{

}


void RStatsUVA::calculateMeans()
{   
    for (size_t a1 = 0; a1 < 3; ++a1)
    {
        if (m_sampleSize > 0 && m_totalNonZeroCount(a1) > 0)
        {
            m_means(a1) = m_totalAmount(a1) / static_cast<RStatsFloat>(m_sampleSize);
            //std::cerr << "Means:" <<m_means(a1)<<std::endl;
        }
    }    
}

void RStatsUVA::calculatePointEstimates()
{ 
    for (size_t a1 = 0; a1 < 3; ++a1)
    {
        m_pointEstimates(a1) = m_means(a1) * m_universeSize;
        m_totalPointEstimates(a1)+=m_pointEstimates(a1);
        //std::cerr << "PointEst1:" <<m_pointEstimates(a1)<<std::endl;
        //std::cerr << "PointEst2:" <<m_totalPointEstimates(a1)<<std::endl;
    }    
}

void RStatsUVA::calculateCorrectionFactor()
{    
    if (m_universeSize > 1)
    {
        m_sefin =  (std::sqrt((m_universeSize - m_sampleSize) / ((RStatsFloat)m_universeSize)));
        //std::cerr << "Sefin:" << m_sefin << std::endl;
    }
}

void RStatsUVA::calculateDegreesOfFreedom()
{
    m_currentDOF = m_sampleSize - 1;
    //std::cerr << "Degrees:" << m_currentDOF << std::endl;
}

void RStatsUVA::calculateStandardDeviation()
{    
    for (size_t a1 = 0; a1 < 3; ++a1)
    {
        if (RStatsUtils::isEqual(m_totalAmount(a1),0.) == false &&
            m_sampleSize > 1)
        {
            RStatsFloat temp =  ((std::pow(m_totalAmount(a1),2)) / static_cast<RStatsFloat>(m_sampleSize));
            if (temp < m_totalPowerOfTwoAmount(a1))
            {
                m_standardDeviation(a1) =  (std::sqrt((m_totalPowerOfTwoAmount(a1) - temp) / m_currentDOF));
            }
            else
            {
                m_standardDeviation(a1) = 0;
            }
        }
    }
}

void RStatsUVA::calculateUpperAndLowerLimits()
{
    for (size_t a1 = 0; a1 < 3; ++a1)
    {
        if (m_totalNonZeroCount(a1) > 0)
        {
            RStatsFloat temp0 = m_precision80(a1) * m_universeSize;
            RStatsFloat temp1 = m_precision90(a1) * m_universeSize;
            RStatsFloat temp2 = m_precision95(a1) * m_universeSize;
            m_lower80(a1) = m_pointEstimates(a1) - temp0;
            m_lower90(a1) = m_pointEstimates(a1) - temp1;
            m_lower95(a1) = m_pointEstimates(a1) - temp2;
            m_upper80(a1) = m_pointEstimates(a1) + temp0;
            m_upper90(a1) = m_pointEstimates(a1) + temp1;
            m_upper95(a1) = m_pointEstimates(a1) + temp2;
        }
    }
}

void RStatsUVA::calculateOverallPrecision()
{
    //std::cerr << "CalOverallPrec" << std::endl;
//    for (size_t a1 = 0; a1 < 3; ++a1)
//    {
//        if (m_nonZeroCount(a1) > 0)
//        {
//            m_standardError(a1) = std::sqrt(m_standardError(a1));
//            m_precesion80(a1) = m_tval
//        }
//           STDERR#(0, Loop2%) = Sqr(STDERR#(0, Loop2%))
//           PRCISN#(0, Loop2%, 1) = TVALS#(30, 0) * STDERR#(0, Loop2%)
//           LWRLMT#(0, Loop2%, 1) = PNTEST#(0, Loop2%) - PRCISN#(0, Loop2%, 0)
//           UPRLMT#(0, Loop2%, 1) = PNTEST#(0, Loop2%) + PRCISN#(0, Loop2%, 0)
//
//             PRCISN#(0, Loop2%, 1) = TVALS#(30, 1) * STDERR#(0, Loop2%)
//           LWRLMT#(0, Loop2%, 1) = PNTEST#(0, Loop2%) - PRCISN#(0, Loop2%, 1)
//           UPRLMT#(0, Loop2%, 1) = PNTEST#(0, Loop2%) + PRCISN#(0, Loop2%, 1)
//
//             PRCISN#(0, Loop2%, 2) = TVALS#(30, 2) * STDERR#(0, Loop2%)
//           LWRLMT#(0, Loop2%, 2) = PNTEST#(0, Loop2%) - PRCISN#(0, Loop2%, 2)
//           UPRLMT#(0, Loop2%, 2) = PNTEST#(0, Loop2%) + PRCISN#(0, Loop2%, 2)
//        End If
//    Next Loop2%
   // }
}

void RStatsUVA::calculateStandardError()
{    
    for (size_t a1 = 0; a1 < 3; ++a1)
    {
        if (RStatsUtils::isEqual(m_standardDeviation(a1), 0.) == false &&
            m_sampleSize > 1)
        {
            m_standardError(a1) =  ((m_standardDeviation(a1) / std::sqrt(m_sampleSize)) * m_sefin);
            RStatsFloat universe = static_cast<RStatsFloat>(m_universeSize);
            RStatsFloat sample = static_cast<RStatsFloat>(m_sampleSize);
            RStatsFloat tempValue = (m_standardDeviation(a1) * std::sqrt((universe / sample) * (universe - sample)));
            tempValue = std::pow(tempValue,2);
            m_totalStandardError(a1) += tempValue;
            //std::cerr << "StdErr1:" <<m_standardError(a1)<<std::endl;
            //std::cerr << "StdErr2:" <<m_totalStandardError(a1)<<std::endl;
        }
    }
    processSamplingError();
}

void RStatsUVA::calculateSkewness()
{
    for (size_t a1 = 0; a1 < 3; ++a1)
    {
        if (m_sampleSize > 0 && m_totalNonZeroCount(a1) > 0)
        {
            RStatsFloat meanRaised2 = std::pow(m_means(a1),2);
            RStatsFloat temp1 = m_totalPowerOfThreeAmount(a1) / m_sampleSize;
            temp1 -= ((3 * m_totalPowerOfTwoAmount(a1) / m_sampleSize) * m_means(a1));
            temp1 += (2 *  std::pow(m_means(a1),3));
            RStatsFloat temp2 = 0;
            if ((m_totalPowerOfTwoAmount(a1) / m_sampleSize) > meanRaised2)
            {
                temp2 = std::sqrt((m_totalPowerOfTwoAmount(a1) / m_sampleSize) - meanRaised2);
            }
            else
            {
                temp2 = 0.;
            }
            if (temp2 >= 1)
            {
                m_skewAmount(a1) = temp1 / std::pow(temp2,3);
            }
            //std::cerr << "Skew:" <<m_skewAmount(a1)<<std::endl;
        }
    }
    calculateKurtosis();
}

void RStatsUVA::processSamplingError()
{    
    //std::cerr << "Sampling Error" <<std::endl;
    m_temporary80 = m_temporary90 = m_temporary95 = 0.;
    int dof = static_cast<int>(m_currentDOF);
    if (dof > 3)
    {
        processSetup();
    }
    else if (dof == 1)
    {
        m_temporary80 = 3.077683537175;
        m_temporary90 = 6.313751514675;
        m_temporary95 = 12.706204736175;
    }
    else if (dof == 2)
    {
        m_temporary80 = 1.885618083164;
        m_temporary90 = 2.919985580354;
        m_temporary95 = 4.30265272975;
    }
    else if (dof == 3)
    {
        m_temporary80 = 1.637744353696;
        m_temporary90 = 2.353363434802;
        m_temporary95 = 3.182446305284;
    }
    processFindIntervals();
}

void RStatsUVA::processFindIntervals()
{
    //std::cerr << "FindIntervals" <<std::endl;
    for (size_t a1 = 0; a1 < 3; ++a1)
    {
        if (m_totalNonZeroCount(a1) > 0)
        {
            m_precision80(a1) = m_temporary80 * m_standardError(a1);
            m_precision90(a1) = m_temporary90 * m_standardError(a1);
            m_precision95(a1) = m_temporary95 * m_standardError(a1);
            //std::cerr << "Prec80:" << m_precision80(a1) << std::endl;
            //std::cerr << "Prec90:" << m_precision90(a1) << std::endl;
            //std::cerr << "Prec95:" << m_precision95(a1) << std::endl;
        }
    }

    calculateUpperAndLowerLimits();
    calculateSkewness();
    calculateOverallPrecision();



}

void RStatsUVA::processSetup()
{
    //std::cerr << "TSetup" << std::endl;
    m_totalNumberOfTerms = 100;
    m_totalNumberOfConditionalIterations = 1000;
    m_eps = 0.00000000000001;
    m_formulaA = .5;
    m_formulaB = .5 * m_currentDOF;
    m_formulaPI = 4 * std::atan(1);
    m_conditionalCounter = 0;
    processConditionalLoop();
}

void RStatsUVA::processConditionalLoop()
{
    //std::cerr << "ConLoop:"<<m_conditionalCounter<<std::endl;
    ++m_conditionalCounter;
    m_currentLowValue = 0;
    m_currentHighValue = 4;
    m_conditionalUsage = 0;
    if (m_conditionalCounter == 1)
    {
       m_conditionalUsage = 80;
    }
    else if (m_conditionalCounter == 2)
    {
       m_conditionalUsage = 90;
    }
    else if (m_conditionalCounter == 3)
    {
       m_conditionalUsage = 95;
    }
    //std::cerr << "CumProb:" << m_cumalativeProbability << std::endl;

    m_cumalativeProbability = (static_cast<RStatsFloat>(m_conditionalUsage) / 200. + 0.5);

       // Set Low prob
       m_tValue = m_currentLowValue;       
       processFindCumaltiveProbability();
       //std::cerr << "CumProb-Low:" << m_cumalativeProbability << std::endl;
       //std::cerr << "Prob-Low:" << m_currentProbability << std::endl;
       m_currentLowProbability = m_currentProbability;

       // Set High prob
       m_tValue = m_currentHighValue;
       processFindCumaltiveProbability();
       //std::cerr << "CumProb-High:" << m_cumalativeProbability << std::endl;
       //std::cerr << "Prob-High:" << m_currentProbability << std::endl;
       m_currentHighProbability = m_currentProbability;

       m_conditionalIterator = 0;
       processStartLoop();
}

void RStatsUVA::processStartLoop()
{
    //std::cerr << "Start Loop:" << m_conditionalIterator << std::endl;
    ++m_conditionalIterator;    
    m_lastTValue = m_tValue;

    RStatsFloat value = static_cast<RStatsFloat>(m_currentLowValue) + static_cast<RStatsFloat>(m_currentHighValue);
    m_tValue = ( value / 2.);
    processFindCumaltiveProbability();
    RStatsFloat newProb = m_currentProbability;
    if (m_currentProbability < m_cumalativeProbability)
    {
        m_currentLowValue = m_tValue;
    }
    else
    {
        m_currentHighValue = m_tValue;
    }
    RStatsFloat difference = std::fabs(m_tValue - m_lastTValue) - m_eps;
    if (difference < 0 || RStatsUtils::isEqual(difference,0.))
    {
        if (m_conditionalCounter == 1)
        {
            m_temporary80 = m_tValue;
        }
        else if (m_conditionalCounter == 2)
        {
            m_temporary90 = m_tValue;
        }
        else
        {
            m_temporary95 = m_tValue;
        }
    }
    else
    {
        if (m_conditionalIterator < m_totalNumberOfConditionalIterations)
        {
            processStartLoop();
        }
        else
        {
            THROW_GENERIC_EXCEPTION("Program was unable to determine a t-value");
        }
    }
    if (m_conditionalCounter < 3)
    {
        processConditionalLoop();
    }
    else
    {
        processFindIntervals();
    }
    processFindCumaltiveProbability();
}

void RStatsUVA::processFindCumaltiveProbability()
{
    //std::cerr << "FindCumProb" << std::endl;
    m_xValue = (std::pow(m_tValue,2) / (std::pow(m_tValue,2)+m_currentDOF));
    RStatsInteger nterms = 0;
    RStatsInteger dof = static_cast<RStatsInteger>(m_currentDOF);
    //find C0;
    if (dof == 2)
    {
        m_formulaC0 = 1;
        processFindTerms();
    }

    if (dof == 3)
    {
        m_formulaC0 =  (4 / m_formulaPI);
        processFindTerms();
    }

    if ((dof - 2 * (dof / 2)) == 0)
    {
        m_formulaC0 = 1;
        nterms = dof / 2 - 1;
        for (int i = 1; i <= nterms; ++i)
        {
            RStatsFloat temp = 2 * i + 1;
            m_formulaC0 =  ((m_formulaC0 * temp) / (temp - 1));
        }
    }
    else
    {
        m_formulaC0 = 4 / m_formulaPI;
        nterms = ((dof - 1) / 2) - 1;
        for (int i = 1; i <= nterms; ++i)
        {
            RStatsFloat temp = 2 * i + 2;
            m_formulaC0 =  ((m_formulaC0 * temp) / (temp - 1));
        }
    }
    processFindTerms();
}

void RStatsUVA::reset()
{

  m_kurtosis.initialize(3);
  m_means.initialize(3);
  m_pointEstimates.initialize(3);
  m_standardError.initialize(3);
  m_standardDeviation.initialize(3);
  m_skewAmount.initialize(3);
  m_precision80.initialize(3);
  m_precision90.initialize(3);
  m_precision95.initialize(3);
  m_upper80.initialize(3);
  m_upper90.initialize(3);
  m_upper95.initialize(3);
  m_lower80.initialize(3);
  m_lower90.initialize(3);
  m_lower95.initialize(3);
  m_tValue80.initialize(3);
  m_tValue90.initialize(3);
  m_tValue95.initialize(3);
  m_nonZeroCount.initialize(3);
  m_totalNonZeroCount.initialize(3);
  m_totalPointEstimates.initialize(3);
  m_totalStandardError.initialize(3);
  m_totalStandardDeviation.initialize(3);
  m_totalAmount.initialize(3);
  m_totalPowerOfTwoAmount.initialize(3);
  m_totalPowerOfThreeAmount.initialize(3);
  m_totalPowerOfFourAmount.initialize(3);
  m_totalNonZeroCount.initialize(3);                
  m_cumalativeProbability = 0;
  m_currentProbability = 0;
  m_currentLowProbability = 0;
  m_currentHighProbability = 0;
  m_currentLowValue = 0;
  m_currentHighValue = 0;
  m_currentDOF = 0;
  m_cumalativeProbability = 0;
  m_tValue = 0;
  m_xValue = 0;
  m_lastTValue = 0;
  m_temporary80 = 0;
  m_temporary90 = 0;
  m_temporary95 = 0;
  m_formulaC0 = 0;
  m_formulaPI = 0;
  m_formulaB = 0;
  m_formulaA = 0;
  m_eps = 0;
  m_sefin = 0;
  m_front = 0;
  m_temporaryValue = 0;
  m_conditionalUsage  = 0;
  m_conditionalCounter  = 0;
  m_totalNumberOfTerms  = 0;
  m_conditionalIterator  = 0;
  m_sampleSize  = 0;
  m_universeSize  = 0;
  m_totalNumberOfConditionalIterations  = 0;

}

void RStatsUVA::processFindCurrentProbability()
{
    //std::cerr << "FindProbVal" << std::endl;
    m_currentProbability = .5 * (m_front * m_temporaryValue + 1);
}

void RStatsUVA::processFindTerms()
{
    //std::cerr << "FindTerms" << std::endl;
    m_front = std::pow((1 - m_xValue), m_formulaB) *
              std::pow(m_xValue,m_formulaA);
    m_temporaryValue = m_formulaC0;
   RStatsFloat logOld = std::log(m_temporaryValue);
   if (RStatsUtils::isEqual(m_xValue, 0.))
   {
       m_temporaryValue = 0.;
       processFindCurrentProbability();
       return;
   }
   for (int a1 = 1; a1 <= m_totalNumberOfTerms; ++a1)
   {
       RStatsFloat log1 =  (std::log((a1 - 1 + m_formulaA + m_formulaB) / (a1 + m_formulaA)));
       RStatsFloat log2 = logOld;
       RStatsFloat log3 = std::log(m_xValue);
       RStatsFloat log4 = log1 + log2 + a1 * std::log(m_xValue);
       logOld = log1 + log2;
       m_temporaryValue += std::exp(log4);       
   }
    processFindCurrentProbability();
}


}}}}//end namespace


