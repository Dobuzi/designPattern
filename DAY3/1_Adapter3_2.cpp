#include <iostream>
#include <list>
#include <vector>
#include <deque>

// class adapter
// template<typename T, typename Container = std::deque<T> >
// class stack
// {
// 	Container c;
// 	public:
// 	inline	void	push(const T& a)	{ c.push_back(a); }
// 	inline	void	pop()				{ c.pop_back(); }
// 	inline	T&		top()				{ return c.back(); }
// };

// Object adapter
template<typename T, typename Container = std::deque<T> >
class stack
{
	Container* c;
	public:
	stack(Container* c) : c(c) {}
	inline	void	push(const T& a)	{ c->push_back(a); }
	inline	void	pop()				{ c->pop_back(); }
	inline	T&		top()				{ return c->back(); }
};

// #include <stack>
// using namespace std;

int main()
{
	// stack<int, std::vector<int>	>	s;
	// stack<int, std::list<int>	>	s2;
	std::list<int> ss;
	stack<int, std::list<int>	>	s(&ss);

	s.push(10);
	std::cout << s.top() << std::endl;

	// s.push_front(20);
}