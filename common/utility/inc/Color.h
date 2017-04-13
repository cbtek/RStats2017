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

#include <cstdint>
#include <string>
#include <memory>

namespace cbtek {
namespace common {
namespace utility {

namespace colorStringStyle
{
    enum ColorStringStyle
    {
        RGB_255        //eg. 255 127 64
        ,RGBA_255      //eg. 255 127 64 255
        ,RGB_FLOAT     //eg. 1.0 0.5 0.25
        ,RGBA_FLOAT    //eg. 1.0 0.5 0.25 1.0
        ,RGB_HTML_HEX  //eg. #FFAA33
        ,RGBA_HTML_HEX //eg. #FFAA33AA
        ,ARGB_HTML_HEX //eg. #AARRGGBB
    };
}
class Color
{
public:

    /**
     * @brief Color
     */
    Color();

    /**
     * @brief Color
     * @param color
     */
    Color(std::uint32_t color);

    /**
     * @brief Color
     * @param rgbaHex
     */
    Color(const std::string & rgbaHex);

    /**
     * @brief Color
     * @param name
     * @param red
     * @param green
     * @param blue
     * @param alpha
     */
    Color(const std::string & name,const uint8_t & red,
          const uint8_t & green,
          const uint8_t & blue,
          const uint8_t & alpha=255);

    /**
     * @brief Color
     * @param red
     * @param green
     * @param blue
     * @param alpha
     */
    Color(const uint8_t & red,
          const uint8_t & green,
          const uint8_t & blue,
          const uint8_t & alpha=255);

    /**
     * @brief set
     * @param red
     * @param green
     * @param blue
     * @param alpha
     */
    void set (const uint8_t & red,
              const uint8_t & green,
              const uint8_t & blue,
              const uint8_t & alpha=255);

    /**
     * @brief set
     * @param htmlColor
     */
    void set(const std::string& htmlColor);

    /**
     * @brief setRed
     * @param red
     */
    void setRed(const uint8_t & red);

    /**
     * @brief setGreen
     * @param green
     */
    void setGreen(const uint8_t & green);

    /**
     * @brief setBlue
     * @param blue
     */
    void setBlue(const uint8_t & blue);

    /**
     * @brief setAlpha
     * @param alpha
     */
    void setAlpha(const uint8_t & alpha);

    /**
     * @brief getRed
     * @return
     */
    uint8_t getRed() const;

    /**
     * @brief toInteger
     * @return
     */
    std::uint32_t toInteger() const;

    /**
     * @brief operator ==
     * @param color
     * @return
     */
    bool operator==(const Color & color) const;

    /**
     * @brief operator !=
     * @param color
     * @return
     */
    bool operator!=(const Color & color) const;

    /**
     * @brief getGreen
     * @return
     */
    uint8_t getGreen() const;

    /**
     * @brief getBlue
     * @return
     */
    uint8_t getBlue() const;

    /**
     * @brief getAlpha
     * @return
     */
    uint8_t getAlpha() const;

    /**
     * @brief toString
     * @param style
     * @return
     */
    std::string toString(const colorStringStyle::ColorStringStyle &style=colorStringStyle::RGBA_255) const;

    /**
     * @brief isTransparent
     * @return
     */
    bool isTransparent() const;

    /**
     * @brief getName
     * @return
     */
    std::string getName() const;

    /**
     * @brief setName
     * @param name
     */
    void setName(const std::string & name);

private:

    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
    std::string m_name;
};
typedef std::shared_ptr<Color> ColorPtr;
}}}//namespace
