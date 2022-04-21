#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class CalcProxy : public ICalc
{
	int server;
	public:
	CalcProxy() { server = ec_find_server("Calc"); }

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