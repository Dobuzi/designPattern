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

class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }
    static Shape* Create() { return new Rect; }
};

class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }
    static Shape* Create() { return new Circle; }
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

// void Create( Shape*(*f)() )
// {
//     Shape* s = f();
// }


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

    factory.RegisterShape(1, &Rect::Create);
    factory.RegisterShape(2, &Circle::Create);

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




