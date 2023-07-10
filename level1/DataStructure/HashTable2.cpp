#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5 + 3;

int n;
int h[N];

int find(int x)
{
    int k = (x % N + N) % N;

    while (h[k] != 0x3f3f3f3f && h[k] != x)
    {
        if (k == N - 1)
            k = 0;
        else
            k++;
    }

    return k;
}

int main()
{
    scanf("%d", &n);
    memset(h, 0x3f, sizeof h);

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        int k = find(x);

        if (op[0] == 'I')
            h[k] = x;
        else if (op[0] == 'Q')
            if (h[k] == x)
                printf("Yes\n");
            else
                printf("No\n");
    }

    return 0;
}