#include <iostream>
#include <vector>

class Subject;

struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}

    Subject* pSubject = nullptr;
};

class Subject
{
    std::vector<IGraph*> v;
public:
	void attach(IGraph* p)
    {
        v.push_back(p);
        p->pSubject = this;
    }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
	virtual void edit() = 0;
};

class Table : public Subject
{
	int value;
    int data[5];
public:
    int* getData() { return data; }
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void Update(int n) override
	{
        Table* pTable = static_cast<Table*>(pSubject);

        int* data = pTable->getData();
        
		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "|";

		std::cout << std::endl;
	}
};

class PieGraph : public IGraph
{
	public:
	void Update(int n) override
	{
        Table* pTable = static_cast<Table*>(pSubject);

        int* data = pTable->getData();

		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "O";

		std::cout << std::endl;

	}
};

int main()
{
	Table t;
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	t.edit();
}