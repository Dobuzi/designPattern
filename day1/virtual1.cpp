#include <iostream>

class Base
{
    int x;

    public:
        virtual void f1() {}
        virtual void f2() {}
        virtual void f3() {}
};

class Derived : public Base
{
    int y;

    public:
        void f1() override {}
};

int main()
{
    Base b;
    Derived d;

    Base* p = &d;

    p->f1();
    std::cout << sizeof(Derived) << std::endl;
}