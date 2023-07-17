#include <iostream>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
const int N = 110;

int n, m;
int maze[N][N];
int step[N][N];

pii q[N * N];
int head, tail = -1;

void bfs()
{
    int nx[4] = {1, -1, 0, 0};
    int ny[4] = {0, 0, 1, -1};

    memset(step, -1, sizeof step);

    q[++tail] = {1, 1};
    step[1][1] = 0;

    while (head <= tail)
    {
        auto t = q[head++];

        for (int i = 0; i < 4; i++)
        {
            int a = t.first + nx[i];
            int b = t.second + ny[i];

            bool inside = a > 0 && a <= n && b > 0 && b <= m;

            if (inside && maze[a][b] == 0 && step[a][b] == -1)
            {
                step[a][b] = step[t.first][t.second] + 1;
                q[++tail] = {a, b};
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &maze[i][j]);

    bfs();
    printf("%d", step[n][m]);

    return 0;
}