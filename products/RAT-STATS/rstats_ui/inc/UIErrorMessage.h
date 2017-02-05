/*
    UIErrorMessage.h
    

*/

#ifndef _OIG_RATSTATS_UI_UIERRORMESSAGE_H
#define _OIG_RATSTATS_UI_UIERRORMESSAGE_H
#include <QDialog>

class Ui_UIErrorMessage;

namespace oig {
namespace ratstats {
namespace ui {


class UIErrorMessage : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIErrorMessage
	/*!
		Detailed description for UIErrorMessage
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIErrorMessage(QWidget *parent = 0);
    
    
    //! Destructor for UIErrorMessage
    ~UIErrorMessage();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIErrorMessage *m_ui;
    
};

}}}//end namespace

#endif // _OIG_RATSTATS_UI_UIERRORMESSAGE_H
