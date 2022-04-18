#include <iostream>

// loosely coupling : expandable
class ICamera
{
    public:
        virtual void take() = 0;
};

class People
{
    public:
        void UseCamera(ICamera* p) { p->take(); }
};

class Camera : public ICamera
{
    public:
        void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
    public:
        void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public HDCamera
{
    public:
        void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
    Camera c;
    HDCamera hc;
    UHDCamera uhc;
    p.UseCamera(&c);
    p.UseCamera(&hc);
    p.UseCamera(&uhc);
}

