/*
    RStatsOutputStream.hpp
    
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

#include <vector>

#include "RStatsWorkbook.h"

namespace cbtek {
namespace rocketstats {
namespace utils {

/**
 * @brief The RStatsWorkbookStream interface represents a simple
 * read/write stream for various workbook file formats.
 */
class RStatsWorkbookStream
{
public:

    /**
     * @brief write This function will be inherited by implementing
     * classes to provide support for writing a workbook to file
     * @param workbook The workbook to write
     */    
    virtual void write(const RStatsWorkbook& workbook) = 0;

    /**
     * @brief read This function will be inherited by implementing
     * classes to provide support for reading a workbook from file
     * @return
     */
    virtual RStatsWorkbook read() = 0;

    //! Virtual Destructor
    virtual ~RStatsWorkbookStream(){}
};
/**
 * @brief RStatsWorkbookStreamPtr Typedef of shared pointer for this
 * interface
 */
typedef std::shared_ptr<RStatsWorkbookStream> RStatsWorkbookStreamPtr;

}}}//end namespace
