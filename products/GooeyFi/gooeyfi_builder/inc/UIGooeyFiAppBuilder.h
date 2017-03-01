/*
    UIGooeyFiAppBuilder.h
    
MIT License

Copyright (c) 2016 cbtek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef _CBTEK_PRODUCTS_GOOEYFI_BUILDER_UIGOOEYFIAPPBUILDER_H
#define _CBTEK_PRODUCTS_GOOEYFI_BUILDER_UIGOOEYFIAPPBUILDER_H

#include <QDialog>
#include <QAbstractButton>
#include <QTableWidget>
#include <QButtonGroup>

#include "gooeyfi_core/inc/GooeyFiApp.h"

class Ui_UIGooeyFiAppBuilder;

namespace cbtek {
namespace products {
namespace gooeyfi {
namespace builder {


class UIGooeyFiAppBuilder : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIGooeyFiAppBuilder
	/*!
		Detailed description for UIGooeyFiAppBuilder
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIGooeyFiAppBuilder(QWidget *parent = 0);


    /**
     * @brief UIGooeyFiAppBuilder
     * @param parent
     */
    explicit UIGooeyFiAppBuilder(const core::GooeyFiApp& app,
                                 QWidget *parent = 0);
    
    //! Destructor for UIGooeyFiAppBuilder
    ~UIGooeyFiAppBuilder();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIGooeyFiAppBuilder *m_ui;
    core::GooeyFiApp * m_app;
    core::GooeyFiWidgetPage * m_currentAppPage;
    QMap<core::GooeyFiWidgetPage*, core::GooeyFiWidgetPtr> m_widgetMap;
    QButtonGroup m_editButtonGroup,m_deleteButtonGroup;
    QTableWidget * m_currentTable;

    void onInitialize();
    void onPopulate();

private slots:
     void onAdd();
     void onAddWidget(const core::GooeyFiWidgetPtr& widget, QTableWidget *table);
     void onPreview();
     void onOk();
     void onEdit(QAbstractButton * button);
     void onDelete(QAbstractButton * button);
};

}}}}//end namespace

#endif // _CBTEK_PRODUCTS_GOOEYFI_BUILDER_UIGOOEYFIAPPBUILDER_H
