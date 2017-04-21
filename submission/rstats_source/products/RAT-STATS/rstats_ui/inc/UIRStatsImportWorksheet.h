/*
    UIRStatsImportWorksheet.h
    

*/

#ifndef _OIG_RATSTATS_UI_UIRSTATSIMPORTWORKSHEET_H
#define _OIG_RATSTATS_UI_UIRSTATSIMPORTWORKSHEET_H
#include <QDialog>

#include "rstats_utils/inc/RStatsWorkbook.h"

#include "rstats_ui/inc/UIRStatsWorkbook.h"

class Ui_UIRStatsImportWorksheet;

namespace oig {
namespace ratstats {
namespace ui {


class UIRStatsImportWorksheet : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsImportWorksheet
	/*!
		Detailed description for UIRStatsImportWorksheet
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsImportWorksheet(const oig::ratstats::utils::RStatsWorkbook& workbook,
                                     QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsImportWorksheet
    ~UIRStatsImportWorksheet();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsImportWorksheet *m_ui;

     /**
      * @brief m_currentSheet Hold the current worksheet being viewed in the UI
      */
     oig::ratstats::utils::RStatsWorksheet m_currentSheet;

     /**
      * @brief m_workbookWidget The current workbook widget
      */
     oig::ratstats::ui::UIRStatsWorkbook* m_workbookWidget;

private slots:
     void onOk();
     void onCancel();
     void onSheetSelected(const oig::ratstats::utils::RStatsWorksheet& sheet);
signals:
     void sheetSelected(const oig::ratstats::utils::RStatsWorksheet& sheetSelected);

};

}}}//end namespace

#endif // _OIG_RATSTATS_UI_UIRSTATSIMPORTWORKSHEET_H
