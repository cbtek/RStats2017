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

#include "TimeUtils.hpp"
#include "DateUtils.hpp"
#include "StringUtils.hpp"

namespace cbtek{
namespace common{
namespace utility{
namespace DateTimeUtils{

/**
 * @brief getDisplayTimeStamp
 * @param dateEntity
 * @param timeEntity
 * @return
 */
inline std::string getDisplayTimeStamp(const DateEntity& dateEntity,
                                       const TimeEntity& timeEntity)
{
    return (DateUtils::toShortDateString(dateEntity,"mm/dd/yyyy")+" at "+StringUtils::toString(TimeUtils::to12HourTimeString(timeEntity)));
}

/**
 * @brief getDisplayTimeStamp
 * @return
 */
inline std::string getDisplayTimeStamp()
{
    return getDisplayTimeStamp(DateUtils::getCurrentDate(),TimeUtils::getCurrentTime());
}

/**
 * @brief getTimeStampInteger
 * @param dateEntity
 * @param timeEntity
 * @return
 */
inline std::uint64_t getTimeStampInteger(const DateEntity& dateEntity=DateUtils::getCurrentDate(),
                                         const TimeEntity& timeEntity=TimeUtils::getCurrentTime())
{
    return StringUtils::toUInt(std::to_string(dateEntity.toDateInteger())+std::to_string(timeEntity.toTimeInteger()));
}

/**
 * @brief getTimeStamp
 * @return
 */
inline std::string getTimeStamp()
{
    return (DateUtils::toShortDateString(DateUtils::getCurrentDate(),"yyyymmdd")+"T"+StringUtils::toString(TimeUtils::getCurrentTime().toTimeInteger())+"."+StringUtils::toString((std::uint64_t)TimeUtils::getMillisecondsNow()));
}

/**
 * @brief getTimeStamp
 * @param dateEntity
 * @param timeEntity
 * @return
 */
inline std::string getTimeStamp(const DateEntity& dateEntity,
                                const TimeEntity& timeEntity)
{
    return (DateUtils::toShortDateString(dateEntity,"yyyymmdd")+"T"+StringUtils::toString(timeEntity.toTimeInteger()));
}

}}}} //namespace
