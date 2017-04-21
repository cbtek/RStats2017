/*
    UIRStatsSVA.h    
*/

#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QComboBox>
#include <QKeyEvent>
#include <QLabel>
#include <QActionGroup>

#include "rstats_utils/inc/RStatsWorkbook.h"
#include "rstats_utils/inc/RStatsConditionLogger.h"
#include "rstats_ui/inc/UIRStatsWorkbook.h"

#include "RStatsSVASessionData.h"

class Ui_UIRStatsSVA;

namespace oig {
namespace ratstats {
namespace modules {
namespace sva {

class UIRStatsSVA : public QMainWindow
{
    Q_OBJECT

public:
    //! Constructor for UIRStatsSVA
	/*!
        Detailed description for UIRStatsSVA
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsSVA(QWidget *parent = 0);

    //! Destructor for UIRStatsSVA
    ~UIRStatsSVA();

protected:

    /**
     * @brief keyPressEvent
     * @param evt
     */
    void keyPressEvent(QKeyEvent*evt);

private:

    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsSVA *m_ui;

     /**
      * @brief m_clock
      */
     QTimer m_clock;

     /**
      * @brief Labels/Strings for output
      */
     QString m_currentTextFileOutput;
     QString m_currentCSVFileOutput;     
     QLabel * m_currentTextFileOutputLabel;
     QLabel * m_currentCSVFileOutputLabel;

     /**
      * @brief Paths for importing the data and size sheet
      */
     QString m_sizeTableImportFilePath;
     QString m_dataTableImportFilePath;

     /**
      * @brief Icons used by the validation console
      */
     QIcon m_iconError;
     QIcon m_iconWarning;
     QIcon m_iconOK;

     /**
      * @brief Current data sheets/workbooks for data/size tables
      */
     oig::ratstats::utils::RStatsWorksheet m_currentDataSheet;
     oig::ratstats::utils::RStatsWorksheet m_currentSizeSheet;
     oig::ratstats::utils::RStatsWorkbook m_currentDataWorkbook;
     oig::ratstats::utils::RStatsWorkbook m_currentSizeWorkbook;

     /**
      * @brief Used by validation console
      */
     oig::ratstats::utils::RStatsConditionLogger m_conditionLogger;

     /**
      * @brief View for Workbook object
      */
     oig::ratstats::ui::UIRStatsWorkbook * m_outputWorkbook;

     /**
      * @brief m_fullScreenToggle Toggles full screen mode to view output data
      */
     bool m_fullScreenToggle;


     /**
      * @brief m_autoSetFileOutput Allows output checkboxes to be changed without signaling event for file browser
      */
     bool m_autoSetFileOutput;

     /**
      * @brief m_recentSessionActionGroup Holds all the recently ran session actions
      */
     QActionGroup * m_recentSessionActionGroup;

     /**
      * @brief m_recentSessionsMap
      */
     std::map<std::string,utils::RStatsModuleSessionDataPtr> m_recentSessionsMap;

     /**
      * @brief m_dataFormatType
      */
     utils::RStatsDataFormatType m_dataFormatType;     

     /**
      * @brief m_currentDataFormat
      */
     oig::ratstats::utils::RStatsDataFormatType m_currentDataFormat;

     /**
      * @brief importDataTable
      * @param dataTableFilePath
      */
     void importDataTable(const std::string& dataTableFilePath);

     /**
      * @brief importSizeTable
      * @param sizeTableFilePath
      */
     void importSizeTable(const std::string& sizeTableFilePath);

     /**
      * @brief setCSVFileOutput
      * @param csvFile
      */
     void setCSVFileOutput(const std::string& csvFile);

     /**
      * @brief setTextFileOutput
      * @param textFile
      */
     void setTextFileOutput(const std::string& textFile);

     /**
      * @brief getSessionData Binds the view to the model data for sva
      * @return The data fields relevent to sva
      */
     RStatsSVASessionData getSessionData() const;

     /**
      * @brief setSessionData Binds the model data to the view for sva
      * @param data The fields that are relevant to sva
      */
     void setSessionData(const RStatsSVASessionData& data);

     /**
      * @brief updateRecentSessions Updates the recently used sessions
      */
     void updateRecentSessions();     

     /**
      * @brief populateWithColumns Populates combobox with spreadsheet column labels
      * @param columns set of column integers
      * @param comboBox The view control to populate
      */
     void populateWithColumns(const std::set<size_t> &columns, QComboBox* comboBox);

     /**
      * @brief populateWithRows Populates combobox with spreadsheet row labels
      * @param rows set of row integers
      * @param comboBox The view control to populate
      */
     void populateWithRows(const std::set<size_t> &rows, QComboBox* comboBox);

protected:
     void resizeEvent(QResizeEvent*);

protected slots:
     /**
      * @brief onClearRecentSessions
      */
     void onClearRecentSessions();

     /**
      * @brief onRecentSessionSelected
      * @param action
      */
     void onRecentSessionSelected(QAction* action);

     /**
      * @brief onUpdateRowColumnExtentsForDataTable
      */
     void onUpdateRowColumnExtentsForDataTable();

     /**
      * @brief onUpdateRowColumnExtentsForSizeTable
      */
     void onUpdateRowColumnExtentsForSizeTable();

     /**
      * @brief onValidate
      * @return
      */
     bool onValidate();

     /**
      * @brief onUpdateClock
      */
     void onUpdateClock();

     /**
      * @brief onExecute
      */
     void onExecute();

     /**
      * @brief onExit
      */
     void onExit();

     /**
      * @brief onToggleFullScreen
      */
     void onToggleFullScreen();

     /**
      * @brief onSampleSizeInputSheetSelected
      * @param sheet
      */
     void onSampleSizeInputSheetSelected(const oig::ratstats::utils::RStatsWorksheet& sheet);

     /**
      * @brief onSampleDataInputSheetSelected
      * @param sheet
      */
     void onSampleDataInputSheetSelected(const oig::ratstats::utils::RStatsWorksheet& sheet);

     /**
      * @brief onComboSizeInputSheetSelected
      * @param row
      */
     void onComboSizeInputSheetSelected(int row);

     /**
      * @brief onComboDataInputSheetSelected
      * @param row
      */
     void onComboDataInputSheetSelected(int row);

     /**
      * @brief onImportDataInput
      */
     void onImportDataInput();

     /**
      * @brief onImportSizeInput
      */
     void onImportSizeInput();

     /**
      * @brief onHelp
      */
     void onHelp();

     /**
      * @brief onSaveCSVFile
      */
     void onSaveCSVFile();

     /**
      * @brief onSaveTextFile
      */
     void onSaveTextFile();

     /**
      * @brief onUpdateDataFormatSelection
      */
     void onUpdateDataFormatSelection();

     /**
      * @brief onAbout
      */
     void onAbout();
};

}}}}//end namespace
