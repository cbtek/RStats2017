/*
    UIRStatsMain.h
*/

#pragma once

#include <QMainWindow>
#include <QShortcut>
#include <QGridLayout>
#include <QGroupBox>
#include <QMap>
#include <QToolButton>
#include <QButtonGroup>
#include <QSet>
#include <QTableWidget>
#include <QKeySequence>
#include <QPaintEvent>
#include <QListWidget>
#include <QTreeWidgetItem>

#include "rstats_ui/inc/UIRStatsShortcut.h"
#include "rstats_utils/inc/RStatsModuleProperties.h"
#include <QAccessibleWidget>

class Ui_UIRStatsMain;

namespace oig {
namespace ratstats {
namespace main {

class UIRStatsMain : public QMainWindow
{
    Q_OBJECT

public:

    //! Constructor for UIRStatsMain
	/*!
		Detailed description for UIRStatsMain
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsMain(QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsMain
    ~UIRStatsMain();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsMain *m_ui;

     //Private data memebers
     QVector<QToolButton*> m_allLaunchButtons;
     QMap<size_t, QListWidget*> m_tableMap;
     QMap<size_t, QButtonGroup*> m_launchButtonMap;
     QMap<size_t, QButtonGroup*> m_editButtonMap;
     QMap<size_t, QButtonGroup*> m_removeButtonMap;

     //Icons for the UI
     QIcon m_iconEdit;
     QIcon m_iconHelp;
     QIcon m_iconModule;
     QIcon m_iconFolder;
     QIcon m_iconRemove;
     QIcon m_iconExit;
     QIcon m_iconSettings;
     QIcon m_iconObject;
     QIcon m_iconAbout;
     QIcon m_iconAdd;
     QIcon m_iconOk;
     QIcon m_iconRun;
     QIcon m_iconError;

     //Font used by UI
     QFont m_font;

     //Default height of buttons on UI
     int m_buttonHeight;

     //Determines if table has user (keyboard) focus
     bool m_tableHasFocus;

     //GUI Table to hold all modules
     QListWidget * m_currentTable;

     //Functions used internally
     void onInitialize(int defaultCategoryIndex = 0);
     QString getKeyAssignment(int count, bool isLaunch=true, bool isEdit=false, bool isRemove=false) const;
     QKeySequence getKeyLaunchSequence(int count, QString & keyString) const;
     QKeySequence getKeyEditSequence(int count, QString & keyString) const;
     QKeySequence getKeyRemoveSequence(int count, QString & keyString) const;

     void clearButtonMaps();
protected:     
     //Qt Events
    void showEvent(QShowEvent *);
    void resizeEvent(QResizeEvent *event);    
    void keyPressEvent(QKeyEvent * event);

    //Functions to modify property module state
    void editModule(const QString &propsPath);
    void removeModule(const QString &propsPath);
    void launchModule(const QString &propsPath);    

protected slots:
    void onExit();    

    //SLots for launching other windows    
    void onLaunchSettingsManager();
    void onLaunchAbout();
    void onLaunchHelp();
    void onLaunchModule(QAbstractButton* button);
    void onLaunchModuleShortcut(QShortcut* button);
    void onUpdateTableHeader(bool isModuleListSelected);    
    void onAddNewModule();        
    void onRemoveModuleShortcut(QShortcut* button);
    void onRemoveModule(QAbstractButton* button);
    void onEditModuleShortcut(QShortcut* button);
    void onEditModule(QAbstractButton* button);    
    void onItemChanged(QListWidgetItem* item);
    void onRepopulateModules(const std::vector<utils::RStatsModuleProperties> &propsIn);
};

}}}//end namespace

