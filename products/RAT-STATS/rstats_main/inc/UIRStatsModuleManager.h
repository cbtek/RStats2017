/*
    UIRStatsModuleManager.h
    

*/

#ifndef _OIG_RATSTATS_MAIN_UIRSTATSMODULEMANAGER_H
#define _OIG_RATSTATS_MAIN_UIRSTATSMODULEMANAGER_H
#include <QDialog>

class Ui_UIRStatsModuleManager;

namespace oig {
namespace ratstats {
namespace main {


class UIRStatsModuleManager : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsModuleManager
	/*!
		Detailed description for UIRStatsModuleManager
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsModuleManager(QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsModuleManager
    ~UIRStatsModuleManager();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsModuleManager *m_ui;
    
private slots:
     void onCancel();
};

}}}//end namespace

#endif // _OIG_RATSTATS_MAIN_UIRSTATSMODULEMANAGER_H
