// upcasting1.cpp
class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Dog*    p1 = &d;
	// int*	p2 = &d; // error
	Animal* p3 = &d; // ok. upcasting
	p3->age = 10;
	// p3->color = 20; // error
	static_cast<Dog*>(p3)->color = 10;
}











