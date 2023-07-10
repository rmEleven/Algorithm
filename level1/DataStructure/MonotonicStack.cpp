#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> stk;

int main()
{
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);

        while (stk.size() && stk.top() >= x)
            stk.pop();
        if (stk.size())
            printf("%d ", stk.top());
        else
            printf("-1 ");
        stk.push(x);
    }

    return 0;
}