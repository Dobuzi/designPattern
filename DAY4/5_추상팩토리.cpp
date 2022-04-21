// 3_추상팩토리 - 147
#include <iostream>
using namespace std;

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
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
	void Draw() { cout << "Draw WinButton" << endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { cout << "Draw WinEdit" << endl; }
};

struct OSXButton : public IButton
{
	void Draw() { cout << "Draw OSXButton" << endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { cout << "Draw OSXButton" << endl; }
};

int main(int argc, char** argv)
{
	? btn;
	if (strcmp(argv[0], "-style:OSX") == 0)
		btn = new OSXButton;
	else
		btn = new WinButton;
}








