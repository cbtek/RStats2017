/*
    RStatsScriptProviderProperties.h
    

*/

#ifndef _OIG_RATSTATS_UTILS_RSTATSSCRIPTPROVIDERPROPERTIES_H
#define _OIG_RATSTATS_UTILS_RSTATSSCRIPTPROVIDERPROPERTIES_H

#include <string>

namespace oig {
namespace ratstats {
namespace utils {


class RStatsScriptProviderProperties 
{
public:
	//! Constructor for RStatsScriptProviderProperties
	/*!
		Detailed description for RStatsScriptProviderProperties
	*/
	RStatsScriptProviderProperties();
        /**
    * @brief Setter for m_path
    * @param Value to replace m_path
    */
    void setPath(const std::string & value);

    /**
    * @brief Setter for m_icon
    * @param Value to replace m_icon
    */
    void setIcon(const std::string & value);

    /**
    * @brief Setter for m_args
    * @param Value to replace m_args
    */
    void setArgs(const std::string & value);

    /**
    * @brief Setter for m_name
    * @param Value to replace m_name
    */
    void setName(const std::string & value);


        /**
    * @brief Getter for m_path
    * @return Return copy of m_path
    */
    const std::string & getPath() const;

    /**
    * @brief Getter for m_icon
    * @return Return copy of m_icon
    */
    const std::string & getIcon() const;

    /**
    * @brief Getter for m_args
    * @return Return copy of m_args
    */
    const std::string & getArgs() const;

    /**
    * @brief Getter for m_name
    * @return Return copy of m_name
    */
    const std::string & getName() const;


    /**
     * @brief saveConfig
     */
    void saveConfig();

    /**
     * @brief saveConfig
     * @param filePath
     */
    void saveConfig(const std::string & filePath);

    /**
     * @brief loadConfig
     * @param filePath
     */
    void loadConfig(const std::string & filePath);


    /**
     * @brief removeConfigFile
     */
    void removeConfig();

    /**
     * @brief setConfigPath
     * @param configPath
     */
    void setConfigPath(const std::string & configPath);

    /**
     * @brief getConfigPath
     * @return
     */
    const std::string & getConfigPath() const;

	//! Destructor
	~RStatsScriptProviderProperties();	

private:

    std::string m_path;
    std::string m_configPath;
    std::string m_icon;
    std::string m_args;
    std::string m_name;


};
}}}//end namespace

#endif // _OIG_RATSTATS_UTILS_RSTATSSCRIPTPROVIDERPROPERTIES_H

