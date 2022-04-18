template<typename T> class List
{
public:
	void push_front(const T& a)
	{
		//......
	}
};
List<int> st; // 전역변수는 멀티스레드에 안전하지 않습니다.

int main()
{
	st.push_front(10);
}




