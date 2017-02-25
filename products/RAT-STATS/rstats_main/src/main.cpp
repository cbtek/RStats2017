//#include <QApplication>
//#include "UIRStatsMain.h"

//int main(int argc, char ** argv)
//{
//	QApplication a(argc,argv);
//    oig::ratstats::main::UIRStatsMain main;
//    main.show();
//	return a.exec();
//}

#include "gooeyfi_launcher/inc/UIGooeyFiAppFactory.h"

using namespace cbtek::products::gooeyfi;

#include <QApplication>

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
    core::GooeyFiApp app("C:/Dev/CBTek/cpp/Contests/RStats2017/products/GooeyFi/gooeyfi_core/res/sample2.xml");
    app.read();
    launcher::UIGooeyFiAppPtr ui =
            cbtek::products::gooeyfi::launcher::UIGooeyFiAppFactory::create(app);

    ui->initialize();
    ui->start();
    return a.exec();
}

