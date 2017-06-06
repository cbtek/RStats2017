/*
    UIRStatsAbout.h
    

*/

#pragma once
#include <QDialog>


class Ui_UIRStatsAbout;

namespace cbtek {
namespace rocketstats {
namespace ui {

/**
 * @brief The UIRStatsAbout class represents the code-behind for the
 * "About" dialog used in ROCKET-STATS.
 */
class UIRStatsAbout : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsAbout
	/*!
		Detailed description for UIRStatsAbout
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsAbout(QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsAbout
    ~UIRStatsAbout();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsAbout *m_ui;
private slots:
     /**
      * @brief onOK Event is executed whenever user clicks the Ok button.
      * This event just closes the window
      */
     void onOK();
};
}}}//end namespace
