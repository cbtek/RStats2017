/**
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

#include "ColorFactory.h"
#include <vector>

namespace cbtek {
namespace common {
namespace utility {

namespace colorFunctions
{
    enum ColorFunction
    {
        ADD_5_RANDOM_COLORS,
        ADD_10_RANDOM_COLORS,
        ADD_15_RANDOM_COLORS,
        ADD_20_RANDOM_COLORS,
        ADD_5_RANDOM_LIGHT_COLORS,
        ADD_10_RANDOM_LIGHT_COLORS,
        ADD_15_RANDOM_LIGHT_COLORS,
        ADD_20_RANDOM_LIGHT_COLORS,
        ADD_5_RANDOM_DARK_COLORS,
        ADD_10_RANDOM_DARK_COLORS,
        ADD_15_RANDOM_DARK_COLORS,
        ADD_20_RANDOM_DARK_COLORS
    };
}
class ColorLoop
{

public:

    ColorLoop();

    /**
     * @brief operator <<
     * @param color
     * @return
     */
    ColorLoop & operator<<(const Color & color);

    /**
     * @brief operator <<
     * @param colorType
     * @return
     */
    ColorLoop & operator<< (const colors::ColorType & colorType);

    /**
     * @brief operator <<
     * @param function
     * @return
     */
    ColorLoop & operator<< (const colorFunctions::ColorFunction & function);

    /**
     * @brief generateUniqueColors
     * @param count
     */
    void generateUniqueColors(const size_t & count);

    /**
     * @brief getNextColor
     * @return
     */
    Color getNextColor();

    /**
     * @brief reset
     */
    void reset();

    /**
     * @brief clear
     */
    void clear();

    /**
     * @brief getColorAt
     * @param ndx
     * @return
     */
    Color getColorAt(size_t ndx) const;

    /**
     * @brief getCurrentColorNdx
     * @return
     */
    size_t getCurrentColorNdx() const;

    /**
     * @brief setCurrentColorNdx
     * @param ndx
     */
    void setCurrentColorNdx(size_t ndx);

private:
    size_t m_currentColor;
    std::vector<Color> m_colors;
    bool colorExists(const Color & color);
};
}}}//namespace
