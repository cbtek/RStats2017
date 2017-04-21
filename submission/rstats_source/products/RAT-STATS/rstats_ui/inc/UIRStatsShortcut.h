/*
    UIRStatsShortcut.h
    

*/

#ifndef _OIG_RATSTATS_UI_UIRSTATSSHORTCUT_H
#define _OIG_RATSTATS_UI_UIRSTATSSHORTCUT_H
#include <QShortcut>

namespace oig {
namespace ratstats {
namespace ui {


class UIRStatsShortcut :public QShortcut
{
    Q_OBJECT
public:
	//! Constructor for UIRStatsShortcut
	/*!
		Detailed description for UIRStatsShortcut
	*/
    UIRStatsShortcut(const QKeySequence & sequence, QWidget * parent);
        
	//! Destructor
	~UIRStatsShortcut();	

private slots:
    void onActivated();

signals:
    void activated(QShortcut * shortcut);
    
};
}}}//end namespace

#endif // _OIG_RATSTATS_UI_UIRSTATSSHORTCUT_H

