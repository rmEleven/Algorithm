#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3e5 + 10;
typedef pair<int, int> pii;

int n, m;
int a[N], s[N];
vector<int> alls;
vector<pii> adds;
vector<pii> querys;

int find(int x)
{
    int l = 0;
    int r = alls.size() - 1;

    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    return l + 1;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        int x, c;
        scanf("%d%d", &x, &c);
        adds.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        querys.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto add : adds)
    {
        int k = find(add.first);
        a[k] += add.second;
    }

    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    for (auto query : querys)
    {
        int l = find(query.first);
        int r = find(query.second);
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}