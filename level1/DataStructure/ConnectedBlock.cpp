#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N], cnt[N];

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
    {
        p[i] = i;
        cnt[i] = 1;
    }

    while (m--)
    {
        char op[3];
        int a, b;

        scanf("%s", op);

        if (op[0] == 'C')
        {
            scanf("%d%d", &a, &b);
            int ra = find(a);
            int rb = find(b);

            if (ra != rb)
            {
                p[ra] = rb;
                cnt[rb] += cnt[ra];
            }
        }
        else if (op[1] == '1')
        {
            scanf("%d%d", &a, &b);
            int ra = find(a);
            int rb = find(b);

            if (ra == rb)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
        {
            scanf("%d", &a);
            int ra = find(a);
            printf("%d\n", cnt[ra]);
        }
    }

    return 0;
}