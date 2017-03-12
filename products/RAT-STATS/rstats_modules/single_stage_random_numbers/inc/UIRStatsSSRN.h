/*
 UIRStatsSSRN.h
 

*/

#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QActionGroup>

#include "rstats_utils/inc/RStatsConditionLogger.h"
#include "rstats_utils/inc/RStatsUtils.hpp"

class Ui_UIRStatsSSRN;

namespace oig {
namespace ratstats {
namespace modules {
namespace ssrn {


struct SessionData
{
    SessionData():dateValue(0),timeValue(0),order(0),spares(0),low(0),high(0),seed(0.){}
    void load(const std::string& url);
    std::string toString() const;
    std::string name;
    std::uint64_t dateValue;
    std::uint64_t timeValue;
    oig::ratstats::utils::RStatsInteger order;
    oig::ratstats::utils::RStatsInteger spares;
    oig::ratstats::utils::RStatsInteger low;
    oig::ratstats::utils::RStatsInteger high;
    oig::ratstats::utils::RStatsFloat seed;
};

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
    QMap<QString,SessionData> m_recentSessionsMap;


    SessionData getSessionData() const;
    void setSessionData(const SessionData& data);
    void updateRecentSessions();
private slots:                    
        void onSeedBoxToggled(bool toggle);
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

