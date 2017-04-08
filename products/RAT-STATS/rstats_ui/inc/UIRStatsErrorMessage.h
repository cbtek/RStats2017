/*
    UIRStatsErrorMessage.h
    

*/

#pragma once

#include <QDialog>

class Ui_UIRStatsErrorMessage;

namespace oig {
namespace ratstats {
namespace ui {


class UIRStatsErrorMessage : public QDialog
{
    Q_OBJECT

public:
    //! Constructor for UIRStatsErrorMessage
	/*!
        Detailed description for UIRStatsErrorMessage
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIRStatsErrorMessage(QString & title,
                                  QString & message,
                                  bool exitApplication=false,
                                  QWidget *parent = 0);
    
    
    /**
     * @brief UIRStatsErrorMessage
     * @param title
     * @param message
     * @param exitApplication
     * @param parent
     */
    explicit UIRStatsErrorMessage(const std::string & title,
                                  const std::string & message,
                                  bool exitApplication=false,
                                  QWidget *parent = 0);

    //! Destructor for UIRStatsErrorMessage
    ~UIRStatsErrorMessage();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIRStatsErrorMessage *m_ui;

     bool m_exitApplication;
private slots:
    void onOk();
    void onSave();
    void onCopy();
    void onInit(const QString & title, const QString & message);
};

}}}//end namespace
