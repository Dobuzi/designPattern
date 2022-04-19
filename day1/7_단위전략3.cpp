// Policy Base Design
// 1. Interface Base Change - Strategy Pattern
// 2. Template Base Change - Policy Base Design
struct nolock
{
	inline void lock()		{}
	inline void unlock()	{}
};

struct mutex_lock
{
	inline void lock()		{}
	inline void unlock()	{}
};

template<typename T, typename ThreadModel = nolock> class List
{
	ThreadModel locker;
public:
	void push_front(const T& a)
	{
		locker.lock();
		//......
		locker.unlock();
	}
};

List<int> st;
List<int, mutex_lock> st2;

int main()
{
	st.push_front(10);
}




