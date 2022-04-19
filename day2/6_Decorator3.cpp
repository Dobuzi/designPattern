// Decorator - 65 page
#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

class LeftMissile
{
    SpaceShip* ship;
    public:
        LeftMissile(SpaceShip* ship) : ship(ship) {}
        void Fire()
        {
            ship->Fire();
            std::cout << "Fire Left Missile" << std::endl;
        }
};

int main()
{
	SpaceShip ss;
	ss.Fire();

    LeftMissile lm(&ss);
    lm.Fire();
}