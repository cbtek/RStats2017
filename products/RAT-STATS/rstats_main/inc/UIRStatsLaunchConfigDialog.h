/*
    UIRStatsLaunchConfigDialog.h
    

*/

#ifndef _OIG_RATSTATS_MAIN_UIRSTATSLAUNCHCONFIGDIALOG_H
#define _OIG_RATSTATS_MAIN_UIRSTATSLAUNCHCONFIGDIALOG_H
#include <QDialog>

#include "rstats_utils/inc/RStatsModuleProperties.h"

class Ui_UIRStatsLaunchConfigDialog;

namespace oig {
namespace ratstats {
namespace main {


class UIRStatsLaunchConfigDialog : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsLaunchConfigDialog
	/*!
		Detailed description for UIRStatsLaunchConfigDialog
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsLaunchConfigDialog(const utils::RStatsModuleProperties& props, QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsLaunchConfigDialog
    ~UIRStatsLaunchConfigDialog();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsLaunchConfigDialog *m_ui;
     utils::RStatsModuleProperties m_props;


private slots:
     void onInit();
     void onSave();
     void onCancel();
     void onLaunch();

signals:
    void propertiesSaved(const utils::RStatsModuleProperties& props);

};

}}}//end namespace

#endif // _OIG_RATSTATS_MAIN_UIRSTATSLAUNCHCONFIGDIALOG_H
