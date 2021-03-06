#include <iostream>
#include <string>
// #include <conio.h>
#include <cstdio>

struct IValidator
{
    virtual bool validate(const std::string& data, char c) = 0;
    virtual bool iscomplete(const std::string& data) { return true; }
    virtual ~IValidator() {}
};

class Edit
{
	std::string data;
    IValidator* pVal = nullptr;
public:
    void setValidator(IValidator *p) { pVal = p; }
	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = getchar(); 

			if (c == 13 && ( pVal == nullptr || pVal->iscomplete(data) )) break;

			if ( pVal == nullptr || pVal->validate(data, c) )
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


