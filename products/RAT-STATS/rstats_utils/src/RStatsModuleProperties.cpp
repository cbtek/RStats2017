/*
    RStatsModuleProperties.cpp
    

*/
//----------------------------------------
//RStatsModuleProperties.cpp generated by sunefusion on 02-28-2017 at 09:39:48 PM
//----------------------------------------
#include "RStatsModuleProperties.h"

#include <sstream>

#include "utility/inc/XMLReader.h"
#include "utility/inc/XMLStreamWriter.h"
#include "utility/inc/XMLUtils.h"
#include "utility/inc/FileUtils.hpp"

using namespace cbtek::common::utility;

namespace oig {
namespace ratstats {
namespace utils {


RStatsModuleProperties::RStatsModuleProperties()
{
    m_showAppConsole = false;
}

RStatsModuleProperties::~RStatsModuleProperties()
{

}

void RStatsModuleProperties::loadConfig(const std::string &filePath)
{
    XMLReader reader;
    reader.load(filePath);
    XMLDataElement * module = reader.getElement("module");
    if (module)
    {
        m_appName = module->getAttributeValue("name");
        m_appPath = module->getAttributeValue("path");
        m_appType = module->getAttributeValue("type");
        m_appWorkingDir = module->getAttributeValue("working_dir");
        m_appCategory = module->getAttributeValue("category");
        m_appIcon = module->getAttributeValue("icon");
        m_showAppConsole = module->getAttributeValueAsBool("show_console");
        m_appArgs = XMLUtils::getDecodedString(module->getAttributeValue("args"));
        m_configPath = filePath;
    }
    else
    {
        throw FileNotFoundException(EXCEPTION_TAG_LINE+"Could not parse file at \""+filePath+"\"");
    }
}

void RStatsModuleProperties::saveConfig()
{
    saveConfig(m_configPath);
}

void RStatsModuleProperties::saveConfig(const std::string &filePath)
{
    std::ofstream out(filePath.c_str());
    if (out.is_open())
    {
        XMLStreamWriter xml(out);
        xml.writeStartDocument();
        xml.writeStartElement("module");
        xml.writeAttribute("name",m_appName);
        xml.writeAttribute("category",m_appCategory);
        xml.writeAttribute("path",m_appPath);
        xml.writeAttribute("script_path",m_appScriptPath);
        xml.writeAttribute("type",m_appType);
        xml.writeAttribute("working_dir",m_appType);
        xml.writeAttribute("icon",m_appIcon);
        xml.writeAttribute("show_console", (m_showAppConsole ? "TRUE" : "FALSE"));        
        xml.writeLastAttributeAndCloseTag("args",XMLUtils::getEncodedString(m_appArgs));
        m_configPath = filePath;
    }
}

void RStatsModuleProperties::setType(const std::string &value)
{
    m_appType=value;
}

void RStatsModuleProperties::setName(const std::string & value)
{
    m_appName=value;
}

void RStatsModuleProperties::setWorkingDir(const std::string & value)
{
    m_appWorkingDir=value;
}

void RStatsModuleProperties::setPath(const std::string & value)
{
    m_appPath=value;
}

void RStatsModuleProperties::setCategory(const std::string & value)
{
    m_appCategory=value;
}

void RStatsModuleProperties::generateApplicationCommand(std::string& commandOut)
{
    std::ostringstream command;
    command << m_appScriptPath<<" "<<m_appPath<<" "<<m_appArgs;
    commandOut = command.str();
}

const std::string &RStatsModuleProperties::getType() const
{
    return m_appType;
}

const std::string &RStatsModuleProperties::getName() const
{
    return m_appName;
}

const std::string &RStatsModuleProperties::getWorkingDir() const
{
    return m_appWorkingDir;
}

const std::string &RStatsModuleProperties::getPath() const
{
    return m_appPath;
}

const std::string &RStatsModuleProperties::getCategory() const
{
    return m_appCategory;
}

const std::string &RStatsModuleProperties::getDefinitionPath() const
{
    return m_configPath;
}

const std::string &RStatsModuleProperties::getArgs() const
{
    return m_appArgs;
}

void RStatsModuleProperties::setArgs(const std::string &value)
{
    m_appArgs = value;
}

void RStatsModuleProperties::setDefinitionPath(const std::string &path)
{
    m_configPath = path;
}

void RStatsModuleProperties::removeConfig()
{
    FileUtils::deleteFile(m_configPath);
}

void RStatsModuleProperties::setScriptPath(const std::string &scriptFilePath)
{
    m_appScriptPath = scriptFilePath;
}

const std::string &RStatsModuleProperties::getScriptPath() const
{
    return m_appScriptPath;
}

void RStatsModuleProperties::setIcon(const std::string &appIcon)
{
    m_appIcon = appIcon;
}

std::string RStatsModuleProperties::getIcon() const
{
    return m_appIcon;
}

void RStatsModuleProperties::setConsoleShown(bool flag)
{
    m_showAppConsole = flag;
}

bool RStatsModuleProperties::isConsoleShown() const
{
    return m_showAppConsole;
}
}}}//end namespace


