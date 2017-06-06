/*
    UIRStatsScriptProviderConfigDialog.h
    

*/

#pragma once
#include <QDialog>

#include "rstats_utils/inc/RStatsScriptProviderProperties.h"

class Ui_UIRStatsScriptProviderConfigDialog;

namespace cbtek {
namespace rocketstats {
namespace ui {

/**
 * @brief The UIRStatsScriptProviderConfigDialog class provides code-behind
 * for editing RStatsScriptProviderProperties
 */
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

     /**
      * @brief m_props
      */
     utils::RStatsScriptProviderProperties m_props;

private slots:

     /**
      * @brief onInit
      */
     void onInit();

     /**
      * @brief onOk
      */
     void onOk();

     /**
      * @brief onBrowseProviderIcon
      */
     void onBrowseProviderIcon();

     /**
      * @brief onBrowseProviderPath
      */
     void onBrowseProviderPath();
};
}}}//end namespace
