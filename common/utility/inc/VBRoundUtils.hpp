#pragma once

#include <time.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>

namespace cbtek {
namespace common {
namespace utility {
namespace VBRoundUtils {
    namespace library
    {
        #ifdef __ANDROID__
        inline std::int64_t qbr(long double f)
        {
          std::int64_t i; int temp=0;
          if (f>9223372036854775807) {temp=1;f=f-9223372036854775808u;} //if it's too large for a signed std::int64_t, make it an unsigned std::int64_t and return that value if possible.
          if (f<0) i=f-0.5f; else i=f+0.5f;
          if (temp) return i|0x8000000000000000;//+9223372036854775808;
          return i;
        }
        inline std::uint64_t qbr_longdouble_to_uint64(long double f){if (f<0) return(f-0.5f); else return(f+0.5f);}
        inline std::int32_t qbr_float_to_long(float f){if (f<0) return(f-0.5f); else return(f+0.5f);}
        inline std::int32_t qbr_double_to_long(double f){if (f<0) return(f-0.5f); else return(f+0.5f);}
        #else
        //QBASIC compatible rounding via FPU:
//        #ifdef __WIN32
//        inline std::int64_t qbr(long double f){
//          std::int64_t i; int temp=0;
//          if (f>9223372036854775807) {temp=1;f=f-9223372036854775808u;} //if it's too large for a signed std::int64_t, make it an unsigned std::int64_t and return that value if possible.
//          __asm{
//              fld   f
//              fistp i
//              }
//          if (temp) return i|0x8000000000000000;//+9223372036854775808;
//          return i;
//        }
//        inline std::uint64_t qbr_longdouble_to_uint64(long double f)
//        {
//          std::uint64_t i;
//          __asm{
//            fld   f
//              fistp i
//              }
//          return i;
//        }

//        inline std::int32_t qbr_float_to_long(float f)
//        {
//          int32 i;
//          __asm{
//            fld   f
//              fistp i
//              }
//          return i;
//        }
//        inline std::int32_t qbr_double_to_long(double f)
//        {
//          std::int32_t i;
//          __asm{
//            fld   f
//              fistp i
//              }
//          return i;
//        }
//        #else
            //FLDS=load single
            //FLDL=load double
            //FLDT=load long double
            inline std::int64_t qbr(long double f)
            {
              std::int64_t i; int temp=0;
              if (f>9223372036854775807) {temp=1;f=f-9223372036854775808u;} //if it's too large for a signed std::int64_t, make it an unsigned std::int64_t and return that value if possible.
              __asm__ (
                       "fldt %1;"
                       "fistpll %0;"
                       :"=m" (i)
                       :"m" (f)
                       );
              if (temp) return i|0x8000000000000000;// if it's an unsigned std::int64_t, manually set the bit flag
              return i;
            }
            inline std::uint64_t qbr_longdouble_to_uint64(long double f){
              std::uint64_t i;
              __asm__ (
                       "fldt %1;"
                       "fistpll %0;"
                       :"=m" (i)
                       :"m" (f)
                       );
              return i;
            }
            inline std::int32_t qbr_float_to_long(float f)
            {
              std::int32_t i;
              __asm__ (
                       "flds %1;"
                       "fistpl %0;"
                       :"=m" (i)
                       :"m" (f)
                       );
              return i;
            }
            inline int32_t qbr_double_to_long(double f)
            {
              int32_t i;
              __asm__ (
                       "fldl %1;"
                       "fistpl %0;"
                       :"=m" (i)
                       :"m" (f)
                       );
              return i;
            }
            //#endif
        #endif //x86 support
    }

    inline std::int64_t vbRound(long double value)
    {
        return library::qbr(value);
    }

} // VBRoundUtils
}}} // namespace
