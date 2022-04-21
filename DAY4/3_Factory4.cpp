#include <iostream>
#include <vector>
#include <map>
#include "helper.h"

class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

    // CREATOR is type to take the address of func
    typedef Shape*(*CREATOR)();
    std::map<int, CREATOR> create_map;
    public:
    void RegisterShape(int type, CREATOR f)
    {
        create_map[type] = f;
    }

	Shape* Create(int type)
	{
		Shape* p = nullptr;
        if (create_map[type] != nullptr) p = create_map[type]();
		return p;
	}
};

struct AutoRegister
{
    AutoRegister(int type, Shape*(*f)())
    {
        ShapeFactory::getInstance().RegisterShape(type, f);
    }
};

#define REGISTER_SHAPE(type, classname)					\
AutoRegister classname::ar(type, &classname::Create);	\

class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }
    DECLARE_SHAPE(Rect)
};
REGISTER_SHAPE(1, Rect)

class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }
    DECLARE_SHAPE(Circle)
};
REGISTER_SHAPE(2, Circle)


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7)
		{
			Shape* p = factory.Create(cmd);
			if ( p != nullptr ) v.push_back(p);
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->Draw();
			}
		}
	}
}