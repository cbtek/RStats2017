/*
    UIRStatsSVA.h
    

*/

#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QComboBox>
#include <QKeyEvent>
#include <QLabel>

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

     /**
      * @brief Icons for varios buttons/menus
      */
     QIcon m_iconFolder;
     QIcon m_iconSave;
     QIcon m_iconHelp;
     QIcon m_iconExit;
     QIcon m_iconRun;
     QIcon m_iconAdd;
     QIcon m_iconError;
     QIcon m_iconWarning;
     QIcon m_iconOK;

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
