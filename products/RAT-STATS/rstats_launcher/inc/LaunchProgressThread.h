/*
 LaunchProgressThread.h
 

*/

#pragma once

#include <QThread>
#include <QProcess>

namespace oig {
namespace ratstats {
namespace launcher {


class LaunchProgressThread :public QThread
{
    Q_OBJECT
public:
    //! Constructor for LaunchProgressThread
    /*!
        Detailed description for LaunchProgressThread
    */
    LaunchProgressThread(QString command);
    
    
    void run();
    //! Destructor
    ~LaunchProgressThread();	

private:

    QProcess m_process;
    QString m_command;
private slots:
    void readyReadStandardError();
    void readyReadStandardOutput();
    void onErrorOccured(QProcess::ProcessError err);

signals:
    void consoleOutput(QString text);
    
};
}}}//end namespace


