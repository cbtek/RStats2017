/*
    UIRStatsWorkbook.h
    

*/

#ifndef _OIG_RATSTATS_UI_UIRSTATSWORKBOOK_H
#define _OIG_RATSTATS_UI_UIRSTATSWORKBOOK_H
#include <QWidget>

#include "rstats_utils/inc/RStatsWorkbook.h"



class Ui_UIRStatsWorkbook;

namespace oig {
namespace ratstats {
namespace ui {


class UIRStatsWorkbook : public QWidget
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsWorkbook
	/*!
		Detailed description for UIRStatsWorkbook
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsWorkbook(QWidget *parent = 0);

    explicit UIRStatsWorkbook(const utils::RStatsWorkbook& workbook, QWidget *parent = 0);
    
    void setWorkbook(const utils::RStatsWorkbook& workbook);
    
    //! Destructor for UIRStatsWorkbook
    ~UIRStatsWorkbook();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsWorkbook *m_ui;

     oig::ratstats::utils::RStatsWorkbook m_workbook;

private slots:
     void onPopulateTable(const oig::ratstats::utils::RStatsWorksheet& sheet);
     void onSheetSelected(int index);
     void onResizeToContents();
};

}}}//end namespace

#endif // _OIG_RATSTATS_UI_UIRSTATSWORKBOOK_H
