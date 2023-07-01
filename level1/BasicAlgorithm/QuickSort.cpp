#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int q[N];

void quickSort(int l, int r)
{
    if (l >= r)
        return;

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

    quickSort(l, j);
    quickSort(j + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    quickSort(0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}