/*
    UIRStatsAbout.h
    

*/

#ifndef _OIG_RATSTATS_MAIN_UIRSTATSABOUT_H
#define _OIG_RATSTATS_MAIN_UIRSTATSABOUT_H
#include <QDialog>

class Ui_UIRStatsAbout;

namespace oig {
namespace ratstats {
namespace ui {


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
     void onOK();
};

}}}//end namespace

#endif // _OIG_RATSTATS_MAIN_UIRSTATSABOUT_H
