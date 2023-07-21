#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5010;
typedef pair<int, int> pii;

int n;
pii a[N];
int f[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    sort(a + 1, a + n + 1);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j].second < a[i].second)
                f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }
    printf("%d", ans);

    return 0;
}