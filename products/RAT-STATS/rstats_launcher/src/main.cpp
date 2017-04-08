#include <QApplication>
#include <QMessageBox>

#include "UIRStatsLaunchProgressDialog.h"

#include "rstats_utils/inc/RStatsModuleProperties.h"

#include "rstats_ui/inc/UIRStatsUtils.hpp"
#include "rstats_ui/inc/UIRStatsErrorMessage.h"

#include "utility/inc/StringUtils.hpp"
#include "utility/inc/FileUtils.hpp"

using namespace cbtek::common::utility;
using namespace oig::ratstats::launcher;
using namespace oig::ratstats::utils;
using namespace oig::ratstats::ui;

int main(int argc, char ** argv)
{
	QApplication a(argc,argv);
    UIRStatsUtils::loadThemeSettings(&a);
    RStatsModuleProperties props;
    std::string modulePath = StringUtils::getCommandLineArg(argc,argv,"--module-path","-m");

    try
    {
        if (FileUtils::fileExists(modulePath))
        {
            props.loadConfig(modulePath);            
            if (!props.isConsoleShown())
            {
                std::string command;
                props.generateApplicationCommand(command);
                StringUtils::trimmedInPlace(command);
                if (FileUtils::fileExists(command))
                {
                    QProcess::startDetached(QString::fromStdString(command));
                }
                else
                {
                    throw FileNotFoundException(EXCEPTION_TAG+"Could not find module at \""+props.getPath()+"\"");
                }
                return a.exec();
            }
            UIRStatsLaunchProgressDialog ui(props);
            return ui.exec();
        }
        if (StringUtils::trimmed(modulePath).size())
        {
            throw FileNotFoundException(EXCEPTION_TAG+"Could not find file at \""+modulePath+"\"");
        }
        else
        {
            throw FileNotFoundException(EXCEPTION_TAG+"No file defined for the launcher.\n Please send file as command line argument -m <filePath> or --module-path <filePath> \""+modulePath+"\"");
        }
    }
    catch(std::exception& e)
    {
        UIRStatsErrorMessage("Launcher Error Occurred",std::string(e.what()),true).exec();
        return -1;
    }
}

