/*
    UIRStatsScriptProviderConfigDialog.h
    

*/

#ifndef _OIG_RATSTATS_MAIN_UIRSTATSSCRIPTPROVIDERCONFIGDIALOG_H
#define _OIG_RATSTATS_MAIN_UIRSTATSSCRIPTPROVIDERCONFIGDIALOG_H
#include <QDialog>

#include "rstats_utils/inc/RStatsScriptProviderProperties.h"

class Ui_UIRStatsScriptProviderConfigDialog;

namespace oig {
namespace ratstats {
namespace ui {


class UIRStatsScriptProviderConfigDialog : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsScriptProviderConfigDialog
	/*!
		Detailed description for UIRStatsScriptProviderConfigDialog
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsScriptProviderConfigDialog(const utils::RStatsScriptProviderProperties & props,
                                                QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsScriptProviderConfigDialog
    ~UIRStatsScriptProviderConfigDialog();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsScriptProviderConfigDialog *m_ui;
     utils::RStatsScriptProviderProperties m_props;

private slots:
     void onInit();
     void onOk();
     void onBrowseProviderIcon();
     void onBrowseProviderPath();
};


}}}//end namespace

#endif // _OIG_RATSTATS_MAIN_UIRSTATSSCRIPTPROVIDERCONFIGDIALOG_H
