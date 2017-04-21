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

#include <chrono>
#include <ctime>
#include <sstream>
#include <string>

#include "utility/inc/UtilityCommon.hpp"

namespace cbtek{
namespace common{
namespace utility{
class DateTimeUtils_EmbeddedUtils
{

public:
    /**
    * @brief Converts string to upper-case
    * @param Reference to the string to convert
    */
    static void toUpperInPlace(std::string &str)
    {
        size_t count=str.size();
        for (size_t a1 = 0;a1<count;++a1)
        {
            str[a1] = static_cast<char>(toupper(str[a1]));
        }
    }


    /**
    * @brief Converts string to upper-case
    * @param The string to convert
    * @return The converted string
    */
    static std::string toUpper(const std::string &str)
    {
        std::string strOut = str;
        toUpperInPlace(strOut);
        return strOut;
    }


    /**
     * @brief Perfroms string replace (in-place)
     * @param inputString The string that contains oldString to replace
     * @param oldString The old string to replace
     * @param newString The new string to insert
     * @param isCaseSensitive Should oldString be caseSensitive
     * within inputString?
     * @return inputString with the replaced oldString.  If oldString
     * is not found within inputString then inputString is returned
     * unmodified.
     */
    static std::string replace(const std::string &inputString,
                                     const std::string &oldString,
                                     const std::string &newString,
                                     bool isCaseSensitive = c_DEFAULT_CASE_SENSITIVE)
    {

        if (isCaseSensitive)
        {
            std::string subject = inputString;
            std::string search  = oldString;
            std::string replace = newString;

                size_t pos = 0;
                while((pos = subject.find(search, pos)) != std::string::npos)
                {
                     subject.replace(pos, search.length(), replace);
                     pos += replace.length();
                }
                return subject;
        }
        else
        {
            std::string subject = (inputString);
            std::string search  = toUpper(oldString);
            std::string replace = toUpper(newString);

                size_t pos = 0;
                while((pos = subject.find(search, pos)) != std::string::npos)
                {
                     subject.replace(pos, search.length(), replace);
                     pos += replace.length();
                }
                return subject;
        }
    }


    /**
     * @brief contains
     * @param src
     * @param subStr
     * @param caseSensitive
     * @return
     */
    static bool contains(const std::string &srcStr,
                         const std::string &subStr,
                         bool caseSensitive = c_DEFAULT_CASE_SENSITIVE)
    {
        if (caseSensitive)
        {
            if (srcStr.find(subStr) != std::string::npos)
            {
                return true;
            }
        }
        else
        {
            if (toUpper(srcStr).find(toUpper(subStr)) !=
                    std::string::npos)
            {
                return true;
            }
        }
        return false;
    }

    template<typename T>
    static T toNumber(const std::string & value)
    {
        std::istringstream in(value,std::istringstream::in);
        T returnValue;
        in>>returnValue;
        return returnValue;
    }


};

class CBTEK_UTILS_DLL DateEntity
{

public:
    DateEntity()
    {
        m_month = 1;
        m_day = 1;
        m_year = 1970;
    }

    DateEntity(const size_t &month, const size_t &day, const size_t &year)
    {
        m_month = month;
        m_day = day;
        m_year = year;
    }

    DateEntity(const size_t &dateInteger)
    {
        std::string dateStr = std::to_string(dateInteger);
        if (dateStr.size() ==  8)
        {
            m_year = DateTimeUtils_EmbeddedUtils::toNumber<size_t>(dateStr.substr(0,4));
            m_month = DateTimeUtils_EmbeddedUtils::toNumber<size_t>(dateStr.substr(4,2));
            m_day = DateTimeUtils_EmbeddedUtils::toNumber<size_t>(dateStr.substr(6,2));
        }
        else
        {
            m_month = 1;
            m_day = 1;
            m_year = 1970;
        }
    }

    size_t getMonth() const
    {
        return m_month;
    }

    size_t getDay() const
    {
        return m_day;
    }

    size_t getYear() const
    {
        return m_year;
    }

    void setMonth(const size_t &month)
    {
        m_month = month;
    }

    void setDay(const size_t &day)
    {
        m_day = day;
    }

    void setYear(const size_t &year)
    {
        m_year = year;
    }

    size_t toDateInteger() const
    {
        std::string dateStr = std::to_string(m_year)+
                (m_month<10?"0"+std::to_string(m_month):std::to_string(m_month))+
                (m_day<10?"0"+std::to_string(m_day):std::to_string(m_day));
        return DateTimeUtils_EmbeddedUtils::toNumber<size_t>(dateStr);
    }

    bool operator <(const DateEntity &date) const
    {
       return toDateInteger() < date.toDateInteger();
    }

    bool operator<= (const DateEntity &date) const
    {
        return toDateInteger()<=  date.toDateInteger();
    }

    bool operator >(const DateEntity &date) const
    {
        return toDateInteger()>date.toDateInteger();
    }

    bool operator>= (const DateEntity &date) const
    {
        return toDateInteger()>= date.toDateInteger();
    }

    bool operator  ==  (const DateEntity &date) const
    {
        return toDateInteger() ==  date.toDateInteger();
    }

    bool operator!= (const DateEntity &date) const
    {
        return toDateInteger()!= date.toDateInteger();
    }

    size_t operator -(const DateEntity &date) const
    {

        size_t lowYear = 0,highYear = 0;
        size_t days = 0;
        if (m_year<date.getYear())
        {
            lowYear = m_year;
            highYear = date.getYear();
        }

        else if (m_year>date.getYear())
        {
            lowYear = date.getYear();
            highYear = m_year;
        }

        for (size_t a1 = lowYear;a1<highYear;++a1)
        {
            days+= 365;
            if (DateEntity(1,1,a1).isLeapYear())
            {
                days++;
            }
        }
        DateEntity d1(date.getMonth(),date.getDay(),1901);
        DateEntity d2(getMonth(),getDay(),1901);
        size_t d1Days = d1.getDays();
        size_t d2Days = d2.getDays();
        if (d1Days>d2Days)
        {
            days +=  d1Days-d2Days;
        }
        else
        {
            days +=  d2Days-d1Days;
        }

        return days;
    }

    bool isLeapYear() const
    {
    //    The year is evenly divisible by 4;
    //    If the year can be evenly divided by 100, it is NOT a leap year, unless;
    //    The year is also evenly divisible by 400. Then it is a leap year.
        return ((m_year % 4  ==  0 && m_year % 100 !=  0) || m_year % 400  ==   0);
    }

    size_t getDays() const
    {
        size_t daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        size_t days = 0;
        for (size_t a1 = 0;a1<m_month-1;++a1)
        {
            if (a1 < 12)
            {
                if(a1 ==  1 && isLeapYear())
                {
                    days+= daysInMonth[a1]+1;
                }
                else
                {
                    days+= daysInMonth[a1];
                }
            }
        }
        return days+(m_day);
    }

private:
    size_t m_month;
    size_t m_day;
    size_t m_year;
};


class CBTEK_UTILS_DLL TimeEntity
{
public:

    TimeEntity(const size_t &time)
    {

        std::string timeStr = std::to_string(time);
        if (timeStr.size() == 6)
        {
            m_hour = DateTimeUtils_EmbeddedUtils::toNumber<size_t>(timeStr.substr(0,2));
            m_minute = DateTimeUtils_EmbeddedUtils::toNumber<size_t>(timeStr.substr(2,2));
            m_second = DateTimeUtils_EmbeddedUtils::toNumber<size_t>(timeStr.substr(4,2));
        }
        else if (timeStr.size() ==  5)
        {
            m_hour = DateTimeUtils_EmbeddedUtils::toNumber<size_t>(timeStr.substr(0,1));
            m_minute = DateTimeUtils_EmbeddedUtils::toNumber<size_t>(timeStr.substr(1,2));
            m_second = DateTimeUtils_EmbeddedUtils::toNumber<size_t>(timeStr.substr(3,2));
        }
        else
        {
            m_hour = 0;
            m_minute = 0;
            m_second = 0;

        }
        m_millisecond = 0;
    }

    TimeEntity()
    {
        m_hour = 0;
        m_minute = 0;
        m_second = 0;
        m_millisecond = 0;
    }

    TimeEntity(size_t hour,
                           size_t minute,
                           size_t second,
                           size_t millisecond = 0)
    {
        m_hour = hour;
        m_minute = minute;
        m_second = second;
        m_millisecond = millisecond;
    }

    bool operator>(const TimeEntity &time) const
    {
        return (this->getAsSeconds() > time.getAsSeconds());
    }

    bool operator<(const TimeEntity &time) const
    {
        return (this->getAsSeconds() < time.getAsSeconds());
    }

    bool operator<= (const TimeEntity &time) const
    {
        return (this->getAsSeconds() <=  time.getAsSeconds());
    }

    bool operator>= (const TimeEntity &time) const
    {
        return (this->getAsSeconds() >=  time.getAsSeconds());
    }

    bool operator==  (const TimeEntity &time) const
    {
        return (time.getHour() ==  m_hour && time.getMinute() ==  m_minute && time.getSecond() ==  m_second && time.getMillisecond() ==  m_millisecond);
    }

    void setHour(const size_t &hour)
    {
        m_hour = hour;
    }

    void setMinute(const size_t &minute)
    {
        m_minute = minute;
    }

    void setSecond(const size_t &second)
    {
        m_second = second;
    }

    void setMillisecond(const size_t &millisecond)
    {
        m_millisecond = millisecond;
    }

    size_t getHour() const
    {
        return m_hour;
    }

    size_t getMinute() const
    {
        return m_minute;
    }

    size_t getSecond() const
    {
        return m_second;
    }

    size_t getMillisecond() const
    {
        return m_millisecond;
    }

    size_t toTimeInteger() const
    {
        std::string hourStr = std::to_string(m_hour);
        std::string minStr = std::to_string(m_minute);
        std::string secStr = std::to_string(m_second);
        std::string timeStr = (m_hour<10?"0"+hourStr:hourStr) + (m_minute<10?"0"+minStr:minStr) + (m_second<10?"0"+secStr:secStr);
        return DateTimeUtils_EmbeddedUtils::toNumber<size_t>(timeStr);
    }

    size_t getAsMinutes() const
    {
        return (m_hour*60)+m_minute;
    }

    size_t getAsSeconds() const
    {
        return (getAsMinutes()*60)+m_second;
    }

    size_t getAsMilliseconds() const
    {
        return (getAsSeconds()*1000)+m_millisecond;
    }

    size_t getAsMicroseconds() const
    {
        return (getAsMilliseconds()*1000);
    }

private:
    size_t m_hour;
    size_t m_minute;
    size_t m_second;
    size_t m_millisecond;
};



typedef std::chrono::system_clock SystemClock;
typedef std::chrono::high_resolution_clock HighResolutionClock;
typedef HighResolutionClock::time_point HighResolutionTimePoint;
typedef SystemClock::time_point SystemTimePoint;
typedef std::chrono::milliseconds Milliseconds;
typedef std::chrono::microseconds Microseconds;
typedef std::chrono::nanoseconds Nanoseconds;
typedef std::chrono::seconds Seconds;

class TimeUtils
{

public:
    /**
     * @brief toString
     * @param value
     * @return
     */
    template <typename T>
    static std::string toString(T value)
    {
        std::ostringstream out;
        out << value;
        return out.str();
    }

    /**
     * @brief getSecondsNow
     * @return
     */
   static uint64_t getSecondsNow()
    {
        return static_cast<std::uint64_t>(time(NULL));
    }

    /**
     * @brief getNanosecondsNow
     * @return
     */
    static double getNanosecondsNow()
    {
        HighResolutionTimePoint tp = HighResolutionClock::now();
        Seconds secs= std::chrono::duration_cast<Seconds>(tp.time_since_epoch());
        return secs.count();
    }

    /**
     * @brief getMicrosecondsNow
     * @return
     */
    static double getMicrosecondsNow()
    {
        HighResolutionTimePoint tp = HighResolutionClock::now();
        Microseconds secs= std::chrono::duration_cast<Microseconds>(tp.time_since_epoch());
        return secs.count();
    }

    /**
     * @brief getCurrentMilliseconds
     * @return
     */
    static std::uint64_t getCurrentMilliseconds()
    {
        std::chrono::milliseconds ms = std::chrono::duration_cast< std::chrono::milliseconds >(
        std::chrono::system_clock::now().time_since_epoch());
        return static_cast<std::uint64_t>(ms.count());
    }

    /**
     * @brief getMillisecondsNow
     * @return
     */
    static double getMillisecondsNow()
    {
        HighResolutionTimePoint tp = HighResolutionClock::now();
        Milliseconds secs= std::chrono::duration_cast<Milliseconds>(tp.time_since_epoch());
        return secs.count();
    }

    /**
     * @brief toTimeString
     * @param time
     * @return
     */
    static std::string toTimeString(const TimeEntity &time)
    {
        return (time.getHour()<10?"0":"")+toString(time.getHour())+":"+(time.getMinute()<10?"0":"")+toString(time.getMinute())+":"+(time.getSecond()<10?"0":"")+toString(time.getSecond());
    }

    /**
     * @brief to12HourTimeString
     * @param time
     * @return
     */
    static std::string to12HourTimeString(const TimeEntity &time)
    {
        std::string extension="AM";
        size_t hour=time.getHour();
        if (time.getHour()>11 )
        {
            extension="PM";
            if (time.getHour()!=12)
            {
                hour=time.getHour()-12;
            }
        }

        if (hour==0)
        {
            hour=12;
        }

        return (hour<10?"0":"")+toString(hour)+":"+(time.getMinute()<10?"0":"")+toString(time.getMinute())+":"+(time.getSecond()<10?"0":"")+toString(time.getSecond())+ " "+extension;
    }

    /**
     * @brief getCurrentTime
     * @return
     */
    static TimeEntity getCurrentTime()
    {
        time_t t = time(0);
        struct tm * now = localtime( & t );
        return TimeEntity(static_cast<size_t>(now->tm_hour),
                          static_cast<size_t>(now->tm_min),
                          static_cast<size_t>(now->tm_sec));
    }

    /**
     * @brief getTimeFromSeconds
     * @param secs
     * @return
     */
    static TimeEntity getTimeFromSeconds(const uint64_t &secs)
    {
        TimeEntity tm;
        tm.setHour(secs/3600);
        tm.setMinute((secs%3600)/60);
        tm.setSecond((secs%3600)%60);
        return tm;
    }

    /**
     * @brief getTimeFromMilliseconds
     * @param ms
     * @return
     */
    static TimeEntity getTimeFromMilliseconds(const uint64_t &ms)
    {
        return getTimeFromSeconds(ms/1000);
    }

    /**
     * @brief toCurrentTimeString
     * @return
     */
    static std::string toCurrentTimeString()
    {
        return toTimeString(getCurrentTime());
    }

    /**
     * @brief toCurrent12HourTimeString
     * @return
     */
    static std::string toCurrent12HourTimeString()
    {
        return to12HourTimeString(getCurrentTime());
    }
};


class DateUtils
{

private:
    DateUtils();
    DateUtils& operator=(const DateUtils&);
    DateUtils(const DateUtils&);
    ~DateUtils();

public:
    /**
     * @brief toShortDateString
     * @param date
     * @param format
     * @return
     */
    static std::string toShortDateString(const DateEntity &date,
                                         const std::string &format="mm-dd-yyyy")
    {
        std::string dateStr=format;

        if (DateTimeUtils_EmbeddedUtils::contains(dateStr,"yyyy"))
        {
            dateStr = DateTimeUtils_EmbeddedUtils::replace(dateStr,"yyyy",std::to_string(date.getYear()));
        }

        if(DateTimeUtils_EmbeddedUtils::contains(dateStr,"mm"))
        {
            dateStr=DateTimeUtils_EmbeddedUtils::replace(dateStr,"mm",(date.getMonth()<10?"0"+std::to_string(date.getMonth()):std::to_string(date.getMonth())));
        }

        if(DateTimeUtils_EmbeddedUtils::contains(dateStr,"dd"))
        {
            dateStr=DateTimeUtils_EmbeddedUtils::replace(dateStr,"dd",(date.getDay()<10?"0"+std::to_string(date.getDay()):std::to_string(date.getDay())));
        }
        return dateStr;
    }

    /**
     * @brief toLongDateString
     * @param date
     * @return
     */
    static std::string toLongDateString(const DateEntity &date)
    {
        std::string months[12] =
        {
            "January","February","March","April",
            "May","June","July","August",
            "September","October","November","December"
        };

        if (date.getMonth() <13)
        {
            return months[date.getMonth()-1]+" "+std::to_string(date.getDay())+", "+std::to_string(date.getYear());
        }
        return "";
    }

    /**
     * @brief getCurrentDate
     * @return
     */
    static DateEntity getCurrentDate()
    {
        time_t t = time(0);
        struct tm * now = localtime( & t );
        return DateEntity(static_cast<size_t>(now->tm_mon + 1),
                          static_cast<size_t>(now->tm_mday),
                          static_cast<size_t>(now->tm_year + 1900));
    }

    /**
     * @brief toCurrentLongDateString
     * @return
     */
    static std::string toCurrentLongDateString()
    {
        return toLongDateString(getCurrentDate());
    }

    /**
     * @brief toCurrentShortDateString
     * @return
     */
    static std::string toCurrentShortDateString()
    {
        return toShortDateString(getCurrentDate());
    }

};


class DateTimeUtils
{

public:
    /**
     * @brief getDisplayTimeStamp
     * @param dateEntity
     * @param timeEntity
     * @return
     */
    static std::string getDisplayTimeStamp(const DateEntity& dateEntity,
                                           const TimeEntity& timeEntity)
    {
        return (DateUtils::toShortDateString(dateEntity,"mm/dd/yyyy")+" at "+TimeUtils::to12HourTimeString(timeEntity));
    }

    /**
     * @brief getDisplayTimeStamp
     * @return
     */
    static std::string getDisplayTimeStamp()
    {
        return getDisplayTimeStamp(DateUtils::getCurrentDate(),TimeUtils::getCurrentTime());
    }

    /**
     * @brief getTimeStampInteger
     * @param dateEntity
     * @param timeEntity
     * @return
     */
    static std::uint64_t getTimeStampInteger(const DateEntity& dateEntity=DateUtils::getCurrentDate(),
                                             const TimeEntity& timeEntity=TimeUtils::getCurrentTime())
    {
        return std::strtoull(((std::to_string(dateEntity.toDateInteger()) + std::to_string(timeEntity.toTimeInteger()))).c_str(), NULL,10);
    }

    /**
     * @brief getTimeStamp
     * @return
     */
    static std::string getTimeStamp()
    {
        return (DateUtils::toShortDateString(DateUtils::getCurrentDate(),"yyyymmdd")+"T"+std::to_string(TimeUtils::getCurrentTime().toTimeInteger())+"."+std::to_string(static_cast<std::uint64_t>(TimeUtils::getMillisecondsNow())));
    }

    /**
     * @brief getTimeStamp
     * @param dateEntity
     * @param timeEntity
     * @return
     */
    static std::string getTimeStamp(const DateEntity& dateEntity,
                                    const TimeEntity& timeEntity)
    {
        return (DateUtils::toShortDateString(dateEntity,"yyyymmdd")+"T"+std::to_string(timeEntity.toTimeInteger()));
    }
};

}}} //namespace
