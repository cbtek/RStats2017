/*
 UILaunchOptionsDialog.h
 

*/

#pragma once

#include <QDialog>

class Ui_UILaunchOptionsDialog;

namespace oig {
namespace ratstats {
namespace ui {


class UILaunchOptionsDialog : public QDialog
{
    Q_OBJECT

public:
    //! Constructor for UILaunchOptionsDialog
    /*!
        Detailed description for UILaunchOptionsDialog
        @param      parent points to embedding super widget. Defaults to null.
    */
    explicit UILaunchOptionsDialog(QWidget *parent = 0);
    
    
    //! Destructor for UILaunchOptionsDialog
    ~UILaunchOptionsDialog();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UILaunchOptionsDialog *m_ui;
    
};

}}}//end namespace

