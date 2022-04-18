#include <iostream>
#include <vector>

class Shape
{
    protected:
        virtual void draw_imp()
        {
            std::cout << "draw shape" << std::endl;
        }

    public:
        Shape() {}
        virtual ~Shape() {}

        virtual void draw() final
        {
            std::cout << "mutex lock" << std::endl;
            draw_imp();
            std::cout << "mutex unlock" << std::endl;
        }

        virtual Shape* clone() // prototype pattern: copy the origin object to create the othere object
        {
            Shape* p = new Shape(*this);

            return p;
        }
};

class Rect : public Shape
{
    public:
        Rect() {}
        ~Rect() {}
        void draw_imp() override { std::cout << "draw rect" << std::endl; }
        virtual Rect* clone() override
        {
            Rect* p = new Rect(*this);
            
            return p;
        }
};

class Circle : public Shape
{
    public:
        Circle() {}
        ~Circle() {}
        void draw_imp() override { std::cout << "draw circle" << std::endl; }
        virtual Circle* clone() override
        {
            Circle* p = new Circle(*this);
            
            return p;
        }
};

class Triangle : public Shape
{
    public:
        Triangle() {}
        ~Triangle() {}
        void draw_imp() override { std::cout << "draw triangle" << std::endl; }
        
        virtual Triangle* clone() override
        {
            Triangle* p = new Triangle(*this);

            return p;
        }
};

// class Factory
// {
//     public:
//         Rect* creatRect()
//         {
//             return new Rect;
//         }

//         Circle* createCircle()
//         {
//             return new Circle;
//         }

//         Triangle* createTriangle()
//         {
//             return new Triangle;
//         }
// };

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
        else if (cmd == 8)
        {
            std::cout << "Put in the number of shape to copy.: ";

            int k;
            std::cin >> k;
            v.push_back( v[k]->clone() );
        }
    }
}

// Template Method
// NVI : None Virtual Interface