/*
    UIRStatsUVA.h
*/

#pragma once

#include <QMainWindow>
#include <QActionGroup>
#include <QLabel>
#include <QComboBox>
#include <QTimer>

#include "rstats_utils/inc/RStatsWorkbook.h"
#include "rstats_utils/inc/RStatsConditionLogger.h"

#include "rstats_ui/inc/UIRStatsWorkbook.h"

#include "RStatsUVASessionData.h"

class Ui_UIRStatsUVA;

namespace oig {
namespace ratstats {
namespace modules {
namespace uva {


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
    void resizeEvent(QResizeEvent * e);
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsUVA *m_ui;

     /**
      * @brief Validation Console Icons
      */
     QIcon m_iconError;
     QIcon m_iconOK;
    QIcon m_iconWarning;

    QTimer m_clock;

     QActionGroup* m_recentSessionActionGroup;
     std::map<std::string,utils::RStatsModuleSessionDataPtr> m_recentSessionsMap;

    /**
    * @brief PushButtons/Strings for output
    */
    QString m_currentTextFileOutput;
    QString m_currentCSVFileOutput;
    QString m_dataTableImportFilePath;

    QLabel * m_currentTextFileOutputPushButton;
    QLabel * m_currentCSVFileOutputPushButton;

    bool m_autoSetFileOutput;

    /**
    * @brief Current data sheets/workbooks
    */
    oig::ratstats::utils::RStatsWorksheet m_currentDataSheet;
    oig::ratstats::utils::RStatsWorkbook m_currentDataWorkbook;

    /**
    * @brief Used by validation console
    */
    oig::ratstats::utils::RStatsConditionLogger m_conditionLogger;
    bool m_fullScreenToggle;
    utils::RStatsDataFormatType m_dataFormatType;

    void importDataTable(const std::string& dataTableFilePath);
    void importSizeTable(const std::string& sizeTableFilePath);
    void populateWithColumns(const std::set<size_t>& columns, QComboBox* comboBox);
    void populateWithRows(const std::set<size_t>& rows, QComboBox* comboBox);
    void setTextFileOutput(const std::string& textFile);
    void setCSVFileOutput(const std::string& csvFile);
    RStatsUVASessionData getSessionData() const;
    void setSessionData(const RStatsUVASessionData& data);
    void updateRecentSessions();

    oig::ratstats::utils::RStatsDataFormatType m_currentDataFormat;

 private slots:
      void onImportDataInput();
      void onRecentSessionSelected(QAction* action);
      void onComboDataInputSheetSelected(int row);
      void onSampleDataInputSheetSelected(const oig::ratstats::utils::RStatsWorksheet& sheet);
      void onUpdateRowColumnExtentsForDataTable();
      void onUpdateDataFormatSelection();
      void onClearRecentSessions();
      void onAddNewRowToDataTable();
      void onAddNewColumnToDataTable();
      void onSaveTextFile();
      void onSaveCSVFile();
      void onHelp();
      void onAbout();
      void onExecute();
      void onExit();
      bool onValidate();
      void onUpdateClock();
      void onLaunchCSVOutputProgram();
      void onLaunchTextOutputProgram();
};

}}}}//end namespace


