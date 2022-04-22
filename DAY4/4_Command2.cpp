// 3_Command 
#include <iostream>
#include <vector>
#include <stack>

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

struct ICommand
{
	virtual void Execute() = 0;
	virtual bool CanUndo()	{ return false; }
	virtual void Undo() 	{}
	virtual ~ICommand()		{}
};

class AddCommand : public ICommand
{
    std::vector<Shape*>& v;
	public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}
	void Execute() override { v.push_back( CreateShape() ); }
	bool CanUndo() override { return true; }
	void Undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}

    virtual Shape* CreateShape() = 0;
};

class AddRectCommand : public AddCommand
{
	public:
	AddRectCommand(std::vector<Shape*>& v) : AddCommand(v) {}
	Shape* CreateShape() override { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
	public:
	AddCircleCommand(std::vector<Shape*>& v) : AddCommand(v) {}
	Shape* CreateShape() override { return new Circle; }
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
	public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}
	void Execute() override
	{
		for (auto p : v)
			p->Draw();
	}
	bool CanUndo() override { return true; }
	void Undo() override
	{
		system("clear");
	}
};

#define COMMAND(command)	\
pCmd = new command(v);		\
pCmd->Execute();			\
undo_stack.push(pCmd);		\

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> undo_stack;

	ICommand* pCmd = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;
		if (cmd == 1) 
		{
			COMMAND(AddRectCommand)
		}
		else if (cmd == 2) 
		{
			COMMAND(AddCircleCommand)
		}
		else if (cmd == 9)
		{
			COMMAND(DrawCommand)
		}
		else if (cmd == 0)
		{
			if ( !undo_stack.empty() )
			{
				pCmd = undo_stack.top();
				undo_stack.pop();
				if (pCmd->CanUndo()) pCmd->Undo();
				delete pCmd;
			}
		}
	}
}


