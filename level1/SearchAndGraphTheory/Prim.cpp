#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int edge[N][N];
int d[N];
bool st[N];

int prim()
{
    int size = 0;

    memset(d, 0x3f, sizeof d);

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || d[j] < d[t]))
                t = j;

        st[t] = true;

        if (i && d[t] == INF)
            return INF;

        if (i)
            size += d[t];

        for (int j = 1; j <= n; j++)
            if (!st[j] && edge[t][j] < d[j])
                d[j] = edge[t][j];
    }

    return size;
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(edge, 0x3f, sizeof edge);
    for (int i = 1; i <= n; i++)
        edge[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[a][b] = edge[b][a] = min(edge[a][b], c);
    }

    int ans = prim();
    if (ans > INF / 2)
        printf("impossible");
    else
        printf("%d", ans);

    return 0;
}