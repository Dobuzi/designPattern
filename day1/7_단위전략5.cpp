#include <memory>
// STL �� ����
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	Alloc ax;
public:
	void resize(int n)
	{
		T* buff = ax.allocate(n);

		ax.deallocate(buff, n);
	}
};

int main()
{
	
}