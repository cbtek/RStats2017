/*
    RStatsSettingsManager.h
    

*/
#pragma once

#include <string>
#include <memory>
#include <vector>

namespace oig {
namespace ratstats {
namespace utils {

class Setting
{
public:
    std::string label,type,description,id;
    virtual ~Setting() {}
};

class NumericSetting : public Setting
{
public:
    int min,max,value;
};

class PathBrowserSetting : public Setting
{
public:
    std::string value;
};

typedef std::shared_ptr<Setting> SettingPtr;

class RStatsSettingsManager 
{

public:
	//! Constructor for RStatsSettingsManager
	/*!
		Detailed description for RStatsSettingsManager
	*/
	RStatsSettingsManager();
        
	//! Static instance method for this singleton
    static RStatsSettingsManager & inst();

    /**
     * @brief getSettings
     * @return
     */
    const std::vector<SettingPtr> & getSettings() const;

    /**
     * @brief setSettings
     * @param settings
     */
    void setSettings(const std::vector<SettingPtr>& settings);

    /**
     * @brief readSettings
     */
    void readSettings();

    /**
     * @brief writeSettings
     */
    void writeSettings();

    /**
     * @brief getSettingById
     * @param id
     * @return
     */
    SettingPtr getSettingById(const std::string& id) const;

	//! Destructor
	~RStatsSettingsManager();	

private:
    static RStatsSettingsManager m_instance;
    std::string m_settingsFilePath;
    std::vector<SettingPtr> m_settings;
    
};
}}}//end namespace
