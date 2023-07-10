#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 10;

char str[N];
stack<int> nums;
stack<char> ops;
unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval()
{
    int b = nums.top();
    nums.pop();
    int a = nums.top();
    nums.pop();
    char c = ops.top();
    ops.pop();

    int x = 0;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else if (c == '/')
        x = a / b;

    nums.push(x);
}

int main()
{
    cin >> str;

    for (int i = 0; str[i]; i++)
    {
        char t = str[i];

        if (isdigit(t))
        {
            int n = 0;
            int j = i;
            while (isdigit(str[j]))
                n = n * 10 + str[j++] - '0';
            nums.push(n);
            i = j - 1;
        }
        else if (t == '(')
            ops.push(t);
        else if (t == ')')
        {
            while (ops.top() != '(')
                eval();
            ops.pop();
        }
        else
        {
            while (ops.size() && pr[ops.top()] >= pr[t])
                eval();
            ops.push(t);
        }
    }

    while (ops.size())
        eval();

    cout << nums.top() << endl;

    return 0;
}