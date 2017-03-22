/*
    UIRStatsSVA.h
    

*/

#pragma once

#include <QMainWindow>
#include <QTimer>

#include "rstats_utils/inc/RStatsWorkbook.h"

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
     QTimer m_clock;

     oig::ratstats::utils::RStatsWorksheet m_currentInputSheet;
     oig::ratstats::utils::RStatsWorksheet m_currentSizeSheet;
protected slots:     
     void onUpdateClock();
     void onContinue();
     void onExit();     
     void onSampleSizeSheetSelected(const oig::ratstats::utils::RStatsWorksheet& sheet);
     void onSampleInputSheetSelected(const oig::ratstats::utils::RStatsWorksheet& sheet);
     void onImportSampleInputData();
     void onImportSampleSizeData();
     void onHelp();
     void onSetOutputFolder();
     void onSetPrinterOptions();
     void onSetStratum(int count);
};

}}}}//end namespace
