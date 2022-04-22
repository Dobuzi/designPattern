// 5_���丮�޼ҵ�
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------
// Style �ɼǰ� ������� �׻� Windows ����� Dialog

class WinDialog
{
public:
	void init()
	{
		WinButton* btn  = new WinButton;
		WinEdit*   edit = new WinEdit;

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
};

class OSXDialog
{
public:
	void init()
	{
		OSXButton* btn  = new OSXButton;
		OSXEdit*   edit = new OSXEdit;

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
};

int main(int argc, char** argv)
{

}