// 3_���������� - 15 page
#include <iostream>
#include <vector>

class Shape
{
    public:
        Shape() {}
        virtual ~Shape() {}
        virtual void draw() { std::cout << "draw shape" << std::endl; }
};

class Rect : public Shape
{
    public:
        Rect() {}
        ~Rect() {}
        void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
    public:
        Circle() {}
        ~Circle() {}
        void draw() override { std::cout << "draw circle" << std::endl; }
};

class Triangle : public Shape
{
    public:
        Triangle() {}
        ~Triangle() {}
        void draw() override { std::cout << "draw triangle" << std::endl; }
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
        else if (cmd == 3) v.push_back(new Triangle);
        else if (cmd == 9)
        {
            for (auto p : v)
                p->draw();
        }
    }
}

// OCP (Open Close Principle) : Open to expand, Close to edit Principle
// 5 Design Principle
// SOLID : SRP, OCP, LSP, ISP, DIP