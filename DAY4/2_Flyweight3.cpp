#include <iostream>
#include <string>
#include <map>

class Shape
{
public:
	virtual ~Shape() {}
	virtual void draw() = 0;
};

class Image : public Shape
{
	std::string image_url;
	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void draw() override { std::cout << "draw " << image_url << std::endl; }
    static std::map<std::string, Image*> image_map;
    static Image* Create(const std::string& url)
    {
        Image* img = image_map[url];
        if (img == nullptr)
        {
            img = new Image(url);
            image_map[url] = img;
        }
        
        return img;
    }
};
std::map<std::string, Image*> Image::image_map;

int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->draw();

    std::cout << img1 << std::endl;
    std::cout << img2 << std::endl;
}