template<typename T> class List
{
public:
	void push_front(const T& a)
	{
		lock();

		unlock();
	}

	virtual void lock() {}
	virtual void unlock() {}
};
List<int> st; // ���������� ��Ƽ�����忡 �������� �ʽ��ϴ�.

int main()
{
	st.push_front(10);
}




