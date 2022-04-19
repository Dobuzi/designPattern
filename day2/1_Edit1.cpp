#include <iostream>
#include <string>
#include <conio.h>

class Edit
{
	std::string data;
public:
	std::string getData()
	{
		std::cin >> data;
		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


