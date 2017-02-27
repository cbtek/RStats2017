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
#include "gooeyfi_builder/inc/UIGooeyFiAppBuilder.h"

using namespace cbtek::products::gooeyfi;

#include <QApplication>

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
#ifdef __WIN32
    core::GooeyFiApp app("C:/Dev/CBTek/cpp/Contests/RStats2017/products/GooeyFi/gooeyfi_core/res/sample2.xml");
#else
    core::GooeyFiApp app("/home/sunefusion/dev/CBTek/RStats2017/products/GooeyFi/gooeyfi_core/res/sample2.xml");
#endif
    app.read();
    launcher::UIGooeyFiAppPtr ui =
            cbtek::products::gooeyfi::launcher::UIGooeyFiAppFactory::create(app);

    ui->initialize();
    ui->start();

    builder::UIGooeyFiAppBuilder * appBuilder = new builder::UIGooeyFiAppBuilder();
    appBuilder->show();
    return a.exec();
}

