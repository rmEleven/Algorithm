#include <iostream>
using namespace std;

void getPrimeFactor(int x)
{
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt++;
                x /= i;
            }
            printf("%d %d\n", i, cnt);
        }

    if (x > 1)
        printf("%d %d\n", x, 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);

        getPrimeFactor(x);
        printf("\n");
    }

    return 0;
}