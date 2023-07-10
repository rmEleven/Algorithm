#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int q[N];
int head, tail = -1;

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
            q[++tail] = x;
        }
        else if (op == "pop")
            head++;
        else if (op == "empty")
            if (head > tail)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        else if (op == "query")
            cout << q[head] << endl;
    }

    return 0;
}