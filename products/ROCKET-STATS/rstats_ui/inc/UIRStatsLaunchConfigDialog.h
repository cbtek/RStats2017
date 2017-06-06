/*
    UIRStatsLaunchConfigDialog.h
    

*/

#pragma once

#include <QDialog>

#include "rstats_utils/inc/RStatsModuleProperties.h"

class Ui_UIRStatsLaunchConfigDialog;

namespace cbtek {
namespace rocketstats {
namespace ui {

/**
 * @brief The UIRStatsLaunchConfigDialog class represents the code-behind
 * for editing RStatsModuleProperties.
 */
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

     /**
      * @brief m_isModified Flag holds whether or not this instance of
      * the config dialog has been edited
      */
     bool m_isModified;


private slots:

     /**
      * @brief onInit
      */
     void onInit();

     /**
      * @brief onSave
      */
     void onSave();

     /**
      * @brief onSave
      * @param out
      */
     void onSave(utils::RStatsModuleProperties& out);

     /**
      * @brief onCancel Close this dialog
      */
     void onCancel();

     /**
      * @brief onLaunch Executes/Tests the newly defined module
      */
     void onLaunch();

     /**
      * @brief onBrowseModulePath Locates the module path from disk
      */
     void onBrowseModulePath();

     /**
      * @brief onBrowseModuleWorkingDir Sets the working directory for module property
      */
     void onBrowseModuleWorkingDir();

     /**
      * @brief onBrowseModuleIcon Locates the module icon from disk
      */
     void onBrowseModuleIcon();

signals:
    void propertiesSaved(const utils::RStatsModuleProperties& props);

};
}}}//end namespace
