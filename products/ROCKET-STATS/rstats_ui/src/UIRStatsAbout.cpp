/*
    UIRStatsAbout.cpp
    

*/
//UIRStatsAbout.cpp generated by CBTek Solutions on 02-03-2017 at 02:12:08 AM

#include "UIRStatsAbout.h"
#include "ui_UIRStatsAbout.h"

#include "UIRStatsUtils.hpp"

#include "utility/inc/SystemUtils.hpp"
#include "utility/inc/FileUtils.hpp"

using namespace cbtek::common::utility;

namespace cbtek {
namespace rocketstats {
namespace ui {


UIRStatsAbout::UIRStatsAbout(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui_UIRStatsAbout)
{
    m_ui->setupUi(this);
    connect(m_ui->m_btnOK,SIGNAL(clicked(bool)),this,SLOT(onOK()));        
    UIRStatsUtils::initButton(m_ui->m_btnOK,"img_ok.png");
    m_ui->m_lblRStatsLogo->setPixmap(UIRStatsUtils::getPixmap("img_logo_background.png"));
    m_ui->m_lblTeamCBTekLogo->setPixmap(UIRStatsUtils::getPixmap("img_team_cbtek_logo_round.png"));
}


UIRStatsAbout::~UIRStatsAbout()
{
    delete m_ui;
}

void UIRStatsAbout::onOK()
{
    this->close();
}
}}}//end namespace
