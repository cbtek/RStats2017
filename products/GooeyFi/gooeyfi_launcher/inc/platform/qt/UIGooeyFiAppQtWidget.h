/*
 UIGooeyFiAppQtWidget.h
 
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

#pragma once

#include <QWidget>

#include "gooeyfi_core/inc/GooeyFiApp.h"

class Ui_UIGooeyFiAppQtWidget;

namespace cbtek {
namespace products {
namespace gooeyfi {
namespace launcher {
namespace platform {
namespace qt {


class UIGooeyFiAppQtWidget : public QWidget
{
    Q_OBJECT

public:
    //! Constructor for UIGooeyFiAppQtWidget
    /*!
        Detailed description for UIGooeyFiAppQtWidget
        @param      parent points to embedding super widget. Defaults to null.
    */
    explicit UIGooeyFiAppQtWidget(const core::GooeyFiApp &app, QWidget *parent = 0);
    
    
    //! Destructor for UIGooeyFiAppQtWidget
    ~UIGooeyFiAppQtWidget();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIGooeyFiAppQtWidget *m_ui;
    
};

}}}}}}//end namespace

