/*
    RStatsObjectList.h
    
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
#include <map>
#include <string>
#include <vector>
#include <set>
#include <tgmath.h>
#include <algorithm>

#include "utility/inc/Exception.hpp"

namespace cbtek {
namespace rocketstats {
namespace utils {

typedef float float32_t;
typedef double float64_t;
typedef long double float128_t;

/**
 * @brief The RStatsObjectList class is used to represent a simple N-dimensional
 * array with similar add/remove syntax with VB/VBA
 */
template <typename T>
class RStatsObjectList
{
public:
    /**
     * @brief RStatsObjectList (Constructor)
     */
    RStatsObjectList();

    /**
     * @brief RStatsObjectList (Constructor)
     * @param size The total size of the array
     * @param dimensionCount The number of dimensions to create
     */
    RStatsObjectList(size_t size, size_t dimensionCount = 1);

    /**
     * @brief initialize
     * @param size The total size of the array
     * @param dimensionCount The number of dimensions to create
     */
    void initialize(size_t size, size_t dimensionCount = 1);

    /**
     * @brief size Returns the size of the vector at specified dimension
     * @return Return size_t size of vector at specified dimension
     */
    size_t size(size_t dimension = 0) const;

    /**
     * @brief resize Resizes all dimensions to newSize
     * @param newSize New size for all dimensions
     */
    void resize(size_t newSize);

    /**
     * @brief operator () Used to access the data by reference
     * @param index Index of the element to access
     * @param dimension The dimension to access
     * @return Return reference to type T
     */
    T & operator()(size_t index, size_t dimension = 0);

    /**
     * @brief operator () Used to access the data by const reference
     * @param index Index of the element to access
     * @param dimension The dimension to access
     * @return Return const reference to type T
     */
    const T & operator()(size_t index, size_t dimension = 0) const;

    /**
     * @brief toString Converts all elements into a string and returns it
     * @return Return string containing all elements
     */
    std::string toString() const;

    /**
     * @brief toString
     * @param orderByDimension
     * @return
     */
    std::string toString(size_t orderByDimension) const;

    /**
     * @brief getNumDimensions
     * @return
     */
    size_t getNumDimensions() const;

    /**
     * @brief addValues
     * @param values
     * @param dimensionForValues
     */
    void addValues(const RStatsObjectList<T>& values,
                   size_t sourceDimension = 0);

    /**
     * @brief addValues
     * @param values
     */
    void addValues(const std::vector<T>& values);


    /**
     * @brief getValues
     * @param dimension
     * @return
     */
    RStatsObjectList<T> getValues(size_t dimension = 0) const;

    /**
     * @brief toStdVector
     * @param dimension
     * @return
     */
    const std::vector<T>& toStdVector(size_t dimension = 0) const;

    /**
     * @brief clear
     */
    void clear();

    /**
     * @brief sort
     * @param dimension
     */
    void sort(size_t dimension = 0);

    //! Destructor
    ~RStatsObjectList();
private:
    std::vector<std::vector<T> > m_values;
    
};


template <typename T>
RStatsObjectList<T>::RStatsObjectList()
{

}

template <typename T>
RStatsObjectList<T>::RStatsObjectList(size_t size, size_t dimensionCount)
{
    this->initialize(size,dimensionCount);
}

template <typename T>
RStatsObjectList<T>::~RStatsObjectList()
{

}

template <typename T>
void RStatsObjectList<T>::initialize(size_t size, size_t dimensionCount)
{
    m_values.clear();
    m_values.resize(dimensionCount);
    for (size_t a1 = 0;a1 < dimensionCount; ++a1)
    {
        m_values[a1].resize(size);
    }
}

template <typename T>
size_t RStatsObjectList<T>::size(size_t dimension) const
{
    if (dimension < m_values.size())
    {
        return m_values[dimension].size();
    }
    throw cbtek::common::utility::IndexOutOfRangeException(EXCEPTION_TAG_LINE+"Dimension is out of range!");
}

template<typename T>
void RStatsObjectList<T>::resize(size_t newSize)
{
    for (auto& values : m_values)
    {
        values.resize(newSize);
    }
}

template <typename T>
T &RStatsObjectList<T>::operator()(size_t index, size_t dimension)
{
    if (dimension < m_values.size())
    {
        if (index < m_values[dimension].size())
        {
            return m_values[dimension][index];
        }
        else throw cbtek::common::utility::IndexOutOfRangeException(EXCEPTION_TAG_LINE+"Dimension is out of range.");
    }
    else throw cbtek::common::utility::IndexOutOfRangeException(EXCEPTION_TAG_LINE+"Index is out of range.");
}

template <typename T>
const T &RStatsObjectList<T>::operator()(size_t index, size_t dimension) const
{
    if (dimension < m_values.size())
    {
        if (index < m_values[dimension].size())
        {
            return m_values[dimension][index];
        }
        else throw cbtek::common::utility::IndexOutOfRangeException(EXCEPTION_TAG_LINE+"Dimension is out of range.");
    }
    else throw cbtek::common::utility::IndexOutOfRangeException(EXCEPTION_TAG_LINE+"Index is out of range.");
}

template <typename T>
std::string RStatsObjectList<T>::toString() const
{
    std::ostringstream out;
    for (size_t a1 = 0;a1 < m_values.size();++a1)
    {
        out << "["<<a1<<"]: ";
        for (size_t a2 = 0;a2 < m_values[a1].size();++a2)
        {
            out << m_values[a1][a2]<<((a2 < m_values[a1].size()-1) ? "," : "\n" );
        }
    }
    return out.str();
}

template <typename T>
std::string RStatsObjectList<T>::toString(size_t orderByDimension) const
{
    std::ostringstream out;
    std::map<T, std::pair<size_t,std::vector<T> > > numberMap;
    for (size_t a1 = 0;a1 < m_values.size();++a1)
    {
        for (size_t a2 = 0;a2 < m_values[a1].size();++a2)
        {
            if (a2 == orderByDimension)
            {
                numberMap[m_values[a1][a2]] = std::make_pair(a1,m_values[a1]);
            }
        }
    }

    for (auto itSorted : numberMap)
    {
        out << "["<<itSorted.second.first<<"]: ";
        for (size_t a2 = 0;a2 < itSorted.second.second.size();++a2)
        {
            out << itSorted.second.second[a2]<< ", ";
        }
        out << std::endl;
    }

    return out.str();
}

template<typename T>
size_t RStatsObjectList<T>::getNumDimensions() const
{
    return m_values.size();
}

template<typename T>
void RStatsObjectList<T>::addValues(const RStatsObjectList<T> &values,
                                       size_t dimensionForValues)
{
    if (values.size()  == 0)
    {
        return;
    }

    m_values.push_back(std::vector<T> ());
    for (size_t a1 = 0 ;a1 < values.size(dimensionForValues);++a1)
    {
        m_values.back().push_back(values(a1,dimensionForValues));
    }
}

template<typename T>
void RStatsObjectList<T>::addValues(const std::vector<T> &values)
{
    if (values.size()  == 0)
    {
        return;
    }
    m_values.push_back(values);
}

template<typename T>
void RStatsObjectList<T>::clear()
{
    m_values.clear();
}


template<typename T>
RStatsObjectList<T> RStatsObjectList<T>::getValues(size_t dimension) const
{
    if (dimension < this->getNumDimensions())
    {
        RStatsObjectList<T> values;
        size_t count = this->size(dimension);
        values.initialize(count);
        for (size_t a1 = 0; a1 < count; ++a1)
        {
            values(a1) = this->operator ()(a1,dimension);
        }
        return values;
    }
    throw cbtek::common::utility::IndexOutOfRangeException(EXCEPTION_TAG_LINE+"Dimension index is out of range!");
}


template<typename T>
const std::vector<T> &RStatsObjectList<T>::toStdVector(size_t dimension) const
{
    if (dimension < m_values.size())
    {
        return m_values[dimension];
    }
    throw cbtek::common::utility::IndexOutOfRangeException(EXCEPTION_TAG_LINE+"Dimension index is out of range!");
}

template<typename T>
void RStatsObjectList<T>::sort(size_t dimension)
{
    if (dimension < this->getNumDimensions())
    {
        std::sort(m_values[dimension].begin(),
                  m_values[dimension].end());
    }
}

typedef RStatsObjectList<std::int64_t> RStatsInt64List;
typedef RStatsObjectList<float32_t> RStatsFloat32List;
typedef RStatsObjectList<float64_t> RStatsFloat64List;
typedef RStatsObjectList<float128_t> RStatsFloat128List;
typedef RStatsObjectList<std::string> RStatsStringList;

}}}//end namespace


