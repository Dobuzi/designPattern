// upcasting3.cpp
#include <iostream>

class Animal 
{
public: 
	int age;
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};

void NewYear(Animal* pAnimal)
{
	++(pAnimal->age);
}
int main()
{
	Animal a;
	// a.age = 3;
	NewYear(&a);
	Dog    d; NewYear(&d);
	std::cout << a.age << std::endl;
	std::cout << d.age << std::endl;
}













