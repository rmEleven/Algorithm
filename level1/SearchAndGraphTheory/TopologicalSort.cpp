#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], val[N], nex[N], idx;
int in[N];
int q[N];

void addEdge(int a, int b)
{
    in[b]++;
    val[idx] = b;
    nex[idx] = h[a];
    h[a] = idx++;
}

bool topsort()
{
    int head = 0, tail = -1;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q[++tail] = i;

    while (head <= tail)
    {
        int t = q[head++];

        for (int i = h[t]; ~i; i = nex[i])
        {
            int j = val[i];

            in[j]--;
            if (in[j] == 0)
                q[++tail] = j;
        }
    }

    return tail == n - 1;
}

int main()
{
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
    }

    if (topsort())
        for (int i = 0; i < n; i++)
            printf("%d ", q[i]);
    else
        printf("-1");

    return 0;
}