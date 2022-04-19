#include <iostream>
#include <vector>
#include <string>

struct NotImplemented : public std::exception {};

class Item
{
	std::string title;

	public:
		int size;
		Item(const std::string& title, int size = 0) : title(title), size(size) {}
		virtual ~Item() {}
		virtual void addItem(Item* i) { throw NotImplemented(); }
		virtual int getSize() { throw NotImplemented(); }
};

class File : public Item
{
	public:
		File(const std::string& title, int size) : Item(title, size) {}
		~File() {}
		int getSize() override { return size; }
};

class Folder : public Item
{
	std::vector<Item*> v;
	public:
		Folder(const std::string& title) : Item(title) {}
		~Folder() {}
		void addItem(Item* i) override { v.push_back(i); }
		int getSize() override
		{
			int sz = 0;
			for (int i = 0; i < v.size(); i++)
			{
				sz += v[i]->getSize();
			}
			return sz;
		}
};

int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->addItem(fo1);
	root->addItem(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->addItem(f1);
	root->addItem(f2);

	// ������ �ڽŸ��� ũ��� �ֽ��ϴ�.
	// ������ �ڽŸ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	std::cout << f2->getSize() << std::endl; // 20
	std::cout << fo1->getSize() << std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}


