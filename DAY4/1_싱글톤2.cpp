#include <iostream>

#define MAKE_SINGLETON(classname)                  \
private:                                           \
classname() {}                                     \
classname(const classname& c) = delete;            \
classname& operator=(const classname& c) = delete; \
public:                                            \
static classname& getInstance()                    \
{                                                  \
    static classname instance;                     \
    return instance;                               \
}                                                  \

class Cursor
{
    MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	
	std::cout << &c1 << "\n" << &c2 << std::endl;
}