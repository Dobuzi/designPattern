#include <iostream>
#include <string>
#include <conio.h>

class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13) break;

			if (isdigit(c))
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << std::endl;

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


