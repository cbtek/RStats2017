/*
    RStatsConditionLogger.h
    

*/

#pragma once

#include <set>
#include <string>
#include <vector>

namespace cbtek {
namespace rocketstats {
namespace utils {
enum class ConditionType
{
    Warning,
    Informative,
    Error
};

/**
 * @brief The RStatsConditionLogger class provides support for creating
 * warning, informative and error messages based on boolean conditions.
 * This object is used by the modules for realtime error/exception monitoring.
 */
class RStatsConditionLogger 
{
public:

    /**
     * @brief RStatsConditionLogger (Constructor)
     */
	RStatsConditionLogger();

    /**
     * @brief addWarning Adds warning condition to logger
     * @param condition Condition that shows warning if true
     * @param message The actual warning message
     */
    void addWarning(bool condition, const std::string& message);

    /**
     * @brief addInformation Adds information condition to logger
     * @param condition Condition that shows information if true
     * @param message The acutal information message
     */
    void addInformation(bool condition, const std::string& message);

    /**
     * @brief addError Add error condition to logger
     * @param condition COndition that shows error if true
     * @param message The actual error message
     */
    void addError(bool condition, const std::string& message);

    /**
     * @brief getMessages Get all the messages in logger
     * @return Returns vector of string containing all messages
     */
    const std::vector<std::string>& getMessages() const;

    /**
     * @brief hasMessages Determine if there are any messages
     * @return Returns true if messages exist, false otherwise
     */
    bool hasMessages() const;

    /**
     * @brief hasError Determine if there are any error messages
     * @return Returns true if error messages exist, false otherwise
     */
    bool hasError() const;

    /**
     * @brief hasWarning Determine if there are any warning messages
     * @return Returns true if warning messages exist, false otherwise
     */
    bool hasWarning() const;

    /**
     * @brief hasInformation Determine if there are any information messages
     * @return Returns true if info messages exist, false otherwise
     */
    bool hasInformation() const;

    /**
     * @brief clear Clears all messages from logger
     */
    void clear();

    /**
     * @brief setWarningQSS
     * @param qss
     */
    void setWarningQSS(const std::string& qss);

    /**
     * @brief setErrorQSS
     * @param qss
     */
    void setErrorQSS(const std::string& qss);

    /**
     * @brief setInformationQSS
     * @param qss
     */
    void setInformationQSS(const std::string& qss);

    /**
     * @brief isError
     * @param index
     * @return
     */
    bool isError(size_t index) const;

    /**
     * @brief isWarning
     * @param index
     * @return
     */
    bool isWarning(size_t index) const;

    /**
     * @brief isInformation
     * @param index
     * @return
     */
    bool isInformation(size_t index) const;

	//! Destructor
	~RStatsConditionLogger();	

private:    
    std::vector<std::string> m_messages;
    std::vector<ConditionType> m_conditionSet;
    std::string m_warningQSS;
    std::string m_errorQSS;
    std::string m_informationQSS;   
};
}}}//end namespace


