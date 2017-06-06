/*
    UIRStatsWorkbook.h
    

*/

#pragma once

#include <QWidget>
#include <QTableWidget>

#include "rstats_utils/inc/RStatsWorkbook.h"
#include "UIRStatsTablePreviewWidget.h"


class Ui_UIRStatsWorkbook;

namespace cbtek {
namespace rocketstats {
namespace ui {

/**
 * @brief The UIRStatsWorkbook class is used by the SVA class to provide
 * support for displaying multiple worksheets in the output results
 */
class UIRStatsWorkbook : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief UIRStatsWorkbook (Constructor)
     * @param parent
     */
    explicit UIRStatsWorkbook(QWidget *parent = 0);

    /**
     * @brief UIRStatsWorkbook (Constructor)
     * @param workbook The workbook to populate the ui with
     * @param parent
     */
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
     cbtek::rocketstats::utils::RStatsWorksheet m_currentSheet;
     cbtek::rocketstats::utils::RStatsWorkbook m_workbook;
};

}}}//end namespace
