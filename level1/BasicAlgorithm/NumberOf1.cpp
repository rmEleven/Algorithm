#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);

        int cnt = 0;
        while (x)
        {
            x -= x & -x;
            cnt++;
        }
        printf("%d ", cnt);
    }

    return 0;
}