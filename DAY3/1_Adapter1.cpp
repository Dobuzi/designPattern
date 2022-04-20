#include <iostream>
#include <string>
#include <vector>


// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.

class TextView
{
	std::string data;
public:
	TextView(std::string s) : data(s) {}

	void Show() { std::cout << data << std::endl; }
};

class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }
};

class Text : public TextView, public Shape
{
	public:
		Text(const std::string& data) : TextView(data) {}

		void Draw() override
		{
			TextView::Show();
		}
};

int main()
{
	std::vector<Shape*> v;
	
	v.push_back( new Text("Hello") );
	v[0]->Draw();
}







