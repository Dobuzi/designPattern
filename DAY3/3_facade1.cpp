
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

int main()
{
	// // 1. ��Ʈ��ũ ���̺귯�� �ʱ�ȭ
	// WSADATA w;
	// WSAStartup(0x202, &w);

	// 2. ���� ����
	int sock = socket(PF_INET, SOCK_STREAM, 0); // TCP ����

	// 3. ���Ͽ� �ּ� ����
	struct sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sock, (SOCKADDR*)&addr, sizeof(addr));

	// 4. ������ ��� ���·κ���
	listen(sock, 5);

	// 5. Ŭ���̾�Ʈ�� �����Ҷ� ���� ���
	struct sockaddr_in addr2 = { 0 };
	int sz = sizeof(addr2);

	accept(sock, (SOCKADDR*)&addr2, &sz);

	// 6. socket ���̺귯�� cleanup
	WSACleanup();
}