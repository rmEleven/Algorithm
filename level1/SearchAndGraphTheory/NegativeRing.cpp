#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 2010;
const int M = 10010;
const int INF = 0x3f3f3f3f;

int n, m;
int h[N], val[M], nex[M], w[M], idx;
int d[N], cnt[N];
bool st[N];

void addEdge(int a, int b, int c)
{
    w[idx] = c;
    val[idx] = b;
    nex[idx] = h[a];
    h[a] = idx++;
}

bool spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }

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
                cnt[j] = cnt[t] + 1;

                if (cnt[j] > n - 1)
                    return true;

                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
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

    if (spfa())
        printf("Yes");
    else
        printf("No");

    return 0;
}