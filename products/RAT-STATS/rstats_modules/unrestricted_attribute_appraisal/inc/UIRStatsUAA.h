/*
    UIRStatsUAA.h
    

*/

#pragma once

#include <QMainWindow>
#include <QActionGroup>
#include <QAction>
#include <QLabel>

#include "rstats_utils/inc/RStatsUtils.hpp"

#include "RStatsUAASessionData.h"

class Ui_UIRStatsUAA;

namespace oig {
namespace ratstats {
namespace modules {
namespace uaa {

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

protected:
    void resizeEvent(QResizeEvent*);
private:

    QIcon m_exitIcon;
    QIcon m_runIcon;
    QIcon m_helpIcon;
    QActionGroup* m_recentSessionActionGroup;
    std::map<std::string,utils::RStatsModuleSessionDataPtr> m_recentSessionsMap;
    RStatsUAASessionData getSessionData() const;
    void setSessionData(const RStatsUAASessionData& data);
    void updateRecentSessions();

    /**
     * @brief Labels/Strings for output
     */
    QString m_currentTextFileOutput;
    QString m_currentCSVFileOutput;
    QLabel * m_currentTextFileOutputLabel;
    QLabel * m_currentCSVFileOutputLabel;
    bool m_autoSetFileOutput;

    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsUAA *m_ui;

     void setTextFileOutput(const std::string& textFile);
     void setCSVFileOutput(const std::string& csvFile);
private slots:
     void onRecentSessionSelected(QAction* action);
     void onUpdateSampleCount();
     void onUpdateUniverseCount();
     void onClearRecentSessions();
     void onSaveTextFile();
     void onSaveCSVFile();
     void onHelp();
     void onExecute();
     void onExit();
     void onAbout();

};

}}}}//end namespace
