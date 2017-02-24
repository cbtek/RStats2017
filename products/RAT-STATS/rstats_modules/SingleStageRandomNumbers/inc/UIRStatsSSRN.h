/*
 UIRStatsSSRN.h
 

*/

#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QActionGroup>

#include "rstats_utils/inc/RStatsConditionLogger.h"

class Ui_UIRStatsSSRN;

namespace oig {
namespace ratstats {
namespace modules {
namespace ssrn {


class UIRStatsSSRN : public QMainWindow
{
    Q_OBJECT

public:
    //! Constructor for UIRStatsSSRN
    /*!
        Detailed description for UIRStatsSSRN
        @param      parent points to embedding super widget. Defaults to null.
    */
    explicit UIRStatsSSRN(QWidget *parent = 0);


    //! Destructor for UIRStatsSSRN
    ~UIRStatsSSRN();
private:
    /**
    * MOC generated ui class for this widget
    */
    Ui_UIRStatsSSRN *m_ui;
    oig::ratstats::utils::RStatsConditionLogger m_logger;

    QString m_currentAccessExcelFileOutput;
    QString m_currentTextFileOutput;
    QTimer m_clock;
    QIcon m_iconEdit,  m_iconHelp,  m_iconModule,m_iconRun,
          m_iconFolder,m_iconRemove,m_iconExit,  m_iconSettings,
          m_iconObject,m_iconAbout, m_iconAdd,   m_iconWarning,
          m_iconError, m_iconOK;

    QActionGroup * m_recentSessionActionGroup;
private slots:

     void onSaveSession();
     void onSaveRecentSession();
     void onSaveSession(const std::string& sessionUrl);
     void onLoadSessions();
     void onLoadSession(const std::string& sessionUrl);
     void onClearRecentSessions();
     void onRecentSessionSelected(QAction* action);
     void onExit();
     void onGenerate();
     void onHelp();
     void onValidateForm();
     void onSaveAccessExcelFile();
     void onSaveTextFile();
     void onUpdateClock();
};

}}}}//end namespace

