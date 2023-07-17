#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int p[N];
struct Edge
{
    int a, b, c;
    bool operator<(const Edge &E) const
    {
        return c < E.c;
    }
} edges[M];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    int size = 0;
    int cnt = 0;

    sort(edges, edges + m);

    for (int i = 0; i < m; i++)
    {
        int a = edges[i].a;
        int b = edges[i].b;
        int c = edges[i].c;

        int ra = find(a);
        int rb = find(b);

        if (ra != rb)
        {
            p[ra] = rb;
            size += c;
            cnt++;
        }
    }

    if (cnt < n - 1)
        return INF;
    return size;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    int ans = kruskal();

    if (ans > INF / 2)
        printf("impossible");
    else
        printf("%d", ans);

    return 0;
}