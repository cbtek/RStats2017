/*
    RStatsUtils.h
    
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

#include <cinttypes>
#include <vector>
#include <cfloat>
#include <cmath>

#include "rstats_utils/inc/RStatsModuleProperties.h"
#include "rstats_utils/inc/RStatsScriptProviderProperties.h"

#include "RStatsObjectList.hpp"

#include "utility/inc/FileUtils.hpp"
#include "utility/inc/SystemUtils.hpp"
#include "utility/inc/StringUtils.hpp"

namespace oig {
namespace ratstats {
namespace utils {

/***********************************************************/
/**/
/**/    typedef oig::ratstats::utils::float64_t RStatsFloat;
/**/    typedef std::int64_t RStatsInteger;
/**/    typedef oig::ratstats::utils::RStatsObjectList<RStatsFloat> RStatsFloatList;
/**/    typedef oig::ratstats::utils::RStatsObjectList<RStatsInteger> RStatsIntegerList;
/**/
/***********************************************************/

enum class RStatsCalculationType
{
    Subtract,
    Multiply,
    Add,
    Divide
};


/**
 * @brief The RStatsDataFormatType enum
 */
enum class RStatsDataFormatType
{
    Examine,
    Audit,
    Difference,
    ExamineAndAudit,
    ExamineAndDifference,
    AuditAndDifference
};


enum class RStatsConditionalOperatorType
{
    Equal,
    NotEqual,
    LessThan,
    LessThanOrEqualTo,
    GreaterThan,
    GreaterThanOrEqualTo
};

namespace RStatsUtils
{
    template <typename Integer>
    static Integer ipow(Integer base, Integer exp)
    {
        Integer result = 1;
        while (exp)
        {
            if (exp & 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }
        return result;
    }


    /**
     * @brief isEqual
     * @param value1
     * @param value2
     * @return
     */
    template <typename Float>
    static bool isEqual(Float value1, Float value2)
    {
        return (value1 - value2) < FLT_EPSILON;
    }

    /**
     * @brief getSum
     * @param values
     * @param dimension
     * @return
     */
    template <typename Number>
    static Number getSum(const RStatsObjectList<Number>& values,
                         size_t dimension = 0)
    {
        Number sum = 0.;
        size_t size = values.size(dimension);
        for (size_t a1 = 0; a1 < size; ++a1 )
        {
            sum += values(a1,dimension);
        }
        return sum;
    }

    /**
     * @brief getSumRaisedTo
     * @param values
     * @param power
     * @param dimension
     * @return
     */
    template <typename Float>
    static Float getSumRaisedTo(const RStatsObjectList<Float>& values,
                                Float power,
                                size_t dimension = 0)
    {
        Float sum = 0.;
        size_t size = values.size(dimension);
        for (size_t a1 = 0; a1 < size; ++a1 )
        {
            sum += std::pow(values(a1,dimension),power);
        }
        return sum;
    }

    template <typename Number>
    static size_t getNumItemsThatMatchCondition(RStatsConditionalOperatorType condition,
                                                const RStatsObjectList<Number>& values,
                                                Number value,
                                                size_t dimension = 0)
    {
        size_t count = 0;
        size_t size = values.size(dimension);
        for (size_t a1 = 0; a1 < size; ++a1 )
        {
            if (condition == RStatsConditionalOperatorType::Equal &&
                isEqual(values(a1,dimension), value))
            {
                ++count;
            }
            else if (condition == RStatsConditionalOperatorType::NotEqual &&
                     !isEqual(values(a1,dimension), value))
            {
                ++count;
            }
            else if (condition == RStatsConditionalOperatorType::GreaterThan &&
                     values(a1,dimension) > value)
            {
                ++count;
            }
            else if (condition == RStatsConditionalOperatorType::LessThan &&
                     values(a1,dimension) < value)
            {
                ++count;
            }
            else if (condition == RStatsConditionalOperatorType::GreaterThanOrEqualTo &&
                     (values(a1,dimension) > value || RStatsUtils::isEqual(values(a1,dimension), value)))
            {
                ++count;
            }
            else if (condition == RStatsConditionalOperatorType::LessThanOrEqualTo &&
                     (values(a1,dimension) < value || RStatsUtils::isEqual(values(a1,dimension), value)))
            {
                ++count;
            }
        }
        return count;
    }

    template<typename Number>
    static void calculate(const RStatsObjectList<Number>& input1,
                          const RStatsObjectList<Number>& input2,
                          RStatsObjectList<Number> &result,
                          RStatsCalculationType calculation,
                          size_t dimension = 0)
    {
        size_t input1Size = input1.size(dimension);
        size_t input2Size = input2.size(dimension);

        if (input1Size == input2Size)
        {
            result.initialize(input1Size,1);
            switch (calculation)
            {
                case RStatsCalculationType::Add:
                {
                    for (size_t a1 = 0; a1 < input1Size; ++a1)
                    {
                        result(a1) = input1(a1,dimension) + input2(a1, dimension);
                    }
                }
                break;
                case RStatsCalculationType::Subtract:
                {
                    for (size_t a1 = 0; a1 < input1Size; ++a1)
                    {
                        result(a1) = input1(a1,dimension) - input2(a1, dimension);
                    }
                }
                break;
                case RStatsCalculationType::Multiply:
                {
                    for (size_t a1 = 0; a1 < input1Size; ++a1)
                    {
                        result(a1) = input1(a1,dimension) * input2(a1, dimension);
                    }
                }
                break;
                case RStatsCalculationType::Divide:
                {
                    for (size_t a1 = 0; a1 < input1Size; ++a1)
                    {
                        Number value = input2(a1, dimension);
                        if (isEqual(value, 0.))
                        {
                            continue;
                        }

                        result(a1) = input1(a1,dimension) / value;
                    }
                }
                break;
            }
        }
    }



    template<typename Number>
    static RStatsObjectList<Number> getNumbersAdded(const RStatsObjectList<Number>& input1,
                                                    const RStatsObjectList<Number>& input2,
                                                    size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Add,dimension);
        return values;
    }

    template<typename Number>
    static RStatsObjectList<Number> getNumbersSubtracted(const RStatsObjectList<Number>& input1,
                                                         const RStatsObjectList<Number>& input2,
                                                         size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Subtract,dimension);
        return values;
    }

    template<typename Number>
    static RStatsObjectList<Number> getNumbersMultiplied(const RStatsObjectList<Number>& input1,
                                                         const RStatsObjectList<Number>& input2,
                                                         size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Multiply,dimension);
        return values;
    }

    template<typename Number>
    static RStatsObjectList<Number> getNumbersDivided(const RStatsObjectList<Number>& input1,
                                                      const RStatsObjectList<Number>& input2,
                                                      size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Divide,dimension);
        return values;
    }

    static std::string getModulePropertiesPath()
    {
        std::string path1,path2,path3,path;
        path1 = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(), "config/.rstats_module_properties");
        if (cbtek::common::utility::FileUtils::isDirectory(path1) && cbtek::common::utility::FileUtils::isDirectoryWritable(path1))
        {
            path = path1;
        }

        path2 = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserAppDirectory(), "config/.rstats_module_properties");
        if (cbtek::common::utility::FileUtils::isDirectory(path2) && cbtek::common::utility::FileUtils::isDirectoryWritable(path2))
        {
            path = path2;
        }

        path3 = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserHomeDirectory(), "config/.rstats_module_properties");
        if (cbtek::common::utility::FileUtils::isDirectory(path3) && cbtek::common::utility::FileUtils::isDirectoryWritable(path3))
        {
            path=path3;
        }

        if (!path.empty())
        {
            return path;
        }
        throw cbtek::common::utility::FileAccessException(EXCEPTION_TAG_LINE+"Could not locate directory for module definitions! Valid locations: "+path1+"\n"+path2+"\n"+path3);
    }

    /**
     * @brief getScriptProviderPropertiesPath
     * @return
     */
    static std::string getScriptProviderPropertiesPath()
    {
        std::string path1,path2,path3,path;
        path1 = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(), "config/.rstats_script_provider_properties");
        if (cbtek::common::utility::FileUtils::isDirectory(path1) && cbtek::common::utility::FileUtils::isDirectoryWritable(path1))
        {
            path = path1;
        }

        path2 = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserAppDirectory(), "config/.rstats_script_provider_properties");
        if (cbtek::common::utility::FileUtils::isDirectory(path2) && cbtek::common::utility::FileUtils::isDirectoryWritable(path2))
        {
            path = path2;
        }

        path3 = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserHomeDirectory(), "config/.rstats_script_provider_properties");
        if (cbtek::common::utility::FileUtils::isDirectory(path3) && cbtek::common::utility::FileUtils::isDirectoryWritable(path3))
        {
            path=path3;
        }

        if (!path.empty())
        {
            return path;
        }
        throw cbtek::common::utility::FileAccessException(EXCEPTION_TAG_LINE+"Could not locate directory for script providers! Valid locations: "+path1+"\n"+path2+"\n"+path3);
    }

    static std::vector<RStatsModuleProperties> getModulePropertiesList()
    {
        std::vector<RStatsModuleProperties>propsList;
        std::string path = getModulePropertiesPath();

        std::vector<std::string> filters,entries;
        filters.push_back("xml");
        cbtek::common::utility::FileUtils::getFileEntries(path,true,filters,entries);
        for (const std::string& file : entries)
        {
            try
            {
                RStatsModuleProperties props;
                props.loadConfig(file);
                propsList.push_back(props);
            }
            catch(...)
            {
                continue;
            }
        }
        return propsList;
    }



    static std::vector<std::string> getModuleCategories()
    {
        std::set<std::string> categorySet;
        std::string path = getModulePropertiesPath();
        std::vector<std::string> filters,entries;
        filters.push_back("xml");
        cbtek::common::utility::FileUtils::getFileEntries(path,true,filters,entries);

        for (const std::string& file : entries)
        {
            try
            {
                RStatsModuleProperties props;
                props.loadConfig(file);
                std::string category = cbtek::common::utility::StringUtils::trimmed(props.getCategory());
                if(category.empty())
                {
                    category = "Uncategorized";
                }
                categorySet.insert(category);
            }
            catch(...)
            {
                continue;
            }
        }
        return std::vector<std::string>(categorySet.begin(),categorySet.end());
    }


    static std::vector<RStatsScriptProviderProperties> getScriptProviderPropertiesList()
    {
        std::vector<RStatsScriptProviderProperties>propsList;
        std::string path = getScriptProviderPropertiesPath();

        std::vector<std::string> filters,entries;
        filters.push_back("xml");
        cbtek::common::utility::FileUtils::getFileEntries(path,true,filters,entries);
        for (const std::string& file : entries)
        {
            try
            {
                RStatsScriptProviderProperties props;
                props.loadConfig(file);
                propsList.push_back(props);
            }
            catch(...)
            {
                continue;
            }
        }
        return propsList;
    }


    /**
     * @brief RStatsWorksheet::getColumnIndexFromLabel
     * @param columnLabel
     * @return
     */
    static size_t getColumnIndexFromLabel(const std::string &columnLabel)
    {
        int sum = 0;
        for (int i = 0; i < columnLabel.size(); i++)
        {
            sum *= 26;
            sum += (std::toupper(columnLabel[i]) - 'A');
        }
        return sum;
    }

    /**
     * @brief RStatsWorksheet::getColumnLabelFromIndex
     * @param columnIndex
     * @return
     */
    static std::string getColumnLabelFromIndex(size_t columnIndex)
    {
        int div = (int)columnIndex+1;
        std::string colLetter;
        int mod = 0;
        while (div > 0)
        {
            mod = (div - 1) % 26;
            colLetter = (char)(65 + mod) + colLetter;
            div = (int)((div - mod) / 26);
        }
        return colLetter;
    }
}

}}}//end namespace

