#include <iostream>
using namespace std;

const int N = 1010;

int n;
int a[N], f[N];

int main()
{
    scanf("%d", &n);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);

        f[i] = a[i];
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + a[i]);
        ans = max(ans, f[i]);
    }

    printf("%d", ans);

    return 0;
}