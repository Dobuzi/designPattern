// Decorator - 65 page
#include <iostream>

struct Item
{
    virtual void Fire() = 0;
    virtual ~Item() {}
};

class SpaceShip : public Item
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

class LeftMissile : public Item
{
    Item* item;
    public:
        LeftMissile(Item* item) : item(item) {}
        void Fire()
        {
            item->Fire();
            std::cout << "Fire Left Missile" << std::endl;
        }
};

class RightMissile : public Item
{
    Item* item;
    public:
        RightMissile(Item* item) : item(item) {}
        void Fire()
        {
            item->Fire();
            std::cout << "Fire Right Missile" << std::endl;
        }
};

int main()
{
	SpaceShip ss;
	// ss.Fire();

    LeftMissile lm(&ss);
    // lm.Fire();

    RightMissile rm(&lm);
    rm.Fire();
}