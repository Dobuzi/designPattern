// 2_Builder
#include <iostream>
#include <string>

typedef std::string Hat;		// class Hat{}
typedef std::string Uniform;	// class Uniform{}
typedef std::string Shoes;		// class Shoes{}
typedef std::string Character;	// class Character{}

struct IBuilder
{
    virtual Hat makeHat() = 0;
    virtual Uniform makeUniform() = 0;
    virtual Shoes makeShoes() = 0;

    virtual ~IBuilder() {}
};

class Director
{
    IBuilder* pBuilder = nullptr;
public:
    void setBuilder(IBuilder* p) { pBuilder = p; }
	Character construct()
	{
		Character c;
		c = c + pBuilder->makeHat();
		c = c + " - " + pBuilder->makeUniform();
		c = c + " - " + pBuilder->makeShoes();
		return c;
	}
};

struct Korean : public IBuilder
{
    Hat     makeHat()       override { return "MLB Ball cap"; }
    Uniform makeUniform()   override { return "T shirt";}
    Shoes   makeShoes()     override { return "Adidas running shoes";}
};

struct American : public IBuilder
{
    Hat     makeHat()       override { return "Cowboy Hat"; }
    Uniform makeUniform()   override { return "Sweater";}
    Shoes   makeShoes()     override { return "Nike air force 1";}
};

int main()
{
    Korean k;
    American a;

	Director d;
    // d.setBuilder(&k);
    d.setBuilder(&a);
	Character c = d.construct();
	std::cout << c << std::endl;

}