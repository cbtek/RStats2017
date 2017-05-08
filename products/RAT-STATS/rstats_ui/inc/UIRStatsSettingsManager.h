/*
    UIRStatsSettingsManager.h
    

*/

#pragma once

#include <QDialog>
#include <QMap>
#include <QIcon>
#include <QButtonGroup>
#include <QStyle>

#include "rstats_utils/inc/RStatsUtils.hpp"

class Ui_UIRStatsSettingsManager;

namespace oig {
namespace ratstats {
namespace ui {

/**
 * @brief The UIRStatsSettingsManager class represents the properties
 * in the settings dialog such as theme management and script provider
 * management.
 */
class UIRStatsSettingsManager : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsSettingsManager
	/*!
		Detailed description for UIRStatsSettingsManager
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsSettingsManager(QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsSettingsManager
    ~UIRStatsSettingsManager();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsSettingsManager *m_ui;    

     /**
      * @brief m_props
      */
     std::vector<utils::RStatsScriptProviderProperties>  m_props;

     /**
      * @brief m_editButtons
      */
     QButtonGroup * m_editButtons;

     /**
      * @brief m_deleteButtons
      */
     QButtonGroup * m_deleteButtons;

     /**
      * @brief m_editIcon
      */
     QIcon m_editIcon,m_addIcon,m_exitIcon,m_removeIcon;     

private slots:

     /**
      * @brief onClose
      */
     void onClose();

     /**
      * @brief onInitScriptProviders
      */
     void onInitScriptProviders();

     /**
      * @brief onInitThemes
      */
     void onInitThemes();

     /**
      * @brief onInitKeyBindings
      */
     void onInitKeyBindings();

     /**
      * @brief onEditScriptProvider
      * @param button
      */
     void onEditScriptProvider(QAbstractButton * button);

     /**
      * @brief onDeleteScriptProvider
      * @param button
      */
     void onDeleteScriptProvider(QAbstractButton * button);

     /**
      * @brief onAddScriptProvider
      */
     void onAddScriptProvider();     

     /**
      * @brief onWriteThemeSettings
      */
     void onWriteThemeSettings();
};

}}}//end namespace
