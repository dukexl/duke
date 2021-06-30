#include <xlpublic/base/Thread.h>
#include <xlpublic/base/CountDownLatch.h>
#include <xlpublic/base/Exception.h>

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <linux/unistd.h>

namespace XL
{
    namespace CurrentThread
    {
        __thread int t_cachedTid = 0;
        __thread char t_tidString[32];
        __thread const char *t_threadName = "unknown";
        const bool sameType = boost::is_same<int, pid_t>::value;
        BOOST_STATIC_ASSERT(sameType);
    }

    namespace detail
    {
        pid_t gettid()
        {
            return static_cast<pid_t>(::syscall(SYS_gettid));
        }

        void afterFork()
        {
            XL::CurrentThread::t_cachedTid = 0;
            XL::CurrentThread::t_threadName = "main";
            CurrentThread::tid();
        }

        class ThreadNameInitializer
        {
        public:
            ThreadNameInitializer()
            {
                XL::CurrentThread::t_threadName = "main";
                CurrentThread::tid();
                pthread_atfork(NULL, NULL, &afterFork);
            }
        };

        ThreadNameInitializer init;
    }
}

using namespace XL;

void CurrentThread::cacheTid()
{
    if (t_cachedTid == 0)
    {
        t_cachedTid = detail::gettid();
        int n = snprintf(t_tidString, sizeof(t_tidString), "%5d", t_cachedTid);
    }
}