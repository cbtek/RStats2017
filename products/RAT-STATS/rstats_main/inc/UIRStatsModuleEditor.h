/*
    UIRStatsModuleEditor.h
    

*/

#ifndef _OIG_RATSTATS_MAIN_UIRSTATSMODULEEDITOR_H
#define _OIG_RATSTATS_MAIN_UIRSTATSMODULEEDITOR_H

#include <QDialog>
#include <QShortcut>

class Ui_UIRStatsModuleEditor;

namespace oig {
namespace ratstats {
namespace main {

class UIRStatsModuleEditor : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIRStatsModuleEditor
	/*!
		Detailed description for UIRStatsModuleEditor
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsModuleEditor(QWidget *parent = 0);
        
    //! Destructor for UIRStatsModuleEditor
    ~UIRStatsModuleEditor();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsModuleEditor *m_ui;
private slots:
     void onCancel();
     void onSave();

signals:
     void moduleSaved(const QString& name,
                      const QString& group,
                      const QString& executable,
                      const QString& arguments,
                      const QString& iconUrl);
};

}}}//end namespace

#endif // _OIG_RATSTATS_MAIN_UIRSTATSMODULEEDITOR_H
