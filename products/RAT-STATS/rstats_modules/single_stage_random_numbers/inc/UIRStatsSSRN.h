/*
 UIRStatsSSRN.h
 

*/

#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QActionGroup>
#include <QLabel>

#include "rstats_utils/inc/RStatsConditionLogger.h"
#include "rstats_utils/inc/RStatsUtils.hpp"
#include "rstats_utils/inc/RStatsModuleSessionData.hpp"

#include "RStatsSSRNSessionData.h"

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

    QString m_currentCSVFileOutput;
    QString m_currentTextFileOutput;
    QLabel * m_currentCSVFileOutputLabel;
    QLabel * m_currentTextFileOutputLabel;

    QIcon m_iconError;
    QIcon m_iconWarning;
    QIcon m_iconOK;

    cbtek::common::utility::Random m_rnd;
    QActionGroup * m_recentSessionActionGroup;
    std::map<std::string,utils::RStatsModuleSessionDataPtr> m_recentSessionsMap;    
    bool m_autoSetFileOutput;

    void setCSVFileOutput(const std::string& csvFile);
    void setTextFileOutput(const std::string& textFile);
    RStatsSSRNSessionData getSessionData() const;
    void setSessionData(const RStatsSSRNSessionData& data);
    void updateRecentSessions();
private slots:                    
     void onSeedBoxToggled(bool toggle);
     void onClearRecentSessions();
     void onRecentSessionSelected(QAction* action);
     void onExit();
     void onExecute();
     void onHelp();
     void onValidate();
     void onSaveCSVFile();
     void onSaveTextFile();
     void onUpdateClock();
};

}}}}//end namespace

