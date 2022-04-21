#include <iostream>
#include <thread>
#include <chrono>

class Cursor
{
private:
	Cursor() 
	{
		std::cout << "Cursor() start " << std::endl;
		std::cout << std::this_thread::get_id() << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(30));

		std::cout << "Cursor() end" << std::endl;
	}

	Cursor(const Cursor& c) = delete;            
	Cursor& operator=(const Cursor& c) = delete; 

public:
	static Cursor& getInstance()
	{
		std::cout << "**** arrive : " << std::this_thread::get_id() << std::endl;
		static Cursor instance;
		std::cout << "**** finish : " << std::this_thread::get_id() << std::endl;

		return instance;
	}
};
int main()
{
	std::thread t1(&Cursor::getInstance);
	
	std::this_thread::sleep_for(std::chrono::seconds(1)); 

	std::thread t2(&Cursor::getInstance);

	t1.join();
	t2.join();
}








