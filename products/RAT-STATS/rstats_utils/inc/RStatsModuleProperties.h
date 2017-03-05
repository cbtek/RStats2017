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
    void setPath(const std::string & value);

    /**
    * @brief Setter for m_group
    * @param Value to replace m_group
    */
    void setCategory(const std::string & value);

    /**
    * @brief Setter for m_args
    * @param Value to replace m_args
    */
    void setArgs(const std::vector<std::pair<std::string,std::string> > & value);

    /**
     * @brief getCommand
     * @return
     */
    void generateApplicationCommand(std::string& commandOut);

    /**
     * @brief setScriptPrefix
     * @param type
     * @param scriptFilePath
     */
    void setScriptPath(const std::string& scriptFilePath);

    const std::string & getScriptPath() const;

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
    const std::string & getPath() const;

    /**
    * @brief Getter for m_group
    * @return Return copy of m_group
    */
    const std::string & getCategory() const;

    /**
     * @brief getDefinitionPath
     * @return
     */
    const std::string & getDefinitionPath() const;

    /**
    * @brief Getter for m_args
    * @return Return copy of m_args
    */
    const std::string & getArgs() const;

    /**
     * @brief setArgs
     * @param value
     */
    void setArgs(const std::string &value);


    /**
     * @brief setDefinitionPath
     * @param path
     */
    void setDefinitionPath(const std::string & path);   

    /**
     * @brief load
     * @param filePath
     */
    void loadConfig(const std::string& filePath);

    /**
     * @brief save
     */
    void saveConfig(const std::string& filePath);

    /**
     * @brief saveConfig
     */
    void saveConfig();

    /**
     * @brief removeConfig
     */
    void removeConfig();

    /**
     * @brief setIcon
     * @param appIcon
     */
    void setIcon(const std::string& appIcon);

    /**
     * @brief getIcon
     * @return
     */
    std::string getIcon() const;

    /**
     * @brief isApplicationConsoleShown
     * @return
     */
    bool isConsoleShown() const;

    /**
     * @brief setConsoleShown
     * @param flag
     */
    void setConsoleShown(bool flag);

    //! Destructor
    ~RStatsModuleProperties();

private:
    std::string m_appType;
    std::string m_appName;
    std::string m_appWorkingDir;
    std::string m_appPath;
    std::string m_appCategory;
    std::string m_appIcon;
    std::string m_appScriptPath;
    std::string m_configPath;
    std::string m_appArgs;
    bool m_showAppConsole;    

};
}}}//end namespace

#endif // _OIG_RATSTATS_UTILS_RSTATSMODULEPROPERTIES_H

