#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int h[N], val[M], nex[M], idx;
int color[N];

void addEdge(int a, int b)
{
    val[idx] = b;
    nex[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int x, int c)
{
    color[x] = c;

    for (int i = h[x]; ~i; i = nex[i])
    {
        int j = val[i];
        if (!color[j] && !dfs(j, 3 - c))
            return false;
        else if (color[j] == c)
            return false;
    }

    return true;
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
        addEdge(b, a);
    }

    bool ans = true;
    for (int i = 1; i <= n; i++)
        if (!color[i] && !dfs(i, 1))
        {
            ans = false;
            break;
        }

    if (ans)
        printf("Yes");
    else
        printf("No");

    return 0;
}