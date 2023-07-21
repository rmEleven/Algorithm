#include <iostream>
#include <string.h>
using namespace std;

const int N = 1010;
const int M = 15;

int n, m;
char str[N][M];
char tmp[M];
int f[M][M];

int editDis(char *a, char *b)
{
    int la = strlen(a + 1);
    int lb = strlen(b + 1);

    for (int i = 1; i <= la; i++)
        f[i][0] = i;
    for (int i = 1; i <= lb; i++)
        f[0][i] = i;

    for (int i = 1; i <= la; i++)
        for (int j = 1; j <= lb; j++)
        {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }

    return f[la][lb];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", str[i] + 1);

    while (m--)
    {
        int t;
        scanf("%s%d", tmp + 1, &t);

        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (editDis(str[i], tmp) <= t)
                cnt++;

        printf("%d\n", cnt);
    }

    return 0;
}