// ***********************************************************************
// Filename         : Types.h
// Author           : XULI
// Created          : 2020-10-16
// Description      : 转换函数
// ***********************************************************************
#ifndef _TYPES_H_
#define _TYPES_H_
#include <string>

namespace XL
{
    using std::string;
    template <typename To, typename From>
    inline To implicit_cast(From const &f)
    {
        return f;
    }

    template <typename To, typename From>
    inline To down_cast(From *f)
    {
        return static_cast<To>(f);
    }

} // namespace XL

#endif