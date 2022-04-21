#include <iostream>
#include <string>
#include <map>
#include "helper.h"

class Shape
{
public:
	virtual ~Shape() {}
	virtual void draw() = 0;
};

class EditableImage : public Shape
{

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

    friend class ImageFactory;
};

class ImageFactory
{
    std::map<std::string, Image*> image_map;
    public:
    Image* Create(const std::string& url)
    {
        Image* img = image_map[url];
        if (img == nullptr)
        {
            img = new Image(url);
            image_map[url] = img;
        }
        
        return img;
    }

    MAKE_SINGLETON(ImageFactory)
};

int main()
{
	ImageFactory& f = ImageFactory::getInstance();

    Image* img1 = f.Create("www.naver.com/a.png");
    img1->draw();

    Image* img2 = f.Create("www.naver.com/a.png");
    img2->draw();

    std::cout << img1 << std::endl;
    std::cout << img2 << std::endl;
}