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
#include <QTimer>
#include <QTableWidget>
#include <QKeySequence>
#include <QPaintEvent>
#include <QListWidget>
#include <QTreeWidgetItem>
#include <QActionGroup>

#include "rstats_ui/inc/UIRStatsTablePreviewWidget.h"
#include "rstats_ui/inc/UIRStatsShortcut.h"
#include "rstats_utils/inc/RStatsModuleProperties.h"
#include <QAccessibleWidget>

class Ui_UIRStatsMain;

namespace cbtek {
namespace rocketstats {
namespace main {

/**
 * @brief The UIRStatsMain class contains the code-behind for the
 * ROCKET-STATS main menu window.
 */
class UIRStatsMain : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief UIRStatsMain (constructor)
     * @param parent
     */
    explicit UIRStatsMain(QWidget *parent = 0);

    /**
     * @brief UIRStatsMain (destructor)
     */
    ~UIRStatsMain();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsMain *m_ui;
     std::map<std::string, std::vector<cbtek::rocketstats::utils::RStatsModuleProperties> > m_groupedModules;

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
     /**
      * @brief m_lastTableRow Stores last selected table row
      */
     std::map<int, int> m_lastTableRowMap;

     /**
      * @brief m_shortcuts
      */
     std::vector<ui::UIRStatsShortcut*> m_shortcuts;

     //Font used by UI
     QFont m_font;

     //Default height of buttons on UI
     int m_buttonHeight;

     //Determines if table has user (keyboard) focus
     bool m_tableHasFocus;

     //GUI Table to hold all modules
     ui::UIRStatsTablePreviewWidget * m_tblModules;

     /**
      * @brief onInitialize
      * @param defaultCategoryIndex
      */
     void onInitialize(int defaultCategoryIndex = 0);

     /**
      * @brief getKeyAssignment
      * @param count
      * @param isLaunch
      * @param isEdit
      * @param isRemove
      * @return
      */
     QString getKeyAssignment(int count, bool isLaunch=true, bool isEdit=false, bool isRemove=false) const;

     /**
      * @brief getKeyLaunchSequence
      * @param count
      * @param keyString
      * @return
      */
     QKeySequence getKeyLaunchSequence(int count, QString & keyString) const;

     /**
      * @brief getKeyEditSequence
      * @param count
      * @param keyString
      * @return
      */
     QKeySequence getKeyEditSequence(int count, QString & keyString) const;

     /**
      * @brief getKeyRemoveSequence
      * @param count
      * @param keyString
      * @return
      */
     QKeySequence getKeyRemoveSequence(int count, QString & keyString) const;   

protected:     
    /**
     * @brief keyPressEvent
     * @param event
     */
    void keyPressEvent(QKeyEvent * event);

    /**
     * @brief editModule This is called when module properties
     * need to be edited
     * @param propsPath The path to the module properties config
     * @param row The row of the module to edit
     */
    void editModule(const QString &propsPath, int row);

    /**
     * @brief removeModule This is called when module properties
     * need to be removed
     * @param propsPath The path to the module properties config
     * @param row The row of the module to remove
     */
    void removeModule(const QString &propsPath, int row);

    /**
     * @brief launchModule This is called when module is
     * to be launched
     * @param propsPath The path to the module properties config
     */
    void launchModule(const QString &propsPath);    

protected slots:

    /**
     * @brief onExit
     */
    void onExit();    

    /**
     * @brief onLaunchSettingsManager
     */
    void onLaunchSettingsManager();

    /**
     * @brief onLaunchAbout
     */
    void onLaunchAbout();

    /**
     * @brief onLaunchHelp
     */
    void onLaunchHelp();

    /**
     * @brief launchModule This is called when module is
     * to be launched
     * @param propsPath The path to the module properties config
     * @param row The row of the module to be launched
     */
    void onLaunchModule(const utils::RStatsModuleProperties &props, int row);

    /**
     * @brief onLaunchModuleShortcut
     * @param button
     */
    void onLaunchModuleShortcut(QShortcut* button);

    /**
     * @brief onUpdateTableHeader
     * @param isModuleListSelected
     */
    void onUpdateTableHeader(bool isModuleListSelected);    

    /**
     * @brief onAddNewModule
     */
    void onAddNewModule();        

    /**
     * @brief onRemoveModuleShortcut
     * @param button
     */
    void onRemoveModuleShortcut(QShortcut* button);

    /**
     * @brief removeModule This is called when module properties
     * need to be removed
     * @param props The module properties
     * @param row The row of the module to remove
     */
    void onRemoveModule(const utils::RStatsModuleProperties& props, int row);

    /**
     * @brief onEditModuleShortcut
     * @param button
     */
    void onEditModuleShortcut(QShortcut* button);

    /**
     * @brief editModule This is called when module properties
     * need to be edited
     * @param props The module properties
     * @param row The row of the module to edit
     */
    void onEditModule(const utils::RStatsModuleProperties& props, int row);

    /**
     * @brief onCategoryChanged
     * @param row
     */
    void onCategoryChanged(int row);

    /**
     * @brief onRepopulateModules
     * @param propsIn
     */
    void onRepopulateModules(const std::vector<utils::RStatsModuleProperties> &propsIn);

    /**
     * @brief onModuleCellActivated
     * @param item
     */
    void onModuleCellActivated(QTableWidgetItem*item);
};

}}}//end namespace

