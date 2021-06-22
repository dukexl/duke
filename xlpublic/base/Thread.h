#ifndef XL_BASE_THREAD_H
#define XL_BASE_THREAD_H

#include "Atomic.h"
#include "Types.h"
#include "noncopyable.h"

#include <functional>
#include <pthread.h>

namespace XL
{
    class Thread : private XL::noncopyable
    {
    public:
        typedef std::function<void()> ThreadFunc;

        explicit Thread(const ThreadFunc &, const string &name = string());
        ~Thread();

        void start();
        int join();
        bool started() const { return started_; }
        pid_t tid() const { return tid_; }
        const string &name() const { return name_; }

        static int numCreated() { return numCreated.get(); }

    private:
        static void *stratThread(void *thread);
        void runInThread();

        bool started_;
        pthread_t pthreadId_;
        pid_t tid_;
        ThreadFunc func_;
        string name_;
        static AtomicInt32 numCreated_;
    };
}

#endif