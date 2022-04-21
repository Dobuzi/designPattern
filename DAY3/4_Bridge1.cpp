// 6_Bridge1 - 90 page
#include <iostream>

class IMP3
{
	public:
	virtual void Play() = 0;
	virtual void Stop() = 0;
	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public:
	void Play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void Stop() { std::cout << "Stop" << std::endl; }
};

class Iriver : public IMP3
{
public:
	void Play() { std::cout << "Play MP3 with Iriver" << std::endl; }
	void Stop() { std::cout << "Stop" << std::endl; }
};

class MP3
{
	IMP3* implementor;
	public:
	MP3(IMP3* p = nullptr) : implementor(p)
	{
		if (implementor == nullptr) implementor = new IPod;
	}

	void Play() { implementor->Play(); }
	void Stop() { implementor->Stop(); }
	void PlayOneMinute()
	{
		implementor->Play();
		// wait 1 min
		implementor->Stop();
	}
};

class People
{
public:
	void Use(MP3* p)
	{
		p->Play();
		p->Stop();
		p->PlayOneMinute();
	}
};
int main()
{
	People p;
	MP3 mp3(new Iriver);
	p.Use(&mp3);
}


