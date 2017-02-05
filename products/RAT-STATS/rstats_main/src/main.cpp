#include <QApplication>
#include "UIRStatsMain.h"

int main(int argc, char ** argv)
{
	QApplication a(argc,argv);
    oig::ratstats::main::UIRStatsMain main;
    main.show();
	return a.exec();
}

