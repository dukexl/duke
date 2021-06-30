#ifndef XL_BASE_BLOCKINGQUEUE_H
#define XL_BASE_BLOCKINGQUEUE_H

#include <xlpublic/base/CurrentThread.h>
#include <xlpublic/base/noncopyable.h>
#include <assert.h>
#include <pthread.h>

namespace XL
{
    class MutexLock : noncopyable
    {
    public:
        MutexLock() : holder_(0)
        {
            int ret = pthread_mutex_init(&mutex_, NULL);
            assert(ret == 0);
            (void)ret;
        }

        ~MutexLock()
        {
            assert(holder_ == 0);
            int ret = pthread_mutex_destroy(&mutex_);
            assert(ret == 0);
            (void)ret;
        }

        bool isLockedByThisThread()
        {
            return holder_ == CurrentThread::tid();
        }

        void assertLocked()
        {
            assert(isLockedByThisThread());
        }

        void lock()
        {
            pthread_mutex_lock(&mutex_);
            holder_ = CurrentThread::tid();
        }

        void unlock()
        {
            holder_ = 0;
            pthread_mutex_unlock(&mutex_);
        }

        pthread_mutex_t *getPthreadMutex()
        {
            return &mutex_;
        }

    private:
        pthread_mutex_t mutex_;
        pid_t holder_;
    };

    class MutexLockGuard : noncopyable
    {
    public:
        explicit MutexLockGuard(MutexLock &mutex) : mutex_(mutex)
        {
            mutex_.lock();
        }
        ~MutexLockGuard()
        {
            mutex_.unlock();
        }

    private:
        MutexLock &mutex_;
    };

#define MutexLockGuard(x) error "Missing guard object name"
}

#endif