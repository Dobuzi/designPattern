// 3_���������� - 15 page
#include <iostream>
#include <vector>

class Shape
{
    public:
        Shape() {}
        virtual ~Shape() {}
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
}

