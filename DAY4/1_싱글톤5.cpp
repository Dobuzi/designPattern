#include <iostream>
#include <mutex>

// RAII (Resource Acquisition Is Initialization)
// Stack Unwinding : local variables are safely destroyed when catching the exception

// template<typename T>
// class lock_guard
// {
//     T& m;
//     public:
//     lock_guard(T& m) : m(m) { m.lock(); }
//     ~lock_guard()           { m.unlock(); }
// };

#define MAKE_SINGLETON(classname)                   \
private:                                            \
classname() {}                                      \
classname(const classname& c) = delete;             \
classname& operator=(const classname& c) = delete;  \
static classname* pinstance;                        \
static std::mutex mtx;                              \
public:                                             \
static classname& getInstance()                     \
{                                                   \
    std::lock_guard<std::mutex> g(mtx);             \
    if (pinstance == nullptr)                       \
        pinstance == new classname;                 \
    return *pinstance;                              \
}                                                   \

class Cursor
{
    MAKE_SINGLETON(Cursor)
};
Cursor*     Cursor::pinstance = nullptr;
std::mutex  Cursor::mtx;

int main()
{
	Cursor& c1 = Cursor::getInstance();
}