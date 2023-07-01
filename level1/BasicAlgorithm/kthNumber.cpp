#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int q[N];

int quickSort(int l, int r, int k)
{
    if (l >= r)
        return q[l];

    int x = q[l + r >> 1];
    int i = l - 1;
    int j = r + 1;

    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);

        if (i < j)
            swap(q[i], q[j]);
    }

    int len = j - l + 1;
    if (k <= len)
        return quickSort(l, j, k);
    return quickSort(j + 1, r, k - len);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    printf("%d", quickSort(0, n - 1, m));

    return 0;
}