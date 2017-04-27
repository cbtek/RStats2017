/*
    UIRStatsTablePreviewWidget.h
    

*/
#pragma once

#include <QTableWidget>
#include <QKeyEvent>

namespace oig {
namespace ratstats {
namespace ui {

class UIRStatsTablePreviewWidget :public QTableWidget
{
public:
   /*
    * @brief UIRStatsTablePreviewWidget
    *
	*/
    explicit UIRStatsTablePreviewWidget(QWidget * parent = nullptr);
    
    
	/*
     * @brief UIRStatsTablePreviewWidget (Descructor)
     *
	 */
    ~UIRStatsTablePreviewWidget();
protected:
    void keyPressEvent(QKeyEvent * event);
    
};
}}}//end namespace

