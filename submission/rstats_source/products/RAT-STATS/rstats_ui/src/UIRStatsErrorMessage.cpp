/*
    UIRStatsErrorMessage.cpp
    

*/
//UIRStatsErrorMessage.cpp generated by CBTek Solutions on 02-04-2017 at 01:21:08 PM

#include "UIRStatsErrorMessage.h"
#include "ui_UIRStatsErrorMessage.h"

#include <QFileDialog>
#include <QApplication>

#include "UIRStatsUtils.hpp"

#include "utility/inc/FileUtils.hpp"

using namespace cbtek::common::utility;

namespace oig {
namespace ratstats {
namespace ui {


UIRStatsErrorMessage::UIRStatsErrorMessage(QString &title, QString &message, bool exitApplication, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui_UIRStatsErrorMessage)
{
    m_ui->setupUi(this);
    onInit(title,message);
    m_exitApplication = exitApplication;    
}

UIRStatsErrorMessage::UIRStatsErrorMessage(const std::string &title, const std::string &message, bool exitApplication, QWidget *parent):
    QDialog(parent),
    m_ui(new Ui_UIRStatsErrorMessage)
{
    m_ui->setupUi(this);
    m_exitApplication = exitApplication;
    onInit(QString::fromStdString(title),
           QString::fromStdString(message));
}


void UIRStatsErrorMessage::onInit(const QString & title, const QString & message)
{
    m_ui->m_txtErrorMessage->setText(message);
    this->setWindowTitle(title);
    m_ui->m_btnCopy->setIcon(UIRStatsUtils::getIcon("img_copy.png"));
    m_ui->m_btnSave->setIcon(UIRStatsUtils::getIcon("img_save.png"));
    m_ui->m_btnOk->setIcon(UIRStatsUtils::getIcon("img_ok.png"));
    connect(m_ui->m_btnOk,SIGNAL(clicked(bool)),this,SLOT(onOk()));
    connect(m_ui->m_btnCopy,SIGNAL(clicked(bool)),this,SLOT(onCopy()));
    connect(m_ui->m_btnSave,SIGNAL(clicked(bool)),this,SLOT(onSave()));
}

UIRStatsErrorMessage::~UIRStatsErrorMessage()
{
    delete m_ui;
}

void UIRStatsErrorMessage::onOk()
{
    this->close();
    if (m_exitApplication)
    {
        qApp->exit(-1);
    }
}

void UIRStatsErrorMessage::onSave()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Save Error Message...", "" , "*.txt");
    if (!filePath.trimmed().isEmpty())
    {
        FileUtils::writeFileContents(filePath.toStdString(),m_ui->m_txtErrorMessage->toPlainText().toStdString());
    }
}

void UIRStatsErrorMessage::onCopy()
{
    m_ui->m_txtErrorMessage->selectAll();
    m_ui->m_txtErrorMessage->copy();
}


}}}//end namespace

