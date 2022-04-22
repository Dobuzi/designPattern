// 1_State1 - 182 page
#include <iostream>

struct IState
{
    virtual void run() = 0;
    virtual void attack() = 0;
    virtual ~IState() {}
};

class Charater
{
	int gold;
	int item;
    IState* pState = nullptr;
public:
    void setState(IState* p) { pState = p; }
	void run()    { pState->run(); }
	void attack() { pState->attack(); }
};

class NormalState : public IState
{
    public:
    void run()  override    { std::cout << "run" << std::endl; }
    void attack() override  { std::cout << "attack" << std::endl; }
};

class GoodItemState : public IState
{
    public:
    void run()  override    { std::cout << "fast run" << std::endl; }
    void attack() override  { std::cout << "power attack" << std::endl; }
};

int main()
{
    NormalState ns;
    GoodItemState gs;

	Charater* p = new Charater;

	p->setState(&ns);
    p->run();
	p->attack();

    p->setState(&gs);
    p->run();
    p->attack();
}

// Strategy Pattern : Change the policy of object
// State Pattern    : Change the all action of object
// Builder Pattern  : When making the complex shape of object
// Decorator Pattern: Add function (Not change)