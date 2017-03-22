/*
    UIRStatsUAA.h
    

*/

#pragma once

#include <QMainWindow>

class Ui_UIRStatsUAA;

namespace oig {
namespace ratstats {
namespace modules {
namespace uaa {


class UIRStatsUAA : public QMainWindow
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsUAA
	/*!
		Detailed description for UIRStatsUAA
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsUAA(QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsUAA
    ~UIRStatsUAA();
private:

    QIcon m_exitIcon;
    QIcon m_runIcon;
    QIcon m_helpIcon;
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsUAA *m_ui;
    
};

}}}}//end namespace
