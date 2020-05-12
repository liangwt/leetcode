/**
 * 使用一个辅助栈，记录每一层的最小值
 **/ 

#include <stack>
#include <limits.h>

using namespace std;

class MinStack
{
public:
    stack<int> sk;
    stack<int> min_sk;

    /** initialize your data structure here. */
    MinStack()
    {
        min_sk.push(INT_MAX);
    }

    void push(int x)
    {
        sk.push(x);
        min_sk.push(min(x, min_sk.top()));
    }

    void pop()
    {
        sk.pop();
        min_sk.pop();
    }

    int top()
    {
        return sk.top();
    }

    int getMin()
    {
        return min_sk.top();
    }
};

int main()
{
    auto m = new MinStack();
    m->push(-2);
    m->push(0);
    m->push(-3);

    assert(m->getMin() == -3);

    m->pop();

    assert(m->top() == 0);
    assert(m->getMin() == -2);
}
