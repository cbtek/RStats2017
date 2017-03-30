/*
    UIRStatsUAA.h
    

*/

#pragma once

#include <QMainWindow>
#include <QActionGroup>
#include <QAction>
#include <QLabel>

#include "rstats_utils/inc/RStatsUtils.hpp"

class Ui_UIRStatsUAA;

namespace oig {
namespace ratstats {
namespace modules {
namespace uaa {

struct SessionData
{
    SessionData():dateValue(0),timeValue(0),universe(0),samples(0),coi(0){}
    void load(const std::string& url);
    std::string toString() const;
    std::string name;
    oig::ratstats::utils::RStatsInteger dateValue;
    oig::ratstats::utils::RStatsInteger timeValue;
    oig::ratstats::utils::RStatsInteger universe;
    oig::ratstats::utils::RStatsInteger samples;
    oig::ratstats::utils::RStatsInteger coi;
};

class UIRStatsUAA : public QMainWindow
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsUAA
	/*!
		Detailed description for UIRStatsUAA
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsUAA(QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsUAA
    ~UIRStatsUAA();
private:

    QIcon m_exitIcon;
    QIcon m_runIcon;
    QIcon m_helpIcon;
    QActionGroup* m_recentSessionActionGroup;
    QMap<QString,SessionData> m_recentSessionsMap;
    SessionData getSessionData() const;
    void setSessionData(const SessionData& data);
    void updateRecentSessions();

    /**
     * @brief Labels/Strings for output
     */
    QString m_currentTextFileOutput;
    QString m_currentCSVFileOutput;
    QLabel * m_currentTextFileOutputLabel;
    QLabel * m_currentCSVFileOutputLabel;


    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsUAA *m_ui;

private slots:
     void onRecentSessionSelected(QAction* action);
     void onUpdateSampleCount();
     void onUpdateUniverseCount();
     void onClearRecentSessions();
     void onSetTextFileOutput();
     void onSetCSVFileOutput();
     void onHelp();
     void onContinue();
     void onExit();

};

}}}}//end namespace
