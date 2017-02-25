/*
 UIGooeyFiApp.hpp
 
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

#include "gooeyfi_core/inc/GooeyFiApp.h"

#include <memory>

namespace cbtek {
namespace products {
namespace gooeyfi {
namespace launcher {


class UIGooeyFiApp 
{
public:

    /**
     * @brief start
     */
    virtual void start() = 0;

    /**
     * @brief initialize
     */
    virtual void initialize() = 0;

    //! Virtual Destructor
    virtual ~UIGooeyFiApp(){}
};
typedef std::shared_ptr<UIGooeyFiApp> UIGooeyFiAppPtr;
}}}}//end namespace
