/*
    UISVA.h
    

*/

#ifndef _OIG_RATSTATS_SVA_UISVA_H
#define _OIG_RATSTATS_SVA_UISVA_H
#include <QMainWindow>

class Ui_UISVA;

namespace oig {
namespace ratstats {
namespace sva {


class UISVA : public QMainWindow
{
    Q_OBJECT

public:
	//! Constructor for UISVA
	/*!
		Detailed description for UISVA
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UISVA(QWidget *parent = 0);

    //! Destructor for UISVA
    ~UISVA();
private:

    /** 
    * MOC generated ui class for this widget
    */
     Ui_UISVA *m_ui;

protected slots:
     void onContinue();
     void onExit();
     void onImportInputData();
     void onExportInputData();
     void onHelp();
     void onSetOutputFolder();
     void onSetPrinterOptions();
};

}}}//end namespace

#endif // _OIG_RATSTATS_SVA_UISVA_H
