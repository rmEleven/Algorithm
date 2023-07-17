#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int n;
int h[N], val[N * 2], nex[N * 2], idx;
bool st[N];
int ans = N;

void addEdge(int a, int b)
{
    val[idx] = b;
    nex[idx] = h[a];
    h[a] = idx++;
}

int dfs(int x)
{
    int size = 0;
    int tmax = 0;

    st[x] = true;

    for (int i = h[x]; i != -1; i = nex[i])
    {
        int j = val[i];

        if (!st[j])
        {
            int s = dfs(j);
            tmax = max(tmax, s);
            size += s;
        }
    }

    tmax = max(tmax, n - size - 1);
    ans = min(ans, tmax);

    return size + 1;
}

int main()
{
    memset(h, -1, sizeof h);

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        addEdge(a, b);
        addEdge(b, a);
    }

    dfs(1);

    printf("%d", ans);

    return 0;
}