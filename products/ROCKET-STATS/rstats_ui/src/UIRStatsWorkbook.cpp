/*
    UIRStatsWorkbook.cpp
    

*/
//UIRStatsWorkbook.cpp generated by CBTek Solutions on 02-02-2017 at 12:51:01 AM

#include "UIRStatsWorkbook.h"
#include "ui_UIRStatsWorkbook.h"
#include <QTextBrowser>

#include "UIRStatsUtils.hpp"

namespace cbtek {
namespace rocketstats {
namespace ui {

using namespace cbtek::rocketstats::utils;

UIRStatsWorkbook::UIRStatsWorkbook(QWidget *parent) : QWidget(parent),m_ui(new Ui_UIRStatsWorkbook)
{
    m_ui->setupUi(this);
}

UIRStatsWorkbook::UIRStatsWorkbook(const RStatsWorkbook &workbook, QWidget *parent): QWidget(parent),m_ui(new Ui_UIRStatsWorkbook)
{
    m_ui->setupUi(this);
    setWorkbook(workbook);
}

void UIRStatsWorkbook::setWorkbook(const RStatsWorkbook &workbook)
{            
    clear();
    m_workbook = workbook;
    for (const auto& sheet : m_workbook.getWorksheets())
    {
        QTextBrowser *table = new QTextBrowser;
        table->setHtml(QString::fromStdString(sheet.toHTMLTableString()));
        //UIRStatsUtils::bindSheetToUI(sheet,table);
        m_ui->m_tabWorkbook->addTab(table,QString::fromStdString(sheet.getWorksheetTitle()));
        //table->resizeColumnsToContents();
        //table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
    if (m_ui->m_tabWorkbook->count() > 0)
    {
        m_ui->m_tabWorkbook->setCurrentIndex(0);
    }
}

void UIRStatsWorkbook::clear()
{
    //Loop from back and remove all tabs
    int count = m_ui->m_tabWorkbook->count();
    for (int a1 = count - 1; a1 >= 0; --a1)
    {
        QWidget * widget = m_ui->m_tabWorkbook->widget(a1);
        if (widget)
        {
            delete widget;
        }
        m_ui->m_tabWorkbook->removeTab(a1);
    }   
}

UIRStatsWorkbook::~UIRStatsWorkbook()
{
    delete m_ui;
}
}}}//end namespace

