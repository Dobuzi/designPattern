#include <iostream>

class Base
{
public:
	virtual ~Base() {} // 기반 클래스 소멸자는 반드시 가상함수로 설계
};

class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() alloc" << std::endl; }
	~Derived() { std::cout << "~Derived() delete" << std::endl; }
};

int main()
{
	Derived d;
	Base* p = new Derived;
	delete p;

	return 0;
}