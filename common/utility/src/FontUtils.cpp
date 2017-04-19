
#include "utility/inc/FontUtils.h"

namespace cbtek{
namespace common{
namespace utility{

Font::Font()
{
    m_changed=false;
    m_fontFamily="times";
    m_pointSize=10;
    m_isBold=false;
    m_isItalic=false;
    m_isUnderlined=false;
}

Font::Font(std::string fontFamily,
           size_t pointSize,
           bool isBold,
           bool isItalic,
           bool isUnderlined)
{
    m_fontFamily=fontFamily;
    m_pointSize=pointSize;
    m_isBold=isBold;
    m_isItalic=isItalic;
    m_isUnderlined=isUnderlined;
    m_changed=true;
}

bool Font::operator ==(const Font &font)
{
    return (font.getFontFamily()==m_fontFamily &&
            font.getPointSize()==m_pointSize &&
            font.isBold()==m_isBold &&
            font.isItalic()==m_isItalic &&
            font.isUnderlined()==m_isUnderlined);
}

void Font::setFontFamily(const std::string &fontFamily)
{
    m_fontFamily=fontFamily;
    m_changed=true;
}

void Font::setPointSize(const size_t &pointSize)
{
    m_pointSize=pointSize;
    m_changed=true;
}

void Font::setBold(const bool &enabled)
{
    m_isBold=enabled;
    m_changed=true;
}

void Font::setItalic(const bool &enabled)
{
    m_isItalic=enabled;
    m_changed=true;
}

void Font::setUnderlined(const bool &enabled)
{
    m_isUnderlined=enabled;
    m_changed=true;
}

bool Font::isBold() const
{
    return m_isBold;
}

bool Font::isItalic() const
{
    return m_isItalic;
}

bool Font::isUnderlined() const
{
    return m_isUnderlined;
}

std::string Font::getFontFamily() const
{
    return m_fontFamily;
}

size_t Font::getPointSize() const
{
    return m_pointSize;
}

std::string Font::toString() const
{
    return m_fontFamily +","+std::to_string(m_pointSize) + "," + std::to_string(m_isBold)+ "," + std::to_string(m_isItalic)+ "," + std::to_string(m_isUnderlined);
}

bool Font::hasDefaultChanged() const
{
    return m_changed;
}

void Font::setChanged(bool flag)
{
    m_changed=flag;
}

Font FontFactory::create(const fontStyle::FontStyle &style)
{
    switch(style)
    {
        case fontStyle::NORMAL:
            return Font("times",12);
        break;
        case fontStyle::HEADING_1:
            return Font("arial",16,true);
        break;
        case fontStyle::HEADING_2:
            return Font("arial",14,false);
        break;
        case fontStyle::HEADING_3:
            return Font("arial",14,false,true);
        break;
        case fontStyle::HEADING_4:
            return Font("arial",12,true,false);
        break;
        case fontStyle::HEADING_5:
            return Font("arial",12,true,true);
        break;
        case fontStyle::HEADING_6:
            return Font("arial",10,false,true);
        break;
        case fontStyle::HEADING_7:
            return Font("arial",10,true,false,true);
        break;
        case fontStyle::HEADING_8:
            return Font("arial",10,true,true,false);
        break;
        case fontStyle::HEADING_9:
            return Font("arial",8,true,false,true);
        break;
        case fontStyle::HEADING_10:
            return Font("arial",8);
        break;
        case fontStyle::SYSTEM_SMALL:
            return Font("system",8);
        break;
        case fontStyle::SYSTEM_BIG:
            return Font("system",10);
        break;
        case fontStyle::SYSTEM_MEDIUM:
            return Font("system",12);
        break;
        default:
            return Font();
        break;
    }
}

Font FontFactory::create(const std::string &fontString)
{
    std::vector<std::string> items = FontUtils_EmbeddedUtils::split(fontString,",");
    Font font;
    FontUtils_EmbeddedUtils::clean(items);
    if (items.size() > 4)
    {
        font.setFontFamily(items[0]);
        font.setPointSize(FontUtils_EmbeddedUtils::toNumber<size_t>(items[1]));
        font.setBold(FontUtils_EmbeddedUtils::toNumber<bool>(items[2]));
        font.setItalic(FontUtils_EmbeddedUtils::toNumber<bool>(items[3]));
        font.setUnderlined(FontUtils_EmbeddedUtils::toNumber<bool>(items[4]));
    }
    return font;
}
}}}//namespace
