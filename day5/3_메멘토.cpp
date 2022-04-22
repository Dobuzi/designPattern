#include <iostream>

class Graphics
{
	int width;
	std::string color;
	std::string style;
	public:
	void DrawLine(int a, int b, int c, int d)
	{
		std::cout << a << b << c << d << std::endl;
	};
	void setStrokeWidth(int a) { width = a; }
	void setStrokeColor(std::string a) { color = a; }
	void setStrokeStyle(std::string a) { style = a; }
};
int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);
}