/*
    UIGooeyFiWidgetDefaults.h
    
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

#ifndef _CBTEK_PRODUCTS_GOOEYFI_BUILDER_UIGOOEYFIWIDGETDEFAULTS_H
#define _CBTEK_PRODUCTS_GOOEYFI_BUILDER_UIGOOEYFIWIDGETDEFAULTS_H

#include <QDialog>
#include <gooeyfi_core/inc/GooeyFiWidget.hpp>

class Ui_UIGooeyFiWidgetDefaults;

namespace cbtek {
namespace products {
namespace gooeyfi {
namespace builder {


class UIGooeyFiWidgetDefaults : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIGooeyFiWidgetDefaults
	/*!
		Detailed description for UIGooeyFiWidgetDefaults
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIGooeyFiWidgetDefaults(const core::GooeyFiWidgetPtr& widget,
                                     QWidget *parent = 0);
    
    
    //! Destructor for UIGooeyFiWidgetDefaults
    ~UIGooeyFiWidgetDefaults();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIGooeyFiWidgetDefaults *m_ui;
     core::GooeyFiWidgetPtr m_widget;

     void onInit();
signals:
     void widgetUpdated(const core::GooeyFiWidgetPtr& widget);

};

}}}}//end namespace

#endif // _CBTEK_PRODUCTS_GOOEYFI_BUILDER_UIGOOEYFIWIDGETDEFAULTS_H
