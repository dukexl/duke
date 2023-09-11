/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2023-06-05 14:33:35
 * @LastEditors: xuli
 * @LastEditTime: 2023-06-05 14:33:36
 */
#ifndef _MARROS_H_
#define _MARROS_H_

#include <cassert>
#include <stdexcept>

#define OS_LINUX

// Macros to disable copying and moving
#define DISALLOW_COPY(cname)                             \
  cname(const cname &) = delete;            /* NOLINT */ \
  cname &operator=(const cname &) = delete; /* NOLINT */

#define DISALLOW_MOVE(cname)                        \
  cname(cname &&) = delete;            /* NOLINT */ \
  cname &operator=(cname &&) = delete; /* NOLINT */

#define DISALLOW_COPY_AND_MOVE(cname) \
  DISALLOW_COPY(cname);               \
  DISALLOW_MOVE(cname);

#define ASSERT(expr, message) assert((expr) && (message))

#define UNREACHABLE(message) throw std::logic_error(message)


#endif