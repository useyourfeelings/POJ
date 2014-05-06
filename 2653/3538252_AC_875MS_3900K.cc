#include<iostream>
using namespace std;

struct Line
{
    double a;
    double b;
    double c;
    double d;
};

Line lines[100001];
int dead[100001];

double direction(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3)
{
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int intersect(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3, const double &x4, const double &y4)
{
    return max(x1, x2) >= min(x3, x4) &&
           max(x3, x4) >= min(x1, x2) &&
           max(y1, y4) >= min(y3, y4) &&
           max(y3, y4) >= min(y1, y2) &&
           direction(x1, y1, x2, y2, x3, y3) * direction(x1, y1, x2, y2, x4, y4) <= 0 &&
           direction(x3, y3, x4, y4, x1, y1) * direction(x3, y3, x4, y4, x2, y2) <= 0;
}

int main()
{
    int n, i, j, total;
    while(scanf("%d", &n) && n != 0)
    {
        for(i = 1; i <= n; ++ i) dead[i] = 0;
        for(i = 1; i <= n; ++ i)
            scanf("%lf%lf%lf%lf", &lines[i].a, &lines[i].b, &lines[i].c, &lines[i].d);
        total = 1;
        for(i = 1; i < n; ++ i)
        {
            for(j = i + 1; j <= n; ++ j)
            {
                if(intersect(lines[i].a, lines[i].b, lines[i].c, lines[i].d,
                             lines[j].a, lines[j].b, lines[j].c, lines[j].d))
                {
                    dead[i] = 1;
                    break;
                }
            }
            if(j >= n) // got
            {
                if(++ total >= 1000) break;
            }
        }
        printf("Top sticks: ");
        for(i = 1; i < n; ++ i)
            if(!dead[i]) printf("%d, ", i);
        printf("%d.\n", n);
    }
    return 0;
}