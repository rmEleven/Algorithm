#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 150010;
const int INF = 0x3f3f3f3f;

int n, m;
int h[N], val[N], nex[N], w[N], idx;
int d[N];
bool st[N];

void addEdge(int a, int b, int c)
{
    w[idx] = c;
    val[idx] = b;
    nex[idx] = h[a];
    h[a] = idx++;
}

int dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, 1});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int dist = t.first;
        int num = t.second;

        st[num] = true;

        if (num == n)
            return dist;

        for (int i = h[num]; ~i; i = nex[i])
        {
            int j = val[i];
            if (!st[j] && d[num] + w[i] < d[j])
            {
                d[j] = d[num] + w[i];
                heap.push({d[j], j});
            }
        }
    }

    return d[n];
}

int main()
{
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addEdge(a, b, c);
    }

    int ans = dijkstra();

    if (ans == INF)
        printf("-1");
    else
        printf("%d", ans);

    return 0;
}