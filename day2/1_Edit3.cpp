#include <iostream>
#include <string>
// #include <conio.h>
#include <cstdio>
// #include <curses.h>

class Edit
{
	std::string data;
public:
    virtual bool validate(const std::string& data, char c)
    {
        return true;
    }

    virtual bool iscomplete(const std::string& data)
    {
        return true;
    }

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = std::getchar(); 

			if (c == 13 && iscomplete(data) == true) break;

			if ( validate(data, c) )
			{
				std::cout << c;
				data.push_back(c);
			}
		}
        std::cout << std::endl;
		return data;
	}
};

class NumEdit : public Edit
{
    public:
        bool validate(const std::string& data, char c) override
        {
            return isdigit(c);
        }

        bool iscomplete(const std::string& data) override
        {
            return data.size() >= 10;
        }
};

int main()
{
	// Edit e;
    NumEdit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}