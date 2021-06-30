#ifndef XL_BASE_EXCEPTION_H
#define XL_BASE_EXCEPTION_H

#include <xlpublic/base/Types.h>
#include <exception>

namespace XL
{
    class Exception : public std::exception
    {
    public:
        explicit Exception(const char *what);
        explicit Exception(const string &what);
        virtual ~Exception() throw();
        virtual const char *what() const throw();
        const char *stackTrace() const throw();

    private:
        void fillStackTrace();
        string demangle(const char *symbol);
        string message_;
        string stack_;
    };
}

#endif