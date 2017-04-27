/*
    UIRStatsUVA.cpp
    

*/
//UIRStatsUVA.cpp generated by CBTek Solutions on 02-06-2017 at 11:18:47 AM

#include "UIRStatsUVA.h"
#include "ui_UIRStatsUVA.h"

#include "RStatsUVA.h"

#include "rstats_ui/inc/UIRStatsAbout.h"
#include "rstats_ui/inc/UIRStatsUtils.hpp"
#include "rstats_ui/inc/UIRStatsErrorMessage.h"

#include "rstats_utils/inc/RStatsWorkbookStreamFactory.h"

#include "utility/inc/DateTimeUtils.hpp"


#include <QFileDialog>
#include <QListWidgetItem>
#include <QDesktopServices>
#include <QAbstractButton>

using namespace oig::ratstats::ui;
using namespace oig::ratstats::utils;

using namespace cbtek::common::utility;

namespace oig {
namespace ratstats {
namespace modules {
namespace uva {


UIRStatsUVA::UIRStatsUVA(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui_UIRStatsUVA)
{    
    m_ui->setupUi(this);

    //Initialize output labels for status bar
    m_currentCSVFileOutputLabel = nullptr;
    m_currentTextFileOutputLabel = nullptr;        

    //Initialize preview table widget
    m_tblPreview = new UIRStatsTablePreviewWidget;
    m_ui->dockWidgetContents->layout()->addWidget(m_tblPreview);

    //Set icons that get reused (validation console)
    m_iconError = UIRStatsUtils::getIcon("img_error.png");
    m_iconWarning = UIRStatsUtils::getIcon("img_warning.png");
    m_iconOK = UIRStatsUtils::getIcon("img_ok.png");
    m_ui->m_txtAuditName->setPlaceholderText(QString::fromStdString(RStatsUtils::getAuditName()));
    m_currentDataFormat = RStatsDataFormatType::Examine;

    //Initialize all buttons
    UIRStatsUtils::initButton(m_ui->m_btnImportSampleInputData, "img_folder.png");
    UIRStatsUtils::initButton(m_ui->m_btnExecute, "img_run.png");
    UIRStatsUtils::initButton(m_ui->m_btnExit, "img_exit.png");
    UIRStatsUtils::initButton(m_ui->m_btnHelp, "img_help.png");

    //Initialize all menu actions
    UIRStatsUtils::initAction(m_ui->actionAbout,"img_about.png","Alt+A");
    UIRStatsUtils::initAction(m_ui->actionExecute,"img_run.png","Alt+R");
    UIRStatsUtils::initAction(m_ui->actionExit,"img_exit.png","Alt+Q");
    UIRStatsUtils::initAction(m_ui->actionHelp,"img_help.png","Alt+H");
    UIRStatsUtils::initAction(m_ui->actionRecently_Used,"img_clock.png","Alt+S");

    //Set init for startup options
    m_ui->m_dockOptions->setTitleBarWidget(new QWidget());
    m_ui->m_frmOutput->hide();
    m_ui->m_cmbDataInputSheets->addItem("No Sheets Available");
    m_ui->m_cmbDataInputSheets->setEnabled(false);
    m_ui->m_rdbExamined->setChecked(true);
    m_autoSetFileOutput = false;
    updateRecentSessions();
    onUpdateDataFormatSelection();

    //Initialize all UI events
    connect(m_ui->actionHelp,SIGNAL(triggered()),this,SLOT(onHelp()));
    connect(m_ui->actionExit,SIGNAL(triggered()),this,SLOT(onExit()));
    connect(m_ui->actionExecute,SIGNAL(triggered(bool)),this,SLOT(onExecute()));
    connect(m_ui->actionAbout,SIGNAL(triggered(bool)),this,SLOT(onAbout()));
    connect(m_ui->m_chkTextOutput,SIGNAL(toggled(bool)),this,SLOT(onSaveTextFile()));
    connect(m_ui->m_chkCSVOutput,SIGNAL(toggled(bool)),this,SLOT(onSaveCSVFile()));
    connect(m_ui->m_btnImportSampleInputData,SIGNAL(clicked(bool)),this,SLOT(onImportDataInput()));
    connect(m_ui->m_btnHelp,SIGNAL(clicked(bool)),this,SLOT(onHelp()));    
    connect(m_ui->m_btnExit,SIGNAL(clicked(bool)),this,SLOT(onExit()));    
    connect(m_ui->m_btnExecute,SIGNAL(clicked(bool)),this,SLOT(onExecute()));
    connect(m_ui->m_cmbDataInputSheets,SIGNAL(currentIndexChanged(int)),this,SLOT(onComboDataInputSheetSelected(int)));    
    connect(m_ui->m_rdbAudited,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
    connect(m_ui->m_rdbExamined,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
    connect(m_ui->m_rdbDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
    connect(m_ui->m_rdbAuditedAndDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
    connect(m_ui->m_rdbExaminedAndAudited,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
    connect(m_ui->m_rdbExaminedAndDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));

    connect(&m_clock,SIGNAL(timeout()),this,SLOT(onUpdateClock()));

    onUpdateClock();
    m_clock.start(1000);

    onSetTabOrder();
}

void UIRStatsUVA::onImportDataInput()
{
    //Show the "File Browser"
    m_dataTableImportFilePath = QFileDialog::getOpenFileName(this,"Import Stratified Variable Appraisal Sample Input File...","","Supported Input Files(*.csv *.xlsx *.dif *.xls)");

    //Make sure imported file is valid before attempting to import data table
    if (!m_dataTableImportFilePath.isEmpty() && QFile::exists(m_dataTableImportFilePath))
    {
        importDataTable(m_dataTableImportFilePath.toStdString());
    }
}

void UIRStatsUVA::importDataTable(const std::string& dataTableFilePath)
{
    //Make sure URL is valid for dataTableFilePath
    if (StringUtils::isEmpty(dataTableFilePath) || !FileUtils::fileExists(dataTableFilePath))
    {
        return;
    }

    //Set global (in class scope) path for data table
    m_dataTableImportFilePath = QString::fromStdString(dataTableFilePath);

    //Read in data table with all available sheets
    m_ui->m_cmbDataInputSheets->clear();
    try
    {
        std::string filePath = m_dataTableImportFilePath.toStdString();
        m_currentDataWorkbook.load(filePath);
        if (m_currentDataWorkbook.getNumWorksheets() == 0)
        {
            THROW_GENERIC_EXCEPTION("No worksheets were found in \""+filePath+"\"")
        }
        m_ui->m_cmbDataInputSheets->setEnabled(true);

        std::vector<std::string> worksheetNames = m_currentDataWorkbook.getWorksheetNames();
        for(const auto& sheetName : worksheetNames)
        {
            m_ui->m_cmbDataInputSheets->addItem(QString::fromStdString(sheetName));
        }
        onUpdateRowColumnExtentsForDataTable();
    }
    //Throw up custom dialog if something bad happens
    catch(const std::exception& exception)
    {
        m_ui->m_cmbDataInputSheets->addItem("No Sheets Available");
        m_ui->m_cmbDataInputSheets->setEnabled(false);
        QString title = "Error occured trying to import " + m_dataTableImportFilePath;
        QString message = QString(exception.what());
        UIRStatsErrorMessage(title,message).exec();
        return;
    }
}

void UIRStatsUVA::onUpdateClock()
{
    onValidate();
}

void UIRStatsUVA::onSetTabOrder()
{
    this->setTabOrder(m_ui->m_txtAuditName,m_ui->m_spnUniverseSize);
    this->setTabOrder(m_ui->m_spnUniverseSize,m_ui->m_rdbExamined);
    this->setTabOrder(m_ui->m_rdbExamined,m_ui->m_rdbAudited);
    this->setTabOrder(m_ui->m_rdbAudited,m_ui->m_rdbDifference);
    this->setTabOrder(m_ui->m_rdbDifference,m_ui->m_rdbExaminedAndAudited);
    this->setTabOrder(m_ui->m_rdbExaminedAndAudited,m_ui->m_rdbAuditedAndDifference);
    this->setTabOrder(m_ui->m_rdbAuditedAndDifference,m_ui->m_rdbExaminedAndDifference);
    this->setTabOrder(m_ui->m_rdbExaminedAndDifference,m_ui->m_chkCSVOutput);
    this->setTabOrder(m_ui->m_chkCSVOutput,m_ui->m_chkTextOutput);
    this->setTabOrder(m_ui->m_chkTextOutput,m_ui->m_chkViewInBrowser);
    this->setTabOrder(m_ui->m_chkViewInBrowser,m_ui->m_cmbDataInputSheets);
    this->setTabOrder(m_ui->m_cmbDataInputSheets,m_ui->m_btnImportSampleInputData);
    this->setTabOrder(m_ui->m_btnImportSampleInputData,m_ui->m_cmbDataRowStartDataTable);
    this->setTabOrder(m_ui->m_cmbDataRowStartDataTable,m_ui->m_cmbExaminedDataTable);
    this->setTabOrder(m_ui->m_cmbExaminedDataTable,m_ui->m_cmbAuditedDataTable);
    this->setTabOrder(m_ui->m_cmbAuditedDataTable,m_ui->m_cmbDifferenceDataTable);
    this->setTabOrder(m_ui->m_cmbDifferenceDataTable,m_tblPreview);
    this->setTabOrder(m_tblPreview,m_ui->m_txtOutput);
    this->setTabOrder(m_ui->m_txtOutput,m_ui->m_btnHelp);
    this->setTabOrder(m_ui->m_btnHelp,m_ui->m_btnExecute);
    this->setTabOrder(m_ui->m_btnExecute,m_ui->m_btnExit);
    this->setTabOrder(m_ui->m_btnExit,m_ui->m_lstValidationConsole);
}

void UIRStatsUVA::onUpdateDataFormatButtons()
{
    QAbstractButton * button = qobject_cast<QAbstractButton*>(sender());
    if (button)
    {
        disconnect(m_ui->m_rdbAudited,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
        disconnect(m_ui->m_rdbExamined,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
        disconnect(m_ui->m_rdbDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
        disconnect(m_ui->m_rdbAuditedAndDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
        disconnect(m_ui->m_rdbExaminedAndAudited,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
        disconnect(m_ui->m_rdbExaminedAndDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));

        m_ui->m_rdbAudited->setChecked(false);
        m_ui->m_rdbExamined->setChecked(false);
        m_ui->m_rdbDifference->setChecked(false);
        m_ui->m_rdbAuditedAndDifference->setChecked(false);
        m_ui->m_rdbExaminedAndAudited->setChecked(false);
        m_ui->m_rdbExaminedAndDifference->setChecked(false);
        button->setChecked(true);
        onUpdateDataFormatSelection();

        connect(m_ui->m_rdbAudited,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
        connect(m_ui->m_rdbExamined,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
        connect(m_ui->m_rdbDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
        connect(m_ui->m_rdbAuditedAndDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
        connect(m_ui->m_rdbExaminedAndAudited,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
        connect(m_ui->m_rdbExaminedAndDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatButtons()));
        onValidate();
    }
}

void UIRStatsUVA::onUpdateDataFormatSelection()
{    
    m_ui->m_cmbAuditedDataTable->setEnabled(false);
    m_ui->m_cmbExaminedDataTable->setEnabled(false);
    m_ui->m_cmbDifferenceDataTable->setEnabled(false);
    if (m_ui->m_rdbAudited->isChecked())
    {
        m_ui->m_cmbAuditedDataTable->setEnabled(true);
        m_currentDataFormat = RStatsDataFormatType::Audit;
    }
    else if (m_ui->m_rdbDifference->isChecked())
    {
        m_ui->m_cmbDifferenceDataTable->setEnabled(true);
        m_currentDataFormat = RStatsDataFormatType::Difference;
    }
    else if (m_ui->m_rdbExamined->isChecked())
    {
        m_ui->m_cmbExaminedDataTable->setEnabled(true);
        m_currentDataFormat = RStatsDataFormatType::Examine;
    }
    else if (m_ui->m_rdbAuditedAndDifference->isChecked())
    {
        m_ui->m_cmbDifferenceDataTable->setEnabled(true);
        m_ui->m_cmbAuditedDataTable->setEnabled(true);
        m_currentDataFormat = RStatsDataFormatType::AuditAndDifference;
    }
    else if (m_ui->m_rdbExaminedAndDifference->isChecked())
    {
        m_ui->m_cmbDifferenceDataTable->setEnabled(true);
        m_ui->m_cmbExaminedDataTable->setEnabled(true);
        m_currentDataFormat = RStatsDataFormatType::ExamineAndDifference;
    }
    else if (m_ui->m_rdbExaminedAndAudited->isChecked())
    {
        m_ui->m_cmbAuditedDataTable->setEnabled(true);
        m_ui->m_cmbExaminedDataTable->setEnabled(true);
        m_currentDataFormat = RStatsDataFormatType::ExamineAndAudit;
    }
}

void UIRStatsUVA::onUpdateRowColumnExtentsForDataTable()
{
    std::set<size_t> rows,cols;
    m_currentDataSheet.findDataRowsAndColumns(rows,cols);
    populateWithColumns(cols,m_ui->m_cmbAuditedDataTable);
    populateWithColumns(cols,m_ui->m_cmbExaminedDataTable);
    populateWithColumns(cols,m_ui->m_cmbDifferenceDataTable);
    populateWithRows(rows,m_ui->m_cmbDataRowStartDataTable);
}

void UIRStatsUVA::onSampleDataInputSheetSelected(const RStatsWorksheet& sheet)
{
    UIRStatsUtils::bindSheetToUI(sheet,m_tblPreview,true,0,0);
    m_currentDataSheet = sheet;
    onUpdateRowColumnExtentsForDataTable();
    m_tblPreview->verticalHeader()->show();
}

void UIRStatsUVA::onComboDataInputSheetSelected(int row)
{
    if (row < 0)
    {
        return;
    }
    size_t index = static_cast<size_t>(row);
    if (index < m_currentDataWorkbook.getNumWorksheets())
    {
        RStatsWorksheet sheet = m_currentDataWorkbook(index);
        onSampleDataInputSheetSelected(sheet);
    }
}


void UIRStatsUVA::populateWithColumns(const std::set<size_t>& columns,
                                      QComboBox *comboBox)
{
    comboBox->clear();
    for(const auto& column : columns)
    {
        std::string label = RStatsUtils::getColumnLabelFromIndex(column);
        comboBox->addItem(QString::fromStdString(label));
    }
}

void UIRStatsUVA::populateWithRows(const std::set<size_t>& rows,
                                   QComboBox *comboBox)
{
    comboBox->clear();
    for(const auto& row : rows)
    {
        comboBox->addItem(QString::number(row+1));
    }
}

UIRStatsUVA::~UIRStatsUVA()
{
    delete m_ui;
}

void UIRStatsUVA::onHelp()
{
    QString url = QString::fromStdString(FileUtils::buildFilePath(SystemUtils::getCurrentExecutableDirectory(),"rstats_help/rstats_uva.pdf"));
    if (!QFile::exists(url) || !QDesktopServices::openUrl(url))
    {
        UIRStatsErrorMessage("Could not load help file","Could not open the help file located at \"" + url.toStdString() + "\"",false,this).exec();
    }
}

void UIRStatsUVA::onAbout()
{
    UIRStatsAbout().exec();
}

void UIRStatsUVA::onExecute()
{
    try
    {
        m_clock.start(1000);
        onValidate();
        size_t universeSize = static_cast<size_t>(m_ui->m_spnUniverseSize->value());
        RStatsDataFormatTypeIndex dfIndex;
        if (m_ui->m_rdbAudited->isChecked())
        {
            dfIndex.type = RStatsDataFormatType::Audit;
            dfIndex.primaryDatasetColumnIndex  = RStatsUtils::getColumnIndexFromLabel(m_ui->m_cmbAuditedDataTable->currentText().toStdString());
        }
        else if (m_ui->m_rdbDifference->isChecked())
        {
            dfIndex.type = RStatsDataFormatType::Difference;
            dfIndex.primaryDatasetColumnIndex  = RStatsUtils::getColumnIndexFromLabel(m_ui->m_cmbDifferenceDataTable->currentText().toStdString());
        }
        else if (m_ui->m_rdbExamined->isChecked())
        {
            dfIndex.type = RStatsDataFormatType::Examine;
            dfIndex.primaryDatasetColumnIndex  = RStatsUtils::getColumnIndexFromLabel(m_ui->m_cmbExaminedDataTable->currentText().toStdString());
        }
        else if (m_ui->m_rdbAuditedAndDifference->isChecked())
        {
            dfIndex.type = RStatsDataFormatType::AuditAndDifference;
            dfIndex.secondaryDatasetColumnIndex  = RStatsUtils::getColumnIndexFromLabel(m_ui->m_cmbDifferenceDataTable->currentText().toStdString());
            dfIndex.primaryDatasetColumnIndex  = RStatsUtils::getColumnIndexFromLabel(m_ui->m_cmbAuditedDataTable->currentText().toStdString());
        }
        else if (m_ui->m_rdbExaminedAndDifference->isChecked())
        {
            dfIndex.type = RStatsDataFormatType::ExamineAndDifference;
            dfIndex.secondaryDatasetColumnIndex  = RStatsUtils::getColumnIndexFromLabel(m_ui->m_cmbDifferenceDataTable->currentText().toStdString());
            dfIndex.primaryDatasetColumnIndex  = RStatsUtils::getColumnIndexFromLabel(m_ui->m_cmbExaminedDataTable->currentText().toStdString());
        }
        else if (m_ui->m_rdbExaminedAndAudited->isChecked())
        {
            dfIndex.type = RStatsDataFormatType::ExamineAndAudit;
            dfIndex.secondaryDatasetColumnIndex  = RStatsUtils::getColumnIndexFromLabel(m_ui->m_cmbAuditedDataTable->currentText().toStdString());
            dfIndex.primaryDatasetColumnIndex  = RStatsUtils::getColumnIndexFromLabel(m_ui->m_cmbExaminedDataTable->currentText().toStdString());
        }
        m_dataFormatType = dfIndex.type;

        size_t dataSheetRowDataStart = static_cast<size_t>(m_ui->m_cmbDataRowStartDataTable->currentText().toInt() - 1);
        RStatsUVA uva;
        std::string auditName = m_ui->m_txtAuditName->text().toStdString();
        if (StringUtils::isEmpty(auditName))
        {
            auditName = m_ui->m_txtAuditName->placeholderText().toStdString();
        }
        uva.execute(auditName,universeSize,m_currentDataSheet,dataSheetRowDataStart,dfIndex);

        RStatsWorkbook output;
        uva.saveToWorkbook(output);

        //Merge all output sheets into one
        RStatsWorksheet worksheet = output.mergeSheets(RStatsWorkbookMergeDirection::MergeBottom,2);
        m_ui->m_txtOutput->setHtml(QString::fromStdString(worksheet.toHTMLTableString()));

        //Save CSV file (for Excel/Access) if applicable
        if (m_ui->m_chkCSVOutput->isChecked())
        {
            FileUtils::writeFileContents(m_currentCSVFileOutput.toStdString(),worksheet.toCommaDelimitedString());
        }

        //Save Text file, if applicable
        if (m_ui->m_chkTextOutput->isChecked())
        {
            FileUtils::writeFileContents(m_currentCSVFileOutput.toStdString(),worksheet.toEvenlySpacedString());
        }            

        m_clock.stop();
        m_ui->m_frmOutput->show();        
        m_ui->m_frmOutput->show();
        m_ui->m_lblNoData->hide();        

        //Save the session data
        RStatsUVASessionData sessionData = getSessionData();
        sessionData.setCreationDate(DateUtils::getCurrentDate());
        sessionData.setCreationTime(TimeUtils::getCurrentTime());
        m_recentSessionsMap[sessionData.getAuditName()] = RStatsModuleSessionDataPtr(new RStatsUVASessionData(sessionData));
        RStatsUtils::saveRecentSession(m_recentSessionsMap[sessionData.getAuditName()]);
        updateRecentSessions();


        //Show results in browser if selected
        if (m_ui->m_chkViewInBrowser->isChecked())
        {
            RStatsWorksheet worksheet = output.mergeSheets(RStatsWorkbookMergeDirection::MergeBottom,2);
            std::string htmlPath = FileUtils::buildFilePath(SystemUtils::getUserTempDirectory(), FileUtils::getRandomFileName(10,0)+".html");
            FileUtils::writeFileContents(htmlPath,worksheet.toHTMLTableString());
            QDesktopServices::openUrl(QString::fromStdString(htmlPath));
        }

    }
    catch (std::exception& e)
    {
        UIRStatsErrorMessage("Error occured while executing \""+this->windowTitle().toStdString()+"\"",
                             std::string(e.what()),false,this).exec();
        return;
    }
}

void UIRStatsUVA::onExit()
{
    this->close();
}

bool UIRStatsUVA::onValidate()
{
    m_conditionLogger.clear();
    m_ui->m_lstValidationConsole->clear();

    m_conditionLogger.addWarning((
                                   m_ui->m_rdbAuditedAndDifference->isChecked() ||
                                   m_ui->m_rdbExaminedAndAudited->isChecked()) &&
                                   m_ui->m_cmbAuditedDataTable->count() < 2,
                                   ("There are NOT enough columns for this 'audit' data format.\n Please choose another data format or import a different worksheet."));


    m_conditionLogger.addWarning((
                                   m_ui->m_rdbAuditedAndDifference->isChecked() ||
                                   m_ui->m_rdbExaminedAndDifference->isChecked()) &&
                                   m_ui->m_cmbAuditedDataTable->count() < 2,
                                   "There are NOT enough columns for this 'difference' data format.\n Please choose another data format or import a different worksheet.");

     m_conditionLogger.addError((m_tblPreview->rowCount() == 0),
                                "You have NOT imported any content rows into the data table.");

     m_conditionLogger.addError((m_tblPreview->columnCount() == 0),
                                "You have NOT imported any content columns into the data table.");

     m_conditionLogger.addWarning((!m_ui->m_chkCSVOutput->isChecked() && !m_ui->m_chkTextOutput->isChecked()),
                                "You have NOT selected an output file for the results.  Assuming screen display only.");

     m_conditionLogger.addWarning(m_ui->m_txtAuditName->text().isEmpty(),
                                  "You have NOT set the name for this audit.  Using auto-generated name: '"+m_ui->m_txtAuditName->placeholderText().toStdString()+"'");

     if (!m_conditionLogger.hasMessages())
     {
         if (!m_fullScreenToggle)
         {
            m_ui->m_dockValidationConsole->hide();
            //m_ui->m_lblErrorConsole->setVisible(true);
            m_ui->m_lstValidationConsole->setVisible(false);
         }


        m_ui->m_btnExecute->setEnabled(true);
        m_ui->actionExecute->setEnabled(true);
         return true;
     }
     if (!m_fullScreenToggle)
     {
        m_ui->m_dockValidationConsole->show();
        //m_ui->m_lblErrorConsole->setVisible(false);
        m_ui->m_lstValidationConsole->setVisible(true);
     }
     size_t index = 0;
     for(const std::string & message : m_conditionLogger.getMessages())
     {
         QListWidgetItem * item = new QListWidgetItem;
         item->setText(QString::fromStdString(message));
         if (m_conditionLogger.isError(index))
         {
             item->setIcon(m_iconError);
         }
         else if (m_conditionLogger.isWarning(index))
         {
             item->setIcon(m_iconWarning);
         }
         else
         {
             item->setIcon(m_iconOK);
         }
         ++index;
         m_ui->m_lstValidationConsole->addItem(item);
     }

     if (m_conditionLogger.hasError())
     {
         m_ui->m_btnExecute->setEnabled(false);         
         m_ui->actionExecute->setEnabled(false);
     }
     else
     {
         m_ui->m_btnExecute->setEnabled(true);
         m_ui->actionExecute->setEnabled(true);
     }
     return false;
}

RStatsUVASessionData UIRStatsUVA::getSessionData() const
{
    QString text = m_ui->m_txtAuditName->text();
    if (text.isEmpty())
    {
        text = m_ui->m_txtAuditName->placeholderText();
    }
    RStatsUVASessionData data;
    data.setAuditName(text.toStdString());
    data.setDataFormat(m_currentDataFormat);
    data.setUniverseSize(m_ui->m_spnUniverseSize->value());
    data.setDataRowStart(m_ui->m_cmbDataRowStartDataTable->currentText().toInt());
    data.setAuditColumn(m_ui->m_cmbAuditedDataTable->currentText().toStdString());
    data.setExamineColumn(m_ui->m_cmbExaminedDataTable->currentText().toStdString());
    data.setDifferenceColumn(m_ui->m_cmbDifferenceDataTable->currentText().toStdString());
    data.setDataTableSheetName(m_ui->m_cmbDataInputSheets->currentText().toStdString());
    data.setDataTableFilePath(m_dataTableImportFilePath.toStdString());
    data.setCSVOutputFile(m_currentCSVFileOutput.toStdString());
    data.setTextOutputFile(m_currentTextFileOutput.toStdString());
    data.setViewInBrowserFlag(m_ui->m_chkViewInBrowser->isChecked());
    return data;
}

void UIRStatsUVA::setSessionData(const RStatsUVASessionData& data)
{
    m_currentDataWorkbook.clear();
    m_currentDataSheet.setWorksheetTitle("Data Sheet");
    m_currentDataWorkbook.addWorksheet(m_currentDataSheet);
    m_ui->m_spnUniverseSize->setValue(static_cast<int>(data.getUniverseSize()));
    m_ui->m_chkViewInBrowser->setChecked(data.isViewableInBrowser());

    //set audit name
    std::string text = (data.getAuditName());
    if (StringUtils::isEmpty(text))
    {
        text = RStatsUtils::getAuditName();
    }
    m_ui->m_txtAuditName->setText(QString::fromStdString(text));
    if (FileUtils::fileExists(data.getDataTableFilePath()))
    {
        importDataTable(data.getDataTableFilePath());
    }
    else
    {
        UIRStatsErrorMessage("Could not load recently saved session...",
                             "The file located at \""+data.getDataTableFilePath()+"\" appears to be missing or in a read-only state.  Please manually import the file again before continuing.",false).exec();
        onValidate();
        return;
    }

    onUpdateRowColumnExtentsForDataTable();
    onSampleDataInputSheetSelected(m_currentDataSheet);

    if (!StringUtils::isEmpty(data.getDataTableSheetName()))
    {
        m_ui->m_cmbDataInputSheets->setCurrentText(QString::fromStdString(data.getDataTableSheetName()));
    }

    switch(data.getDataFormat())
    {
        case RStatsDataFormatType::Difference:m_ui->m_rdbDifference->setChecked(true);break;
        case RStatsDataFormatType::Examine:m_ui->m_rdbExamined->setChecked(true);break;
        case RStatsDataFormatType::AuditAndDifference:m_ui->m_rdbAuditedAndDifference->setChecked(true);break;
        case RStatsDataFormatType::ExamineAndAudit:m_ui->m_rdbExaminedAndAudited->setChecked(true);break;
        case RStatsDataFormatType::ExamineAndDifference:m_ui->m_rdbExaminedAndDifference->setChecked(true);break;
        case RStatsDataFormatType::Audit:m_ui->m_rdbAudited->setChecked(true);break;
    }

    m_ui->m_cmbAuditedDataTable->setCurrentText(QString::fromStdString(data.getAuditColumn()));
    m_ui->m_cmbExaminedDataTable->setCurrentText(QString::fromStdString(data.getExamineColumn()));
    m_ui->m_cmbDifferenceDataTable->setCurrentText(QString::fromStdString(data.getDifferenceColumn()));
    m_ui->m_cmbDataRowStartDataTable->setCurrentText(QString::number(data.getDataRowStart()));

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

void UIRStatsUVA::onClearRecentSessions()
{
    RStatsUtils::clearRecentSessions(c_RECENT_SESSION_EXTENSION);
    updateRecentSessions();
}

void UIRStatsUVA::onSaveTextFile()
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

void UIRStatsUVA::onSaveCSVFile()
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

void UIRStatsUVA::onRecentSessionSelected(QAction* action)
{
    std::string name = action->property("name").toString().toStdString();
    if (m_recentSessionsMap.count(name))
    {
        RStatsUVASessionData * data = dynamic_cast<RStatsUVASessionData*>(m_recentSessionsMap[name].get());
        setSessionData(*data);
    }
    onValidate();
}

void UIRStatsUVA::updateRecentSessions()
{
    std::pair<QActionGroup*,QAction*> actionPair=UIRStatsUtils::buildRecentSessions<RStatsUVASessionData>(
                                                 this,
                                                 m_ui->actionRecently_Used,
                                                 this->m_recentSessionsMap,
                                                 c_RECENT_SESSION_EXTENSION);


    if (actionPair.first && actionPair.second)
    {
        connect(actionPair.first,SIGNAL(triggered(QAction*)),this,SLOT(onRecentSessionSelected(QAction*)));
        connect(actionPair.second,SIGNAL(triggered(bool)),this,SLOT(onClearRecentSessions()));
    }

}

void UIRStatsUVA::setTextFileOutput(const std::string& textFile)
{
    m_currentTextFileOutput = QString::fromStdString(textFile);
    if (!m_currentTextFileOutput.isEmpty())
    {
        if (m_currentTextFileOutputLabel == nullptr)
        {
            m_currentTextFileOutputLabel = new QLabel;
            //connect(m_currentTextFileOutputLabel,SIGNAL(clicked(bool)),this,SLOT(onLaunchTextOutputProgram()));
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

void UIRStatsUVA::setCSVFileOutput(const std::string& csvFile)
{
    m_currentCSVFileOutput = QString::fromStdString(csvFile);
    if (!m_currentCSVFileOutput.isEmpty())
    {
        if (m_currentCSVFileOutputLabel == nullptr)
        {
            m_currentCSVFileOutputLabel = new QLabel;
            //connect(m_currentCSVFileOutputLabel,SIGNAL(clicked(bool)),this,SLOT(onLaunchCSVOutputProgram()));
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


void UIRStatsUVA::resizeEvent(QResizeEvent *)
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

