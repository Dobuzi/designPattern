#include <iostream>
using namespace std;

struct ISharedMemory
{
	virtual void* Alloc() = 0;
	virtual void Free() = 0;
	virtual ~ISharedMemory() {}
};

class Win32SharedMemory : public ISharedMemory
{
public:
	virtual void* Alloc() {}
	virtual void Free() {}
};
class LinuxSharedMemory : public ISharedMemory 
{
public:
	virtual void* Alloc() {}
	virtual void Free() {}
};

class SharedMemory
{
	ISharedMemory* impl;
	public:
	SharedMemory(ISharedMemory* p = nullptr)	:	impl(p)
	{
		if (p == nullptr) impl = new LinuxSharedMemory;
	}

	void* Alloc()	{ impl->Alloc(); }
	void Free()		{ impl->Free(); }
};

class Stack : public SharedMemory {};
class List	: public SharedMemory {};

// class	Win32Stack	:	public	Win32SharedMemory	{};
// class	Win32List	:	public	Win32SharedMemory	{};

// class	LinuxStack	:	public	LinuxSharedMemory	{};
// class	LinuxList	:	public	LinuxSharedMemory	{};

int main()
{
	return 0;
}