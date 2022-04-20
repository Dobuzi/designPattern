#define USING_GUI
#include "cppmaster.h"

// Proxy pattern : Make class to delegate element
// Proxy : Change the function call to operation code and transfer it to server
// Stub : Call the function with arrived operation code
// We call it proxy-stub communication

class CalcProxy
{
	int server;
	public:
	CalcProxy() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	CalcProxy* pCalc = new CalcProxy;

	std::cout << pCalc->Add(10, 20) << std::endl;
    std::cout << pCalc->Sub(10, 20) << std::endl;
}





