// 6_Bridge1 - 90 page
#include <iostream>

class IPod 
{
public:
	void Play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void Stop() { std::cout << "Stop" << std::endl; }
};

class People
{
public:
	void Use(IPod* p)
	{
		p->Play();
		p->Stop();
	}
};
int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


