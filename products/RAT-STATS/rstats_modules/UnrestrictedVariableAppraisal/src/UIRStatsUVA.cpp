/*
    UIRStatsUVA.cpp
    

*/
//UIRStatsUVA.cpp generated by CBTek Solutions on 02-06-2017 at 11:18:47 AM

#include "UIRStatsUVA.h"
#include "ui_UIRStatsUVA.h"

namespace oig {
namespace ratstats {
namespace modules {
namespace uva {


UIRStatsUVA::UIRStatsUVA(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui_UIRStatsUVA)
{
    m_ui->setupUi(this);
}


UIRStatsUVA::~UIRStatsUVA()
{
    delete m_ui;
}
}}}}//end namespace
