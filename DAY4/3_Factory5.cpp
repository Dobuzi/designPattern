#include <iostream>
#include <vector>
#include <map>
#include "helper.h"

class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}

    virtual Shape* Clone() = 0;
};

class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }
    static Shape* Create() { return new Rect; }
    Rect* Clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }
    static Shape* Create() { return new Circle; }
    Circle* Clone() override { return new Circle(*this); }
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

    std::map<int, Shape*> prototype_map;
    public:
    void RegisterShape(int type, Shape* sample)
    {
        // create_map[type] = f;
        prototype_map[type] = sample;
    }

	Shape* Create(int type)
	{
		Shape* p = nullptr;
        if (prototype_map[type] != nullptr) p = prototype_map[type]->Clone();
		return p;
	}

    void showSample()
    {
        std::map<int, Shape*>::iterator it;
        for (it = prototype_map.begin(); it != prototype_map.end(); it++)
        {
            std::cout << it->first << ": ";
            it->second->Draw();
        }
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

    Rect* blueRect = new Rect;
    Rect* redRect = new Rect;
    Circle* redCircle = new Circle;

    factory.RegisterShape(1, blueRect);
    factory.RegisterShape(2, redRect);
    factory.RegisterShape(3, redCircle);

    factory.showSample();

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




