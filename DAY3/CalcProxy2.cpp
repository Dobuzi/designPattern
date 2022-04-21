#define USING_GUI
#include <atomic>
#include "cppmaster.h"
#include "ICalc.h"

class CalcProxy2 : public ICalc
{
	int server;
	std::atomic<int> refCount{0};
	public:
	void AddRef() { ++refCount; }
	void Release() { if (--refCount == 0) delete this; }

	CalcProxy2() { server = ec_find_server("Calc"); }
	~CalcProxy2() { std::cout << "~CalcProxy2" << std::endl; }

	int Add(int a, int b) override { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) override { return ec_send_server(server, 2, a, b); }
};

extern "C"
ICalc* CreateInstance()
{
    return new CalcProxy;
}

int main
{
    return 0;
}