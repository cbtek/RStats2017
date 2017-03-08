/*
    UIRStatsUVA.h
*/

#pragma once

#include <QMainWindow>

class Ui_UIRStatsUVA;

namespace oig {
namespace ratstats {
namespace modules {
namespace uva {


class UIRStatsUVA : public QMainWindow
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsUVA
	/*!
		Detailed description for UIRStatsUVA
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsUVA(QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsUVA
    ~UIRStatsUVA();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsUVA *m_ui;
    
};

}}}}//end namespace

