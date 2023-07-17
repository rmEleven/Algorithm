#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int edge[N][N];
int d[N];
bool st[N];

int dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || d[j] < d[t]))
                t = j;

        st[t] = true;
        if (t == n)
            return d[t];

        for (int j = 1; j <= n; j++)
            d[j] = min(d[j], d[t] + edge[t][j]);
    }

    return d[n];
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(edge, 0x3f, sizeof edge);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[a][b] = min(edge[a][b], c);
    }

    int ans = dijkstra();

    if (ans == INF)
        printf("-1");
    else
        printf("%d", ans);

    return 0;
}