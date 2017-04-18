/*
MIT License

Copyright (c) 2016 cbtek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
//----------------------------------------
//RStatsSSRN.cpp generated by CBTek Solutions on 01-25-2017 at 03:48:32 PM
//----------------------------------------

#include "RStatsSSRN.h"

#include "rstats_utils/inc/RStatsUtils.hpp"

#include "utility/inc/Exception.hpp"
#include "utility/inc/FileUtils.hpp"

#include <bitset>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <memory>
#include <cstring>

using namespace cbtek::common::utility;

namespace oig {
namespace ratstats {
namespace modules {
namespace ssrn {

void RStatsSSRN::saveToCSVFile(const std::string &filePath)
{
    RStatsWorksheet sheet;
    saveToWorksheet(sheet);
    FileUtils::writeFileContents(filePath,sheet.toCommaDelimitedString());
}

void RStatsSSRN::saveToWorksheet(RStatsWorksheet &worksheetOut)
{
    worksheetOut.setDefaultFont(Font("arial",10));
    worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignRight);
    worksheetOut("A1") = "Audit Name:";
    worksheetOut("A2") = "Seed Used:";
    worksheetOut("A3") = "Frame Size:";
    worksheetOut("A4") = "Creation Date:";
    worksheetOut("A5") = "Creation Time:";
    worksheetOut("A6") = "Sequential Count:";
    worksheetOut("A7") = "Random Order Count:";
    worksheetOut("A8") = "Lower-Bound:";
    worksheetOut("A9") = "Upper-Bound:";
    worksheetOut("A10") = "Total Sum:";
    worksheetOut("A11") = "Total Count:";

    worksheetOut.setDefaultFont(Font("arial",10,true));
    worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignLeft);
    worksheetOut("B1") = m_outputData.auditName;
    worksheetOut("B2") = StringUtils::toString(m_outputData.seed,2);
    worksheetOut("B3") = StringUtils::toString(m_outputData.frameSize);
    worksheetOut("B4") = DateUtils::toLongDateString(m_outputData.createDate);
    worksheetOut("B5") = TimeUtils::to12HourTimeString(m_outputData.createTime);
    worksheetOut("B6") = StringUtils::toString(m_outputData.sequentialCount);
    worksheetOut("B7") = StringUtils::toString(m_outputData.sparesCount);
    worksheetOut("B8") = StringUtils::toString(m_outputData.lower);
    worksheetOut("B9") = StringUtils::toString(m_outputData.upper);
    worksheetOut("B10") = StringUtils::toString(m_outputData.sum);
    worksheetOut("B11") = StringUtils::toString(m_outputData.sequentialCount+m_outputData.sparesCount);
    worksheetOut.setDefaultTextAlignment(RStatsTextAlignment::AlignMiddle);
    worksheetOut("C1") = "Number Type";
    worksheetOut("D1") = "Selection Order";
    worksheetOut("E1") = "Value";
    worksheetOut.setDefaultFont(Font("arial",10,true));


    size_t r = 1;
    for (const RStatsSSRNValue& value : m_outputData.values)
    {
        std::string type = (value.orderType==RStatsSSRNOrderType::RandomlyOrdered?"(Random)":"(Spare)");
        Color typeBg = (value.orderType==RStatsSSRNOrderType::RandomlyOrdered?Color(255,255,200):Color(200,255,255));
        Color typeFg = Color(1,1,1);
        worksheetOut(r,2) = type;
        worksheetOut(r,2).fgColor = typeFg;
        worksheetOut(r,2).bgColor = typeBg;

        worksheetOut(r,3) = StringUtils::toString(value.orderIndex);
        worksheetOut(r,3).fgColor = typeFg;
        worksheetOut(r,3).bgColor = typeBg;

        worksheetOut(r,4) = StringUtils::toString(value.value);
        worksheetOut(r,4).fgColor = typeFg;
        worksheetOut(r,4).bgColor = typeBg;
        ++r;
    }
}

void RStatsSSRN::saveToTextFile(const std::string &filePath)
{
    RStatsWorksheet sheet;
    saveToWorksheet(sheet);
    FileUtils::writeFileContents(filePath,sheet.toEvenlySpacedString());
}

RStatsSSRNOutputData RStatsSSRN::execute(const std::string &auditName,
                                         RStatsFloat inputSeed,
                                         RStatsInteger sequentialOrder,
                                         RStatsInteger sparesInRandomOrder,
                                         RStatsInteger lowNumber,
                                         RStatsInteger highNumber)
{
    RStatsSSRNInputData vbRandOutput,vbRandOutputA,vbRandOutputB,vbRandOutputC;
    RStatsInteger currentSeed = this->vbRandInit(-1);
    this->vbRand(currentSeed, 30269,vbRandOutput);
    currentSeed = vbRandOutput.stepValue;
    currentSeed = vbRandomize(inputSeed,currentSeed);
    vbRand(currentSeed,30269,vbRandOutputA);
    vbRand(vbRandOutputA.stepValue,30307,vbRandOutputB);
    vbRand(vbRandOutputB.stepValue,30323,vbRandOutputC);    
    double seedA = std::floor(vbRandOutputA.ratStatValue);
    double seedB = std::floor(vbRandOutputB.ratStatValue);
    double seedC = std::floor(vbRandOutputC.ratStatValue);    
    m_sequentialCount = sequentialOrder;
    m_sparesCount = sparesInRandomOrder;
    RStatsIntegerList sequentialOrderList(sequentialOrder);
    RStatsIntegerList sparesInRandomOrderList(sparesInRandomOrder);
    RStatsInteger sampleSize = sequentialOrder + sparesInRandomOrder;
    RStatsIntegerList randomNumbers(sampleSize);
    RStatsInteger upperBound = highNumber;
    RStatsInteger lowerBound = lowNumber;
    RStatsInteger frameSize = (upperBound - lowerBound) + 1;
    std::vector<RStatsInteger> repeatCheck(frameSize);    
    m_outputData.auditName = auditName;
    m_outputData.upper = upperBound;
    m_outputData.lower = lowerBound;
    m_outputData.frameSize = frameSize;
    m_outputData.seed = inputSeed;
    m_outputData.sequentialCount = sequentialOrder;
    m_outputData.sparesCount = sparesInRandomOrder;

    for (size_t j = 0; j < sampleSize; ++j)
    {
        bool repeatFlag = true;
        while(repeatFlag)
        {
            double term1 = std::floor(seedA / 177.0);
            double term2 = seedA - (177 * term1);
            seedA = 171 * term2 - 2 * term1;
            if (seedA <= 0)
            {
                seedA += 30269;
            }

            term1 = std::floor(seedB / 176.0);
            term2 = seedB - (176 * term1);
            seedB = 172 * term2 - 35 * term1;
            if (seedB <= 0)
            {
                seedB += 30307;
            }

            term1 = std::floor(seedC / 178.0);
            term2 = seedC - (178*term1);
            seedC = 170 * term2 - 63 * term1;
            if (seedC <= 0)
            {
                seedC += 30323;
            }

            double term4 = seedA/30269.0 + seedB/30307.0 + seedC/30323.0;
            RStatsInteger value = std::floor((term4 - std::floor(term4)) * (upperBound-lowerBound+1)) + lowerBound;
            randomNumbers(j) = value;
            if (value == 0)
            {
                int x = 0;
            }
            int check = (value - lowerBound);
            if (check >=0 && check < repeatCheck.size())
            {
                if (repeatCheck[check] == 0)
                {
                    repeatCheck[check] = 1;
                    repeatFlag = false;
                }
            }
        }
    }

    //Note: The naming here can be a little confusing
    //Given an associative container: values[index] = value
    //RandomOrder means that the "values" will appear at random but the "indices" will be
    //in order.
    //This is considered to be "RandomOrder"
    //values[0] = 10
    //values[1] = 6
    //values[2] = 3
    //values[3] = 13

    //SequentialOrder means that the "values" will be sorted by "value" rather than "index"
    //which makes the index appear random.
    //This is considered to be in SequentialOrder:
    //values[2] = 3
    //values[1] = 6
    //values[0] = 10
    //values[3] = 13
    m_outputData.createDate = DateUtils::getCurrentDate();
    m_outputData.createTime = TimeUtils::getCurrentTime();

    size_t index = 0;
    std::map<RStatsInteger, RStatsSSRNValue> sequentialOrderMap;
    std::map<size_t, RStatsSSRNValue> randomOrderMap;
    RStatsInteger sum = 0;
    for (const auto& value : randomNumbers.toStdVector())
    {
        RStatsSSRNValue ssrnValue;
        ssrnValue.value = value;
        ssrnValue.orderIndex = index + 1;
        sum += value;
        if (this->m_sequentialCount > 0)
        {
            ssrnValue.orderType = RStatsSSRNOrderType::SequentiallyOrdered;
            sequentialOrderMap[value] = ssrnValue;
            m_sequentialCount--;
        }
        else if (this->m_sparesCount > 0)
        {
            ssrnValue.orderType = RStatsSSRNOrderType::RandomlyOrdered;
            randomOrderMap[index + 1] = ssrnValue;
            m_sparesCount--;
        }
        ++index;
    }


    for (const auto& it : sequentialOrderMap)
    {
        m_outputData.values.push_back(it.second);
    }

    for (const auto& it : randomOrderMap)
    {
        m_outputData.values.push_back(it.second);
    }
    m_outputData.sum = sum;
    return m_outputData;
}

RStatsInteger RStatsSSRN::vbRandInit(float initVariable)
{
    float fpVal = initVariable;
    std::int32_t fpValInt;
    memcpy(&fpValInt, &fpVal, sizeof(fpValInt));
    std::bitset<32> bits32(fpValInt), output32A,output32B;
    for (size_t a1 = 24; a1 < 32; ++a1)
    {
        output32A.set(a1-24,bits32[a1]);
    }

    for (size_t a1 = 0; a1 < 24; ++a1)
    {
        output32B.set(a1, bits32[a1]);
    }

    return output32A.to_ulong() + output32B.to_ulong();
}


void RStatsSSRN::vbRand(RStatsInteger ExcelSeed,
                           RStatsInteger outputmax,
                           RStatsSSRNInputData & output)
{
    RStatsInteger vara,varb,varc;
    vara = ExcelSeed;
    varb = 1140671485;
    varc = 12820163;
    bool firstflag = true;
    double ValueA = 0;
    while(ValueA >= outputmax | firstflag)
    {
        firstflag = false;
        vara = ExcelSeed;
        ExcelSeed =  (vara * varb + varc ) % (RStatsUtils::ipow(2,24));
        ValueA = (outputmax*ExcelSeed/(double)(RStatsUtils::ipow(2,24)))+1;
    }
    output.stepValue = ExcelSeed;
    output.excelValue = ((double)ExcelSeed/((double)(RStatsUtils::ipow(2,24))));
    output.ratStatValue = ValueA;
}

RStatsInteger RStatsSSRN::vbRandomize(RStatsFloat startingPoint,
                                      RStatsFloat currentSeed)
{
    double fpVal = startingPoint;
    RStatsInteger fpValInt;
    memcpy(&fpValInt, &fpVal, sizeof(fpValInt));
    std::bitset<64> bits64(fpValInt);
    std::bitset<32> bits32;

    for (size_t a1 = 32;a1 < 64;++a1)
    {
        bits32.set(a1-32,bits64[a1]);
    }

    bits64 = std::bitset<64>(currentSeed);
    std::bitset<32> varaBits32,varbBits32,xorBits32,finalBits32A,finalBits32B,finalBits32;
    for (size_t a1 = 0;a1 < 16;++a1)
    {
        varaBits32.set(a1,bits32[a1]);
        varbBits32.set(a1,bits32[a1+16]);
    }

    //perform bitwise xor
    for (size_t a1 = 0;a1 < 32;++a1)
    {
        xorBits32.set(a1,varaBits32[a1] ^ varbBits32[a1]);
    }

    for (size_t a1 = 0;a1 < 16;++a1)
    {
        finalBits32A.set(a1+8,xorBits32[a1]);
    }

    for (size_t a1 = 0;a1 < 8;++a1)
    {
        finalBits32B.set(a1,bits64[a1]);
    }

    for (size_t a1 = 0;a1 < 32;++a1)
    {
        finalBits32.set(a1,finalBits32A[a1] | finalBits32B[a1]);
    }
    return finalBits32.to_ullong();
}
}}}}//end namespace

