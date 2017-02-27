/*
    GooeyFiUtils.h
    
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

#ifndef _CBTEK_PRODUCTS_GOOEYFI_CORE_GOOEYFIUTILS_H
#define _CBTEK_PRODUCTS_GOOEYFI_CORE_GOOEYFIUTILS_H

#include "GooeyFiNumeric.h"
#include "GooeyFiButton.h"
#include "GooeyFiTextInput.h"
#include "GooeyFiPathBrowser.h"

namespace cbtek {
namespace products {
namespace gooeyfi {
namespace core {


class GooeyFiUtils 
{
public:
    static const GooeyFiNumeric * getNumeric(const GooeyFiWidgetPtr& widget);
    static const GooeyFiTextInput * getTextInput(const GooeyFiWidgetPtr& widget);
    static const GooeyFiPathBrowser * getPathBrowser(const GooeyFiWidgetPtr& widget);
    static const GooeyFiButton * getButton(const GooeyFiWidgetPtr& widget);

private:
    //! Private constructor for GooeyFiUtils
	GooeyFiUtils();

    //! Private copy constructor for GooeyFiUtils
	GooeyFiUtils(const GooeyFiUtils &);

	//! Private destructor for GooeyFiUtils
	~GooeyFiUtils();	
};
}}}}//end namespace

#endif

