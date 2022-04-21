#include <iostream>
#include <mutex>

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
    mtx.lock();                                     \
    if (pinstance == nullptr)                       \
        pinstance == new classname;                 \
    mtx.unlock();                                   \
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