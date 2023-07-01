#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int n;
int q[N], t[N];

ll mergeSort(int l, int r)
{
    if (l >= r)
        return 0;

    int mid = l + r >> 1;
    ll ans = mergeSort(l, mid) + mergeSort(mid + 1, r);

    int i = l;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            t[k++] = q[i++];
        else
        {
            ans += mid - i + 1;
            t[k++] = q[j++];
        }
    }

    while (i <= mid)
        t[k++] = q[i++];
    while (j <= r)
        t[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = t[j];

    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    printf("%lld", mergeSort(0, n - 1));

    return 0;
}