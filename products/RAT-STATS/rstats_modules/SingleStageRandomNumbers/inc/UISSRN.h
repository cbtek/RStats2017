/*
    UISSRN.h
    

*/

#pragma once
#include <QDialog>

#include "rstats_utils/inc/RStatsConditionLogger.h"

class Ui_UISSRN;

namespace oig {
namespace ratstats {
namespace ssrn {


class UISSRN : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UISSRN
	/*!
		Detailed description for UISSRN
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UISSRN(QWidget *parent = 0);
    
    
    //! Destructor for UISSRN
    ~UISSRN();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UISSRN *m_ui;
     oig::ratstats::utils::RStatsConditionLogger m_logger;

     QString m_currentOutputDirectory;

private slots:

     void onBrowse();
     void onExit();
     void onGenerate();
     void onHelp();
     void onValidateForm();
};

}}}//end namespace

