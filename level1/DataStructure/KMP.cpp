#include <iostream>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m;
char p[N], s[M];
int nex[N];

int main()
{
    scanf("%d%s%d%s", &n, p + 1, &m, s + 1);

    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])
            j = nex[j];
        if (p[i] == p[j + 1])
            j++;
        nex[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])
            j = nex[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
            printf("%d ", i - n);
    }

    return 0;
}