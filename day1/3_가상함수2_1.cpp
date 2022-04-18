#include <iostream>

class Base
{
public:

protected:
	~Base() {} // 고오급 기술 : 직접 호출 시, 컴파일 에러 유발
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
	delete static_cast<Derived*>(p);

	return 0;
}