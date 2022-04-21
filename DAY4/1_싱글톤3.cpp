#include <iostream>

#define MAKE_SINGLETON(classname)                   \
private:                                            \
classname() {}                                      \
classname(const classname& c) = delete;             \
classname& operator=(const classname& c) = delete;  \
static classname* pinstance;                        \
public:                                             \
static classname& getInstance()                     \
{                                                   \
    if (pinstance == nullptr)                       \
        pinstance == new classname;                 \
    return *pinstance;                              \
}                                                   \

class Cursor
{
    MAKE_SINGLETON(Cursor)
};
Cursor* Cursor::pinstance = nullptr;

int main()
{
	Cursor& c1 = Cursor::getInstance();
}