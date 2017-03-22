/*
    UIRStatsSVADataImportWizard.h
    

*/

#ifndef _OIG_RATSTATS_MODULES_SVA_UIRSTATSSVADATAIMPORTWIZARD_H
#define _OIG_RATSTATS_MODULES_SVA_UIRSTATSSVADATAIMPORTWIZARD_H
#include <QMainWindow>

class Ui_UIRStatsSVADataImportWizard;

namespace oig {
namespace ratstats {
namespace modules {
namespace sva {


class UIRStatsSVADataImportWizard : public QMainWindow
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsSVADataImportWizard
	/*!
		Detailed description for UIRStatsSVADataImportWizard
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsSVADataImportWizard(QWidget *parent = 0);
    
    
    //! Destructor for UIRStatsSVADataImportWizard
    ~UIRStatsSVADataImportWizard();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsSVADataImportWizard *m_ui;
    
};

}}}}//end namespace

#endif // _OIG_RATSTATS_MODULES_SVA_UIRSTATSSVADATAIMPORTWIZARD_H
