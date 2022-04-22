// 방문자 패턴의 의미!!
class Shape
{
	virtual void Draw() = 0;
};
class Rect : public Shape {};
class Circle : public Shape {};

// 전통적인 객체지향 디자인
// 클래스의 추가    :  ?
// 가상 함수의 추가 :  ?


// 방문자 패턴으로 디자인 하면
// 클래스의 추가 : ?
// 함수의 추가   : ?




