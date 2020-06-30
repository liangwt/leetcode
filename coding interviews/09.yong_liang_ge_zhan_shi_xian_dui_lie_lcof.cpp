#include <stack>

using namespace std;

class CQueue
{
private:
    stack<int> T;
    stack<int> R;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        // 先把R里的挪到T中
        while (!R.empty())
        {
            int n = R.top();
            T.push(n);
            R.pop();
        }

        // 把要插入的元素放到T的栈顶
        T.push(value);

        // 再把T里的挪回R中，于是新插入的元素就在R的栈底了
        while (!T.empty())
        {
            int n = T.top();
            R.push(n);
            T.pop();
        }
    }

    int deleteHead()
    {
        // 直接删除R的栈顶
        if (R.empty())
        {
            return -1;
        }

        int n = R.top();
        R.pop();
        return n;
    }
};

int main()
{
    auto q1 = new CQueue();
    q1->appendTail(3);
    assert(q1->deleteHead() == 3);
    assert(q1->deleteHead() == -1);

    auto q2 = new CQueue();
    assert(q2->deleteHead() == -1);
    q2->appendTail(5);
    q2->appendTail(2);
    assert(q2->deleteHead() == 5);
    assert(q2->deleteHead() == 2);
}