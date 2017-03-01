/*
    UIRStatsLaunchProgressDialog.h
    

*/

#ifndef _OIG_RATSTATS_MAIN_UIRSTATSLAUNCHPROGRESSDIALOG_H
#define _OIG_RATSTATS_MAIN_UIRSTATSLAUNCHPROGRESSDIALOG_H

#include <QDialog>
#include <QProcess>

#include "rstats_utils/inc/RStatsModuleProperties.h"

class Ui_UIRStatsLaunchProgressDialog;

namespace oig {
namespace ratstats {
namespace launcher {


class UIRStatsLaunchProgressDialog : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsLaunchProgressDialog
	/*!
		Detailed description for UIRStatsLaunchProgressDialog
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsLaunchProgressDialog(const utils::RStatsModuleProperties& props,
                                          QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsLaunchProgressDialog
    ~UIRStatsLaunchProgressDialog();
private:
    /** 
    * MOC generated ui class for this widget
    */
    Ui_UIRStatsLaunchProgressDialog *m_ui;

    utils::RStatsModuleProperties m_props;
    QProcess m_process;
private slots:
     void onCancel();
    
};

}}}//end namespace

#endif // _OIG_RATSTATS_MAIN_UIRSTATSLAUNCHPROGRESSDIALOG_H
