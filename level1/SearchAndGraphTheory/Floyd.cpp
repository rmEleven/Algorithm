#include <iostream>
#include <cstring>
using namespace std;

const int N = 210;
const int INF = 0x3f3f3f3f;

int n, m, q;
int d[N][N];

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }

    floyd();

    while (q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        if (d[a][b] < INF / 2)
            printf("%d\n", d[a][b]);
        else
            printf("impossible\n");
    }

    return 0;
}