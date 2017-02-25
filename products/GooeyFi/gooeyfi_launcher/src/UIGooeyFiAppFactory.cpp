/*
    UIGooeyFiAppFactory.cpp
    
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
//----------------------------------------
//UIGooeyFiAppFactory.cpp generated by CBTek Solutions on 02-19-2017 at 02:20:44 PM
//----------------------------------------

#include "UIGooeyFiAppFactory.h"

#ifdef USE_QT_PLATFORM
    #include "gooeyfi_launcher/inc/platform/qt/UIGooeyFiAppQt.h"
#else
    #include "gooeyfi_launcher/inc/platform/imgui/UIGooeyFiAppImgui.h"
#endif

namespace cbtek {
namespace products {
namespace gooeyfi {
namespace launcher {

UIGooeyFiAppPtr UIGooeyFiAppFactory::create(const gooeyfi::core::GooeyFiApp& appPayload)
{
    #ifdef USE_QT_PLATFORM
        return UIGooeyFiAppPtr(new platform::qt::UIGooeyFiAppQt(appPayload));
    #else
        return UIGooeyFiAppPtr(new platform::imgui::UIGooeyFiAppImgui(appPayload));
    #endif
}
}}}}//end namespace

