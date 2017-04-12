/*
    UIRStatsSSRN.cpp   
*/
//UIRStatsSSRN.cpp generated by CBTek Solutions on 02-23-2017 at 08:00:38 PM

#include "UIRStatsSSRN.h"
#include "ui_UIRStatsSSRN.h"

#include "RStatsSSRN.h"

#include "rstats_utils/inc/RStatsSettingsManager.h"

#include "rstats_ui/inc/UIRStatsUtils.hpp"
#include "rstats_ui/inc/UIRStatsErrorMessage.h"

#include "utility/inc/DateTimeUtils.hpp"
#include "utility/inc/TimeUtils.hpp"
#include "utility/inc/XMLReader.h"
#include "utility/inc/XMLUtils.h"
#include "utility/inc/XMLStreamWriter.h"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/SystemUtils.hpp"

#include <QFileDialog>
#include <QFile>

using namespace oig::ratstats::ui;
using namespace oig::ratstats::utils;
using namespace cbtek::common::utility;

namespace oig {
namespace ratstats {
namespace modules {
namespace ssrn {

UIRStatsSSRN::UIRStatsSSRN(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui_UIRStatsSSRN)
{
    m_ui->setupUi(this);
    m_ui->m_dockOptions->setTitleBarWidget(new QWidget());    

    m_iconError = UIRStatsUtils::getIcon("img_error.png");
    m_iconOK = UIRStatsUtils::getIcon("img_ok.png");
    m_iconWarning = UIRStatsUtils::getIcon("img_warning.png");

    connect(m_ui->m_btnExit,SIGNAL(clicked(bool)),this,SLOT(onExit()));
    connect(m_ui->m_btnExecute,SIGNAL(clicked(bool)),this,SLOT(onExecute()));
    connect(m_ui->actionExecute,SIGNAL(triggered(bool)),this,SLOT(onExecute()));
    connect(m_ui->m_btnHelp,SIGNAL(clicked(bool)),this,SLOT(onHelp()));
    connect(m_ui->m_spnHighNumber,SIGNAL(valueChanged(int)),this,SLOT(onValidate()));
    connect(m_ui->m_spnLowNumber,SIGNAL(valueChanged(int)),this,SLOT(onValidate()));
    connect(m_ui->m_spnSpares,SIGNAL(valueChanged(int)),this,SLOT(onValidate()));
    connect(m_ui->m_spnOrder,SIGNAL(valueChanged(int)),this,SLOT(onValidate()));
    connect(m_ui->m_chkCSVOutput,SIGNAL(clicked(bool)),this,SLOT(onSaveCSVFile()));
    connect(m_ui->m_chkTextOutput,SIGNAL(clicked(bool)),this,SLOT(onSaveTextFile()));    
    connect(m_ui->m_chkCustomSeed,SIGNAL(toggled(bool)),this,SLOT(onSeedBoxToggled(bool)));
    onUpdateClock();    
    m_autoSetFileOutput = false;
    QString defaultAuditName = QString::fromStdString(RStatsUtils::getAuditName());

    m_ui->m_txtAuditName->setPlaceholderText(defaultAuditName);
    m_ui->m_grpOutput->hide();
    m_ui->m_line->hide();
    m_ui->m_frmTotals->hide();

    m_ui->m_spnSeed->setMaximum(std::numeric_limits<double>::max());
    m_ui->m_spnSeed->setMinimum(std::numeric_limits<double>::min());    
    m_ui->m_spnSeed->setValue(static_cast<RStatsFloat>(TimeUtils::getSecondsNow()) /
                              static_cast<RStatsFloat>(m_rnd.next(10,1000)));

    m_ui->m_btnExecute->setEnabled(false);
    m_ui->actionExecute->setEnabled(false);

    m_currentCSVFileOutputLabel = nullptr;
    m_currentTextFileOutputLabel = nullptr;
    onValidate();
    RStatsInteger buttonHeight = 32;
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
                                 m_ui->actionExecute,
                                 m_ui->actionExit,
                                 m_ui->actionSingle_Stage_Random_Numbers_Help_Guide,
                                 m_ui->actionAbout,
                                 m_ui->actionRecent,
                                 buttonHeight,
                                 this->font());
    m_ui->menuFile->setTitle("&File");
    m_ui->menuHelp->setTitle("&Help");
    updateRecentSessions();
    onSeedBoxToggled(false);

}

UIRStatsSSRN::~UIRStatsSSRN()
{
    delete m_ui;
}

void UIRStatsSSRN::onValidate()
{
    m_logger.clear();
    m_ui->m_lstErrorConsole->clear();
    std::int64_t low  = m_ui->m_spnLowNumber->value();
    std::int64_t high = m_ui->m_spnHighNumber->value();
    std::int64_t order= m_ui->m_spnOrder->value();
    std::int64_t spare= m_ui->m_spnSpares->value();

    m_logger.addWarning(m_ui->m_txtAuditName->text().isEmpty(),
                        "You did not specify an audit name.  Using default: ("+m_ui->m_txtAuditName->placeholderText().toStdString()+")");

    m_logger.addError(((order + spare) == 0 ),
                      "The number of generated values must be greater than zero!");

    m_logger.addError(low > high,
                      "The low number is greater than or equal to the high number!");

    m_logger.addWarning(low == high,
                        "The low number is equal to the high number!");

    m_logger.addWarning((high - low)  < (order + spare),
                        "The sampling frame is less than the total number of values to be generated!");

    size_t index = 0;
    if (m_logger.hasMessages() == false)
    {
        m_ui->m_dockOutput->hide();
        m_ui->m_btnExecute->setEnabled(true);
        m_ui->actionExecute->setEnabled(true);
        return;
    }
    m_ui->m_dockOptions->show();
    for(const std::string & message : m_logger.getMessages())
    {
        QListWidgetItem * item = new QListWidgetItem;
        item->setText(QString::fromStdString(message));
        if (m_logger.isError(index))
        {
            item->setIcon(m_iconError);
        }
        else if (m_logger.isWarning(index))
        {
            item->setIcon(m_iconWarning);
        }
        else
        {
            item->setIcon(m_iconOK);
        }
        ++index;
        m_ui->m_lstErrorConsole->addItem(item);
    }

    if (m_logger.hasError())
    {
        m_ui->m_btnExecute->setEnabled(false);
        m_ui->actionExecute->setEnabled(false);
    }
    else
    {
        m_ui->m_btnExecute->setEnabled(true);
        m_ui->actionExecute->setEnabled(true);
    }
}

void UIRStatsSSRN::onSaveCSVFile()
{
    if (m_autoSetFileOutput)return;
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

void UIRStatsSSRN::onSaveTextFile()
{
    if (m_autoSetFileOutput)return;
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

void UIRStatsSSRN::onUpdateClock()
{
    m_ui->m_lblTime->setText(QString::fromStdString(TimeUtils::to12HourTimeString(TimeUtils::getCurrentTime())));
    m_ui->m_lblDate->setText(QString::fromStdString(DateUtils::toShortDateString(DateUtils::getCurrentDate())));
    if (!m_ui->m_chkCustomSeed->isChecked() && !m_ui->m_spnSeed->isEnabled())
    {        
        m_ui->m_spnSeed->setValue(static_cast<RStatsFloat>(TimeUtils::getSecondsNow()) /
                                  static_cast<RStatsFloat>(m_rnd.next(10,1000)));
    }
}

void UIRStatsSSRN::onExecute()
{
    try
    {
        onUpdateClock();
        m_ui->m_tblOutput->clear();
        RStatsSSRN ssrn;
        std::string name = m_ui->m_txtAuditName->text().toStdString();
        if (StringUtils::isEmpty(name))
        {
            name = m_ui->m_txtAuditName->placeholderText().toStdString();
        }
        RStatsSSRNOutputData outputData = ssrn.execute(name,
                                                       m_ui->m_spnSeed->value(),
                                                       m_ui->m_spnOrder->value(),
                                                       m_ui->m_spnSpares->value(),
                                                       m_ui->m_spnLowNumber->value(),
                                                       m_ui->m_spnHighNumber->value());

        RStatsWorksheet worksheet;
        ssrn.saveToWorksheet(worksheet);
        UIRStatsUtils::bindSheetToUI(worksheet,m_ui->m_tblOutput,false,0,0);

        if (!StringUtils::isEmpty(m_currentTextFileOutput.toStdString()))
        {
            FileUtils::writeFileContents(m_currentTextFileOutput.toStdString(),
                                         worksheet.toEvenlySpacedString());
        }

        if (!StringUtils::isEmpty(m_currentCSVFileOutput.toStdString()))
        {
            FileUtils::writeFileContents(m_currentCSVFileOutput.toStdString(),
                                         worksheet.toCommaDelimitedString());
        }

        m_ui->m_tblOutput->resizeColumnsToContents();
        m_ui->m_tblOutput->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        m_ui->m_grpOutput->show();
        m_ui->m_line->show();
        m_ui->m_frmTotals->show();
        m_ui->m_lblNoData->hide();

        std::string totalStr = StringUtils::toString(m_ui->m_spnOrder->value()+m_ui->m_spnSpares->value(),true);
        std::string frameSizeStr = StringUtils::toString((m_ui->m_spnHighNumber->value()-m_ui->m_spnLowNumber->value())+1,true);
        std::string sumStr = StringUtils::toString(outputData.sum,true);

        m_ui->m_lblTotalRandomNumbersValue->setText(QString::fromStdString(totalStr));
        m_ui->m_lblTotalFrameSizeValue->setText(QString::fromStdString(frameSizeStr));
        m_ui->m_lblOutputSummationValue->setText(QString::fromStdString(sumStr));

        m_ui->m_lblTime->setText(QString::fromStdString(TimeUtils::to12HourTimeString(outputData.createTime)));
        m_ui->m_lblDate->setText(QString::fromStdString(DateUtils::toShortDateString(outputData.createDate)));

        RStatsSSRNSessionData sessionData = getSessionData();
        sessionData.setCreationDate(DateUtils::getCurrentDate().toDateInteger());
        sessionData.setCreationTime(TimeUtils::getCurrentTime().toTimeInteger());
        m_recentSessionsMap[sessionData.getAuditName()]=RStatsModuleSessionDataPtr(new RStatsSSRNSessionData(sessionData));
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

void UIRStatsSSRN::onHelp()
{

}

void UIRStatsSSRN::onExit()
{
    this->close();
}


RStatsSSRNSessionData UIRStatsSSRN::getSessionData() const
{
    QString text = m_ui->m_txtAuditName->text();
    if (text.isEmpty())
    {
        text = m_ui->m_txtAuditName->placeholderText();
    }
    RStatsSSRNSessionData data;
    data.setAuditName(text.toStdString());
    data.setCSVOutputFile(m_currentCSVFileOutput.toStdString());
    data.setTextOutputFile(m_currentTextFileOutput.toStdString());
    data.setSeed(m_ui->m_spnSeed->value());
    data.setOrder(m_ui->m_spnOrder->value());
    data.setSpares(m_ui->m_spnSpares->value());
    data.setLow(m_ui->m_spnLowNumber->value());
    data.setHigh(m_ui->m_spnHighNumber->value());
    return data;
}

void UIRStatsSSRN::setSessionData(const RStatsSSRNSessionData &data)
{
    m_ui->m_chkCustomSeed->setEnabled(true);
    m_ui->m_txtAuditName->setText(QString::fromStdString(data.getAuditName()));
    m_ui->m_spnSeed->setValue(data.getSeed());
    m_ui->m_spnSeed->setEnabled(true);
    m_ui->m_spnHighNumber->setValue(static_cast<int>(data.getHigh()));
    m_ui->m_spnLowNumber->setValue(static_cast<int>(data.getLow()));
    m_ui->m_spnSpares->setValue(static_cast<int>(data.getSpares()));
    m_ui->m_spnOrder->setValue(static_cast<int>(data.getOrder()));

    m_autoSetFileOutput=true;
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
    m_autoSetFileOutput=false;
}
void UIRStatsSSRN::onClearRecentSessions()
{
    RStatsUtils::clearRecentSessions(c_RECENT_SESSION_EXTENSION);        
    updateRecentSessions();
}

void UIRStatsSSRN::onRecentSessionSelected(QAction *action)
{
    std::string name = action->property("name").toString().toStdString();
    if (m_recentSessionsMap.count(name))
    {
        RStatsSSRNSessionData * data = dynamic_cast<RStatsSSRNSessionData*>(m_recentSessionsMap[name].get());
        if (data)
        {
            setSessionData(*data);
        }
    }
}

void UIRStatsSSRN::updateRecentSessions()
{
    std::pair<QActionGroup*,QAction*> actionPair=UIRStatsUtils::buildRecentSessions<RStatsSSRNSessionData>(
                                                 this,
                                                 m_ui->actionRecent,
                                                 this->m_recentSessionsMap,
                                                 c_RECENT_SESSION_EXTENSION);


    if (actionPair.first && actionPair.second)
    {
        connect(actionPair.first,SIGNAL(triggered(QAction*)),this,SLOT(onRecentSessionSelected(QAction*)));
        connect(actionPair.second,SIGNAL(triggered(bool)),this,SLOT(onClearRecentSessions()));
    }

}

void UIRStatsSSRN::onSeedBoxToggled(bool toggle)
{
    if (toggle)
    {
        m_ui->m_spnSeed->setEnabled(true);
        m_ui->m_spnSeed->clear();
        m_ui->m_spnSeed->setFocus();        
    }
    else
    {
        m_ui->m_spnSeed->setEnabled(false);
        onUpdateClock();
    }

}

void UIRStatsSSRN::setTextFileOutput(const std::string& textFile)
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

        m_currentTextFileOutputLabel->setToolTip(m_currentTextFileOutput);
        QString text = "<b>Text File:</b> "+m_currentTextFileOutput;
        QFontMetrics metrics(this->font());
        QString elidedText = metrics.elidedText(text, Qt::ElideMiddle, this->width() / 2);
        m_currentTextFileOutputLabel->setText(elidedText);

        m_ui->m_statusBar->addPermanentWidget(m_currentTextFileOutputLabel);
        m_currentTextFileOutputLabel->show();
    }
    else m_ui->m_statusBar->removeWidget(m_currentTextFileOutputLabel);
}

void UIRStatsSSRN::setCSVFileOutput(const std::string& csvFile)
{
    m_currentCSVFileOutput = QString::fromStdString(csvFile);
    if (!m_currentCSVFileOutput.isEmpty())
    {
        if (m_currentCSVFileOutputLabel == nullptr)
        {
            m_currentCSVFileOutputLabel = new QLabel;
            m_currentCSVFileOutputLabel->setStyleSheet("QLabel{padding:2px;border-radius:5px;background:#AAFFFF;color:#000000;border:1px solid grey;}");
        }
        m_ui->m_statusBar->removeWidget(m_currentCSVFileOutputLabel);
        m_currentCSVFileOutputLabel->setToolTip(m_currentCSVFileOutput);
        QString text = "<b>CSV File:</b> "+m_currentCSVFileOutput;
        QFontMetrics metrics(this->font());
        QString elidedText = metrics.elidedText(text, Qt::ElideMiddle, this->width() / 2);
        m_currentCSVFileOutputLabel->setText(elidedText);

        m_ui->m_statusBar->addPermanentWidget(m_currentCSVFileOutputLabel);
        m_currentCSVFileOutputLabel->show();
    }
    else m_ui->m_statusBar->removeWidget(m_currentCSVFileOutputLabel);
}


void UIRStatsSSRN::resizeEvent(QResizeEvent *)
{
    if (m_currentCSVFileOutputLabel)
    {
        setCSVFileOutput(m_currentCSVFileOutput.toStdString());
    }
    if (m_currentTextFileOutputLabel)
    {
        setTextFileOutput(m_currentTextFileOutput.toStdString());
    }
}

}}}}//end namespace

