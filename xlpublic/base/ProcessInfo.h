#ifndef XL_BASE_PROCESSINFO_H
#define XL_BASE_PROCESSINFO_H

#include <xlpublic/base/Types.h>
#include <xlpublic/base/Timestamp.h>
#include <vector>

namespace XL
{
    namespace ProcessInfo
    {
        pid_t pid();
        string pidString();
        uid_t uid();
        string username();
        uid_t euid();
        Timestamp startTime();
        string hostname();
        string procStatus();
        int openedFiles();
        int maxOpenFiles();
        int numThreads();
        std::vector<pid_t> threads();
    }
}

#endif