#include <iostream>
#include <vector>
#include <memory>

template<typename T>
class MyAlloc
{
	public:
		T* allocate(std::size_t sz)
		{
			T* p = static_cast<T*>(malloc(sizeof(T) * sz));
			std::cout << sz << " allocated at" << p << std::endl;
			return p;
		}

		void deallocate(T* p, std::size_t sz)
		{
			std::cout << sz << " deallocated at" << p << std::endl;
			free(p);
		}

		typedef T value_type;

		MyAlloc() {}

		template<typename U> MyAlloc(const MyAlloc<U>&) {}
};

int main()
{
	std::vector<int, MyAlloc<int> > v;

	v.resize(2);
	v.push_back(299);
	v.push_back(2);
	v.resize(100);
}

// Design Pattern : Design Skill for every OOP langs
// Idioms : Design Skill for the specific lang