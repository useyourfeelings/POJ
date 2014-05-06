#include<iostream>
using namespace std;

int main()
{
    int i, j;
    double x1, x2, x3, y1, y2, y3, t1, t2, x, y;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
                &x1, &y1, &x2, &y2, &t1, &t2, &x3, &y3) != EOF)
    {
        if(t1 == x1 && t2 == y2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        else if(x3 == x1 && y3 == y1)
        {
            swap(x1, x2);
            swap(y1, y2);
            swap(t1, x3);
            swap(t2, y3);
        }
        else if(x3 == x2 && y3 == y2)
        {
            swap(t1, x3);
            swap(t2, y3);
        }
        printf("%.3f %.3f\n", x3 + x1 - x2, y3 + y1 - y2);
    }
    return 0;
}