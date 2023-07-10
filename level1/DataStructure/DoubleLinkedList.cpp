#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int val[N], l[N], r[N], idx;

void addLeft(int k, int x)
{
    val[idx] = x;
    r[idx] = k;
    l[idx] = l[k];
    r[l[k]] = idx;
    l[k] = idx++;
}

void addRight(int k, int x)
{
    val[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx++;
}

void delNode(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    idx = 2;
    r[0] = 1;
    l[1] = 0;

    scanf("%d", &n);

    while (n--)
    {
        string op;
        int k, x;
        cin >> op;

        if (op == "L")
        {
            scanf("%d", &x);
            addRight(0, x);
        }
        else if (op == "R")
        {
            scanf("%d", &x);
            addLeft(1, x);
        }
        else if (op == "D")
        {
            scanf("%d", &k);
            delNode(k + 1);
        }
        else if (op == "IL")
        {
            scanf("%d%d", &k, &x);
            addLeft(k + 1, x);
        }
        else if (op == "IR")
        {
            scanf("%d%d", &k, &x);
            addRight(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
        printf("%d ", val[i]);

    return 0;
}