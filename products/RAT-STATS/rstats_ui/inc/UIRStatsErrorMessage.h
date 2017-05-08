/*
    UIRStatsErrorMessage.h
    

*/

#pragma once

#include <QDialog>

class Ui_UIRStatsErrorMessage;

namespace oig {
namespace ratstats {
namespace ui {

/**
 * @brief The UIRStatsErrorMessage class represents the code-behind for
 * a custom dialog for displaying error/exception messages.
 */
class UIRStatsErrorMessage : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief UIRStatsErrorMessage (Constructor)
     * @param title The message to display in title bar
     * @param message The primary error message
     * @param exitApplication Should application exit after message is dismissed
     * @param parent The parent widget
     */
    explicit UIRStatsErrorMessage(QString & title,
                                  QString & message,
                                  bool exitApplication=false,
                                  QWidget *parent = 0);
    
    
    /**
     * @brief UIRStatsErrorMessage (Constructor)
     * @param title The message to display in title bar
     * @param message The primary error message
     * @param exitApplication Should application exit after message is dismissed
     * @param parent The parent widget
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

     /**
      * @brief m_exitApplication Flag that determines if application should auto-exit when
      * error message dialog is dismissed.
      */
     bool m_exitApplication;
private slots:

     /**
     * @brief onOk Closes/dismisses dialog
     */
    void onOk();

    /**
     * @brief onSave Saves message text
     */
    void onSave();

    /**
     * @brief onCopy Copies all message text
     */
    void onCopy();

    /**
     * @brief onInit Initializes the dialog and sets the title bar text and message text
     * @param title The title bar text
     * @param message The main message text
     */
    void onInit(const QString & title, const QString & message);
};

}}}//end namespace
