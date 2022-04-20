#include <iostream>
#include <string>
#include <vector>

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

class Text2 : public Shape
{
    TextView* txtView;

    public:
        Text2(TextView* p) : txtView(p) {}

        void Draw() override
        {
            txtView->Show();
        }
};

int main()
{
	std::vector<Shape*> v;
	
    TextView tv("ABCD");

	v.push_back( new Text("Hello") );

	v[0]->Draw();

    v.push_back( new Text2(&tv) );
    v[0]->Draw();
}