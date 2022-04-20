#include <iostream>
#include <list>
#include <vector>
#include <deque>


// STL �� Adapter

template<typename T>
class stack : private std::list<T>
{
	public:
	void	push(const T& a)	{ std::list<T>::push_back(a); }
	void	pop()				{ std::list<T>::pop_back(); }
	T&		top()				{ return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	std::cout << s.top() << std::endl;

	// s.push_front(20);
}