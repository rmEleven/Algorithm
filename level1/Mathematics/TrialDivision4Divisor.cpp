#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getDivisors(int x)
{
    vector<int> ans;

    for (int i = 1; i <= x / i; i++)
        if (x % i == 0)
        {
            ans.push_back(i);
            if (i != x / i)
                ans.push_back(x / i);
        }

    sort(ans.begin(), ans.end());

    for (int &x : ans)
        printf("%d ", x);
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);
        getDivisors(x);
        printf("\n");
    }

    return 0;
}