// 3_���������� - 15 page
#include <iostream>
#include <vector>

class Shape
{
    public:
        Shape() {}
        virtual ~Shape() {}
        virtual void draw() {}
};

class Rect : public Shape
{
    public:
        Rect() {}
        ~Rect() {}
        void draw() { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
    public:
        Circle() {}
        ~Circle() {}
        void draw() { std::cout << "draw circle" << std::endl; }
};

int main()
{
    std::vector<Shape*> v;

    while (1)
    {
        int cmd;
        std::cin >> cmd;

        if      (cmd == 1) v.push_back(new Rect);
        else if (cmd == 2) v.push_back(new Circle);
        else if (cmd == 9)
        {
            for (auto p : v)
                p->draw();
        }
    }
}

