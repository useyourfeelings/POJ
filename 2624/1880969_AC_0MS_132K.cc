#include<iostream>
using namespace std;

int main()
{
    double x1, x2, x3, y1, y2, y3, x4, y4;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
                &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != EOF)
    {
        if(x1 == x4 && y1 == y4)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        else if(x3 == x1 && y3 == y1)
        {
            swap(x1, x2);
            swap(y1, y2);
            swap(x4, x3);
            swap(y4, y3);
        }
        else if(x3 == x2 && y3 == y2)
        {
            swap(x4, x3);
            swap(y4, y3);
        }
        printf("%.3lf %.3lf\n", x3 + x1 - x2, y3 + y1 - y2);
    }
    return 0;
}