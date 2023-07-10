#include <iostream>
using namespace std;

typedef unsigned long long ull;

const int N = 1e5 + 10;
const int P = 131;

int n, m;
char str[N];
ull h[N], p[N];

ull getHash(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    scanf("%d%d%s", &n, &m, str + 1);

    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }

    while (m--)
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        if (getHash(l1, r1) == getHash(l2, r2))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}