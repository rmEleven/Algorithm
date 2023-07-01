#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int INF = 2e9;

int n;
vector<pii> segs;

int merge()
{
    vector<pii> ans;
    sort(segs.begin(), segs.end());

    int st = -INF, ed = -INF;
    for (auto seg : segs)
    {
        if (seg.first <= ed)
            ed = max(ed, seg.second);
        else
        {
            if (st != -INF)
                ans.push_back({st, ed});
            st = seg.first;
            ed = seg.second;
        }
    }
    if (st != -INF)
        ans.push_back({st, ed});

    return ans.size();
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }

    printf("%d", merge());

    return 0;
}