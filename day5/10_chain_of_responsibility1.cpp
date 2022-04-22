#include <iostream>

struct Handler
{
	Handler* next = 0;

	virtual bool HandleRequest(int problem) = 0;

	void Handle(int problem)
	{
		// 1. �ڽ��� ��û�� ó��
		if (HandleRequest(problem) == true)
			return;

		// 2. ó������ ���� ��� ���� ��ü�� �ִٸ� ����
		if (next != 0)
			next->Handle(problem);  // HandleRequest�� �ƴ� Handle�� �ٽ�
	}
};


//-----------------------
struct OddHandler : public Handler
{
	bool HandleRequest(int problem) override
	{
		std::cout << "arrive at OddHAndler" << std::endl;
		return problem % 2 == 1;
	}
};

int main()
{
	OddHandler oh;

	oh.Handle(5);
}