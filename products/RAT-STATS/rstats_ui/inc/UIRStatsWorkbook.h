/*
    UIRStatsWorkbook.h
    

*/

#pragma once

#include <QWidget>
#include <QTableWidget>

#include "rstats_utils/inc/RStatsWorkbook.h"
#include "UIRStatsTablePreviewWidget.h"


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
    
    /**
     * @brief setWorkbook
     * @param workbook
     */
    void setWorkbook(const utils::RStatsWorkbook& workbook);        

    /**
     * @brief clear
     */
    void clear();

    //! Destructor for UIRStatsWorkbook
    ~UIRStatsWorkbook();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsWorkbook *m_ui;
     oig::ratstats::utils::RStatsWorksheet m_currentSheet;
     oig::ratstats::utils::RStatsWorkbook m_workbook;
};

}}}//end namespace
