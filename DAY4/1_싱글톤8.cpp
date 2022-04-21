// 7_�̱���1 - 123 page
#include <iostream>

// �̱���
// 1. ���� �Ѱ��� ��ü�� �����Ҽ� �ְ�, 
// 2. ��𼭵� ������ ������� ��ü�� �����Ҽ� �ִ�.

class Cursor
{
	private:
	Cursor()
	{
		std::cout << "Cursor()" << std::endl;
	}

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
	std::cout << "-------------" << std::endl;

	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	
}








