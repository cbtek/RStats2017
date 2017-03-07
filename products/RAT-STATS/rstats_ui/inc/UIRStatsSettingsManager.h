/*
    UIRStatsSettingsManager.h
    

*/

#ifndef _OIG_RATSTATS_MAIN_UIRSTATSSETTINGSMANAGER_H
#define _OIG_RATSTATS_MAIN_UIRSTATSSETTINGSMANAGER_H

#include <QDialog>
#include <QMap>
#include <QIcon>
#include <QButtonGroup>

#include "rstats_utils/inc/RStatsSettingsManager.h"
#include "rstats_utils/inc/RStatsUtils.hpp"

class Ui_UIRStatsSettingsManager;

namespace oig {
namespace ratstats {
namespace ui {


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

     std::vector<utils::RStatsScriptProviderProperties>  m_props;
     QButtonGroup * m_editButtons;
     QButtonGroup * m_deleteButtons;
     QIcon m_editIcon,m_addIcon,m_exitIcon,m_removeIcon;
private slots:
     void onClose();
     void onInitScriptProviders();
     void onInitThemes();
     void onInitKeyBindings();
     void onEditScriptProvider(QAbstractButton * button);
     void onDeleteScriptProvider(QAbstractButton * button);
     void onAddScriptProvider();
};

}}}//end namespace

#endif // _OIG_RATSTATS_MAIN_UIRSTATSSETTINGSMANAGER_H
