/*
 UIRStatsSSRN.h
*/

#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QActionGroup>
#include <QLabel>

#include "rstats_utils/inc/RStatsConditionLogger.h"
#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsModuleSessionData.hpp"

#include "RStatsSSRNSessionData.h"

class Ui_UIRStatsSSRN;

namespace oig {
namespace ratstats {
namespace modules {
namespace ssrn {

class UIRStatsSSRN : public QMainWindow
{
    Q_OBJECT

public:
    //! Constructor for UIRStatsSSRN
    /*!
        Detailed description for UIRStatsSSRN
        @param      parent points to embedding super widget. Defaults to null.
    */
    explicit UIRStatsSSRN(QWidget *parent = 0);

    //! Destructor for UIRStatsSSRN
    ~UIRStatsSSRN();

protected:
    void resizeEvent(QResizeEvent *);

private:


    /**
    * MOC generated ui class for this widget
    */
    Ui_UIRStatsSSRN *m_ui;


    /**
     * @brief m_logger Simple logger for console validation window
     */
    oig::ratstats::utils::RStatsConditionLogger m_logger;

    /**
     * @brief Labels/Strings for the output locations
     */
    QString m_currentCSVFileOutput;
    QString m_currentTextFileOutput;
    QLabel * m_currentCSVFileOutputLabel;
    QLabel * m_currentTextFileOutputLabel;

    /**
     * @brief Icons used for the validation console
     */
    QIcon m_iconError;
    QIcon m_iconWarning;
    QIcon m_iconOK;

    /**
     * @brief m_rnd Simple random number generator
     */
    cbtek::common::utility::Random m_rnd;

    /**
     * @brief m_recentSessionActionGroup Contains recently used action sessions (View)
     */
    QActionGroup * m_recentSessionActionGroup;

    /**
     * @brief m_recentSessionsMap Contains recently used action sessions (Model)
     */
    std::map<std::string,utils::RStatsModuleSessionDataPtr> m_recentSessionsMap;    

    /**
     * @brief m_autoSetFileOutput When this is true, the output files can be
     * manually set without showing browse GUI
     */
    bool m_autoSetFileOutput;

    /**
     * @brief setCSVFileOutput Sets output for CSV file
     * @param csvFile The location to save the CSV file
     */
    void setCSVFileOutput(const std::string& csvFile);

    /**
     * @brief setTextFileOutput Sets output for text file
     * @param textFile The location to save the text file
     */
    void setTextFileOutput(const std::string& textFile);

    /**
     * @brief getSessionData Binds the view data to the model
     * @return Object containing fields relevant for SSRN
     */
    RStatsSSRNSessionData getSessionData() const;

    /**
     * @brief setSessionData Binds the model data to the view
     * @param data Fields relevant to SSRN
     */
    void setSessionData(const RStatsSSRNSessionData& data);

    /**
     * @brief updateRecentSessions Updates the recently used sessions
     */
    void updateRecentSessions();


private slots:                    
    /**
      * @brief onSeedBoxToggled Event occurs when Custom Seed checkbox is toggled
      * @param toggle
      */
     void onSeedBoxToggled(bool toggle);

     /**
      * @brief onClearRecentSessions Event occurs when user clicks "Clear Recent Sessions" from menu
      */
     void onClearRecentSessions();

     /**
      * @brief onRecentSessionSelected Event occurs when user selects a recently used session from menu
      * @param action
      */
     void onRecentSessionSelected(QAction* action);

     /**
      * @brief onExit Event occurs when user clicks the exit button.  This closes the program.
      */
     void onExit();

     /**
      * @brief onExecute Event occurs when user clicks the execute button.
      */
     void onExecute();

     /**
      * @brief onHelp Event occurs when user clicks the Help button.  Should display pdf for this module.
      */
     void onHelp();

     /**
      * @brief onValidate Occurs prior to onExecute completing.  Ensures that all fields are valid and
      * updates the validation console with any new messages.
      */
     void onValidate();

     /**
      * @brief onSaveCSVFile Event occurs when user clicks the checkbox to save csv file.  This will
      * bring up the browse file dialog
      */
     void onSaveCSVFile();

     /**
      * @brief onSaveTextFile Event occurs when user clicks the checkbox to save text file.  This will
      * bring up the browse file dialog
      */
     void onSaveTextFile();

     /**
      * @brief onUpdateClock This function is updated every second prior to the onExecute function being called.
      * It updates the seed with a random value every second.
      */
     void onUpdateClock();

     /**
      * @brief onAbout
      */
     void onAbout();     

};

}}}}//end namespace

