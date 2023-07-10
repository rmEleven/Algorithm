#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int stk[N], top = -1;

int main()
{
    cin >> n;

    while (n--)
    {
        string op;
        int x;

        cin >> op;

        if (op == "push")
        {
            cin >> x;
            stk[++top] = x;
        }
        else if (op == "pop")
            top--;
        else if (op == "empty")
            if (top == -1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        else if (op == "query")
            cout << stk[top] << endl;
    }

    return 0;
}