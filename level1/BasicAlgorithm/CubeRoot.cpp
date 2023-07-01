#include <iostream>
using namespace std;

const double INF = 100000.0;

int main()
{
    double x;
    scanf("%lf", &x);

    double l = -INF, r = INF;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid > x)
            r = mid;
        else
            l = mid;
    }

    printf("%.6lf", l);

    return 0;
}