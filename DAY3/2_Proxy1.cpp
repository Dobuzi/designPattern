#define USING_GUI
#include "cppmaster.h"

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
	// 1. ������ �ڵ��� ��� �ɴϴ�.
	int server = ec_find_server("Calc");

	std::cout << "���� ��ȣ : " << server << std::endl;

	// 2. ������ �����ڵ�� �Ķ���͸� �����մϴ�.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





