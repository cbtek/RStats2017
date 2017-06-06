/*
    UIRStatsTablePreviewWidget.h
    

*/
#pragma once

#include <QTableWidget>
#include <QKeyEvent>

namespace cbtek {
namespace rocketstats {
namespace ui {

/**
 * @brief The UIRStatsTablePreviewWidget is a custom overload of
 * the QTableWidget to provide the ability ignore the Tab key when
 * viewing results in table.  This allows the Tab key to go to the next
 * sibling widget instead of being stuck in the table.
 */
class UIRStatsTablePreviewWidget :public QTableWidget
{
public:
   /**
    * @brief UIRStatsTablePreviewWidget (Constructor)
    * @param parent
	*/
    explicit UIRStatsTablePreviewWidget(QWidget * parent = nullptr);
    
    
    /**
     * @brief UIRStatsTablePreviewWidget (Destructor)
	 */
    ~UIRStatsTablePreviewWidget();
protected:

    /**
     * @brief keyPressEvent Custom event for ignoring the TAB key
     * so that focus is not always stuck in table
     * @param event The event for keys
     */
    void keyPressEvent(QKeyEvent * event);
    
};
}}}//end namespace

