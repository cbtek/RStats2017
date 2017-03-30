/*
    UIRStatsSVA.h
    

*/

#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QComboBox>
#include <QKeyEvent>

#include "rstats_utils/inc/RStatsWorkbook.h"
#include "rstats_utils/inc/RStatsConditionLogger.h"
#include "rstats_ui/inc/UIRStatsWorkbook.h"

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
    void keyPressEvent(QKeyEvent*evt);

private:

    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsSVA *m_ui;
     QIcon m_iconFolder;
     QIcon m_iconSave;
     QIcon m_iconHelp;
     QIcon m_iconExit;
     QIcon m_iconRun;
     QIcon m_iconAdd;
     QIcon m_iconError;
     QIcon m_iconWarning;
     QIcon m_iconOK;
     QTimer m_clock;
     QString m_currentTextFileOutput;
     QString m_currentCSVFileOutput;
     oig::ratstats::utils::RStatsWorksheet m_currentDataSheet;
     oig::ratstats::utils::RStatsWorksheet m_currentSizeSheet;
     oig::ratstats::utils::RStatsWorkbook m_currentDataWorkbook;
     oig::ratstats::utils::RStatsWorkbook m_currentSizeWorkbook;
     oig::ratstats::utils::RStatsConditionLogger m_conditionLogger;
     oig::ratstats::ui::UIRStatsWorkbook * m_outputWorkbook;
     Qt::WindowStates m_currentWindowState;
     Qt::WindowFlags m_currentWindowFlags;
     bool m_fullScreenToggle;
     void populateWithColumns(const std::set<size_t> &columns, QComboBox* comboBox);
     void populateWithRows(const std::set<size_t> &rows, QComboBox* comboBox);
protected slots:     
     void onAddNewRowToDataTable();
     void onAddNewRowToSizeTable();
     void onAddNewColumnToDataTable();
     void onAddNewColumnToSizeTable();
     void onUpdateRowColumnExtentsForDataTable();
     void onUpdateRowColumnExtentsForSizeTable();
     bool onValidate();
     void onUpdateClock();
     void onContinue();
     void onExit();
     void onToggleFullScreen();
     void onSampleSizeInputSheetSelected(const oig::ratstats::utils::RStatsWorksheet& sheet);
     void onSampleDataInputSheetSelected(const oig::ratstats::utils::RStatsWorksheet& sheet);
     void onComboSizeInputSheetSelected(int row);
     void onComboDataInputSheetSelected(int row);
     void onImportDataInput();
     void onImportSizeInput();
     void onHelp();
     void onSaveCSVFile();
     void onSaveTextFile();
     void onSetStratum(int count);
     void onUpdateDataFormatSelection();
};

}}}}//end namespace
