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
#include <sstream>
#include <vector>

namespace cbtek {
namespace common {
namespace utility {
namespace FontUtils_EmbeddedUtils
{
  
  /**
  * @brief Removes all whitespace (\\t \\r \\n ' ' \\f) from
  *        the beginning and end of inputString.
  * @param Reference to the source string to operate upon
  */
  inline void trimmedInPlace(std::string &str)
  {
      int count=static_cast<int>(str.size());
      for (int a1 = 0;a1<count;++a1)
      {
          if (str[a1]==' '||
              str[a1]=='\n' ||
              str[a1]=='\r' ||
              str[a1]=='\f' ||
              str[a1]=='\t' )
          {
              str.erase(str.begin()+a1);
              a1--;
              count--;
              continue;
          }
          else break;
      }
  
  
      if (count==0)
      {
          return;
      }
      int cnt = static_cast<int>(count);
      for (int a1 = cnt-1;a1 >= 0;--a1)
      {
          if (str[a1]==' '||
              str[a1]=='\n' ||
              str[a1]=='\r' ||
              str[a1]=='\f' ||
              str[a1]=='\t' )
          {
              str.erase(str.begin()+a1);
          }
          else
          {
              break;
          }
      }
  }
  
  /**
  * @brief Removes all whitespace (\t \r \n ' ' \f) from
  *        the beginning and end of inputString.
  * @param The source string to operate upon
  * @return Returns the trimmed string as a copy.
  *
  */
  inline std::string trimmed(const std::string &str)
  {
      std::string strOut = str;
      trimmedInPlace(strOut);
      return strOut;
  }
  
  
  /**
  * @brief Splits a string based on the delimeter
  * @param inputString The string to split
  * @param delimiter The delimiter used to break the string apart
  * @param splitItems Reference to string vector. Avoids vector copy.
  * @code {.cpp}
      //Example: Split string based on custom delim
  
      std::string line = "test|item <$CBTEK$> test,data";
  
      std::vector<std::string>items;
  
      split(line,"<$CBTEK$>",items);
  
      //Example Results:
      //items[0]="test|item";
      //items[1]="test,data";
      @endcode
  */
  inline void split(const std::string &str,
                    const std::string &delimiter,
                    std::vector<std::string> &splitItems)
  {
      std::string s = str;
      size_t pos = 0;
      std::string token;
      while ((pos = s.find(delimiter)) != std::string::npos)
      {
          token = s.substr(0, pos);
          splitItems.push_back(token);
          s.erase(0, pos + delimiter.length());
      }
      splitItems.push_back(s);
  }
  
  
  /**
  * @brief Splits a string based on the delimeter
  * @param inputString The string to split
  * @param delimiter The delimiter used to break the string apart
  * @return Return a vector of split strings
  * @code {.cpp}
      //Example: Split string based on custom delim
  
      std::string line = test|item <$CBTEK$> test,data
  
      std::vector<std::string>items;
  
      items = split(line,"<$CBTEK$>");
  
      //Example Results:
      //items[0]="test|item";
      //items[1]="test,data";
      @endcode
  */
  inline std::vector<std::string> split(const std::string &str,
                                        const std::string &delimiter)
  {
      std::vector<std::string> outItems;
      split(str,delimiter,outItems);
      return outItems;
  }
    
  template<typename T>  
  inline T toNumber(const std::string & value)
  {
      std::istringstream in(value,std::istringstream::in);
      T returnValue;
      in>>returnValue;
      return returnValue;
  }
  
  
  /**
   * @brief Trims all items and removes empty elements
   * @param items
   */
  inline void clean(std::vector<std::string> & items)
  {
      if (items.size() == 0)
      {
          return;
      }
      int lastIndex = static_cast<int>(items.size()) - 1;
      for (int a1 = lastIndex; a1>=0 ;--a1)
      {
          size_t index = static_cast<size_t>(a1);
          if (items[index].empty())
          {
              items.erase(items.begin()+index);
              continue;
          }
          FontUtils_EmbeddedUtils::trimmedInPlace(items[index]);
      }
  }
  
}

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

  
   

private:
    bool m_changed;
    bool m_isUnderlined;
    bool m_isBold;
    bool m_isItalic;
    size_t m_pointSize;
    std::string m_fontFamily;
};


namespace fontStyle{
enum FontStyle
{
    NORMAL=0,
    HEADING_1,
    HEADING_2,
    HEADING_3,
    HEADING_4,
    HEADING_5,
    HEADING_6,
    HEADING_7,
    HEADING_8,
    HEADING_9,
    HEADING_10,
    SYSTEM_SMALL,
    SYSTEM_MEDIUM,
    SYSTEM_BIG
};

}
class FontFactory
{

public:
    /**
     * @brief create
     * @param style
     * @return
     */
    static Font create(const fontStyle::FontStyle & style);

    /**
     * @brief create
     * @param fontString
     * @return
     */
    static Font create(const std::string & fontString);

private:
    FontFactory();
    FontFactory(const FontFactory &);
    FontFactory& operator=(const FontFactory&);
};
}}}//namespace
