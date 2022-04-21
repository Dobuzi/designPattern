// 7_�̱���1 - 123 page
#include <iostream>

// �̱���
// 1. ���� �Ѱ��� ��ü�� �����Ҽ� �ְ�, 
// 2. ��𼭵� ������ ������� ��ü�� �����Ҽ� �ִ�.

class Cursor
{
	private:
	Cursor() {}

	Cursor(const Cursor& c) = delete;
	Cursor& operator=(const Cursor& c) = delete;

	public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	
	std::cout << &c1 << "\n" << &c2 << std::endl;

	// Cursor c3 = c1;
	// std::cout << &c3 << std::endl;
	
	// c1 = c2;
}








