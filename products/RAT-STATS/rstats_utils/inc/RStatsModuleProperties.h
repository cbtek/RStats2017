/*
    RStatsModuleProperties.h
    

*/

#pragma once

#include <vector>
#include <string>
#include <map>

namespace oig {
namespace ratstats {
namespace utils {

/**
 * @brief The RStatsModuleProperties class represents a individual
 * module object in RAT-STATS. It provides a method of loading, saving
 * and removing the module to/from disk.
 *
 */
class RStatsModuleProperties 
{
public:

    /**
     * @brief RStatsModuleProperties (Constructor)
     */
	RStatsModuleProperties();

   /**
    * @brief Setter for m_type
    * @param value to replace m_type
    */
    void setType(const std::string & value);

    /**
    * @brief Setter for m_name
    * @param value to replace m_name
    */
    void setName(const std::string & value);

    /**
    * @brief Setter for m_workingDir
    * @param value to replace m_workingDir
    */
    void setWorkingDir(const std::string & value);

    /**
    * @brief Setter for m_location
    * @param value to replace m_location
    */
    void setPath(const std::string & value);

    /**
    * @brief Setter for m_group
    * @param value to replace m_group
    */
    void setCategory(const std::string & value);

    /**
    * @brief Setter for m_args
    * @param value to replace m_args
    */
    void setArgs(const std::vector<std::pair<std::string,std::string> > & value);

    /**
     * @brief getGeneratedApplicationCommand This fuction constructs a
     * command string which includes module path, script (if applicable)
     * and command line arguments
     * @return Returns string of full command thats ready to be launched
     */
    std::string getGeneratedApplicationCommand() const;

    /**
     * @brief generateApplicationCommand
     * @param commandOut
     * @param argsOut
     */
    void generateApplicationCommand(std::string& commandOut, std::string& argsOut);
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
     * @brief getConfigPath
     * @return
     */
    const std::string & getConfigPath() const;


    /**
    * @brief Getter for m_args
    * @return Return copy of m_args
    */
    const std::string & getScriptPathArgs() const;

    /**
     * @brief setArgs
     * @param value
     */
    void setScriptPathArgs(const std::string &value);

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
     * @brief setConfigPath Sets the XML config file path
     * @param path The path to the XML config file
     */
    void setConfigPath(const std::string & path);

    /**
     * @brief loadConfig
     * @param filePath Reads XML config from filePath
     */
    void loadConfig(const std::string& filePath);

    /**
     * @brief saveConfig Saves XML config to filePath
     */
    void saveConfig(const std::string& filePath);

    /**
     * @brief saveConfig Saves XML config to default filePath
     */
    void saveConfig();

    /**
     * @brief removeConfig Deletes XML config from default filePath
     */
    void removeConfig();

    /**
     * @brief setIcon
     * @param appIcon
     */
    void setIcon(const std::string& appIcon);

    /**
     * @brief getIcon Returns string relative URL to icon resource
     * @return
     */
    std::string getIcon() const;

    /**
     * @brief isConsoleShown Determines if command console should
     * be shown.
     * @return Returns true if console should be shown, false otherwise
     */
    bool isConsoleShown() const;

    /**
     * @brief setConsoleShown Sets boolean flag for condition
     * where the command console should be shown when launching
     * a module.
     * @param flag The boolean flag to set
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
    std::string m_appScriptPathArgs;
    std::string m_configPath;
    std::string m_appArgs;
    bool m_showAppConsole;    

};
}}}//end namespace

