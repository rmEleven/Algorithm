#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
const int M = 1e5 + 10;

int n1, n2, m;
int h[N], val[M], nex[M], idx;
int match[N];
bool st[N];

void addEdge(int a, int b)
{
    val[idx] = b;
    nex[idx] = h[a];
    h[a] = idx++;
}

bool find(int x)
{
    for (int i = h[x]; ~i; i = nex[i])
    {
        int j = val[i];

        if (!st[j])
        {
            st[j] = true;

            if (!match[j] || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    memset(h, -1, sizeof h);

    scanf("%d%d%d", &n1, &n2, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
    }

    int ans = 0;
    for (int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof st);
        if (find(i))
            ans++;
    }
    printf("%d", ans);

    return 0;
}