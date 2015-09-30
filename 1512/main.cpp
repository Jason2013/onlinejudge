#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

class CQueue
{
public:
    void push_back(int n);
    int pop_front();
private:
    stack<int> a;
    stack<int> b;
};

void CQueue::push_back(int n)
{
    a.push(n);
}

int CQueue::pop_front()
{
    if (b.empty())
    {
        while (!a.empty())
        {
            b.push(a.top());
            a.pop();
        }
    }
    if (!b.empty())
    {
        int r = b.top();
        b.pop();
        return r;
    }
    return -1;
}

int main()
{
    int n, val;
    char op[10];
    CQueue q;

    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        scanf("%s", op);
        if (strcmp(op, "PUSH") == 0)
        {
            scanf("%d", &val);
            q.push_back(val);
        }
        else if (strcmp(op, "POP") == 0)
        {
            val = q.pop_front();
            printf("%d\n", val);
        }
    }
    return 0;
}
