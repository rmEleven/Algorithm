#include <iostream>
using namespace std;

const int N = 50010;

int n, m;
int p[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i;

    int cnt = 0;
    while (m--)
    {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);

        if (a > n || b > n)
        {
            cnt++;
            continue;
        }

        int ra = find(a);
        int rb = find(b);

        if (op == 1)
        {
            if (ra != rb)
            {
                p[ra] = rb;
                d[ra] = d[b] - d[a];
            }
            else if ((d[a] - d[b]) % 3)
                cnt++;
        }
        else if (op == 2)
        {
            if (ra != rb)
            {
                p[ra] = rb;
                d[ra] = d[b] - d[a] + 1;
            }
            else if ((d[a] - d[b] - 1) % 3)
                cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}