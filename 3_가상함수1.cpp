#include <iostream>

class Animal
{
public:
	// virtual : 메모리 조사 후 함수 호출
	void cry() { std::cout << "Animal Cry" << std::endl; }
};
class Dog : public Animal
{
public:
	void cry() { std::cout << "Dog Cry" << std::endl; } // override : 기반 멤버를 파생이 재생성
};
int main()
{
	Dog d;
	Animal* p = &d; 
	p->cry();
	d.cry();
}