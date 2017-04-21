/*
    RStatsConditionLogger.h
    

*/

#pragma once

#include <set>
#include <string>
#include <vector>

namespace oig {
namespace ratstats {
namespace utils {
enum class ConditionType
{
    Warning,
    Informative,
    Error
};

class RStatsConditionLogger 
{
public:
	//! Constructor for RStatsConditionLogger
	/*!
		Detailed description for RStatsConditionLogger
	*/
	RStatsConditionLogger();

    /**
     * @brief addWarning
     * @param condition
     * @param message
     */
    void addWarning(bool condition, const std::string& message);

    /**
     * @brief addInformation
     * @param condition
     * @param message
     */
    void addInformation(bool condition, const std::string& message);

    /**
     * @brief addError
     * @param condition
     * @param message
     */
    void addError(bool condition, const std::string& message);

    /**
     * @brief getMessages
     * @return
     */
    const std::vector<std::string>& getMessages() const;

    /**
     * @brief hasMessages
     * @return
     */
    bool hasMessages() const;

    /**
     * @brief hasError
     * @return
     */
    bool hasError() const;

    /**
     * @brief hasWarning
     * @return
     */
    bool hasWarning() const;

    /**
     * @brief hasInformation
     * @return
     */
    bool hasInformation() const;

    /**
     * @brief clear
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


