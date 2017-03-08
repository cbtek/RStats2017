/*
    UIRStatsSVA.h
    

*/

#pragma once

#include <QMainWindow>

class Ui_UIRStatsSVA;

namespace oig {
namespace ratstats {
namespace modules {
namespace sva {

class UIRStatsSVA : public QMainWindow
{
    Q_OBJECT

public:
    //! Constructor for UIRStatsSVA
	/*!
        Detailed description for UIRStatsSVA
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsSVA(QWidget *parent = 0);

    //! Destructor for UIRStatsSVA
    ~UIRStatsSVA();
private:

    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsSVA *m_ui;

protected slots:
     void onContinue();
     void onExit();
     void onImportInputData();
     void onExportInputData();
     void onHelp();
     void onSetOutputFolder();
     void onSetPrinterOptions();
};

}}}}//end namespace
