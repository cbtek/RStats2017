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

#include "RStatsModuleSessionData.hpp"
#include "RStatsObjectList.hpp"

#include "utility/inc/DateTimeUtils.hpp"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/SystemUtils.hpp"
#include "utility/inc/StringUtils.hpp"
#include "utility/inc/VBRoundUtils.hpp"

#include "contrib/tiny-process/process.hpp"

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

struct RStatsDataFormatTypeIndex
{
    RStatsDataFormatType type;
    size_t primaryDatasetColumnIndex;
    size_t secondaryDatasetColumnIndex;
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


/**
 * @brief isAHalfFraction
 * @param value
 * @param rf
 * @return
 */
inline static bool isAHalfFraction(double value, double rf)
{
    double frac;
    double integral;

    frac = modf(value, &integral);

    if (round(frac * 10) / 10 != 0.5 && round(frac * 10) / 10 != -0.5)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
 * @brief vbRound2
 * @param value
 * @param rf
 * @return
 */
inline double vbRound2(double value, double rf = 100.)
{
    double tmp;

    value *= rf;
    if (!isAHalfFraction(value, rf))
    {
        return std::round(value) / rf;
    }

    tmp = floor(value);

    if ((int)tmp % 2 == 0)
    {
        return tmp / rf;
    }
    else
    {
        return (tmp + 1) / rf;
    }
}


/**
 * @brief vbRound This function attempts to simulate VB / VBA bankers rounding
 * @param value
 * @return rounded integer value
 */
template <class T>
inline RStatsInteger vbRound(T value)
{
    T val1;
    T decimals;

    if (value >= 0.0)
    {
        decimals = value - floor(value);
        if (decimals > 0.5)
        {
            val1 = ceil(value);
        }
        else if (decimals < 0.5)
        {
            val1 = floor(value);
        } else
        {
            bool is_even = (static_cast<RStatsInteger>(value - decimals) % 2 == 0);
            if (is_even)
            {
                val1 = floor(value);
            }
            else
            {
                val1 = ceil(value);
            }
        }
    }
    else
    {
        decimals = std::abs(value + floor(std::abs(value)));
        if (decimals > 0.5)
        {
            val1 = floor(value);
        }
        else if (decimals < 0.5)
        {
            val1 = ceil(value);
        }
        else
        {
            bool is_even = (static_cast<RStatsInteger>(value + decimals) % 2 == 0);
            if (is_even)
            {
                val1 = ceil(value);
            }
            else
            {
                val1 = floor(value);
            }
        }
    }
    return static_cast<RStatsInteger>(val1);
}

    /**
     * @brief ipow Custom pow function for integers
     * @param base The base value
     * @param exp The exponential value
     * @return Computed base raised to exp
     */
    template <typename Integer>
    inline Integer ipow(Integer base, Integer exp)
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
     * @brief isEqual Compares to floating point values
     * @param value1 First floating point value
     * @param value2 Second floating point value
     * @return True if the floats are equal, false otherwise
     */    
    inline bool isEqual(RStatsFloat value1, RStatsFloat value2)
    {
        return (value1 - value2) < DBL_EPSILON;
    }

    /**
     * @brief getSum Return sum of list of numbers
     * @param values List of numbers to sum
     * @param dimension Dimension of numbers to sum
     * @return total sum of all values
     */
    template <typename Number>
    inline Number getSum(const RStatsObjectList<Number>& values,
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
     * @brief getSumRaisedTo Return sum of values raised to power
     * @param values List of numbers to sum
     * @param power The power to raise each number to
     * @param dimension The dimension of the numbers to sum
     * @return total sum of all raised values
     */
    template <typename Float>
    inline Float getSumRaisedTo(const RStatsObjectList<Float>& values,
                                Float power,
                                size_t dimension = 0)
    {
        Float sum = 0.;
        size_t size = values.size(dimension);
        for (size_t a1 = 0; a1 < size; ++a1 )
        {
            Float value = values(a1,dimension);
            std::string valueStr = cbtek::common::utility::StringUtils::toString(value,3);
            Float powValue = std::pow(cbtek::common::utility::StringUtils::toFloat64(valueStr),power);
            sum += powValue;
        }
        return sum;
    }

    /**
     * @brief getNumItemsThatMatchCondition Attempts to return the number of items in values that match
     * the condition.  Conditions can be =, !=, >, <, >= or <=
     * @param condition The condition to check
     * @param values List of values
     * @param value Number to compare to list of values
     * @param dimension Dimension of values to check
     * @return total count of values that match condition
     */
    template <typename Number>
    inline size_t getNumItemsThatMatchCondition(RStatsConditionalOperatorType condition,
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

    /**
     * @brief calculate
     * @param input1
     * @param input2
     * @param result
     * @param calculation
     * @param dimension
     */
    template<typename Number>    
    inline void calculate(const RStatsObjectList<Number>& input1,
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

    /**
     * @brief getNumbersAdded
     * @param input1
     * @param input2
     * @param dimension
     * @return
     */
    template<typename Number>    
    inline RStatsObjectList<Number> getNumbersAdded(const RStatsObjectList<Number>& input1,
                                                    const RStatsObjectList<Number>& input2,
                                                    size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Add,dimension);
        return values;
    }

    /**
     * @brief getNumbersSubtracted
     * @param input1
     * @param input2
     * @param dimension
     * @return
     */
    template<typename Number>    
    inline RStatsObjectList<Number> getNumbersSubtracted(const RStatsObjectList<Number>& input1,
                                                         const RStatsObjectList<Number>& input2,
                                                         size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Subtract,dimension);
        return values;
    }

    /**
     * @brief getNumbersMultiplied
     * @param input1
     * @param input2
     * @param dimension
     * @return
     */
    template<typename Number>    
    inline RStatsObjectList<Number> getNumbersMultiplied(const RStatsObjectList<Number>& input1,
                                                         const RStatsObjectList<Number>& input2,
                                                         size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Multiply,dimension);
        return values;
    }

    /**
     * @brief getNumbersDivided
     * @param input1
     * @param input2
     * @param dimension
     * @return
     */
    template<typename Number>    
    inline RStatsObjectList<Number> getNumbersDivided(const RStatsObjectList<Number>& input1,
                                                      const RStatsObjectList<Number>& input2,
                                                      size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Divide,dimension);
        return values;
    }

    /**
     * @brief getValidPath
     * @param path
     * @return
     */
    inline std::string getValidPath(const std::string & pathToValidate)
    {
        std::string path1,path2,path3,path;        

        #ifdef __WIN32
            path1 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(), pathToValidate),"/","\\");
        #else
            path1 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(), pathToValidate),"\\","/");
        #endif

        if ((cbtek::common::utility::FileUtils::isDirectory(path1) &&
            cbtek::common::utility::FileUtils::isDirectoryWritable(path1)) ||
             cbtek::common::utility::FileUtils::fileExists(path1))
        {
            path = path1;
        }

        #ifdef __WIN32
            path2 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserAppDirectory(), ".rat-stats/"+pathToValidate),"/","\\");
        #else
            path2 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserAppDirectory(), ".rat-stats/"+pathToValidate),"\\","/");
        #endif
        if ((cbtek::common::utility::FileUtils::isDirectory(path2) &&
            cbtek::common::utility::FileUtils::isDirectoryWritable(path2)) ||
            cbtek::common::utility::FileUtils::fileExists(path2))
        {
            path = path2;
        }

        #ifdef __WIN32
            path3 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserHomeDirectory(), ".rat-stats/"+pathToValidate),"/","\\");
        #else
            path3 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserHomeDirectory(), ".rat-stats/"+pathToValidate),"\\","/");
        #endif

        if ((cbtek::common::utility::FileUtils::isDirectory(path3) &&
            cbtek::common::utility::FileUtils::isDirectoryWritable(path3)) ||
            cbtek::common::utility::FileUtils::fileExists(path3))
        {
            path=path3;
        }

        if (!path.empty())
        {
            return path;
        }
        throw cbtek::common::utility::FileAccessException(EXCEPTION_TAG_LINE+"Could not locate existing or valid directory! Valid locations: \n1) "+path1+"\n2) "+path2+"\n3)"+path3);
    }

    /**
     * @brief getModulePropertiesPath
     * @return
     */
    inline std::string getModulePropertiesPath()
    {
        return getValidPath("config/.rstats_module_properties");
    }

    /**
     * @brief getConfigPath
     * @return
     */
    inline std::string getConfigPath()
    {
        return getValidPath("config");
    }

    /**
     * @brief getContribPath
     * @return
     */
    inline std::string getContribPath()
    {
        return getValidPath("contrib");
    }

    /**
     * @brief getUnzipCommandPath
     * @return
     */
    inline std::string getUnzipCommandPath()
    {
        std::string path;
        #ifdef __WIN32
        path = getValidPath("contrib/unzip/win32/unzip.exe");
        #elif __gnu_linux__
        path = getValidPath("contrib/unzip/linux/unzip");
        #else
        path = getValidPath("contrib/unzip/macos");
        #endif
        return path;
    }

    /**
     * @brief getScriptProviderPropertiesPath
     * @return
     */
    inline std::string getScriptProviderPropertiesPath()
    {
       return getValidPath("config/.rstats_script_provider_properties");
    }

    inline std::string getResourcePath()
    {
        return getValidPath("resx");
    }

    inline std::string getThemeSettingsFilePath()
    {
        return cbtek::common::utility::FileUtils::buildFilePath(RStatsUtils::getConfigPath(),".theme_settings");
    }

    /**
     * @brief getModulePropertiesList
     * @return
     */
    inline std::vector<RStatsModuleProperties> getModulePropertiesList()
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


    /**
     * @brief getModuleCategories
     * @return
     */
    inline std::vector<std::string> getModuleCategories()
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

    /**
     * @brief getScriptProviderPropertiesList
     * @return
     */
    inline std::vector<RStatsScriptProviderProperties> getScriptProviderPropertiesList()
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
    inline size_t getColumnIndexFromLabel(const std::string &columnLabel)
    {
        size_t sum = 0;
        for (size_t i = 0; i < columnLabel.size(); i++)
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
    inline std::string getColumnLabelFromIndex(size_t columnIndex)
    {
        int div = static_cast<int>(columnIndex+1);
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

    /**
     * @brief getCellIndexFromAddress
     * @param cellAddress
     * @return
     */
    inline std::pair<size_t,size_t> getCellIndexFromAddress(const std::string& cellAddress)
    {
        std::string label;
        std::string number;
        for (size_t a1 = 0; a1 < cellAddress.size();++a1)
        {
            if (std::isalpha(cellAddress[a1]))
            {
                label.push_back(cellAddress[a1]);
            }
            else if (std::isdigit(cellAddress[a1]))
            {
                number.push_back(cellAddress[a1]);
            }
        }
        size_t row = static_cast<size_t>(cbtek::common::utility::StringUtils::toInt(number));
        if (row >0)row--;
        size_t col = getColumnIndexFromLabel(label);
        std::pair<size_t,size_t> cellIndex = std::make_pair(row,col);
        return cellIndex;
    }

    /**
     * @brief createValidPath
     * @param pathToCreate
     */
    inline void createValidPath(const std::string& pathToCreate)
    {

        std::string path1,path2,path3,path,parentPath;
        #ifdef __WIN32
            path1 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(), pathToCreate),"/","\\");
        #else
            path1 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(), pathToCreate),"\\","/");
        #endif
        parentPath = cbtek::common::utility::FileUtils::getDirPath(path1);
        if (cbtek::common::utility::FileUtils::fileExists(path1))
        {
            return;
        }
        if (cbtek::common::utility::FileUtils::isDirectoryWritable(parentPath))
        {
            path = path1;
        }

        #ifdef __WIN32
            path2 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserAppDirectory(), ".rat-stats/"+pathToCreate),"/","\\");
        #else
            path2 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserAppDirectory(), ".rat-stats/"+pathToCreate),"\\","/");
        #endif
        parentPath = cbtek::common::utility::FileUtils::getDirPath(path2);
        if (cbtek::common::utility::FileUtils::fileExists(path2))
        {
            return;
        }
        if (cbtek::common::utility::FileUtils::isDirectoryWritable(parentPath))
        {
            path = path2;
        }

        #ifdef __WIN32
            path3 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserHomeDirectory(), ".rat-stats/"+pathToCreate),"/","\\");
        #else
            path3 = cbtek::common::utility::StringUtils::replace(cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserHomeDirectory(), ".rat-stats/"+pathToCreate),"\\","/");
        #endif

        parentPath = cbtek::common::utility::FileUtils::getDirPath(path3);
        if (cbtek::common::utility::FileUtils::fileExists(path3))
        {
            return;
        }
        if (cbtek::common::utility::FileUtils::isDirectoryWritable(parentPath))
        {
            path=path3;
        }

        if (path.empty() || !cbtek::common::utility::FileUtils::createDirectory(path))
        {
            throw cbtek::common::utility::FileAccessException(EXCEPTION_TAG_LINE+"Could not create directory at \""+path+"\" because \""+parentPath+"\" is not writable or does not exist!");
        }
    }


    /**
     * @brief getValidSessionPath
     * @return
     */
    inline std::string getValidSessionPath()
    {
        std::string path = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getUserHomeDirectory(),".rstats_sessions");
        if (cbtek::common::utility::FileUtils::isDirectoryWritable(cbtek::common::utility::FileUtils::getDirPath(path)))
        {
            cbtek::common::utility::FileUtils::createDirectory(path);
        }
        return path;
    }

    /**
     * @brief getRecentSessions
     * @param sessionExtension
     * @return
     */
    inline std::vector<std::string> getRecentSessions(const std::string& sessionExtension)
    {
        return cbtek::common::utility::FileUtils::getFileEntries(getValidSessionPath(),sessionExtension);
    }

    /**
     * @brief saveRecentSession
     * @param sessionData
     * @param sessionExtension
     */
    inline void saveRecentSession(RStatsModuleSessionDataPtr sessionPtr)
    {
        std::vector<std::string> sessions = getRecentSessions(sessionPtr->getType());
        std::string path = getValidSessionPath();
        path = cbtek::common::utility::FileUtils::buildFilePath(path,"session"+std::to_string(sessions.size())+"."+sessionPtr->getType());
        sessionPtr->save(path);
    }

    /**
     * @brief clearRecentSessions
     * @param sessionExtension
     */
    inline void clearRecentSessions(const std::string& sessionExtension)
    {
        std::vector<std::string> entries = cbtek::common::utility::FileUtils::getFileEntries(getValidSessionPath(),sessionExtension);
        for (const auto& entry : entries)
        {
            cbtek::common::utility::FileUtils::deleteFile(entry);
        }
    }

    /**
     * @brief divideValues
     * @param value1
     * @param value2
     * @return
     */
    inline RStatsFloat divideValues(RStatsInteger value1, RStatsInteger value2)
    {
        return (static_cast<RStatsFloat>(value1) / static_cast<RStatsFloat>(value2));
    }


    /**
     * @brief vbDivide
     * @param value1
     * @param value2
     * @return
     */
    inline RStatsInteger vbDivide(RStatsInteger value1, RStatsInteger value2)
    {
        RStatsFloat value = static_cast<RStatsFloat>(value1)/static_cast<RStatsFloat>(value2);
        return ((value1%value2) != 0) ? static_cast<RStatsInteger>(cbtek::common::utility::VBRoundUtils::vbRound(value)) : static_cast<RStatsInteger>(value);
    }

    /**
     * @brief getRandomAuditName
     * @param moduleName
     * @return
     */
    inline std::string getAuditName()
    {
        std::string userName = cbtek::common::utility::SystemUtils::getUserName();
        std::string dateTime = std::to_string(cbtek::common::utility::TimeUtils::getSecondsNow());
        return userName+"_audit_"+dateTime;
    }

    inline std::string getApplicationName()
    {
        return "RAT-STATS Statistical Software";
    }   
}

}}}//end namespace

