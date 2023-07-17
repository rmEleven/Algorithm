#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
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

int spfa()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; ~i; i = nex[i])
        {
            int j = val[i];
            if (d[t] + w[i] < d[j])
            {
                d[j] = d[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
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

    int ans = spfa();

    if (ans < INF / 2)
        printf("%d", ans);
    else
        printf("impossible");

    return 0;
}