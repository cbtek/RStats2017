/*
    RStatsSSRN.h
    
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
#pragma once

#include <vector>
#include <string>

#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsWorksheet.h"
#include "rstats_utils/inc/RStatsObjectList.hpp"

using namespace oig::ratstats::utils;

namespace oig {
namespace ratstats {
namespace modules {
namespace ssrn {

enum class RStatsSSRNOrderType
{
    SequentiallyOrdered,
    RandomlyOrdered
};

/**
 * @brief The RStatsSSRNValue struct
 */
struct RStatsSSRNValue
{
    RStatsInteger orderIndex;
    RStatsInteger value;
    RStatsSSRNOrderType orderType;
};

/**
 * @brief The RStatsSSRNOutputData struct
 */
struct RStatsSSRNOutputData
{
    std::string auditName;
    std::vector<RStatsSSRNValue> values;
    oig::ratstats::utils::RStatsInteger sum;
    oig::ratstats::utils::RStatsInteger upper;
    oig::ratstats::utils::RStatsInteger lower;
    oig::ratstats::utils::RStatsFloat seed;
    oig::ratstats::utils::RStatsInteger frameSize;
    oig::ratstats::utils::RStatsInteger sparesCount;
    oig::ratstats::utils::RStatsInteger sequentialCount;
    cbtek::common::utility::DateEntity createDate;
    cbtek::common::utility::TimeEntity createTime;
};

/**
 * @brief The RStatsSSRNInputData struct
 */
struct RStatsSSRNInputData
{
    double ratStatValue;
    double excelValue;
    oig::ratstats::utils::RStatsInteger stepValue;
};

/**
 * @brief The RStatsSSRN class represents the Single Stage Random Numbers
 * function. In the model-view-controller paradigm, this class represents the
 * controller.
 */
class RStatsSSRN
{

public:

    /**
       * @brief generateRandomNumbers
       * @param auditName
       * @param inputSeed
       * @param sequentialOrder
       * @param sparesInRandomOrder
       * @param lowNumber
       * @param highNumber
       * @return
       */
      RStatsSSRNOutputData execute(const std::string & auditName,
                                   RStatsFloat inputSeed,
                                   oig::ratstats::utils::RStatsInteger sequentialOrder,
                                   oig::ratstats::utils::RStatsInteger sparesInRandomOrder,
                                   oig::ratstats::utils::RStatsInteger lowNumber,
                                   oig::ratstats::utils::RStatsInteger highNumber);



      /**
       * @brief saveToCSVWorksheetFile
       * @param filePath
       */
      void saveToCSVFile(const std::string& filePath);

      /**
       * @brief saveToWorksheet Saves output results to worksheet reference
       * @param worksheetOut Reference to worksheet to be returned
       */
      void saveToWorksheet(oig::ratstats::utils::RStatsWorksheet& worksheetOut);

      /**
       * @brief saveToTextFile
       * @param filePath
       */
      void saveToTextFile(const std::string& filePath);



private:
    size_t m_sequentialCount;
    size_t m_sparesCount;
    RStatsSSRNOutputData m_outputData;

    /**
     * @brief vbRand
     * @param ExcelSeed
     * @param outputmax
     * @param output
     */
    void vbRand(oig::ratstats::utils::RStatsInteger ExcelSeed,
                oig::ratstats::utils::RStatsInteger outputmax,
                RStatsSSRNInputData & output);

    /**
     * @brief vbRandomize
     * @param startingPoint
     * @param currentSeed
     * @return
     */
    oig::ratstats::utils::RStatsInteger vbRandomize(RStatsFloat startingPoint,
                                                    oig::ratstats::utils::RStatsFloat currentSeed);
    
    /**
     * @brief vbRandInit
     * @param initVariable
     * @return
     */
    oig::ratstats::utils::RStatsInteger vbRandInit(float initVariable);
};
}}}}//end namespace

