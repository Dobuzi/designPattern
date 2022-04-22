#include <iostream>

// 방법 1.
// 각 동작을 정의 하는 함수에서
// 아이템의 종류에 따른 분기

// => 새로운 아이템이 추가 되면... 너무 많은 코드의 변경이 필요
//	  OCP 만족 할수 없다.

class Charater
{
	int gold;
	int item;
public:
	void run() 
	{
		if ( item == 1)
			std::cout << "run" << std::endl;
		else if ( item == 2)
			std::cout << "fast run" << std::endl;

	}
	void attack() { std::cout << "attack" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



