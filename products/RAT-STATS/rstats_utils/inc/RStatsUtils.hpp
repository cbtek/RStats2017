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
#include "rstats_utils/inc/RStatsWorksheet.h"
#include "rstats_utils/inc/RStatsScriptProviderProperties.h"

#include "RStatsModuleSessionData.hpp"
#include "RStatsObjectList.hpp"
#include "RStatsTypes.hpp"

#include "utility/inc/DateTimeUtils.hpp"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/SystemUtils.hpp"
#include "utility/inc/StringUtils.hpp"

namespace oig {
namespace ratstats {
namespace utils {

/**
 * @brief This namespace provides commonly used functions without requiring
 * any dependencies on the Qt SDK.
 */

namespace RStatsUtils
{

/**
 * @brief getDataFormatTypeStr Gets the string representation of
 * the data format type enumeration value
 * @param type The enumeration value to convert to string
 * @return Return string representation of data format type enumeration
 */
inline std::pair<std::string,std::string> getDataFormatTypeStr(RStatsDataFormatType type)
{
    std::string primaryTypeStr;
    std::string secondaryTypeStr;
    if (type == RStatsDataFormatType::AuditAndDifference)
    {
        primaryTypeStr = "Audit";
        secondaryTypeStr = "Difference";
    }
    else if (type == RStatsDataFormatType::ExamineAndAudit)
    {
        primaryTypeStr = "Examine";
        secondaryTypeStr = "Difference";
    }
    else if (type == RStatsDataFormatType::ExamineAndAudit)
    {
        primaryTypeStr = "Examine";
        secondaryTypeStr = "Audit";
    }

    else if (type == RStatsDataFormatType::Audit)
    {
        primaryTypeStr = "Audit";
    }
    else if (type == RStatsDataFormatType::Difference)
    {
        primaryTypeStr = "Difference";
    }
    else if (type == RStatsDataFormatType::Examine)
    {
        primaryTypeStr = "Examine";
    }
    return std::make_pair(primaryTypeStr,secondaryTypeStr);
}

/**
 * @brief vbRound This function attempts to simulate VB / VBA bankers rounding
 * @param value The value to round
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
        return (fabs(value1 - value2) <= DBL_EPSILON * std::fmax(fabs(value1), fabs(value2)));
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
     * @brief calculate This function takes in to RStatsObjectList structures
     * and performs calculations on each element.  The result is returned back
     * in a third RStatsObjectList
     * @param input1 The first number list
     * @param input2 The second number list
     * @param result Reference to the output list result
     * @param calculation The calculation to perform
     * @param dimension The dimension to perform the calculation in
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
     * @brief getNumbersAdded This function adds together two RStatsObjetList
     * structures and returns the result in another RStatsObjectList
     * @param input1 The first number list
     * @param input2 The second number list
     * @param dimension The dimension to add
     * @return Return number list of added results
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
     * @brief getNumbersSubtracted This function subtracts two RStatsObjetList
     * structures and returns the result in another RStatsObjectList
     * @param input1 The first number list
     * @param input2 The second number list
     * @param dimension The dimension to subtract
     * @return Return number list of subtracted results
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
     * @brief getNumbersMultiplied This function multiplies two RStatsObjetList
     * structures and returns the result in another RStatsObjectList
     * @param input1 The first number list
     * @param input2 The second number list
     * @param dimension The dimension to multiply
     * @return Return number list of multiplied results
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
     * @brief getNumbersDivided This function divides two RStatsObjetList
     * structures and returns the result in another RStatsObjectList
     * @param input1 The first number list
     * @param input2 The second number list
     * @param dimension The dimension to divide
     * @return Return number list of divided results
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
     * @brief getValidPath RAT-STATS makes use of external files and this
     * function attempts to find a valid path for input files. To remain
     * portable and self-contained, RAT-STATS checks the following places
     * for external files:
     * (1) The execution directory - This is where the RAT-STATS main menu
     * and RAT-STATS internal modules are located.
     *
     * (2) The users application folder - This is different per platform but
     * it represents a folder that is readable/writable by the current user.
     *
     * (3) The users home folder - As a last resort this folder is checked for
     * the location of the file.
     * If none of these paths are valid then an exception is thrown.
     *
     * @param pathToValidate The path to look for in the above 3 locations
     * @return Returns validated path to "pathToValidate" item
     * @throws FileAccessException if a valid path could not be found
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
        throw cbtek::common::utility::FileAccessException(EXCEPTION_TAG_LINE+"Could not locate existing or valid directory! \nValid locations: \n1) "+path1+"\n2) "+path2+"\n3) "+path3);
    }

    /**
     * @brief getModulePropertiesPath Return valid path to module
     * XML config directory
     * @return
     */
    inline std::string getModulePropertiesPath()
    {
        return getValidPath("config/.rstats_module_properties");
    }

    /**
     * @brief getConfigPath Return valid path to config directory
     * @return
     */
    inline std::string getConfigPath()
    {
        return getValidPath("config");
    }

    /**
     * @brief getContribPath Return valid path to contrib directory
     * @return
     */
    inline std::string getContribPath()
    {
        return getValidPath("contrib");
    }

    /**
     * @brief getScriptProviderPropertiesPath Return valid path to
     * script provider XML config directory
     * @return
     */
    inline std::string getScriptProviderPropertiesPath()
    {
       return getValidPath("config/.rstats_script_provider_properties");
    }

    /**
     * @brief getResourcePath
     * @return
     */
    inline std::string getResourcePath()
    {
        return getValidPath("resx");
    }

    /**
     * @brief getThemeSettingsFilePath
     * @return
     */
    inline std::string getThemeSettingsFilePath()
    {
        return cbtek::common::utility::FileUtils::buildFilePath(RStatsUtils::getConfigPath(),".theme_settings");
    }

    /**
     * @brief getModulePropertiesList Read all module properties from disk
     * @return Return vector of all parsed module properties
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
     * @brief getModuleCategories Get list of all module categories
     * @return Return vector of module category names
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
     * @brief getScriptProviderPropertiesList Get list of all parsed script provider
     * from disk
     * @return Return vector of script provider properties
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
     * @brief getRandomAuditName Generates random audit name for use when none is provided
     * @return Return newly created random audit name
     */
    inline std::string getAuditName()
    {
        std::string userName = cbtek::common::utility::SystemUtils::getUserName();
        std::string dateTime = std::to_string(cbtek::common::utility::TimeUtils::getSecondsNow());
        return userName+"_audit_"+dateTime;
    }

    /**
     * @brief getApplicationName Returns name of application
     * @return Returns name of application
     */
    inline std::string getApplicationName()
    {
        return "RAT-STATS Statistical Software";
    }

    /**
     * @brief getCellLabel Gets the spreadsheet cell label (A1, B4, etc) from 0-based
     * row and column indices
     * @param row The row index
     * @param column The column index
     * @return Return string with cell label (A1, B4, etc)
     */
    inline std::string getCellLabel(size_t row, size_t column)
    {
        std::string label = getColumnLabelFromIndex(column);
        label+= std::to_string(row + 1);
        return label;
    }   

    /**
     * @brief getValidModule Returns string path to validated module
     * @param modulePath Initial (unvalidated) path to module
     * @return Returns validated path to module
     * @throws GenericException if modulePath could not be validated
     */
    inline std::string getValidModule(const std::string& modulePath)
    {
        // Check if modulePath is valid
        if (cbtek::common::utility::FileUtils::fileExists(modulePath))
        {
            return modulePath;
        }

        //Get proper path to module
        std::string properPath = cbtek::common::utility::StringUtils::replace(modulePath,"\\","/");
        bool hasPathSeperator = cbtek::common::utility::StringUtils::contains(properPath,"/");
        //Attempt to locate a valid path for the module and disable it if no path can be found
        bool isDisabled = !hasPathSeperator ||
                          !cbtek::common::utility::FileUtils::fileExists(modulePath);

        //On windows make sure we append .exe to binary before checking if it exists
        #ifdef __WIN32
            if (isDisabled &&
                !cbtek::common::utility::StringUtils::endsWith(modulePath,".exe",false))
            {
                isDisabled = !hasPathSeperator ||
                !cbtek::common::utility::FileUtils::fileExists(modulePath+".exe") ||
                !cbtek::common::utility::FileUtils::fileExists(modulePath+".EXE") ||
                !cbtek::common::utility::FileUtils::fileExists(modulePath+".ExE") ||
                !cbtek::common::utility::FileUtils::fileExists(modulePath+".eXe") ||
                !cbtek::common::utility::FileUtils::fileExists(modulePath+".EXe") ||
                !cbtek::common::utility::FileUtils::fileExists(modulePath+".eXE") ||
                !cbtek::common::utility::FileUtils::fileExists(modulePath+".Exe") ||
                !cbtek::common::utility::FileUtils::fileExists(modulePath+".exE");
                if (!isDisabled)
                {
                    return modulePath+".exe";
                }
            }
            else if (isDisabled)
            {
                isDisabled = !hasPathSeperator ||
                             !cbtek::common::utility::FileUtils::fileExists(modulePath);
                if (!isDisabled)
                {
                    return modulePath;
                }
            }
        #endif

        if (isDisabled)
        {
            #ifdef __WIN32
                std::string propsPath1 = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(),modulePath+".exe");
                std::string propsPath2 = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(),modulePath+".EXE");
                std::string propsPath3 = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(),modulePath);
                if (cbtek::common::utility::FileUtils::fileExists(propsPath1))
                {
                    isDisabled = false;
                    return propsPath1;
                }
                else if (cbtek::common::utility::FileUtils::fileExists(propsPath2))
                {
                    isDisabled = false;
                    return propsPath2;
                }
                else if (cbtek::common::utility::FileUtils::fileExists(propsPath3))
                {
                    isDisabled = false;
                    return propsPath3;
                }
            #else
                std::string propsPath = cbtek::common::utility::FileUtils::buildFilePath(cbtek::common::utility::SystemUtils::getCurrentExecutableDirectory(),modulePath);
                if (cbtek::common::utility::FileUtils::fileExists(propsPath))
                {
                    isDisabled = false;
                    return propsPath;
                }
            #endif
        }
        THROW_GENERIC_EXCEPTION("Module could not be validated at \""+modulePath+"\".\nEither the module does not exist yet or it can not be found.");
    }

    /**
     * @brief isValidModule Determines if a module path can be validated
     * @param modulePath Initial path to module
     * @return Returns true if path exists, false otherwise
     */
    inline bool isValidModule(const std::string& modulePath)
    {
        try
        {
            std::string path = getValidModule(modulePath);
            if (cbtek::common::utility::FileUtils::fileExists(path))
            {
                return true;
            }
            return false;
        }
        catch(...)
        {
            return false;
        }
    }        
}
}}}//end namespace

