#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i;

    while (m--)
    {
        char op[2];
        int a, b;

        scanf("%s%d%d", op, &a, &b);

        int ra = find(a);
        int rb = find(b);

        if (op[0] == 'M')
            p[ra] = rb;
        else if (op[0] == 'Q')
            if (ra == rb)
                printf("Yes\n");
            else
                printf("No\n");
    }

    return 0;
}