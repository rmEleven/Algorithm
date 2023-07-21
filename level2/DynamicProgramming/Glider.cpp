#include <iostream>
using namespace std;

const int N = 110;

int k, n;
int a[N], f[N];

int main()
{
    scanf("%d", &k);

    while (k--)
    {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            f[i] = 1;
            for (int j = 1; j < i; j++)
                if (a[j] < a[i])
                    f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }

        for (int i = n; i >= 1; i--)
        {
            f[i] = 1;
            for (int j = n; j > i; j--)
                if (a[j] < a[i])
                    f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }

        printf("%d\n", ans);
    }

    return 0;
}