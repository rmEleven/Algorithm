// f[k][i][j]：表示路径1从(1, 1)走到(i, k-i)，路径2从(1, 1)走到(j, k-j)的所有路径中，数字和的最大值

#include <iostream>
using namespace std;

const int N = 15;

int n;
int a[N][N];
int f[N * 2][N][N];

int main()
{
    scanf("%d", &n);

    int r, c, x;
    while (scanf("%d%d%d", &r, &c, &x), r || c || x)
        a[r][c] = x;

    for (int k = 2; k <= n * 2; k++)
        for (int i1 = 1; i1 <= n; i1++)
            for (int i2 = 1; i2 <= n; i2++)
            {
                int j1 = k - i1;
                int j2 = k - i2;

                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
                {
                    int t = a[i1][j1];
                    if (i1 != i2)
                        t += a[i2][j2];

                    int &x = f[k][i1][i2];
                    x = max(x, f[k - 1][i1][i2] + t);
                    x = max(x, f[k - 1][i1 - 1][i2] + t);
                    x = max(x, f[k - 1][i1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                }
            }

    printf("%d", f[n * 2][n][n]);

    return 0;
}