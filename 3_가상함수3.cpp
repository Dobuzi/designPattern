// 2_�����Լ�������
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// 오타이나 정상적 컴파일
	// virtual void fooo()  {}
	// virtual void goo(double)  {}

	// cpp11에서 새 문법 추가
	virtual void foo() override {}
	// virtual void goo(double) override {}
};
int main()
{

}