// 2_Builder
#include <iostream>
#include <string>

typedef std::string Hat;		// class Hat{}
typedef std::string Uniform;	// class Uniform{}
typedef std::string Shoes;		// class Shoes{}
typedef std::string Character;	// class Character{}

class Director
{
public:
	Character construct()
	{
		Character c;
		c = c + Hat("Ball Cap");
		c = c + Uniform("Blue Tshirt");
		c = c + Shoes("Snickers");
		return c;
	}
};
int main()
{
	Director d;
	Character c = d.construct();
	std::cout << c << std::endl;

}