/*
    RStatsUtils.h
    
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

#include <cinttypes>
#include <vector>
#include <cfloat>
#include <cmath>

#include "RStatsObjectList.hpp"

namespace oig {
namespace ratstats {
namespace utils {

/***********************************************************/
/**/
/**/    typedef oig::ratstats::utils::float64_t RStatsFloat;
/**/    typedef std::int64_t RStatsInteger;
/**/    typedef oig::ratstats::utils::RStatsObjectList<RStatsFloat> RStatsFloatList;
/**/    typedef oig::ratstats::utils::RStatsObjectList<RStatsInteger> RStatsIntegerList;
/**/
/***********************************************************/

enum class RStatsCalculationType
{
    Subtract,
    Multiply,
    Add,
    Divide
};

enum class RStatsConditionalOperatorType
{
    Equal,
    NotEqual,
    LessThan,
    LessThanOrEqualTo,
    GreaterThan,
    GreaterThanOrEqualTo
};

namespace RStatsUtils
{
    template <typename Integer>
    static Integer ipow(Integer base, Integer exp)
    {
        Integer result = 1;
        while (exp)
        {
            if (exp & 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }
        return result;
    }


    /**
     * @brief isEqual
     * @param value1
     * @param value2
     * @return
     */
    template <typename Float>
    static bool isEqual(Float value1, Float value2)
    {
        return (value1 - value2) < FLT_EPSILON;
    }

    /**
     * @brief getSum
     * @param values
     * @param dimension
     * @return
     */
    template <typename Number>
    static Number getSum(const RStatsObjectList<Number>& values,
                         size_t dimension = 0)
    {
        Number sum = 0.;
        size_t size = values.size(dimension);
        for (size_t a1 = 0; a1 < size; ++a1 )
        {
            sum += values(a1,dimension);
        }
        return sum;
    }

    /**
     * @brief getSumRaisedTo
     * @param values
     * @param power
     * @param dimension
     * @return
     */
    template <typename Float>
    static Float getSumRaisedTo(const RStatsObjectList<Float>& values,
                                Float power,
                                size_t dimension = 0)
    {
        Float sum = 0.;
        size_t size = values.size(dimension);
        for (size_t a1 = 0; a1 < size; ++a1 )
        {
            sum += std::pow(values(a1,dimension),power);
        }
        return sum;
    }

    template <typename Number>
    static size_t getNumItemsThatMatchCondition(RStatsConditionalOperatorType condition,
                                                const RStatsObjectList<Number>& values,
                                                Number value,
                                                size_t dimension = 0)
    {
        size_t count = 0;
        size_t size = values.size(dimension);
        for (size_t a1 = 0; a1 < size; ++a1 )
        {
            if (condition == RStatsConditionalOperatorType::Equal &&
                isEqual(values(a1,dimension), value))
            {
                ++count;
            }
            else if (condition == RStatsConditionalOperatorType::NotEqual &&
                     !isEqual(values(a1,dimension), value))
            {
                ++count;
            }
            else if (condition == RStatsConditionalOperatorType::GreaterThan &&
                     values(a1,dimension) > value)
            {
                ++count;
            }
            else if (condition == RStatsConditionalOperatorType::LessThan &&
                     values(a1,dimension) < value)
            {
                ++count;
            }
            else if (condition == RStatsConditionalOperatorType::GreaterThanOrEqualTo &&
                     (values(a1,dimension) > value || RStatsUtils::isEqual(values(a1,dimension), value)))
            {
                ++count;
            }
            else if (condition == RStatsConditionalOperatorType::LessThanOrEqualTo &&
                     (values(a1,dimension) < value || RStatsUtils::isEqual(values(a1,dimension), value)))
            {
                ++count;
            }
        }
        return count;
    }

    template<typename Number>
    static void calculate(const RStatsObjectList<Number>& input1,
                          const RStatsObjectList<Number>& input2,
                          RStatsObjectList<Number> &result,
                          RStatsCalculationType calculation,
                          size_t dimension = 0)
    {
        size_t input1Size = input1.size(dimension);
        size_t input2Size = input2.size(dimension);

        if (input1Size == input2Size)
        {
            result.initialize(input1Size,1);
            switch (calculation)
            {
                case RStatsCalculationType::Add:
                {
                    for (size_t a1 = 0; a1 < input1Size; ++a1)
                    {
                        result(a1) = input1(a1,dimension) + input2(a1, dimension);
                    }
                }
                break;
                case RStatsCalculationType::Subtract:
                {
                    for (size_t a1 = 0; a1 < input1Size; ++a1)
                    {
                        result(a1) = input1(a1,dimension) - input2(a1, dimension);
                    }
                }
                break;
                case RStatsCalculationType::Multiply:
                {
                    for (size_t a1 = 0; a1 < input1Size; ++a1)
                    {
                        result(a1) = input1(a1,dimension) * input2(a1, dimension);
                    }
                }
                break;
                case RStatsCalculationType::Divide:
                {
                    for (size_t a1 = 0; a1 < input1Size; ++a1)
                    {
                        Number value = input2(a1, dimension);
                        if (isEqual(value, 0.))
                        {
                            continue;
                        }

                        result(a1) = input1(a1,dimension) / value;
                    }
                }
                break;
            }
        }
    }

    template<typename Number>
    static RStatsObjectList<Number> getNumbersAdded(const RStatsObjectList<Number>& input1,
                                                    const RStatsObjectList<Number>& input2,
                                                    size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Add,dimension);
        return values;
    }

    template<typename Number>
    static RStatsObjectList<Number> getNumbersSubtracted(const RStatsObjectList<Number>& input1,
                                                         const RStatsObjectList<Number>& input2,
                                                         size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Subtract,dimension);
        return values;
    }

    template<typename Number>
    static RStatsObjectList<Number> getNumbersMultiplied(const RStatsObjectList<Number>& input1,
                                                         const RStatsObjectList<Number>& input2,
                                                         size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Multiply,dimension);
        return values;
    }

    template<typename Number>
    static RStatsObjectList<Number> getNumbersDivided(const RStatsObjectList<Number>& input1,
                                                      const RStatsObjectList<Number>& input2,
                                                      size_t dimension = 0)
    {
        RStatsObjectList<Number> values;
        calculate(input1,input2,values,RStatsCalculationType::Divide,dimension);
        return values;
    }


}
}}}//end namespace

