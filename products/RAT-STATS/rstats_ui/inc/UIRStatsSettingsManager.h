/*
    UIRStatsSettingsManager.h
    

*/

#ifndef _OIG_RATSTATS_MAIN_UIRSTATSSETTINGSMANAGER_H
#define _OIG_RATSTATS_MAIN_UIRSTATSSETTINGSMANAGER_H

#include <QDialog>
#include <QMap>

#include "rstats_utils/inc/RStatsSettingsManager.h"

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
    QMap<size_t, QPair<oig::ratstats::utils::SettingPtr,QWidget *> > m_settingsMap;
private slots:
     void onClose();
};

}}}//end namespace

#endif // _OIG_RATSTATS_MAIN_UIRSTATSSETTINGSMANAGER_H
