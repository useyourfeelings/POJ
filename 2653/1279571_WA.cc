#include<iostream>
#include<list>
using namespace std;

struct point
{
    point(double a, double b):x(a),y(b){}
    double x;
    double y;
};

struct line
{
    line(double a, double b, double c, double d, int e):
                           p1(a, b),p2(c, d),id(e){}
    point p1;
    point p2;
    int id;
};

double direction(point i, point j, point k)
{
    return (k.x - i.x) * (j.y - i.y) -
           (k.y - i.y) * (j.x - i.x);
}

bool on(point i, point j, point k)
{
    if(min(i.x, j.x) <= k.x && k.x <= max(i.x, j.x) &&
       min(i.y, j.y) <= k.y && k.y <= max(i.y, j.y)) return 1;
    return 0;
}

bool intersect(point p1, point p2, point p3, point p4)
{
    double d1, d2, d3, d4;
    d1 = direction(p3, p4, p1);
    d2 = direction(p3, p4, p2);
    d3 = direction(p1, p2, p3);
    d4 = direction(p1, p2, p4);
    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
       ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) return 1;
    else if(d1 == 0 && on(p3, p4, p1)) return 1;
    else if(d2 == 0 && on(p3, p4, p2)) return 1;
    else if(d3 == 0 && on(p1, p2, p3)) return 1;
    else if(d4 == 0 && on(p1, p2, p4)) return 1;
    else return 0;
}

int main()
{   
    int n, i, j;
    double a, b, c, d;
    while(scanf("%d", &n) == 1 && n != 0)
    {
        list<line> LL;
        list<line>::iterator itr;
        for(i = 1; i <= n; i++)
        {
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            itr = LL.begin();
            for(; itr != LL.end(); ++itr)
            {
                if(intersect(point(a, b), point(c, d),
                             itr -> p1, itr -> p2))
                    itr = LL.erase(itr);
            }
            LL.push_back(line(a, b, c, d, i));
        }
        LL.pop_back();
        cout<<"Top sticks: ";
        itr = LL.begin();
        for(; itr != LL.end(); ++itr) cout<<itr -> id<<", ";
        cout<<n<<"."<<endl;
    }
    return 0;
}