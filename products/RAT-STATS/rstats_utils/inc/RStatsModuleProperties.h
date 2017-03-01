/*
    RStatsModuleProperties.h
    

*/

#ifndef _OIG_RATSTATS_UTILS_RSTATSMODULEPROPERTIES_H
#define _OIG_RATSTATS_UTILS_RSTATSMODULEPROPERTIES_H

#include <vector>
#include <string>
#include <map>

namespace oig {
namespace ratstats {
namespace utils {

enum class RStatsModuleType
{
    Binary,
    Python,
    R
};

class RStatsModuleProperties 
{
public:
	//! Constructor for RStatsModuleProperties
	/*!
		Detailed description for RStatsModuleProperties
	*/
	RStatsModuleProperties();
        /**
    * @brief Setter for m_type
    * @param Value to replace m_type
    */
    void setType(const std::string & value);

    /**
    * @brief Setter for m_name
    * @param Value to replace m_name
    */
    void setName(const std::string & value);

    /**
    * @brief Setter for m_workingDir
    * @param Value to replace m_workingDir
    */
    void setWorkingDir(const std::string & value);

    /**
    * @brief Setter for m_location
    * @param Value to replace m_location
    */
    void setLocation(const std::string & value);

    /**
    * @brief Setter for m_group
    * @param Value to replace m_group
    */
    void setGroup(const std::string & value);

    /**
    * @brief Setter for m_args
    * @param Value to replace m_args
    */
    void setArgs(const std::vector<std::pair<std::string,std::string> > & value);

    /**
     * @brief getCommand
     * @return
     */
    void buildCommand(std::string& commandOut);

    /**
     * @brief setScriptPrefix
     * @param type
     * @param scriptFilePath
     */
    void setScriptPath(const std::string& type,
                       const std::string& scriptFilePath);

    /**
    * @brief Getter for m_type
    * @return Return copy of m_type
    */
    const std::string & getType() const;

    /**
    * @brief Getter for m_name
    * @return Return copy of m_name
    */
    const std::string & getName() const;

    /**
    * @brief Getter for m_workingDir
    * @return Return copy of m_workingDir
    */
    const std::string & getWorkingDir() const;

    /**
    * @brief Getter for m_location
    * @return Return copy of m_location
    */
    const std::string & getLocation() const;

    /**
    * @brief Getter for m_group
    * @return Return copy of m_group
    */
    const std::string & getGroup() const;

    /**
    * @brief Getter for m_args
    * @return Return copy of m_args
    */
    const std::vector<std::pair<std::string,std::string> > & getArgs() const;


    /**
     * @brief addArg
     * @param flag
     * @param argument
     */
    void addArg(const std::string& flag,
                const std::string& argument);


    /**
     * @brief clearArgs
     */
    void clearArgs();

	//! Destructor
	~RStatsModuleProperties();	

private:
    std::string m_type;
    std::string m_name;
    std::string m_workingDir;
    std::string m_location;
    std::string m_group;
    std::map<std::string,std::string> m_scriptPathMap;
    std::vector<std::pair<std::string,std::string> > m_args;

};
}}}//end namespace

#endif // _OIG_RATSTATS_UTILS_RSTATSMODULEPROPERTIES_H

