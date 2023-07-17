#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], val[N], nex[N], idx;
int q[N];
int d[N];

void addEdge(int a, int b)
{
    val[idx] = b;
    nex[idx] = h[a];
    h[a] = idx++;
}

int bfs()
{
    memset(d, -1, sizeof d);
    d[1] = 0;

    int head = 0, tail = -1;
    q[++tail] = 1;

    while (head <= tail)
    {
        int t = q[head++];

        for (int i = h[t]; ~i; i = nex[i])
        {
            int j = val[i];

            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q[++tail] = j;
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
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
    }

    cout << bfs() << endl;

    return 0;
}