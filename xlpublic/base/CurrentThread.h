#ifndef XL_BASE_CURRENTTHREAD_H
#define XL_BASE_CURRENTTHREAD_H

namespace xlpublic
{
    namespace CurrentThread
    {
        extern __thread int t_cachedTid;
        extern __thread char t_tidStirng[32];
        extern __thread const char *t_threadName;

        void cacheTid();

        inline int tid()
        {
            if (t_cachedTid == 0)
            {
                cacheTid();
            }
            return t_cachedTid;
        }

        inline const char *tidString()
        {
            return t_tidStirng;
        }

        inline const char *name
        {
            return t_threadName;
        }

        bool isMainThread();
    }
}

#endif