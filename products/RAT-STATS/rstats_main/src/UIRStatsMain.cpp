/*
    UIRStatsMain.cpp
    

*/
//UIRStatsMain.cpp generated by CBTek Solutions on 02-03-2017 at 12:29:37 AM

#include <QIcon>
#include <QGroupBox>
#include <QPushButton>
#include <QScrollArea>
#include <QFontMetrics>
#include <QLabel>
#include <QProcess>

#include "UIRStatsMain.h"
#include "ui_UIRStatsMain.h"

#include "utility/inc/XMLReader.h"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/SystemUtils.hpp"

#include "rstats_ui/inc/UIRStatsSettingsManager.h"
#include "rstats_utils/inc/RStatsSettingsManager.h"
#include "rstats_utils/inc/RStatsModuleProperties.h"
#include "rstats_utils/inc/RStatsUtils.hpp"

#include "UIRStatsAbout.h"
#include "UIRStatsModuleEditor.h"
#include "UIRStatsModuleManager.h"

using namespace cbtek::common::utility;

using namespace oig::ratstats::ui;
using namespace oig::ratstats::utils;

namespace oig {
namespace ratstats {
namespace main {

UIRStatsMain::UIRStatsMain(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui_UIRStatsMain)
{
    m_ui->setupUi(this);            
    onInitialize();
    connect(m_ui->m_actionExit,SIGNAL(triggered(bool)),this,SLOT(onExit()));
    connect(m_ui->m_actionSettings_Manager,SIGNAL(triggered(bool)),this,SLOT(onLaunchSettingsManager()));
    connect(m_ui->m_actionAbout_RAT_STATS_2017,SIGNAL(triggered(bool)),this,SLOT(onLaunchAbout()));
    connect(m_ui->m_actionModule_Manager,SIGNAL(triggered(bool)),this,SLOT(onLaunchModuleManager()));

    connect(m_ui->m_lstModules,SIGNAL(currentRowChanged(int)),this,SLOT(onTabChanged(int)));
    connect(&m_launchButtons,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(onLaunchModule(QAbstractButton*)));
    connect(&m_editButtons,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(onEditModule(QAbstractButton*)));
    connect(&m_removeButtons,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(onRemoveModule(QAbstractButton*)));
    connect(m_ui->m_btnEditCategory,SIGNAL(clicked(bool)),this,SLOT(onEditCategory()));
    connect(m_ui->m_btnNewCategory,SIGNAL(clicked(bool)),this,SLOT(onNewCategory()));
    connect(m_ui->m_btnRemoveCategory,SIGNAL(clicked(bool)),this,SLOT(onRemoveCategory()));
}

UIRStatsMain::~UIRStatsMain()
{
    delete m_ui;
}

void UIRStatsMain::onInitialize()
{
    int buttonHeight = 32;
    int fontSize = 10;

    try
    {
        SettingPtr fontSizeSetting = RStatsSettingsManager::inst().getSettingById("fntSize");
        SettingPtr buttonHeightSetting = RStatsSettingsManager::inst().getSettingById("btnHeight");
        fontSize = (dynamic_cast<NumericSetting*>(fontSizeSetting.get()))->value;
        buttonHeight = (dynamic_cast<NumericSetting*>(buttonHeightSetting.get()))->value;
    }
    catch(const std::exception& e)
    {

    }

    QFont font = this->font();
    font.setPointSize(fontSize);

    //initialize default icons
    QIcon iconEdit,iconHelp,iconModule,iconFolder,iconRemove,iconExit,iconSettings,iconObject,iconAbout,iconAdd;
    std::string appDir = SystemUtils::getApplicationDirectory();
    iconFolder = QIcon(QString::fromStdString(FileUtils::buildFilePath(appDir,"resx/img_folder.png")));
    iconModule = QIcon(QString::fromStdString(FileUtils::buildFilePath(appDir,"resx/img_module.png")));
    iconEdit = QIcon(QString::fromStdString(FileUtils::buildFilePath(appDir,"resx/img_edit.png")));
    iconHelp = QIcon(QString::fromStdString(FileUtils::buildFilePath(appDir,"resx/img_help.png")));
    iconRemove = QIcon(QString::fromStdString(FileUtils::buildFilePath(appDir,"resx/img_remove.png")));
    iconAdd = QIcon(QString::fromStdString(FileUtils::buildFilePath(appDir,"resx/img_add.png")));
    iconExit = QIcon(QString::fromStdString(FileUtils::buildFilePath(appDir,"resx/img_exit.png")));
    iconSettings = QIcon(QString::fromStdString(FileUtils::buildFilePath(appDir,"resx/img_settings.png")));
    iconObject = QIcon(QString::fromStdString(FileUtils::buildFilePath(appDir,"resx/img_object.png")));
    iconAbout = QIcon(QString::fromStdString(FileUtils::buildFilePath(appDir,"resx/img_about.png")));

    setupButton(m_ui->m_btnEditCategory,font,iconEdit,buttonHeight);
    setupButton(m_ui->m_btnRemoveCategory,font,iconRemove,buttonHeight);
    setupButton(m_ui->m_btnNewCategory,font,iconAdd,buttonHeight);

    m_ui->m_actionExit->setIcon(QIcon(iconExit));
    m_ui->m_actionAbout_RAT_STATS_2017->setIcon(QIcon(iconAbout));
    m_ui->m_actionHelp_Topics->setIcon(QIcon(iconHelp));
    m_ui->m_actionModule_Manager->setIcon(QIcon(iconModule));
    m_ui->m_actionSettings_Manager->setIcon(QIcon(iconSettings));
    m_ui->m_menuBar->setFont(font);
    m_ui->m_lstModules->setFont(font);
    m_ui->m_stackModules->setFont(font);
    m_ui->m_lstModules->setIconSize(QSize(buttonHeight-8,buttonHeight-8));

    std::vector<RStatsModuleProperties> propsList = RStatsUtils::getModulePropertiesList();
    std::map<std::string, std::vector<RStatsModuleProperties> > groupedModules;

    for(const RStatsModuleProperties& props : propsList)
    {
        std::string category;
        if (StringUtils::trimmed(props.getApplicationCategory()).size()==0)
        {
            category = "Uncategorized";
        }

        if (groupedModules.count(props.getApplicationCategory()) == 0)
        {
            QListWidgetItem * categoryItem = new QListWidgetItem(iconFolder,
                                                                 QString::fromStdString(category));
            m_ui->m_lstModules->addItem(categoryItem);
        }
        groupedModules[category].push_back(props);
    }

    size_t index = 0;
    for (const auto& it : groupedModules)
    {
        QGridLayout * groupLayout = new QGridLayout;
        groupLayout->setProperty("index",index);
        groupLayout->setProperty("name",QString::fromStdString(it.first));
        m_groupModuleMap[index] = groupLayout;
        m_groupModuleRowColumnMap[index] = QPair<int,int>(0,0);
        for(size_t a2 = 0 ;a2 < it.second.size();++a2)
        {
            RStatsModuleProperties props = it.second[a2];
            if (m_groupModuleMap.contains(index))
            {
                QGridLayout * groupLayout = m_groupModuleMap[index];
                QPair<int,int> position = m_groupModuleRowColumnMap[index];
                bool isDisabled=false,isHidden=false;

                //Setup edit button
                QPushButton * moduleEditButton = new QPushButton;
                setupButton(moduleEditButton,font,iconEdit,buttonHeight,true);
                moduleEditButton->setProperty("index",m_allLaunchButtons.size());
                m_editButtons.addButton(moduleEditButton);
                groupLayout->addWidget(moduleEditButton,position.first,position.second+1);

                //Setup remove button
                QPushButton * moduleRemoveButton = new QPushButton;
                setupButton(moduleRemoveButton,font,iconRemove,buttonHeight,true);
                moduleRemoveButton->setProperty("index",m_allLaunchButtons.size());
                m_removeButtons.addButton(moduleRemoveButton);
                groupLayout->addWidget(moduleRemoveButton,position.first,position.second+2);

                //Setup launch button
                QToolButton * moduleLaunchButton = new QToolButton;
                moduleLaunchButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
                moduleLaunchButton->setText(QString::fromStdString(props.getApplicationName()));
                moduleLaunchButton->setProperty("id",index);

#ifdef __WIN32
                isDisabled = !FileUtils::fileExists(props.getApplicationPath()+".exe");
#else
                isDisabled = !FileUtils::fileExists(props.getApplicationPath());
#endif
                moduleLaunchButton->setIconSize(QSize(buttonHeight-8,buttonHeight-8));

                std::string iconFile = props.getApplicationIcon();
                std::string iconPath = FileUtils::buildFilePath(SystemUtils::getApplicationDirectory(),
                                                                iconFile);

                if (StringUtils::trimmed(iconFile).size() > 0 &&
                    FileUtils::fileExists(iconPath))
                {
                    moduleLaunchButton->setIcon(QIcon(QString::fromStdString(iconPath)));
                }
                else
                {
                    moduleLaunchButton->setIcon(iconModule);
                }

                moduleLaunchButton->setMinimumHeight(buttonHeight);
                moduleLaunchButton->setMaximumHeight(buttonHeight);
                moduleLaunchButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
                m_allLaunchButtons.push_back(moduleLaunchButton);
                m_launchButtons.addButton(moduleLaunchButton);
                groupLayout->addWidget(moduleLaunchButton,position.first,position.second);
                position.first++;
                m_groupModuleRowColumnMap[index] = position;
                m_groupEmpty[index] = false;
            }
        }
        ++index;
    }

    m_ui->m_stackModules->removeWidget(m_ui->m_stackModules->widget(0));
    int maxWidth = 0;
    //Populate the Widget stack and Listbox
    QFontMetrics metrics(this->m_ui->m_lstModules->font());
    for (const auto& it : m_groupModuleMap.toStdMap())
    {
        QGridLayout * layout = it.second;
        QGroupBox * groupFrame = new QGroupBox;
        QScrollArea * scrollArea = new QScrollArea;
        m_groupBoxMap[it.first] = groupFrame;
        groupFrame->setLayout(layout);
        scrollArea->setWidget(groupFrame);
        QString name = layout->property("name").toString();
        m_ui->m_lstModules->addItem(new QListWidgetItem(m_groupIcons[it.first],name));
        m_ui->m_stackModules->addWidget(scrollArea);
        int currentWidth = metrics.width(name);
        if (currentWidth > maxWidth)
        {
            maxWidth = currentWidth;
        }
    }
    m_ui->m_lstModules->setStyleSheet("QListWidget:item{height:"+QString::number(buttonHeight)+"px;padding:1px;}");

    //Set the minimum width of listbox based on its contents
    maxWidth+= (m_ui->m_lstModules->font().pointSize() * 5);
    m_ui->m_lstModules->setMinimumWidth(maxWidth);
    if (m_ui->m_lstModules->count() > 0)
    {
        m_ui->m_lstModules->setCurrentRow(0);
    }
}

void UIRStatsMain::setupButton(QAbstractButton *button,
                               const QFont &font,
                               const QIcon &icon,
                               size_t buttonHeight,
                               bool squareButton)
{
    button->setFont(font);
    button->setIcon(icon);
    button->setIconSize(QSize(buttonHeight-8,buttonHeight-8));
    button->setMaximumHeight(buttonHeight);
    button->setMinimumHeight(buttonHeight);
    if (squareButton)
    {
        button->setMaximumWidth(buttonHeight);
        button->setMinimumWidth(buttonHeight);
    }
}

void UIRStatsMain::showEvent(QShowEvent *event)
{
    for(QToolButton * button : m_allLaunchButtons)
    {
        if (button->property("isDisabled").toBool())
        {
            button->setDisabled(true);
        }
        if (button->property("isHidden").toBool())
        {
            button->setHidden(true);
        }
    }

    if(m_ui->m_stackModules->count() > 0)
    {
        onTabChanged(0);
    }
}

void UIRStatsMain::resizeEvent(QResizeEvent *event)
{
    if(m_ui->m_stackModules->count() > 0)
    {
        onTabChanged(m_ui->m_stackModules->currentIndex());
    }
}

void UIRStatsMain::onExit()
{
    this->close();
}

void UIRStatsMain::onLaunchModuleManager()
{

}

void UIRStatsMain::onLaunchSettingsManager()
{
    UIRStatsSettingsManager().exec();
}

void UIRStatsMain::onLaunchAbout()
{
    UIRStatsAbout().exec();
}

void UIRStatsMain::onLaunchHelp()
{

}

void UIRStatsMain::onTabChanged(int tab)
{
    m_ui->m_stackModules->setCurrentIndex(tab);
    if (m_groupBoxMap.count(tab))
    {
        QGroupBox * groupBox = m_groupBoxMap[tab];
        if (m_groupEmpty[tab])
        {
            groupBox->resize(groupBox->parentWidget()->width(),groupBox->parentWidget()->height());
        }
        else
        {
            groupBox->resize(groupBox->parentWidget()->width(),groupBox->height());
        }
        groupBox->update();
    }

    //Check to see if group is protected from removal
    if (m_groupProtected.contains(tab))
    {
        m_ui->m_btnRemoveCategory->setEnabled(false);
    }
    else
    {
        m_ui->m_btnRemoveCategory->setEnabled(true);
    }
    m_ui->m_stackModules->update();
}

void UIRStatsMain::onEditCategory()
{

}

void UIRStatsMain::onNewCategory()
{

}

void UIRStatsMain::onRemoveCategory()
{

}

void UIRStatsMain::onLaunchModule(QAbstractButton *button)
{
    QString command = button->property("exe").toString() +" "+button->property("args").toString();
    if (!command.trimmed().isEmpty())
    {
        command = QString::fromStdString(FileUtils::buildFilePath(SystemUtils::getApplicationDirectory(),command.toStdString()));
        QProcess::startDetached(command);
    }
}

void UIRStatsMain::onEditModule(QAbstractButton *button)
{

}

void UIRStatsMain::onRemoveModule(QAbstractButton *button)
{

}
}}}//end namespace

