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

     void onInitialize();
     void setupButton(QAbstractButton * button,
                      const QFont& font,
                      const QIcon& icon,
                      size_t buttonHeight,
                      bool squareButton = false);

     QMap<int, QGridLayout*> m_groupModuleMap;
     QMap<int, QPair<int,int> > m_groupModuleRowColumnMap;
     QMap<int, QGroupBox*> m_groupBoxMap;
     QMap<int,bool> m_groupEmpty;
     QSet<int> m_groupProtected;
     QMap<int,QIcon> m_groupIcons;
     QVector<QToolButton*> m_allLaunchButtons;
     QButtonGroup m_launchButtons;
     QButtonGroup m_editButtons;
     QButtonGroup m_removeButtons;

protected:
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent *event);

protected slots:
    void onExit();
    void onLaunchModuleManager();
    void onLaunchSettingsManager();
    void onLaunchAbout();
    void onLaunchHelp();
    void onTabChanged(int tab);
    void onLaunchModule(QAbstractButton* button);
    void onEditModule(QAbstractButton* button);
    void onRemoveModule(QAbstractButton* button);
    void onEditCategory();
    void onNewCategory();
    void onRemoveCategory();
};

}}}//end namespace

#endif // _OIG_RATSTATS_MAIN_UIRSTATSMAIN_H
