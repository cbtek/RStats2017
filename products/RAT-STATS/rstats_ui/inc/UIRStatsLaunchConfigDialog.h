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
namespace ui {


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

    /**
     * @brief launch Calls the exec function for this dialog
     * @return Return true if changes were made (OK was pressed)
     *  or false if this dialog was canceled
     */
    bool launch();

private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsLaunchConfigDialog *m_ui;
     utils::RStatsModuleProperties m_props;

     bool m_isModified;


private slots:
     void onInit();
     void onSave();
     void onCancel();
     void onLaunch();
     void onBrowseModulePath();
     void onBrowseModuleWorkingDir();
     void onBrowseModuleIcon();

signals:
    void propertiesSaved(const utils::RStatsModuleProperties& props);

};

}}}//end namespace

#endif // _OIG_RATSTATS_MAIN_UIRSTATSLAUNCHCONFIGDIALOG_H
