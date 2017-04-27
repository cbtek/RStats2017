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
    QLabel * m_currentTextFileOutputLabel;
    QLabel * m_currentCSVFileOutputLabel;
    bool m_autoSetFileOutput;
    oig::ratstats::utils::RStatsConditionLogger m_conditionLogger;
    QTimer m_clock;

    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsUAA *m_ui;

     /**
      * @brief setTextFileOutput
      * @param textFile
      */
     void setTextFileOutput(const std::string& textFile);

     /**
      * @brief setCSVFileOutput
      * @param csvFile
      */
     void setCSVFileOutput(const std::string& csvFile);

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
      * @brief onValidate Ensures all input fields are valid before executing function
      * @return
      */
     bool onValidate();

     /**
      * @brief onUpdateClock Called every second and is primarly used for calling validation function
      */
     void onUpdateClock();
};

}}}}//end namespace
