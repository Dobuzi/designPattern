#include <iostream>
#include <vector>
#include <allocators> // C++ 표준 메모리 할당기

int main()
{
	// 메모리 할당 방법
	// 1. new / delete 를 직접 사용
	int* p1 = new int[10];
	delete[] p1;

	// 2. allocator 사용
	std::allocator<int> ax; 

	ax.deallocate(p, 10); 

}