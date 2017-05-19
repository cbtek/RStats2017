/*
    UIRStatsUVA.h
*/

#pragma once

#include <QMainWindow>
#include <QActionGroup>
#include <QLabel>
#include <QComboBox>
#include <QTimer>
#include <QButtonGroup>

#include "rstats_utils/inc/RStatsWorkbook.h"
#include "rstats_utils/inc/RStatsConditionLogger.h"

#include "rstats_ui/inc/UIRStatsWorkbook.h"
#include "rstats_ui/inc/UIRStatsTablePreviewWidget.h"

#include "RStatsUVASessionData.h"

class Ui_UIRStatsUVA;

namespace oig {
namespace ratstats {
namespace modules {
namespace uva {

/**
 * @brief The UIRStatsUVA class represents the code-behind for the
 * unrestricted variable appraisal user interface.  In the model-view-controller
 * pardigm this class represents the view.
 */

class UIRStatsUVA : public QMainWindow
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsUVA
	/*!
		Detailed description for UIRStatsUVA
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsUVA(QWidget *parent = 0);
        
    //! Destructor for UIRStatsUVA
    ~UIRStatsUVA();

protected:

    /**
     * @brief resizeEvent Called whenever window is resized.  This is called to reposition
     * output labels in the status bar
     * @param e The resize event object
     */
    void resizeEvent(QResizeEvent * e);

private:
    /**
    * MOC generated ui class for this widget
    */
    Ui_UIRStatsUVA *m_ui;

    /**
     * @brief m_iconError Icon for error in validation console
     */
    QIcon m_iconError;

    /**
     * @brief m_iconOK Icon for information in validation console
     */
    QIcon m_iconOK;

    /**
     * @brief m_iconWarning Icon for warning in validation console
     */
    QIcon m_iconWarning;

    /**
    * @brief m_recentSessionActionGroup Action group used to group together
    * all recenent session entities in the menu
    */
    QActionGroup* m_recentSessionActionGroup;

    /**
    * @brief m_recentSessionsMap Map between recent session and session data fields
    */
    std::map<std::string,utils::RStatsModuleSessionDataPtr> m_recentSessionsMap;

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
    * @brief m_dataTableImportFilePath Path to data input table
    */
    QString m_dataTableImportFilePath;

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
    * @brief m_autoSetFileOutput Flag used to automatically set file output
    */
    bool m_autoSetFileOutput;

    /**
    * @brief m_currentDataSheet The current worksheet
    */
    oig::ratstats::utils::RStatsWorksheet m_currentDataSheet;

    /**
    * @brief m_currentDataWorkbook The current workbook
    */
    oig::ratstats::utils::RStatsWorkbook m_currentDataWorkbook;

    /**
    * @brief m_conditionLogger Used by validation console for handling
    * warning and error conditions
    */
    oig::ratstats::utils::RStatsConditionLogger m_conditionLogger;

    /**
    * @brief m_currentDataFormat The current data format type
    */
    oig::ratstats::utils::RStatsDataFormatType m_currentDataFormat;

    /**
    * @brief m_tblPreview Widget for previewing data input table
    */
    oig::ratstats::ui::UIRStatsTablePreviewWidget * m_tblPreview;

    /**
    * @brief importDataTable Import data table from file
    * @param dataTableFilePath The path to the data table
    */
    void importDataTable(const std::string& dataTableFilePath);

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
    * @brief getSessionData Get UVA session data fields
    * @return Return object for UVA session data fields
    */
    RStatsUVASessionData getSessionData() const;

    /**
    * @brief setSessionData Populates the UI with fields from session data
    * @param data The session data to use
    */
    void setSessionData(const RStatsUVASessionData& data);

    /**
    * @brief updateRecentSessions Repopulates "recently used" fields in menu bar
    */
    void updateRecentSessions();

    /**
     * @brief onValidate Determines if the UVA function is ready to execute based on
     * input data given.  If there are errors/warnings detected then they are listed
     * in the validation console
     * @return Returns true if there are no errors, false otherwise
     */
    bool onValidate();

 private slots:        
    /**
     * @brief onImportDataInputReload
     */
    void onImportDataInputReload();

    /**
    * @brief onImportDataInput
    */    
    void onImportDataInput();

    /**
     * @brief onRecentSessionSelected
     * @param action
     */
    void onRecentSessionSelected(QAction* action);

    /**
     * @brief onComboDataInputSheetSelected
     * @param row
     */
    void onComboDataInputSheetSelected(int row);

    /**
     * @brief onSampleDataInputSheetSelected
     * @param sheet
     */
    void onSampleDataInputSheetSelected(const oig::ratstats::utils::RStatsWorksheet& sheet);

    /**
     * @brief onUpdateRowColumnExtentsForDataTable
     */
    void onUpdateRowColumnExtentsForDataTable();

    /**
     * @brief onUpdateDataFormatSelection
     */
    void onUpdateDataFormatSelection();

    /**
     * @brief onClearRecentSessions
     */
    void onClearRecentSessions();

    /**
     * @brief onSaveTextFile
     */
    void onSaveTextFile();

    /**
     * @brief onSaveCSVFile
     */
    void onSaveCSVFile();

    /**
     * @brief onSaveXLSFile
     */
    void onSaveXLSFile();

    /**
     * @brief onHelp
     */
    void onHelp();

    /**
     * @brief onAbout This function is execcuted when the user clicks "About" from the help menu
     */
    void onAbout();

    /**
     * @brief onExecute This function is executed when the user clicks "Execute" on the form or from the file menu
     */
    void onExecute();

    /**
     * @brief onExit Exits the window
     */
    void onExit();   

    /**
     * @brief onSetTabOrder Manually sets the tab order for this dialog
     */
    void onSetTabOrder();

    /**
     * @brief onUpdateDataFormatButtons Updates the radio buttons for data format type.
     * Ensures the correct combo boxes are enabled in the data input dialog
     */
    void onUpdateDataFormatButtons();

    /**
     * @brief onUpdateValidation Calls the onValidate function
     */
    void onUpdateValidation();

    /**
     * @brief onLaunchNewWindow Event occurs when user clicks the "New Window" File menu item.
     * Will launch new instance of the RStatsUVA window
     */
    void onLaunchNewWindow();

    /**
     * @brief resetFocus
     */
    void onResetFocus();
};
}}}}//end namespace


