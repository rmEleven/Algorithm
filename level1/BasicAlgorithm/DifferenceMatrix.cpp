#include <iostream>
using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N], s[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &s[i][j]);
            a[i][j] = s[i][j] - s[i - 1][j] - s[i][j - 1] + s[i - 1][j - 1];
        }

    while (q--)
    {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        a[x1][y1] += c;
        a[x2 + 1][y1] -= c;
        a[x1][y2 + 1] -= c;
        a[x2 + 1][y2 + 1] += c;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}