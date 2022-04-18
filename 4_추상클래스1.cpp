// 1_추상클래스1.cpp - 10page
class Shape
{
public:
	virtual void Draw() = 0;
							
};
class Rect : public Shape
{
};
int main()
{
	Shape s;
	Rect  r;
}
