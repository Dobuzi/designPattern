struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};

template<typename T> class List
{
	ISync* pSync = nullptr;
public:
	void setSync(ISync* p) { pSync = p; }

	void push_front(const T& a)
	{
		if (pSync) pSync->lock();
		//......
		if (pSync) pSync->unlock();
	}
};

struct pthread_locker : public ISync
{
	public:
		void lock() override {} // pthread_mutex_acquire()
		void unlock() override {} // pthread_mutex_release()
};

List<int> st; 

int main()
{
	pthread_locker locker;
	st.setSync(&locker);
	st.push_front(10);
}




