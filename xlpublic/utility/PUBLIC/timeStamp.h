#ifndef _TIMESTAMP_H_
#define _TIMESTAMP_H_
#include <time.h>
#include <stdio.h>
#include <string>

namespace PUBIIC
{
    class Timestamp
    {
    public:
        Timestamp() : time_(0) {}

        explicit Timestamp(__time64_t time); // 避免隐式转换

        void swap(Timestamp &that)
        {
            std::swap(time_, that.time_);
        }

        std::string toString() const;
        std::string toFromattedString() const;

        bool valid() const { return time_ > 0; }
        __time64_t getTime() const { return time_; }

        static Timestamp now();
        static Timestamp invalid();

    private:
        __time64_t time_;
    };
    /*
    操作符重载三种方式：

class Person{
    string name;
    int age;
public:
    Person(const char* name, int age):name(name),age(age){}
     bool operator<(const Person& b);
 
};
bool Person::operator<(const Person& b)
{
//作为成员函数时，*this即为左操作数a
...
}
 
//作为友元函数重载
class Person{
    string name;
    int age;
public:
    Person(const char* name, int age):name(name),age(age){}
     friend bool operator<(const Person& a,const Person& b);
 
};
bool operator<(const Person& a,const Person& b)
{
...
}
 
//作为普通函数重载（不推荐）
class Person{
public://注意，重载运算符为普通函数时，使用到的类成员必须为public
    string name;
    int age;
public:
    Person(const char* name, int age):name(name),age(age){}
 
};
bool operator<(const Person& a,const Person& b)
{
...
}
    */

    inline bool operator<(Timestamp lhs, Timestamp rhs)
    {
        return lhs.getTime() < rhs.getTime();
    }

    inline bool operator==(Timestamp lhs, Timestamp rhs)
    {
        return lhs.getTime() == rhs.getTime();
    }

    inline __time64_t timeDifference(Timestamp high, Timestamp low)
    {
        __time64_t diff = high.getTime() - low.getTime();
        return diff;
    }

    inline Timestamp addTime(Timestamp timestamp, __time64_t seconds)
    {
        return Timestamp(timestamp.getTime() + seconds);
    }
} // namespace PUBIIC

#endif