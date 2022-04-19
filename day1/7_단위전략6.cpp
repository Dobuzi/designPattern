#include <iostream>
#include <vector>
// #include <allocators> // C++ ǥ�� �޸� �Ҵ��
#include <memory>

int main()
{
	// �޸� �Ҵ� ���
	// 1. new / delete �� ���� ���
	int* p1 = new int[10];
	delete[] p1;

	// 2. allocator ���
	std::allocator<int> ax;

	int* p = ax.allocate(10);
	ax.deallocate(p, 10); 

}