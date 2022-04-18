//1_추상클래스2.cpp
#include <iostream>


class Camera
{
public:	
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class People
{
public:	
	void UseCamera(Camera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);
}





