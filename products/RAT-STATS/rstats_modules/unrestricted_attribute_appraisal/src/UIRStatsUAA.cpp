/*
    UIRStatsUAA.cpp
    

*/
//UIRStatsUAA.cpp generated by snow on 02-05-2017 at 08:52:17 PM

#include "UIRStatsUAA.h"
#include "ui_UIRStatsUAA.h"

#include "RStatsUAA.h"

#include <QFileDialog>
#include <QMessageBox>

#include "rstats_ui/inc/UIRStatsUtils.hpp"
#include "rstats_ui/inc/UIRStatsImportWorksheet.h"
#include "rstats_ui/inc/UIRStatsErrorMessage.h"

#include "utility/inc/TimeUtils.hpp"
#include "utility/inc/DateUtils.hpp"
#include "utility/inc/XMLUtils.h"

using namespace cbtek::common::utility;
using namespace oig::ratstats::ui;
using namespace oig::ratstats::utils;

namespace oig {
namespace ratstats {
namespace modules {
namespace uaa {

UIRStatsUAA::UIRStatsUAA(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui_UIRStatsUAA)
{
    m_ui->setupUi(this);
    m_ui->m_dockOptions->setTitleBarWidget(new QWidget());

    connect(m_ui->m_btnExecute,SIGNAL(clicked()),this,SLOT(onExecute()));
    connect(m_ui->m_btnExit,SIGNAL(clicked()),this,SLOT(onExit()));
    connect(m_ui->m_btnHelp,SIGNAL(clicked()),this,SLOT(onHelp()));
    connect(m_ui->m_spnSampleSize,SIGNAL(valueChanged(int)),this,SLOT(onUpdateSampleCount()));
    connect(m_ui->m_spnUniverseSize,SIGNAL(valueChanged(int)),this,SLOT(onUpdateUniverseCount()));
    connect(m_ui->m_chkCSVOutput,SIGNAL(toggled(bool)),this,SLOT(onSaveCSVFile()));
    connect(m_ui->m_chkTextOutput,SIGNAL(toggled(bool)),this,SLOT(onSaveTextFile()));

    m_currentCSVFileOutputLabel = nullptr;
    m_currentTextFileOutputLabel = nullptr;
    m_autoSetFileOutput = false;
    m_ui->m_txtAuditName->setPlaceholderText(QString::fromStdString(RStatsUtils::getAuditName()));
    m_ui->m_frmOutput->hide();
    onUpdateUniverseCount();
    onUpdateSampleCount();
    updateRecentSessions();

    int buttonHeight = 32;
    UIRStatsUtils::customUISetup(m_ui->m_btnExecute,
                                 m_ui->m_btnExit,
                                 m_ui->m_btnHelp,
                                 nullptr,
                                 nullptr,
                                 nullptr,
                                 nullptr,
                                 nullptr,
                                 nullptr,
                                 nullptr,
                                 nullptr,
                                 m_ui->actionExit,
                                 m_ui->actionHelp_Topics,
                                 m_ui->actionAbout,
                                 m_ui->actionRecentlyUsed,
                                 buttonHeight,
                                 this->font());

}

UIRStatsUAA::~UIRStatsUAA()
{
    delete m_ui;
}

void UIRStatsUAA::onUpdateSampleCount()
{
    m_ui->m_spnCOI->setMaximum(m_ui->m_spnSampleSize->value());
}

void UIRStatsUAA::onUpdateUniverseCount()
{
    m_ui->m_spnSampleSize->setMaximum(m_ui->m_spnUniverseSize->value());
}

void UIRStatsUAA::onHelp()
{

}

void UIRStatsUAA::onExecute()
{
    try
    {
        RStatsInteger sampleSize = m_ui->m_spnSampleSize->value();
        RStatsInteger universeSize = m_ui->m_spnUniverseSize->value();
        RStatsInteger coiSize = m_ui->m_spnCOI->value();

        std::string name = m_ui->m_txtAuditName->text().toStdString();
        if (StringUtils::trimmed(name).empty())
        {
            name = m_ui->m_txtAuditName->placeholderText().toStdString();
        }

        RStatsUAAConfidenceIntervalType type = RStatsUAAConfidenceIntervalType::TwoSided;
        if (coiSize == 0 || coiSize == sampleSize)
        {
            int answer = QMessageBox::question(this,"One or Two sided confidence?","Would you like to compute a one-sided confidence interval?");
            if (answer == QMessageBox::Yes)
            {
                type = (coiSize == 0) ? RStatsUAAConfidenceIntervalType::OneSidedUpper : RStatsUAAConfidenceIntervalType::OneSidedLower;
            }
        }
        RStatsUAA::inst().execute(name,sampleSize,universeSize,coiSize,type);
        RStatsWorksheet output;
        RStatsUAA::inst().saveToWorksheet(output);
        UIRStatsUtils::bindSheetToUI(output,m_ui->m_tblOutput,false,0,1);

        //Save CSV file (for Excel/Access) if applicable
        if (m_ui->m_chkCSVOutput->isChecked())
        {
            FileUtils::writeFileContents(m_currentCSVFileOutput.toStdString(),
                                         output.toCommaDelimitedString());
        }

        //Save Text file, if applicable
        if (m_ui->m_chkTextOutput->isChecked())
        {
            FileUtils::writeFileContents(m_currentTextFileOutput.toStdString(),
                                         output.toEvenlySpacedString());
        }


        m_ui->m_lblDate->setText(QString::fromStdString(DateUtils::toCurrentShortDateString()));
        m_ui->m_lblTime->setText(QString::fromStdString(TimeUtils::toCurrent12HourTimeString()));
        m_ui->m_lblAudit->setText(QString::fromStdString(name));
        m_ui->m_tblOutput->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        m_ui->m_tblOutput->horizontalHeader()->hide();
        m_ui->m_frmOutput->show();
        m_ui->m_lblNoData->hide();
        m_ui->m_tblOutput->setSelectionMode(QAbstractItemView::NoSelection);
        m_ui->m_tblOutput->setGridStyle(Qt::NoPen);


        //Save the session data
        RStatsUAASessionData sessionData = getSessionData();
        sessionData.setCreationDate(DateUtils::getCurrentDate());
        sessionData.setCreationTime(TimeUtils::getCurrentTime());
        m_recentSessionsMap[sessionData.getAuditName()] = RStatsModuleSessionDataPtr(new RStatsUAASessionData(sessionData));
        RStatsUtils::saveRecentSession(m_recentSessionsMap[sessionData.getAuditName()]);
        updateRecentSessions();
    }
    catch (std::exception& e)
    {
        UIRStatsErrorMessage("Error occured while executing \""+this->windowTitle().toStdString()+"\"",
                             std::string(e.what()),false,this).exec();
        return;
    }
}

void UIRStatsUAA::onExit()
{
    this->close();
}

RStatsUAASessionData UIRStatsUAA::getSessionData() const
{
    QString text = m_ui->m_txtAuditName->text();
    if (text.isEmpty())
    {
        text = m_ui->m_txtAuditName->placeholderText();
    }
    RStatsUAASessionData data;
    data.setAuditName(text.toStdString());
    data.setSampleSize(m_ui->m_spnSampleSize->value());
    data.setCoiSize(m_ui->m_spnCOI->value());
    data.setUniverseSize(m_ui->m_spnUniverseSize->value());
    data.setCSVOutputFile(m_currentCSVFileOutput.toStdString());
    data.setTextOutputFile(m_currentTextFileOutput.toStdString());
    return data;
}

void UIRStatsUAA::setSessionData(const RStatsUAASessionData &data)
{
    m_ui->m_txtAuditName->setText(QString::fromStdString(data.getAuditName()));
    m_ui->m_spnSampleSize->setValue(static_cast<int>(data.getSampleSize()));
    m_ui->m_spnCOI->setValue(static_cast<int>(data.getCoiSize()));
    m_ui->m_spnUniverseSize->setValue(static_cast<int>(data.getUniverseSize()));

    m_autoSetFileOutput = true;
    if (!data.getCSVOutputFile().empty())
    {        
        m_ui->m_chkCSVOutput->setChecked(true);
        setCSVFileOutput(data.getTextOutputFile());
        m_ui->m_chkCSVOutput->setToolTip(QString::fromStdString(data.getCSVOutputFile()));
    }
    if (!data.getTextOutputFile().empty())
    {
        m_ui->m_chkTextOutput->setChecked(true);
        setTextFileOutput(data.getTextOutputFile());
        m_ui->m_chkTextOutput->setToolTip(QString::fromStdString(data.getTextOutputFile()));     
    }
    m_autoSetFileOutput = false;
}

void UIRStatsUAA::onClearRecentSessions()
{
    RStatsUtils::clearRecentSessions(c_RECENT_SESSION_EXTENSION);
    updateRecentSessions();
}

void UIRStatsUAA::onSaveTextFile()
{
    if (m_autoSetFileOutput) return;
    if (m_ui->m_chkTextOutput->isChecked())
    {
        m_currentTextFileOutput = UIRStatsUtils::setOutputFile(
                                                               m_ui->m_chkTextOutput,
                                                               "Save to Text file...",
                                                               "*.txt");
        setTextFileOutput(m_currentTextFileOutput.toStdString());
    }
    else m_ui->m_statusBar->removeWidget(m_currentTextFileOutputLabel);

}

void UIRStatsUAA::onSaveCSVFile()
{
    if (m_autoSetFileOutput) return;
    if (m_ui->m_chkCSVOutput->isChecked())
    {
        m_currentCSVFileOutput = UIRStatsUtils::setOutputFile(
                                                              m_ui->m_chkCSVOutput,
                                                              "Save to CSV file...",
                                                              "*.csv");
        setCSVFileOutput(m_currentCSVFileOutput.toStdString());
    }
    else m_ui->m_statusBar->removeWidget(m_currentCSVFileOutputLabel);
}

void UIRStatsUAA::onRecentSessionSelected(QAction* action)
{
    std::string name = action->property("name").toString().toStdString();
    if (m_recentSessionsMap.count(name))
    {
        RStatsUAASessionData * data = dynamic_cast<RStatsUAASessionData*>(m_recentSessionsMap[name].get());
        setSessionData(*data);
    }
}

void UIRStatsUAA::updateRecentSessions()
{
    std::pair<QActionGroup*,QAction*> actionPair=UIRStatsUtils::buildRecentSessions<RStatsUAASessionData>(
                                                 this,
                                                 m_ui->actionRecentlyUsed,
                                                 this->m_recentSessionsMap,
                                                 c_RECENT_SESSION_EXTENSION);


    if (actionPair.first && actionPair.second)
    {
        connect(actionPair.first,SIGNAL(triggered(QAction*)),this,SLOT(onRecentSessionSelected(QAction*)));
        connect(actionPair.second,SIGNAL(triggered(bool)),this,SLOT(onClearRecentSessions()));
    }

}

void UIRStatsUAA::setTextFileOutput(const std::string &textFile)
{
    m_currentTextFileOutput = QString::fromStdString(textFile);
    if (!m_currentTextFileOutput.isEmpty())
    {
        if (m_currentTextFileOutputLabel == nullptr)
        {
            m_currentTextFileOutputLabel = new QLabel;
            m_currentTextFileOutputLabel->setStyleSheet("QLabel{padding:2px;border-radius:5px;background:#AAAAFF;color:#000000;border:1px solid grey;}");
        }
        m_ui->m_statusBar->removeWidget(m_currentTextFileOutputLabel);
        m_currentTextFileOutputLabel->setText("<b>Text File:</b> "+m_currentTextFileOutput);
        m_ui->m_statusBar->addPermanentWidget(m_currentTextFileOutputLabel);
        m_currentTextFileOutputLabel->show();
    }
    else m_ui->m_statusBar->removeWidget(m_currentTextFileOutputLabel);
}

void UIRStatsUAA::setCSVFileOutput(const std::string &csvFile)
{
    m_currentCSVFileOutput = QString::fromStdString(csvFile);
    if (!m_currentCSVFileOutput.isEmpty())
    {
        if (m_currentCSVFileOutputLabel == nullptr)
        {
            m_currentCSVFileOutputLabel = new QLabel;
            m_currentCSVFileOutputLabel->setStyleSheet("QLabel{padding:2px;border-radius:5px;background:#AAAAFF;color:#000000;border:1px solid grey;}");
        }
        m_ui->m_statusBar->removeWidget(m_currentCSVFileOutputLabel);
        m_currentCSVFileOutputLabel->setText("<b>CSV File</b>: "+m_currentCSVFileOutput);
        m_ui->m_statusBar->addPermanentWidget(m_currentCSVFileOutputLabel);
        m_currentCSVFileOutputLabel->show();
    }
    else m_ui->m_statusBar->removeWidget(m_currentCSVFileOutputLabel);
}



}}}}//end namespace

