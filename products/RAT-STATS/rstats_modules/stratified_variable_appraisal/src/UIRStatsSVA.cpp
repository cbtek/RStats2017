/*
    UIRStatsSVA.cpp
    

*/
//UIRStatsSVA.cpp generated by CBTek Solutions on 01-28-2017 at 10:39:41 PM

#include "UIRStatsSVA.h"
#include "ui_UIRStatsSVA.h"
#include "RStatsSVA.h"

#include <QFileDialog>


#include "rstats_ui/inc/UIRStatsAbout.h"
#include "rstats_ui/inc/UIRStatsUtils.hpp"
#include "rstats_ui/inc/UIRStatsImportWorksheet.h"
#include "rstats_ui/inc/UIRStatsErrorMessage.h"

#include "rstats_utils/inc/RStatsWorkbookStreamFactory.h"

#include "utility/inc/DateTimeUtils.hpp"

using namespace cbtek::common::utility;
using namespace oig::ratstats::ui;
using namespace oig::ratstats::utils;

namespace oig {
namespace ratstats {
namespace modules {
namespace sva {


UIRStatsSVA::UIRStatsSVA(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui_UIRStatsSVA)
{
    m_ui->setupUi(this);       

    //Set shortcut for File/Help menu
    m_ui->menuFile->setTitle("&File");
    m_ui->menuHelp->setTitle("&Help");

    //Disable fullscreen
    m_fullScreenToggle = false;

    //Set audit name text to default
    m_ui->m_txtAuditName->setPlaceholderText(QString::fromStdString(RStatsUtils::getAuditName()));

    //Set the CSV/Text file output labels to null
    m_currentCSVFileOutputLabel = nullptr;
    m_currentTextFileOutputLabel = nullptr;

    m_ui->m_dockOptions->setTitleBarWidget(new QWidget());

    //Load icons used by validation console
    m_iconError = UIRStatsUtils::getIcon("img_error.png");
    m_iconOK = UIRStatsUtils::getIcon("img_ok.png");
    m_iconWarning = UIRStatsUtils::getIcon("img_warning.png");

    m_currentDataFormat = RStatsDataFormatType::Examine;

    //Initialize button/action elements
    int buttonHeight = 32;

    UIRStatsUtils::initButton(m_ui->m_btnImportSampleInputData, "img_folder.png");
    UIRStatsUtils::initButton(m_ui->m_btnImportSampleSizeData, "img_folder.png");
    UIRStatsUtils::initButton(m_ui->m_btnExecute, "img_run.png");
    UIRStatsUtils::initButton(m_ui->m_btnExit, "img_exit.png");
    UIRStatsUtils::initButton(m_ui->m_btnHelp, "img_help.png");
    UIRStatsUtils::initAction(m_ui->actionAbout,"img_about.png","Alt+A");
    UIRStatsUtils::initAction(m_ui->actionExecute,"img_run.png","Alt+R");
    UIRStatsUtils::initAction(m_ui->actionExit,"img_exit.png","Alt+Q");
    UIRStatsUtils::initAction(m_ui->actionHelp,"img_help.png","Alt+H");
    UIRStatsUtils::initAction(m_ui->actionRecently_Used,"img_clock.png","Alt+S");


    //Initialize worksheet combo boxes
    m_ui->m_cmbDataInputSheets->addItem("No Sheets Available");
    m_ui->m_cmbSizeInputSheets->addItem("No Sheets Available");
    m_ui->m_cmbDataInputSheets->setEnabled(false);
    m_ui->m_cmbSizeInputSheets->setEnabled(false);

    //Create connections for UI/View elements
    connect(m_ui->actionExecute,SIGNAL(triggered(bool)),this,SLOT(onExecute()));
    connect(m_ui->actionExit,SIGNAL(triggered(bool)),this,SLOT(onExit()));
    connect(m_ui->actionHelp,SIGNAL(triggered(bool)),this,SLOT(onHelp()));
    connect(m_ui->actionAbout,SIGNAL(triggered(bool)),this,SLOT(onAbout()));
    connect(m_ui->m_chkTextOutput,SIGNAL(toggled(bool)),this,SLOT(onSaveTextFile()));
    connect(m_ui->m_chkCSVOutput,SIGNAL(toggled(bool)),this,SLOT(onSaveCSVFile()));
    connect(m_ui->m_btnImportSampleInputData,SIGNAL(clicked(bool)),this,SLOT(onImportDataInput()));
    connect(m_ui->m_btnImportSampleSizeData,SIGNAL(clicked(bool)),this,SLOT(onImportSizeInput()));
    connect(m_ui->m_btnHelp,SIGNAL(clicked(bool)),this,SLOT(onHelp()));
    connect(m_ui->m_btnExit,SIGNAL(clicked(bool)),this,SLOT(onExit()));
    connect(m_ui->m_btnExecute,SIGNAL(clicked(bool)),this,SLOT(onExecute()));    
    connect(m_ui->m_cmbDataInputSheets,SIGNAL(currentIndexChanged(int)),this,SLOT(onComboDataInputSheetSelected(int)));
    connect(m_ui->m_cmbSizeInputSheets,SIGNAL(currentIndexChanged(int)),this,SLOT(onComboSizeInputSheetSelected(int)));
    connect(&m_clock,SIGNAL(timeout()),this,SLOT(onUpdateClock()));    
    connect(m_ui->m_rdbAudited,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatSelection()));
    connect(m_ui->m_rdbExamined,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatSelection()));
    connect(m_ui->m_rdbDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatSelection()));
    connect(m_ui->m_rdbAuditedAndDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatSelection()));
    connect(m_ui->m_rdbExaminedAndAudited,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatSelection()));
    connect(m_ui->m_rdbExaminedAndDifference,SIGNAL(toggled(bool)),this,SLOT(onUpdateDataFormatSelection()));    

    //Enable the Examined data format as default
    m_ui->m_rdbExamined->setChecked(true);

    //Hide the output window
    m_ui->m_grpOutput->hide();

    //Update recently used
    updateRecentSessions();

    //Start the internal clock
    m_clock.start(1000);    
    onUpdateClock();
}

UIRStatsSVA::~UIRStatsSVA()
{
    delete m_ui;
}

void UIRStatsSVA::keyPressEvent(QKeyEvent *evt)
{
    if (evt->key() == Qt::Key_F11)
    {
        onToggleFullScreen();
    }
}

void UIRStatsSVA::populateWithColumns(const std::set<size_t>& columns,
                                      QComboBox *comboBox)
{
    comboBox->clear();
    for(const auto& column : columns)
    {
        std::string label = RStatsUtils::getColumnLabelFromIndex(column);
        comboBox->addItem(QString::fromStdString(label));
    }
}

void UIRStatsSVA::populateWithRows(const std::set<size_t>& rows,
                                   QComboBox *comboBox)
{
    comboBox->clear();
    for(const auto& row : rows)
    {
        comboBox->addItem(QString::number(row + 1));
    }
}

void UIRStatsSVA::onUpdateRowColumnExtentsForDataTable()
{
    std::set<size_t> rows,cols;
    m_currentDataSheet.findDataRowsAndColumns(rows,cols);
    populateWithColumns(cols,m_ui->m_cmbAuditedDataTable);
    populateWithColumns(cols,m_ui->m_cmbExaminedDataTable);
    populateWithColumns(cols,m_ui->m_cmbDifferenceDataTable);
    populateWithRows(rows,m_ui->m_cmbDataRowStartDataTable);
}

void UIRStatsSVA::onUpdateRowColumnExtentsForSizeTable()
{
    std::set<size_t> rows,cols;
    m_currentSizeSheet.findDataRowsAndColumns(rows,cols);
    populateWithColumns(cols,m_ui->m_cmbSampleCountSizeTable);
    populateWithColumns(cols,m_ui->m_cmbUniverseCountSizeTable);
    populateWithRows(rows,m_ui->m_cmbDataRowStartSizeTable);
}

bool UIRStatsSVA::onValidate()
{
    m_conditionLogger.clear();
    m_ui->m_lstErrorConsole->clear();
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

     m_conditionLogger.addError((m_ui->m_tblData->rowCount() == 0),
                                "You have NOT created/imported any content rows into the data table.");

     m_conditionLogger.addError((m_ui->m_tblSizes->rowCount() == 0),
                                "You have NOT created/imported any content rows into the universe/sample size table.");

     m_conditionLogger.addError((m_ui->m_tblData->columnCount() == 0),
                                "You have NOT created/imported any content columns into the data table.");

     m_conditionLogger.addError((m_ui->m_tblSizes->columnCount() == 0),
                                "You have NOT created/imported any content columns into the universe/sample size table.");

     m_conditionLogger.addWarning((!m_ui->m_chkCSVOutput->isChecked() && !m_ui->m_chkTextOutput->isChecked()),
                                "You have NOT selected an output file for the results.  Assuming screen display only.");

     m_conditionLogger.addWarning(m_ui->m_txtAuditName->text().isEmpty(),
                                  "You have NOT set the name for this audit.  Using auto-generated name: '"+m_ui->m_txtAuditName->placeholderText().toStdString()+"'");


     if (!m_conditionLogger.hasMessages())
     {         
         if (!m_fullScreenToggle)
         {
            m_ui->m_dockErrorConsole->hide();
            m_ui->m_lblErrorConsole->setVisible(true);
            m_ui->m_lstErrorConsole->setVisible(false);
         }


         m_ui->m_btnExecute->setEnabled(true);
         m_ui->actionExecute->setEnabled(true);
         return true;
     }     
     if (!m_fullScreenToggle)
     {
        m_ui->m_dockErrorConsole->show();
        m_ui->m_lblErrorConsole->setVisible(false);
        m_ui->m_lstErrorConsole->setVisible(true);
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
         m_ui->m_lstErrorConsole->addItem(item);
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

void UIRStatsSVA::onSampleSizeInputSheetSelected(const RStatsWorksheet &sheet)
{    
    UIRStatsUtils::bindSheetToUI(sheet,m_ui->m_tblSizes,true,0,0);
    m_currentSizeSheet = sheet;
    onUpdateRowColumnExtentsForSizeTable();
    m_ui->m_tblSizes->verticalHeader()->show();
}

void UIRStatsSVA::onSampleDataInputSheetSelected(const RStatsWorksheet &sheet)
{
    UIRStatsUtils::bindSheetToUI(sheet,m_ui->m_tblData,true,0,0);
    m_currentDataSheet = sheet;
    onUpdateRowColumnExtentsForDataTable();
    m_ui->m_tblData->verticalHeader()->show();
}

void UIRStatsSVA::onComboSizeInputSheetSelected(int row)
{
    if (row < 0)
    {
        return;
    }
    size_t index = static_cast<size_t>(row);
    if (index < m_currentSizeWorkbook.getNumWorksheets())
    {
        RStatsWorksheet sheet = m_currentSizeWorkbook(index);        
        onSampleSizeInputSheetSelected(sheet);
    }
}

void UIRStatsSVA::onComboDataInputSheetSelected(int row)
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

void UIRStatsSVA::onUpdateClock()
{    
    onValidate();
}

void UIRStatsSVA::onExecute()
{
    try
    {
        //Update validation console
        onValidate();

        //Setup the dataformat index
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

        //Save the offsets for data sheet and size sheet
        size_t sizeSheetSampleColumn = RStatsUtils::getColumnIndexFromLabel(m_ui->m_cmbSampleCountSizeTable->currentText().toStdString());
        size_t sizeSheetUniverseColumn = RStatsUtils::getColumnIndexFromLabel(m_ui->m_cmbUniverseCountSizeTable->currentText().toStdString());
        size_t sizeSheetRowDataStart = static_cast<size_t>(m_ui->m_cmbDataRowStartSizeTable->currentText().toInt() - 1);
        size_t dataSheetRowDataStart = static_cast<size_t>(m_ui->m_cmbDataRowStartDataTable->currentText().toInt() - 1);
        RStatsSVA sva;

        //Set the audit name
        std::string auditName = m_ui->m_txtAuditName->text().toStdString();
        if (StringUtils::isEmpty(auditName))
        {
            auditName = m_ui->m_txtAuditName->placeholderText().toStdString();
        }

        //Execute the stratified variable appraisal function
        sva.execute(auditName,
                  m_currentDataSheet,
                  m_currentSizeSheet,
                  dfIndex,
                  dataSheetRowDataStart,
                  sizeSheetSampleColumn,
                  sizeSheetUniverseColumn,
                  sizeSheetRowDataStart);

        //Save output of function to workbook object
        RStatsWorkbook workbook;
        sva.saveToWorkbook(workbook);

        //Initialize workbook control
        QLayoutItem *item;
        while ((item = m_ui->m_grpOutput->layout()->takeAt(0)))
        {
            delete item;
        }
        m_outputWorkbook = new UIRStatsWorkbook;
        m_ui->m_grpOutput->layout()->addWidget(m_outputWorkbook);
        m_outputWorkbook->setWorkbook(workbook);
        m_outputWorkbook->onStretchToContents();
        m_outputWorkbook->onHideGridLines();
        m_ui->m_lblNoData->hide();
        m_ui->m_grpOutput->show();

        //Save output formats if selected
        if (!StringUtils::isEmpty(m_currentTextFileOutput.toStdString()))
        {
            workbook.save(m_currentTextFileOutput.toStdString());
        }

        if (!StringUtils::isEmpty(m_currentCSVFileOutput.toStdString()))
        {
            workbook.save(m_currentCSVFileOutput.toStdString());
        }

        //Display results in full screen
        onToggleFullScreen();

        //Set session data
        RStatsSVASessionData sessionData = getSessionData();
        sessionData.setCreationDate(DateUtils::getCurrentDate().toDateInteger());
        sessionData.setCreationTime(TimeUtils::getCurrentTime().toTimeInteger());
        m_recentSessionsMap[sessionData.getAuditName()]=RStatsModuleSessionDataPtr(new RStatsSVASessionData(sessionData));
        RStatsUtils::saveRecentSession(m_recentSessionsMap[sessionData.getAuditName()]);
        updateRecentSessions();


        //Show results in browser if selected
        if (m_ui->m_chkViewInBrowser->isChecked())
        {
            RStatsWorksheet worksheet = workbook.mergeSheets(RStatsWorkbookMergeDirection::MergeBottom,2);
            std::string htmlPath = FileUtils::buildFilePath(SystemUtils::getUserTempDirectory(), FileUtils::getRandomFileName(10,0)+".html");
            FileUtils::writeFileContents(htmlPath,worksheet.toHTMLTableString());
            UIRStatsUtils::desktopOpen(htmlPath);
        }
    }
    catch (std::exception& e)
    {
        UIRStatsErrorMessage("Error occured while executing \""+this->windowTitle().toStdString()+"\"",
                             std::string(e.what()),false,this).exec();
        return;
    }
}

void UIRStatsSVA::onExit()
{
    if (m_fullScreenToggle)
    {
        onToggleFullScreen();
    }
    else
    {
        this->close();
    }
}

void UIRStatsSVA::onToggleFullScreen()
{
    m_fullScreenToggle = !m_fullScreenToggle;
    if (m_fullScreenToggle)
    {
        m_ui->m_dockErrorConsole->hide();
        m_ui->m_dockOptions->hide();
        m_ui->m_dockSampleDataInput->hide();
        m_ui->m_dockSampleSizeInput->hide();
        m_ui->m_btnHelp->hide();
        m_ui->m_btnExecute->hide();
        m_ui->m_btnExit->setText("Click here or press F11 to exit full-screen mode");
        m_ui->m_grpOutput->setTitle("Output Data (Press F11 to exit full-screen mode)");
        this->setWindowState(Qt::WindowMaximized);
    }
    else
    {
        m_ui->m_dockErrorConsole->show();
        m_ui->m_dockOptions->show();
        m_ui->m_dockSampleDataInput->show();
        m_ui->m_dockSampleSizeInput->show();
        m_ui->m_frmCommand->show();
        m_ui->m_grpOutput->setTitle("Output Data:");
        m_ui->m_btnHelp->show();
        m_ui->m_btnExecute->show();
        m_ui->m_btnExit->setText("Exit");
    }
}

void UIRStatsSVA::importDataTable(const std::string &dataTableFilePath)
{
    // make sure the data table file exists
    if (StringUtils::isEmpty(dataTableFilePath) || !FileUtils::fileExists(dataTableFilePath))
    {
        return;
    }

    m_dataTableImportFilePath = QString::fromStdString(dataTableFilePath);
    m_ui->m_cmbDataInputSheets->clear();

    //Load the data table and populate worksheet control
    try
    {
        std::string filePath = m_dataTableImportFilePath.toStdString();
        m_currentDataWorkbook.load(filePath);
        if (m_currentDataWorkbook.getNumWorksheets() == 0)
        {
            THROW_GENERIC_EXCEPTION("No worksheets were found in \""+filePath+"\"")
        }
        m_ui->m_cmbDataInputSheets->setEnabled(true);
        bool setOther = false;
        if (m_currentSizeWorkbook.getNumWorksheets() == 0)
        {
            setOther = true;
            m_sizeTableImportFilePath = m_dataTableImportFilePath;
            m_currentSizeWorkbook = m_currentDataWorkbook;
        }

        std::vector<std::string> worksheetNames = m_currentDataWorkbook.getWorksheetNames();
        if (setOther)
        {
            m_ui->m_cmbSizeInputSheets->clear();
            m_ui->m_cmbSizeInputSheets->setEnabled(true);
        }
        for(const auto& sheetName : worksheetNames)
        {
            if (setOther)
            {
                m_ui->m_cmbSizeInputSheets->addItem(QString::fromStdString(sheetName));
            }
            m_ui->m_cmbDataInputSheets->addItem(QString::fromStdString(sheetName));
        }
        onUpdateRowColumnExtentsForDataTable();
    }
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

void UIRStatsSVA::importSizeTable(const std::string &sizeTableFilePath)
{
    if (StringUtils::isEmpty(sizeTableFilePath) || !FileUtils::fileExists(sizeTableFilePath))
    {
        return;
    }
    m_sizeTableImportFilePath = QString::fromStdString(sizeTableFilePath);
    m_ui->m_cmbSizeInputSheets->clear();
    try
    {
        std::string filePath = m_sizeTableImportFilePath.toStdString();
        m_currentSizeWorkbook.load(filePath);
        if (m_currentSizeWorkbook.getNumWorksheets() == 0)
        {
            THROW_GENERIC_EXCEPTION("No worksheets were found in \""+filePath+"\"")
        }
        m_ui->m_cmbSizeInputSheets->setEnabled(true);
        bool setOther = false;
        if (m_currentDataWorkbook.getNumWorksheets() == 0)
        {
            setOther = true;
            m_dataTableImportFilePath = m_sizeTableImportFilePath;
            m_currentDataWorkbook = m_currentSizeWorkbook;
        }

        std::vector<std::string> worksheetNames = m_currentSizeWorkbook.getWorksheetNames();

        if (setOther)
        {
            m_ui->m_cmbDataInputSheets->clear();
            m_ui->m_cmbDataInputSheets->setEnabled(true);
        }

        for(const auto& sheetName : worksheetNames)
        {
            if (setOther)
            {
                m_ui->m_cmbDataInputSheets->addItem(QString::fromStdString(sheetName));
            }
            m_ui->m_cmbSizeInputSheets->addItem(QString::fromStdString(sheetName));
        }
        onUpdateRowColumnExtentsForSizeTable();
    }
    catch(const std::exception& exception)
    {
        m_ui->m_cmbSizeInputSheets->addItem("No Sheets Available");
        m_ui->m_cmbSizeInputSheets->setEnabled(false);
        QString title = "Error occured trying to import " + m_sizeTableImportFilePath;
        QString message = QString(exception.what());
        UIRStatsErrorMessage(title,message).exec();
        return;
    }
}
void UIRStatsSVA::onImportDataInput()
{
    m_dataTableImportFilePath = QFileDialog::getOpenFileName(this,"Import Stratified Variable Appraisal Sample Input File...","","Supported Input Files(*.csv *.xlsx *.dif)");
    if (!m_dataTableImportFilePath.isEmpty() && QFile::exists(m_dataTableImportFilePath))
    {
        importDataTable(m_dataTableImportFilePath.toStdString());
    }
}

void UIRStatsSVA::onImportSizeInput()
{
    m_sizeTableImportFilePath = QFileDialog::getOpenFileName(this,"Import Stratified Variable Appraisal Universe/Sample Size Input File...","","Supported Input Files(*.csv *.xlsx *.dif)");
    if (!m_sizeTableImportFilePath.isEmpty() && QFile::exists(m_sizeTableImportFilePath))
    {
       importSizeTable(m_sizeTableImportFilePath.toStdString());
    }
}


void UIRStatsSVA::onHelp()
{
    QString url = QString::fromStdString(FileUtils::buildFilePath(SystemUtils::getCurrentExecutableDirectory(),"rstats_help/rstats_sva.pdf"));
    if (!QFile::exists(url))
    {
        UIRStatsErrorMessage("Could not load help file","Could not open the help file located at \"" + url.toStdString() + "\"",false,this).exec();
    }
    else
    {
        UIRStatsUtils::desktopOpen(url.toStdString());
    }
}

void UIRStatsSVA::onAbout()
{
    UIRStatsAbout().exec();
}


void UIRStatsSVA::onUpdateDataFormatSelection()
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

RStatsSVASessionData UIRStatsSVA::getSessionData() const
{
    QString text = m_ui->m_txtAuditName->text();
    if (text.isEmpty())
    {
        text = m_ui->m_txtAuditName->placeholderText();
    }
    RStatsSVASessionData data;
    data.setAuditName(text.toStdString());
    data.setAuditColumn(m_ui->m_cmbAuditedDataTable->currentText().toStdString());
    data.setExamineColumn(m_ui->m_cmbExaminedDataTable->currentText().toStdString());
    data.setDifferenceColumn(m_ui->m_cmbDifferenceDataTable->currentText().toStdString());
    data.setSampleColumn(m_ui->m_cmbSampleCountSizeTable->currentText().toStdString());
    data.setUniverseColumn(m_ui->m_cmbUniverseCountSizeTable->currentText().toStdString());
    data.setDataFormat(m_dataFormatType);
    data.setDataTableRowStart(m_ui->m_cmbDataRowStartDataTable->currentText().toInt());
    data.setSizeTableRowStart(m_ui->m_cmbDataRowStartSizeTable->currentText().toInt());
    data.setDataTableFilePath(m_dataTableImportFilePath.toStdString());
    data.setSizeTableFilePath(m_sizeTableImportFilePath.toStdString());
    data.setCSVOutputFile(m_currentCSVFileOutput.toStdString());
    data.setTextOutputFile(m_currentTextFileOutput.toStdString());
    data.setSizeTableSheetName(m_ui->m_cmbSizeInputSheets->currentText().toStdString());
    data.setDataTableSheetName(m_ui->m_cmbDataInputSheets->currentText().toStdString());
    data.setViewInBrowserFlag(m_ui->m_chkViewInBrowser->isChecked());
    return data;
}

void UIRStatsSVA::setSessionData(const RStatsSVASessionData &data)
{
    std::string text = (data.getAuditName());
    if (StringUtils::isEmpty(text))
    {
        text = RStatsUtils::getAuditName();
    }
    m_ui->m_chkViewInBrowser->setChecked(data.isViewableInBrowser());
    m_ui->m_txtAuditName->setText(QString::fromStdString(text));
    m_currentDataWorkbook.clear();
    m_currentSizeWorkbook.clear();
    m_currentDataSheet.setWorksheetTitle("Data Sheet");
    m_currentSizeSheet.setWorksheetTitle("Size Sheet");
    m_currentDataWorkbook.addWorksheet(m_currentDataSheet);
    m_currentSizeWorkbook.addWorksheet(m_currentSizeSheet);
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

    if (FileUtils::fileExists(data.getSizeTableFilePath()))
    {
        importSizeTable(data.getSizeTableFilePath());
    }
    else
    {
        UIRStatsErrorMessage("Could not load recently saved session...",
                             "The file located at \""+data.getSizeTableFilePath()+"\" appears to be missing or in a read-only state.  Please manually import the file again before continuing.",false).exec();
        onValidate();
        return;
    }
    onUpdateRowColumnExtentsForDataTable();
    onUpdateRowColumnExtentsForSizeTable();
    onSampleDataInputSheetSelected(m_currentDataSheet);
    onSampleSizeInputSheetSelected(m_currentSizeSheet);

    if (!StringUtils::isEmpty(data.getDataTableSheetName()))
    {
        m_ui->m_cmbDataInputSheets->setCurrentText(QString::fromStdString(data.getDataTableSheetName()));
    }

    if (!StringUtils::isEmpty(data.getSizeTableSheetName()))
    {
        m_ui->m_cmbSizeInputSheets->setCurrentText(QString::fromStdString(data.getSizeTableSheetName()));
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
    m_ui->m_cmbDataRowStartDataTable->setCurrentText(QString::number(data.getDataTableRowStart()));
    m_ui->m_cmbDataRowStartSizeTable->setCurrentText(QString::number(data.getSizeTableRowStart()));
    m_ui->m_cmbSampleCountSizeTable->setCurrentText(QString::fromStdString(data.getSampleColumn()));
    m_ui->m_cmbUniverseCountSizeTable->setCurrentText(QString::fromStdString(data.getUniverseColumn()));

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

void UIRStatsSVA::onClearRecentSessions()
{
    RStatsUtils::clearRecentSessions(c_RECENT_SESSION_EXTENSION);
    updateRecentSessions();
}

void UIRStatsSVA::onSaveTextFile()
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

void UIRStatsSVA::onSaveCSVFile()
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

void UIRStatsSVA::onRecentSessionSelected(QAction* action)
{
    std::string name = action->property("name").toString().toStdString();
    if (m_recentSessionsMap.count(name))
    {
        RStatsSVASessionData * data = dynamic_cast<RStatsSVASessionData*>(m_recentSessionsMap[name].get());
        setSessionData(*data);
    }
}

void UIRStatsSVA::updateRecentSessions()
{
    std::pair<QActionGroup*,QAction*> actionPair=UIRStatsUtils::buildRecentSessions<RStatsSVASessionData>(
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
void UIRStatsSVA::setTextFileOutput(const std::string& textFile)
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

void UIRStatsSVA::setCSVFileOutput(const std::string& csvFile)
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


void UIRStatsSVA::resizeEvent(QResizeEvent *)
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

