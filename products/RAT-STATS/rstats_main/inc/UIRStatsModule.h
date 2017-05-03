/*
    UIRStatsModule.h
    

*/
#pragma once
#include <QWidget>
#include <QAccessibleWidget>
#include <QAccessible>

#include "rstats_utils/inc/RStatsModuleProperties.h"

class Ui_UIRStatsModule;
namespace oig {
namespace ratstats {
namespace main {

class UIRStatsModule : public QWidget,public QAccessibleWidget
{
    Q_OBJECT
public:
   /**
    * @brief UIRStatsModule
    * @param parent Pointer to parent widget. Defaults to null.
	*/		
    explicit UIRStatsModule(oig::ratstats::utils::RStatsModuleProperties props,
                            int row,
                            QWidget *parent = 0);

    /**
     * @brief text
     * @param t
     * @return
     */
    virtual QString text(QAccessible::Text t) const;

    virtual QAccessible::Role role(int child) const;
   /**
    * @brief UIRStatsModule
    *
	*/
    ~UIRStatsModule();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsModule *m_ui;
    
     int m_row;
     oig::ratstats::utils::RStatsModuleProperties m_props;
private slots:
     /**
     * @brief onDelete
     */
    void onDelete();

    /**
     * @brief onEdit
     */
    void onEdit();

    /**
     * @brief onLaunch
     */
    void onLaunch();
protected:
    void showEvent(QShowEvent *event);
signals:
     void deleted(const oig::ratstats::utils::RStatsModuleProperties& props, int row);
     void edited(const oig::ratstats::utils::RStatsModuleProperties& props, int row);
     void launched(const oig::ratstats::utils::RStatsModuleProperties& props, int row);

};
}}}//end namespace
