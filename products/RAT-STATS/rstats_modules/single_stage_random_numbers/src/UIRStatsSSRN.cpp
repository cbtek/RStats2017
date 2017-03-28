/*
    UIRStatsSSRN.cpp   
*/
//UIRStatsSSRN.cpp generated by CBTek Solutions on 02-23-2017 at 08:00:38 PM

#include "UIRStatsSSRN.h"
#include "ui_UIRStatsSSRN.h"

#include "RStatsSSRN.h"

#include "rstats_utils/inc/RStatsSettingsManager.h"
#include "rstats_ui/inc/UIRStatsUtils.hpp"

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

static const std::string c_RECENT_SESSION_EXTENSION = "modules_ssrn";

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
    m_ui->m_dockOutput->setTitleBarWidget(new QWidget());
    connect(m_ui->m_btnExit,SIGNAL(clicked(bool)),this,SLOT(onExit()));
    connect(m_ui->m_btnGenerate,SIGNAL(clicked(bool)),this,SLOT(onGenerate()));
    connect(m_ui->m_btnHelp,SIGNAL(clicked(bool)),this,SLOT(onHelp()));
    connect(m_ui->m_spnHighNumber,SIGNAL(valueChanged(int)),this,SLOT(onValidateForm()));
    connect(m_ui->m_spnLowNumber,SIGNAL(valueChanged(int)),this,SLOT(onValidateForm()));
    connect(m_ui->m_spnSpares,SIGNAL(valueChanged(int)),this,SLOT(onValidateForm()));
    connect(m_ui->m_spnOrder,SIGNAL(valueChanged(int)),this,SLOT(onValidateForm()));
    connect(m_ui->m_chkCSVOutput,SIGNAL(clicked(bool)),this,SLOT(onSaveCSVFile()));
    connect(m_ui->m_chkTextOutput,SIGNAL(clicked(bool)),this,SLOT(onSaveTextFile()));    
    connect(m_ui->m_chkCustomSeed,SIGNAL(toggled(bool)),this,SLOT(onSeedBoxToggled(bool)));
    onUpdateClock();    

    QString defaultAuditName = QString::fromStdString(RStatsUtils::getAuditName());

    m_ui->m_txtAuditName->setPlaceholderText(defaultAuditName);
    m_ui->m_grpOutput->hide();
    m_ui->m_line->hide();
    m_ui->m_frmTotals->hide();

    m_ui->m_spnSeed->setMaximum(std::numeric_limits<double>::max());
    m_ui->m_spnSeed->setMinimum(std::numeric_limits<double>::min());    
    m_ui->m_spnSeed->setValue(static_cast<RStatsFloat>(TimeUtils::getSecondsNow()) /
                              static_cast<RStatsFloat>(m_rnd.next(10,1000)));

    m_ui->m_btnGenerate->setEnabled(false);

    //initialize default icons
    m_iconFolder = UIRStatsUtils::getIcon("img_folder.png");
    m_iconModule = UIRStatsUtils::getIcon("img_module.png");
    m_iconEdit = UIRStatsUtils::getIcon("img_edit.png");
    m_iconHelp = UIRStatsUtils::getIcon("img_help.png");
    m_iconRemove = UIRStatsUtils::getIcon("img_remove.png");
    m_iconAdd = UIRStatsUtils::getIcon("img_add.png");
    m_iconExit = UIRStatsUtils::getIcon("img_exit.png");
    m_iconSettings = UIRStatsUtils::getIcon("img_settings.png");
    m_iconObject = UIRStatsUtils::getIcon("img_object.png");
    m_iconAbout = UIRStatsUtils::getIcon("img_about.png");
    m_iconRun = UIRStatsUtils::getIcon("img_run.png");
    m_iconWarning = UIRStatsUtils::getIcon("img_warning.png");
    m_iconError = UIRStatsUtils::getIcon("img_error.png");
    m_iconOK = UIRStatsUtils::getIcon("img_ok.png");
    onValidateForm();
    int buttonHeight = 32;
    UIRStatsUtils::setButtonStyle(m_ui->m_btnExit,this->font(),m_iconExit,buttonHeight);
    UIRStatsUtils::setButtonStyle(m_ui->m_btnGenerate,this->font(),m_iconRun,buttonHeight);
    UIRStatsUtils::setButtonStyle(m_ui->m_btnHelp,this->font(),m_iconHelp,buttonHeight);
    updateRecentSessions();
    onSeedBoxToggled(false);

}

UIRStatsSSRN::~UIRStatsSSRN()
{
    delete m_ui;
}

void UIRStatsSSRN::onValidateForm()
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
        m_ui->m_btnGenerate->setEnabled(false);
    }
    else m_ui->m_btnGenerate->setEnabled(true);
}

void UIRStatsSSRN::onSaveCSVFile()
{
    m_currenCSVOutput = UIRStatsUtils::setOutputFile(this,
                                                   m_ui->m_chkCSVOutput,
                                                   "Save to CSV file...",
                                                   "*.csv");
}

void UIRStatsSSRN::onSaveTextFile()
{
    m_currentTextFileOutput = UIRStatsUtils::setOutputFile(this,
                              m_ui->m_chkTextOutput,
                              "Save to Text file...",
                              "*.txt");
}

void UIRStatsSSRN::onUpdateClock()
{
    m_ui->m_lblTime->setText(QString::fromStdString(TimeUtils::to12HourTimeString(TimeUtils::getCurrentTime())));
    m_ui->m_lblDate->setText(QString::fromStdString(DateUtils::toShortDateString(DateUtils::getCurrentDate())));
    if (!m_ui->m_chkCustomSeed->isChecked())
    {        
        m_ui->m_spnSeed->setValue(static_cast<RStatsFloat>(TimeUtils::getSecondsNow()) /
                                  static_cast<RStatsFloat>(m_rnd.next(10,1000)));
    }
}

void UIRStatsSSRN::onGenerate()
{

    onUpdateClock();
    RStatsSSRNOutputData outputData = RStatsSSRN::inst().execute(m_ui->m_txtAuditName->text().toStdString(),
                                                                 m_ui->m_spnSeed->value(),
                                                                 m_ui->m_spnOrder->value(),
                                                                 m_ui->m_spnSpares->value(),
                                                                 m_ui->m_spnLowNumber->value(),
                                                                 m_ui->m_spnHighNumber->value());

    RStatsWorksheet worksheet;
    RStatsSSRN::inst().saveToWorksheet(worksheet);
    UIRStatsUtils::bindSheetToUI(worksheet,m_ui->m_tblOutput,false,0,0);

    if (StringUtils::isEmpty(m_currentTextFileOutput))
    {
        FileUtils::writeFileContents(m_currentTextFileOutput,
                                     worksheet.toEvenlySpacedString());
    }

    if (StringUtils::isEmpty(m_currentCSVFileOutput))
    {
        FileUtils::writeFileContents(m_currentCSVFileOutput,
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

    SessionData sessionData = getSessionData();
    sessionData.dateValue = DateUtils::getCurrentDate().toDateInteger();
    sessionData.timeValue = TimeUtils::getCurrentTime().toTimeInteger();
    m_recentSessionsMap[QString::fromStdString(sessionData.name)]=sessionData;
    RStatsUtils::saveRecentSession(sessionData.toString(),c_RECENT_SESSION_EXTENSION);
    updateRecentSessions();    
}

void UIRStatsSSRN::onHelp()
{

}

void UIRStatsSSRN::onExit()
{
    this->close();
}


SessionData UIRStatsSSRN::getSessionData() const
{
    QString text = m_ui->m_txtAuditName->text();
    if (text.isEmpty())
    {
        text = m_ui->m_txtAuditName->placeholderText();
    }
    SessionData data;
    data.name = text.toStdString();
    data.seed = m_ui->m_spnSeed->value();
    data.order = m_ui->m_spnOrder->value();
    data.spares = m_ui->m_spnSpares->value();
    data.low = m_ui->m_spnLowNumber->value();
    data.high = m_ui->m_spnHighNumber->value();
    return data;
}

void UIRStatsSSRN::setSessionData(const SessionData &data)
{
    m_ui->m_chkCustomSeed->setEnabled(true);
    m_ui->m_txtAuditName->setText(QString::fromStdString(data.name));
    m_ui->m_spnSeed->setValue(data.seed);
    m_ui->m_spnSeed->setEnabled(true);
    m_ui->m_spnHighNumber->setValue(data.high);
    m_ui->m_spnLowNumber->setValue(data.low);
    m_ui->m_spnSpares->setValue(data.spares);
    m_ui->m_spnOrder->setValue(data.order);

}
void UIRStatsSSRN::onClearRecentSessions()
{
    RStatsUtils::clearRecentSessions(c_RECENT_SESSION_EXTENSION);
    updateRecentSessions();
}

void UIRStatsSSRN::onRecentSessionSelected(QAction *action)
{
    QString name = action->property("name").toString();
    if (m_recentSessionsMap.contains(name))
    {
        SessionData data = m_recentSessionsMap[name];
        setSessionData(data);
    }
}

void UIRStatsSSRN::updateRecentSessions()
{
    m_recentSessionsMap.clear();
    std::vector<std::string> sessionUrls = RStatsUtils::getRecentSessions(c_RECENT_SESSION_EXTENSION);
    if (sessionUrls.empty())
    {
        m_ui->actionRecent->setDisabled(true);
        return;
    }

    m_ui->actionRecent->setDisabled(false);
    m_recentSessionActionGroup = new QActionGroup(this);
    connect(m_recentSessionActionGroup,SIGNAL(triggered(QAction*)),this,SLOT(onRecentSessionSelected(QAction*)));
    QMenu * recentMenu = new QMenu(m_ui->menuFile);
    for (const auto& url : sessionUrls)
    {
        SessionData data;
        data.load(url);
        m_recentSessionsMap[QString::fromStdString(data.name)] = data;
        std::string dateTimeStr = DateTimeUtils::getDisplayTimeStamp(DateEntity(data.dateValue),TimeEntity(data.timeValue));
        QAction * action = new QAction(QString::fromStdString(data.name+" "+dateTimeStr), recentMenu);
        action->setProperty("name",QString::fromStdString(data.name));
        m_recentSessionActionGroup->addAction(action);
        recentMenu->addAction(action);
    }
    recentMenu->addSeparator();
    QAction * clearRecentSessionsAction = new QAction(recentMenu);
    clearRecentSessionsAction->setText("Clear History");
    connect(clearRecentSessionsAction,SIGNAL(triggered(bool)),this,SLOT(onClearRecentSessions()));
    recentMenu->addAction(clearRecentSessionsAction);
    m_ui->actionRecent->setMenu(recentMenu);
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

void SessionData::load(const std::string &url)
{
    if (!url.empty())
    {
        XMLReader reader;
        reader.load(url);
        XMLDataElement * session = reader.getElement("session");
        if (session)
        {
            XMLDataElement* nameXML = session->getChild("name");
            XMLDataElement* seedXML = session->getChild("seed");
            XMLDataElement* orderXML = session->getChild("order");
            XMLDataElement* sparesXML = session->getChild("spares");
            XMLDataElement* lowXML = session->getChild("low");
            XMLDataElement* highXML = session->getChild("high");
            XMLDataElement* dateXML = session->getChild("date");
            XMLDataElement* timeXML = session->getChild("time");
            if (nameXML)this->name = XMLUtils::getDecodedString(nameXML->getElementData(true));
            if (seedXML)this->seed = seedXML->getElementDataAsFloat();
            if (orderXML)this->order = orderXML->getElementDataAsInteger();
            if (sparesXML)this->spares = sparesXML->getElementDataAsInteger();
            if (lowXML)this->low = lowXML->getElementDataAsInteger();
            if (highXML)this->high = highXML->getElementDataAsInteger();
            if (dateXML)this->dateValue = dateXML->getElementDataAsInteger();
            if (timeXML)this->timeValue = timeXML->getElementDataAsInteger();
        }
    }
}

std::string SessionData::toString() const
{
    std::ostringstream out;
    XMLStreamWriter xml(out);
    xml.writeStartDocument();
    xml.writeStartElementNoAttributes("session");
    xml.writeTextElement("name",XMLUtils::getEncodedString(name));
    xml.writeTextElement("seed",StringUtils::toString(seed));
    xml.writeTextElement("order",StringUtils::toString(order));
    xml.writeTextElement("spares",StringUtils::toString(spares));
    xml.writeTextElement("low",StringUtils::toString(low));
    xml.writeTextElement("high",StringUtils::toString(high));
    xml.writeTextElement("date",StringUtils::toString(dateValue));
    xml.writeTextElement("time",StringUtils::toString(timeValue));
    xml.writeEndElement("session");
    return out.str();
}

}}}}//end namespace

