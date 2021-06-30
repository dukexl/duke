#ifndef XL_BASE_COUNTDOWNLATCH_H
#define XL_BASE_COUNTDOWNLATCH_H

#include <xlpublic/base/Condition.h>
#include <xlpublic/base/Mutex.h>
#include <xlpublic/base/noncopyable.h>

namespace XL
{
    class CountDownLatch : noncopyable
    {
    public:
        explicit CountDownLatch(int count);

        void wait();

        void countDown();

        int getCount() const;

    private:
        mutable MutexLock mutex_;
        Condition condition_;
        int count_;
    };
}

#endif