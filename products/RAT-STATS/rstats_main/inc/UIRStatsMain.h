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

#include "rstats_ui/inc/UIRStatsShortcut.h"
#include "rstats_utils/inc/RStatsModuleProperties.h"

class Ui_UIRStatsMain;

namespace oig {
namespace ratstats {
namespace main {

enum class RStatsMainVisualZoom
{
    Normal,
    Larger,
    Largest
};

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

     void onInitialize(int defaultCategoryIndex = 0);    
     QVector<QToolButton*> m_allLaunchButtons;
     QMap<size_t, QTableWidget*> m_tableMap;
     QMap<size_t, QButtonGroup*> m_launchButtonMap;
     QMap<size_t, QButtonGroup*> m_editButtonMap;
     QMap<size_t, QButtonGroup*> m_removeButtonMap;
//     QMap<int, QVector<QAbstractButton*>> m_currentLaunchButtonMap;
//     QMap<int, QVector<QAbstractButton*>> m_currentEditButtonMap;
//     QMap<int, QVector<QAbstractButton*>> m_currentRemoveButtonMap;

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
     QString getKeyAssignment(int count) const;
     QKeySequence getKeyLaunchSequence(int count, QString & keyString) const;
     QKeySequence getKeyEditSequence(int count, QString & keyString) const;
     QKeySequence getKeyRemoveSequence(int count, QString & keyString) const;

     QFont m_font;
     int m_buttonHeight;
     bool m_tableHasFocus;
     QTableWidget * m_currentTable;



protected:
    void showEvent(QShowEvent *);
    void resizeEvent(QResizeEvent *event);
    void editModule(const QString &propsPath);
    void removeModule(const QString &propsPath);
    void launchModule(const QString &propsPath);
    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent * event);
    void setVisualZoom(RStatsMainVisualZoom zoom);
protected slots:
    void onExit();    
    void onLaunchSettingsManager();
    void onLaunchAbout();
    void onLaunchHelp();
    void onTabChanged(int tab);
    void onAddNewModule();
    void onLaunchModuleShortcut(QShortcut* button);
    void onEditModuleShortcut(QShortcut* button);
    void onRemoveModuleShortcut(QShortcut* button);
    void onLaunchModule(QAbstractButton* button);
    void onEditModule(QAbstractButton* button);
    void onRemoveModule(QAbstractButton* button);    
};

}}}//end namespace
