/*
    UIRStatsMain.h
    

*/

#ifndef _OIG_RATSTATS_MAIN_UIRSTATSMAIN_H
#define _OIG_RATSTATS_MAIN_UIRSTATSMAIN_H

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

#include "rstats_ui/inc/UIRStatsShortcut.h"
#include "rstats_utils/inc/RStatsModuleProperties.h"

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

     void onInitialize(int defaultCategoryIndex = 0);
     void setupButton(QAbstractButton * button,
                      const QFont& font,
                      const QIcon& icon,
                      size_t buttonHeight,
                      bool squareButton = false);    
     QVector<QToolButton*> m_allLaunchButtons;
     QMap<int, QTableWidget *> m_tableMap;
     QButtonGroup * m_launchButtons;
     QButtonGroup * m_editButtons;
     QButtonGroup * m_removeButtons;
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
     int m_buttonHeight;

protected:
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent *event);
    void editModule(const QString &propsPath);
    void removeModule(const QString &propsPath);
    void launchModule(const QString &propsPath);
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

#endif // _OIG_RATSTATS_MAIN_UIRSTATSMAIN_H
