#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class CWnd;
std::map<int, CWnd*> this_map;

class CWnd
{
	int mHandle;

	//---------------------
	CWnd* parent; // 부모 윈도우는 한개이다.
	std::vector<CWnd*> child_vec; // 자식윈도우는 여러개 이다.
public:

	void AddChild(CWnd* child)
	{
		child_vec.push_back(child);
		child->parent = this;

		// 실제 child->mHandle 윈도우를 현재 윈도우 자식으로 붙이는 함수
		ec_add_child(this->mHandle, child->mHandle);
	}

	void Create()
	{
		mHandle = ec_make_window(foo, "A");
		this_map[mHandle] = this;
	}

	static int foo(int hwnd, int msg, int a, int b)
	{
		CWnd* const pThis = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: pThis->LButtonDown(); break;
		case WM_KEYDOWN:     pThis->KeyDown(); break;
		}
		return 0;
	}

	virtual bool LButtonDown() { return false; }
	virtual bool KeyDown() { return false; }
};


class MyWindow : public CWnd
{
public:
	void LButtonDown() { std::cout << "LBUTTON" << std::endl;  }
};
class ImageView : public CWnd
{
public:
	void LButtonDown() { std::cout << "ImageView LBUTTON" << std::endl; }
};

int main()
{
	MyWindow w;
	w.Create();

	ImageView view;
	view.Create();
	w.AddChild(&view); // view 를 w의 자식윈도우로 붙인다.

	ec_process_message();
}