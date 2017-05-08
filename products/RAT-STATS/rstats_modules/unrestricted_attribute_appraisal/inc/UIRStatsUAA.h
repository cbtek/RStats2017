/*
    UIRStatsUAA.h
    

*/

#pragma once

#include <QMainWindow>
#include <QActionGroup>
#include <QAction>
#include <QLabel>
#include <QTimer>

#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsConditionLogger.h"

#include "RStatsUAASessionData.h"

class Ui_UIRStatsUAA;

namespace oig {
namespace ratstats {
namespace modules {
namespace uaa {

/**
 * @brief The UIRStatsUAA class represents the code-behind for the
 * unrestricted attribute appraisal user interface.  In the model-view-controller
 * pardigm this class represents the view.
 */
class UIRStatsUAA : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief UIRStatsUAA Class Destructor
     * @param parent Points to embedding super widget. Defaults to null.
     */
    explicit UIRStatsUAA(QWidget *parent = 0);
        
    /**
     * @brief UIRStatsUAA Class Destructor
     */
    ~UIRStatsUAA();

protected:
    /**
     * @brief resizeEvent Called whenever the window is resized
     */
    void resizeEvent(QResizeEvent*);
private:

    QIcon m_iconError;
    QIcon m_iconWarning;
    QIcon m_iconOK;
    QActionGroup* m_recentSessionActionGroup;
    std::map<std::string,utils::RStatsModuleSessionDataPtr> m_recentSessionsMap;    

    /**
     * @brief Labels/Strings for output
     */
    QString m_currentTextFileOutput;
    QString m_currentCSVFileOutput;
    QString m_currentXLSFileOutput;
    QLabel * m_currentTextFileOutputLabel;
    QLabel * m_currentCSVFileOutputLabel;
    QLabel * m_currentXLSFileOutputLabel;
    bool m_autoSetFileOutput;
    oig::ratstats::utils::RStatsConditionLogger m_conditionLogger;   

    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsUAA *m_ui;

     /**
     * @brief setTextFileOutput Set output for text file
     * @param textFile The path to the text file
     */
     void setTextFileOutput(const std::string& textFile);

     /**
     * @brief setCSVFileOutput Set output for CSV file
     * @param csvFile The path to the CSV file
     */
     void setCSVFileOutput(const std::string& csvFile);

     /**
     * @brief setXLSFileOutput Set output for the XLS file
     * @param xlsFile The path to the xls file
     */
     void setXLSFileOutput(const std::string& xlsFile);

     /**
      * @brief getSessionData binds fields from the user interface into
      * session data object
      * @return Session data object containing fields to save
      */
     RStatsUAASessionData getSessionData() const;

     /**
      * @brief setSessionData Binds fields from session data object
      * to the user interface widgets
      * @param data The session data object containing fields for the user interface
      */
     void setSessionData(const RStatsUAASessionData& data);

     /**
      * @brief updateRecentSessions Reinitializes the sessions for this module and populates the menu
      */
     void updateRecentSessions();

     /**
      * @brief onValidate Ensures all input fields are valid before executing function
      * @return
      */
     bool onValidate();


private slots:

     /**
      * @brief onRecentSessionSelected
      * @param action
      */
     void onRecentSessionSelected(QAction* action);

     /**
      * @brief onUpdateSampleCount
      */
     void onUpdateSampleCount();

     /**
      * @brief onUpdateUniverseCount
      */
     void onUpdateUniverseCount();

     /**
      * @brief onClearRecentSessions Deletes all sessions for current module
      */
     void onClearRecentSessions();

     /**
      * @brief onSaveTextFile Saves evenly spaced text file to disk
      */
     void onSaveTextFile();

     /**
      * @brief onSaveCSVFile Saves CSV file to disk
      */
     void onSaveCSVFile();

     /**
      * @brief onSaveXLSFile
      */
     void onSaveXLSFile();

     /**
      * @brief onHelp Launches PDF containing help for unrestricted attribute appraisal
      */
     void onHelp();

     /**
      * @brief onExecute Runs instance of unrestricted attribute appraisal function
      */
     void onExecute();

     /**
      * @brief onExit Closes the menu
      */
     void onExit();

     /**
      * @brief onAbout Displays the about menu
      */
     void onAbout();

     /**
      * @brief onUpdateValidation Used for calling on validate
      */
     void onUpdateValidation();

     /**
      * @brief onLaunchNewWindow Event occurs when user clicks the "New Window" File menu item.
      * Will launch new instance of the RStatsUAA window
      */
     void onLaunchNewWindow();
};

}}}}//end namespace
