/*
    UIRStatsGRN.h
    

*/
#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QActionGroup>
#include <QLabel>

#include <unordered_map>

#include "rstats_utils/inc/RStatsConditionLogger.h"
#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsModuleSessionData.hpp"

#include "RStatsGRNSessionData.h"

class Ui_UIRStatsGRN;
namespace cbtek {
namespace rocketstats {
namespace modules {
namespace grn {

class UIRStatsGRN : public QMainWindow
{
    Q_OBJECT
public:
   /**
    * @brief UIRStatsGRN
    * @param parent Pointer to parent widget. Defaults to null.
	*/		
    explicit UIRStatsGRN(QWidget *parent = 0);
        
   /**
    * @brief UIRStatsGRN
    *
	*/
    ~UIRStatsGRN();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsGRN *m_ui;



     /**
      * @brief m_conditionLogger Simple logger for console validation window
      */
     cbtek::rocketstats::utils::RStatsConditionLogger m_conditionLogger;

     /**
      * @brief m_currentTextFileOutput Path to text file output
      */
     QString m_currentTextFileOutput;

     /**
     * @brief m_currentCSVFileOutput Path to CSV file output
     */
     QString m_currentCSVFileOutput;

     /**
     * @brief m_currentXLSFileOutput Path to XLS file output
     */
     QString m_currentXLSFileOutput;

     /**
     * @brief m_currentTextFileOutputLabel UI label for text output
     */
     QLabel * m_currentTextFileOutputLabel;

     /**
     * @brief m_currentCSVFileOutputLabel UI label for CSV output
     */
     QLabel * m_currentCSVFileOutputLabel;

     /**
     * @brief m_currentXLSFileOutputLabel UI label for XLS output
     */
     QLabel * m_currentXLSFileOutputLabel;

     /**
      * @brief Icons used for the validation console
      */
     QIcon m_iconError;

     /**
      * @brief m_iconWarning
      */
     QIcon m_iconWarning;

     /**
      * @brief m_iconOK
      */
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
     * @brief setXLSFileOutput Set output for the XLS file
     * @param xlsFile The path to the xls file
     */
     void setXLSFileOutput(const std::string& xlsFile);

     /**
      * @brief getSessionData Binds the view data to the model
      * @return Object containing fields relevant for SSRN
      */
     RStatsGRNSessionData getSessionData() const;

     /**
      * @brief setSessionData Binds the model data to the view
      * @param data Fields relevant to SSRN
      */
     void setSessionData(const RStatsGRNSessionData& data);

     /**
      * @brief updateRecentSessions Updates the recently used sessions
      */
     void updateRecentSessions();

     /**
      * @brief onValidate Occurs prior to onExecute completing.  Ensures that all fields are valid and
      * updates the validation console with any new messages.
      */
     bool onValidate();
    
};
}}}}//end namespace
