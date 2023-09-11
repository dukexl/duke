/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-06-01 14:20:13
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-05 14:48:00
 */
#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <string>
#include "Macros.h"

class Buffer
{
private:
    std::string buf_;

public:
    Buffer() = default;
    ~Buffer() = default;

    DISALLOW_COPY_AND_MOVE(Buffer);

    void append(const char *_str, int _size);
    ssize_t size();
    const char *c_str();
    void clear();
    void getline();
    void setBuf(const char *buf);
};

#endif