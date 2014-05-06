#include<iostream>
using namespace std;

int main()
{
    int i, j;
    double x1, x2, x3, y1, y2, y3, t1, t2, x, y;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
                &x1, &y1, &x2, &y2, &t1, &t2, &x3, &y3) != EOF)
    printf("%.3f %.3f\n", x3 + x1 - x2, y3 + y1 - y2);
    return 0;
}