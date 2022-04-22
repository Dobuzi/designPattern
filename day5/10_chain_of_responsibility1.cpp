#include <iostream>

struct Handler
{
	Handler* next = 0;

	virtual bool HandleRequest(int problem) = 0;

	void Handle(int problem)
	{
		// 1. 자신이 요청을 처리
		if (HandleRequest(problem) == true)
			return;

		// 2. 처리되지 않은 경우 다음 객체가 있다면 전달
		if (next != 0)
			next->Handle(problem);  // HandleRequest가 아닌 Handle이 핵심
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