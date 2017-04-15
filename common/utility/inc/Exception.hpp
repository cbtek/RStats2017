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

#include <exception>
#include <sstream>
#include <string>
#include <string.h>


#ifdef __WIN32
    #define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
    #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#define EXCEPTION_TAG "Exception thrown in "+std::string(__FILENAME__)+"::"+std::string(__func__)+", Line="+std::to_string(__LINE__)+": "
#define EXCEPTION_TAG_LINE "Exception thrown in "+std::string(__FILENAME__)+"::"+std::string(__func__)+", Line="+std::to_string(__LINE__)+": \n\n"
namespace cbtek{
namespace common{
namespace utility{

#define CREATE_EXCEPTION(NAME,MESSAGE) \
    class NAME : public std::exception\
    {\
        public:\
            NAME()\
            {\
                m_message=MESSAGE;\
            }\
            \
            NAME(const std::string & message)\
            {\
                m_message=message;\
            }\
            \
        ~NAME() throw(){}\
        virtual const char* what() const throw()\
        {\
            return m_message.c_str();\
        }\
        private:\
            std::string m_message;\
    };\


#define CREATE_EXCEPTION_NO_MSG(NAME) \
    class NAME : public std::exception\
    {\
        public:\
            NAME()\
            {\
                m_message="";\
            }\
            \
            NAME(const std::string & message)\
            {\
                m_message=message;\
            }\
            \
        ~NAME() throw(){}\
        virtual const char* what() const throw()\
        {\
            return m_message.c_str();\
        }\
        private:\
            std::string m_message;\
    };\

CREATE_EXCEPTION(GenericException,"")
CREATE_EXCEPTION(FeatureNotSupportedException,"Requested feature is not supported")
CREATE_EXCEPTION(FileNotFoundException,"FileNotFoundException")
CREATE_EXCEPTION(FileParseException,"FileParseException")
CREATE_EXCEPTION(FileAccessException,"FileAccessException")
CREATE_EXCEPTION(IndexOutOfRangeException,"Index is out of range")
CREATE_EXCEPTION(InvalidOperationException,"Invalid operation occured")
CREATE_EXCEPTION(InvalidParameterException,"Invalid parameter exception")
CREATE_EXCEPTION(InvalidMapKeyException,"Invalid Map Key")
CREATE_EXCEPTION(InvalidCastException,"Invalid Cast Exception")

#define THROW_GENERIC_EXCEPTION(MESSAGE) throw cbtek::common::utility::GenericException(EXCEPTION_TAG_LINE+MESSAGE);

}}}//namespace
