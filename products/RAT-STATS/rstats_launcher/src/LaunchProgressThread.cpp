/*
    LaunchProgressThread.cpp
    

*/
//----------------------------------------
//LaunchProgressThread.cpp generated by CBTek Solutions on 03-01-2017 at 06:23:47 PM
//----------------------------------------
#include "LaunchProgressThread.h"

namespace oig {
namespace ratstats {
namespace launcher {


LaunchProgressThread::LaunchProgressThread(QString command)
{
    m_command=command;
    connect(&m_process,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
    connect(&m_process,SIGNAL(readyReadStandardError()),this,SLOT(readyReadStandardError()));
    connect(&m_process,SIGNAL(errorOccurred(QProcess::ProcessError)),this,SLOT(onErrorOccured(QProcess::ProcessError)));
}

void LaunchProgressThread::run()
{
    m_process.start(m_command);

}

LaunchProgressThread::~LaunchProgressThread()
{

}

void LaunchProgressThread::readyReadStandardOutput()
{
    emit consoleOutput(m_process.readAllStandardOutput());
}

void LaunchProgressThread::onErrorOccured(QProcess::ProcessError err)
{
    emit consoleOutput("<font style='color:#ffaaaa;'>"+m_process.errorString()+"\nPlease ensure the command is correct.</font>");
}

void LaunchProgressThread::readyReadStandardError()
{
     emit consoleOutput("<font style='color:#ffaaaa;'>"+m_process.readAllStandardError()+"</font>");
}


}}}//end namespace

