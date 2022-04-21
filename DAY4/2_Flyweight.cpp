// 5_Flyweight - 167
#include <iostream>
#include <string>
#include <map>

// �Ӽ��� ������ ��ü��  ���� �Ҽ� �ְ� ����.

class Shape
{
public:
	virtual ~Shape() {}
	virtual void draw() = 0;
};

class Image : public Shape
{
	std::string image_url;
public:
	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
	void draw() override { std::cout << "draw " << image_url << std::endl; }
};
int main()
{
	Image* img1 = new Image("www.naver.com/a.png");
	img1->draw();

	Image* img2 = new Image("www.naver.com/a.png");
	img2->draw();

}



