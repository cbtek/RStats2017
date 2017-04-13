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
#include <string>

#include "utility/inc/Color.h"

namespace cbtek {
namespace common {
namespace utility {

namespace textAlignment
{
    enum Alignment
    {
        LEFT,
        MIDDLE,
        RIGHT
    };

    enum HorizontalAlignment
       {
           ALIGN_HGENERAL,
           ALIGN_LEFT,
           ALIGN_HCENTER,
           ALIGN_RIGHT,
           ALIGN_HFILL,
           ALIGN_HJUSTIFY,
           ALIGN_HMERGE,
           ALIGN_HDISTRIBUTED
       };

       enum VerticalAlignment
       {
           ALIGN_TOP,
           ALIGN_VCENTER,
           ALIGN_BOTTOM,
           ALIGN_VJUSTIFY,
           ALIGN_VDISTRIBUTED
       };
}
class Font
{
public:

    /**
     * @brief Font
     */
    Font();

    /**
     * @brief Font
     * @param fontFamily
     * @param pointSize
     * @param isBold
     * @param isItalic
     * @param isUnderlined
     */
    Font(std::string fontFamily,
         size_t pointSize=10,
         bool isBold=false,
         bool isItalic = false,
         bool isUnderlined=false);

    /**
     * @brief operator ==
     * @param font
     * @return
     */
    bool operator==(const Font & font);

    /**
     * @brief setFontFamily
     * @param fontFamily
     */
    void setFontFamily(const std::string & fontFamily);

    /**
     * @brief setPointSize
     * @param pointSize
     */
    void setPointSize(const size_t & pointSize);

    /**
     * @brief setBold
     * @param enabled
     */
    void setBold(const bool & enabled);

    /**
     * @brief setItalic
     * @param enabled
     */
    void setItalic(const bool & enabled);

    /**
     * @brief setUnderlined
     * @param enabled
     */
    void setUnderlined(const bool & enabled);

    /**
     * @brief isBold
     * @return
     */
    bool isBold() const;

    /**
     * @brief isItalic
     * @return
     */
    bool isItalic() const;

    /**
     * @brief isUnderlined
     * @return
     */
    bool isUnderlined() const;

    /**
     * @brief getFontFamily
     * @return
     */
    std::string getFontFamily() const;

    /**
     * @brief getPointSize
     * @return
     */
    size_t getPointSize()const;

    /**
     * @brief toString
     * @return
     */
    std::string toString() const;

    /**
     * @brief hasDefaultChanged
     * @return
     */
    bool hasDefaultChanged() const;

    /**
     * @brief setChanged
     * @param flag
     */
    void setChanged(bool flag);

    /**
     * @brief setFontColor
     * @param c
     */
    void setFontColor(const Color &c);

    /**
     * @brief getFontColor
     * @return
     */
    Color getFontColor() const;

private:
    bool m_changed;
    bool m_isUnderlined;
    bool m_isBold;
    bool m_isItalic;
    size_t m_pointSize;
    std::string m_fontFamily;
    Color m_color;
};

}}}//namespace
