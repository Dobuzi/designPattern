// Decorator - 65 page
#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

class LeftMissile : public SpaceShip
{
    public:
        void Fire()
        {
            SpaceShip::Fire();
            std::cout << "Fire Left Missile" << std::endl;
        }
};

int main()
{
	SpaceShip ss;
	ss.Fire();

    LeftMissile lm;
    lm.Fire();
}