// PointImpl.h
class PointImpl
{
	int x, y;

	public:
	void print();
}

// PointImpl.cpp
#include "PointImpl.h"
void PointImpl::print() {}

// Point.h
class PointImpl;
class Point
{
	PointImpl* pImpl;
public:
	Point();
	void print();
};
// Point.cpp
#include "Point.h"
#include "PointImpl.h"

Point::Point() { pImpl = new PointImpl; }
void Point::print() { pImpl->print(); } // ���� ����

// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}

// PIMPL (Pointer to IMPLemenation) : Use bridge pattern to speed compile. (a.k.a Firewall for Compiler)