/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-06-01 14:29:03
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-05 14:52:30
 */
#include "include/Buffer.h"
#include <string.h>
#include <iostream>

void Buffer::append(const char *_str, int _size)
{
    for (int i = 0; i < _size; ++i)
    {
        if (_str[i] == '\0')
            break;
        buf_.push_back(_str[i]);
    }
}

ssize_t Buffer::size()
{
    return buf_.size();
}

const char*  Buffer::c_str()
{
    return buf_.c_str();
}

void Buffer::clear()
{
    buf_.clear();
}

void Buffer::getline()
{
    buf_.clear();
    std::getline(std::cin,buf_);
}

void Buffer::setBuf(const char * buf)
{
    buf_.clear();
    buf_.append(buf);
}