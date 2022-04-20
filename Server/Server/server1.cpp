// Server1.cpp
#define USING_GUI
#include "cppmaster.h" 

class Server
{
public:
	int Add(int a, int b) { return a + b; }
	int Sub(int a, int b) { return a - b; }
};
Server server;

int handler(int code, int a, int b)
{
	printf("메세지 도착 : %d, %d, %d\n", code, a, b);
	switch (code)
	{
	case 1: return server.Add(a, b);
	case 2: return server.Sub(a, b);
	}
	return 0;
}
int main()
{
	// IPC 서버로 시작
	ec_start_server("Calc", &handler);
}




