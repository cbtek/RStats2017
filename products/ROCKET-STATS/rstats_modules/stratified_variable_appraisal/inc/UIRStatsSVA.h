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

#include "rstats_ui/inc/UIRStatsTablePreviewWidget.h"
#include "rstats_ui/inc/UIRStatsWorkbook.h"

#include "RStatsSVASessionData.h"

class Ui_UIRStatsSVA;

namespace cbtek {
namespace rocketstats {
namespace modules {
namespace sva {

/**
 * @brief The UIRStatsSVA class represents the code-behind for the
 * stratified variable appraisal user interface.  In the model-view-controller
 * pardigm this class represents the view.
 */
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

private:

    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsSVA *m_ui;

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
      * @brief m_currentSizeSheetName
      */
     QString m_currentSizeSheetName;

     /**
      * @brief m_currentDataSheetName
      */
     QString m_currentDataSheetName;

     /**
     * @brief m_dataTableImportFilePath Path to data input table
     */
     QString m_dataTableImportFilePath;

     /**
     * @brief m_dataTableImportFilePath Path to data input table
     */
     QString m_sizeTableImportFilePath;

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
      * @brief Icons used by the validation console
      */
     QIcon m_iconError;
     QIcon m_iconWarning;
     QIcon m_iconOK;

     /**
      * @brief Current data sheets/workbooks for data/size tables
      */
     cbtek::rocketstats::utils::RStatsWorksheet m_currentDataSheet;

     /**
      * @brief m_currentSizeSheet
      */
     cbtek::rocketstats::utils::RStatsWorksheet m_currentSizeSheet;

     /**
      * @brief m_currentDataWorkbook
      */
     cbtek::rocketstats::utils::RStatsWorkbook m_currentDataWorkbook;

     /**
      * @brief m_currentSizeWorkbook
      */
     cbtek::rocketstats::utils::RStatsWorkbook m_currentSizeWorkbook;


     /**
      * @brief m_tblSizeInputPreview Subclassed QTableWidget object representing
      * size input preview table
      */
     cbtek::rocketstats::ui::UIRStatsTablePreviewWidget * m_tblSizeInputPreview;

     /**
      * @brief m_tblDataInputPreview Subclassed QTableWidget object representing
      * data input preview table
      */
     cbtek::rocketstats::ui::UIRStatsTablePreviewWidget * m_tblDataInputPreview;

     /**
      * @brief Used by validation console
      */
     cbtek::rocketstats::utils::RStatsConditionLogger m_conditionLogger;

     /**
      * @brief View for Workbook object
      */
     cbtek::rocketstats::ui::UIRStatsWorkbook * m_outputWorkbook;

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
     cbtek::rocketstats::utils::RStatsDataFormatType m_currentDataFormat;

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
      * @brief setXLSFileOutput
      * @param xlsFile
      */
     void setXLSFileOutput(const std::string& xlsFile);

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
      * @brief onValidate
      * @return
      */
     bool onValidate();

     /**
      * @brief onValidateSizeSheet
      * @param logger
      * @return
      */
     bool onValidateSizeSheet(utils::RStatsConditionLogger& logger);

protected:
     void resizeEvent(QResizeEvent*);

protected slots:

     /**
      * @brief onSampleDataInputSheetReload
      */
     void onSampleDataInputSheetReload();

     /**
      * @brief onSampleSizeInputSheetReload
      */
     void onSampleSizeInputSheetReload();

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
      * @brief onExecute
      */
     void onExecute();

     /**
      * @brief onExit
      */
     void onExit();  

     /**
      * @brief onSampleSizeInputSheetSelected
      * @param sheet
      */
     void onSampleSizeInputSheetSelected(const cbtek::rocketstats::utils::RStatsWorksheet& sheet);

     /**
      * @brief onSampleDataInputSheetSelected
      * @param sheet
      */
     void onSampleDataInputSheetSelected(const cbtek::rocketstats::utils::RStatsWorksheet& sheet);

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

     /**
      * @brief onUpdateDataFormatButtons
      */
     void onUpdateDataFormatButtons();

     /**
      * @brief onSetTabOrder
      */
     void onSetTabOrder();

     /**
      * @brief onSaveXLSFile
      */
     void onSaveXLSFile();

     /**
      * @brief onUpdateValidation Calls the onValidate function
      */
     void onUpdateValidation();

     /**
      * @brief onLaunchNewWindow Event occurs when user clicks the "New Window" File menu item.
      * Will launch new instance of the RStatsSVA window
      */
     void onLaunchNewWindow();
};

}}}}//end namespace
