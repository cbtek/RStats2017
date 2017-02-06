/*
    UIRStatsUAA.h
    

*/

#ifndef _OIG_RATSTATS_UAA_UIRSTATSUAA_H
#define _OIG_RATSTATS_UAA_UIRSTATSUAA_H
#include <QDialog>

class Ui_UIRStatsUAA;

namespace oig {
namespace ratstats {
namespace uaa {


class UIRStatsUAA : public QDialog
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
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsUAA *m_ui;
    
};

}}}//end namespace

#endif // _OIG_RATSTATS_UAA_UIRSTATSUAA_H
