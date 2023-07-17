#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
const int M = 10010;
const int INF = 0x3f3f3f3f;

int n, m, k;
int d[N], backup[N];

struct Edge
{
    int a, b, c;
} edges[M];

int bellmanford()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    for (int i = 0; i < k; i++)
    {
        memcpy(backup, d, sizeof d);

        for (int j = 0; j < m; j++)
        {
            int a = edges[j].a;
            int b = edges[j].b;
            int c = edges[j].c;

            d[b] = min(d[b], backup[a] + c);
        }
    }

    return d[n];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    int ans = bellmanford();

    if (ans < INF / 2)
        printf("%d", ans);
    else
        printf("impossible");

    return 0;
}