#include <iostream>
#include <stack>

template<typename T> class CountedStack
{
    std::stack<T> c;
    int limit;
    public:
    CountedStack(int n) : limit(n) {}
    void push(const T& a)
    {
        if (c.size() == limit)
            throw std::overflow_error();
        c.push(a);
    }
    bool try_push(const T& a)
    {
        if (c.size() == limit)
            return false;
        c.push(a);
        return true;
    }
    T& top()    { return c.top(); }
    void pop()  { c.pop(); }
};

int main()
{
    // std::stack<int> stack;
    CountedStack<int> stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
}