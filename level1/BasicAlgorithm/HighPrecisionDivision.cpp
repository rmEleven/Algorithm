#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> hpDiv(vector<int> &A, int &b)
{
    vector<int> C;
    int t = 0;

    for (int i = A.size() - 1; i >= 0; i--)
    {
        t = t * 10 + A[i];
        C.push_back(t / b);
        t %= b;
    }

    reverse(C.begin(), C.end());
    b = t;

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    auto C = hpDiv(A, b);
    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    printf("\n%d", b);

    return 0;
}