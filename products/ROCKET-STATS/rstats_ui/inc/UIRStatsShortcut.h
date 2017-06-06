/*
    UIRStatsShortcut.h
    

*/

#pragma once

#include <QShortcut>

namespace cbtek {
namespace rocketstats {
namespace ui {

/**
 * @brief The UIRStatsShortcut class is a custom overload of QShortcut
 * to provide more useful "activated" signal that returns pointer to
 * shortcut.
 */
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
    /**
     * @brief onActivated
     */
    void onActivated();

signals:
    /**
     * @brief activated
     * @param shortcut
     */
    void activated(QShortcut * shortcut);
    
};
}}}//end namespace

