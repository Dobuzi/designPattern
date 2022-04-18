// 1_�߻�Ŭ����1.cpp - 10page
class Shape // Abstract Class : one or more pure virtual function
{
public:
	virtual void Draw() = 0; // pure virtual function : No detail, just declare
};

class Rect : public Shape
{
	void Draw() override {}
};

int main()
{
	// Shape s;
	Shape* p;
	Rect  r;
}
