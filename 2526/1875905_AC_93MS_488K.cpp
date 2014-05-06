#include<iostream>
#include<set>
using namespace std;

struct point
{
    point(int xx, int yy):x(xx),y(yy){}
    int x;
    int y;
};

bool operator<(const point &a, const point &p)
{
    if(a.x != p.x) return a.x < p.x;
    return a.y < p.y;
}

int main()
{
    int i, n, Case, maxx, maxy, minx, miny, x, y, cenx, ceny, x5, y5;
    set<point>::iterator itr;
    scanf("%d", &Case);
    while(Case --)
    {
        maxx = maxy = -10000001;
        minx = miny = 10000001;
        set<point> P;
        scanf("%d", &n);
        while(n --)
        {
            scanf("%d%d", &x, &y);
            if(x > maxx) maxx = x;
            if(x < minx) minx = x;
            if(y > maxy) maxy = y;
            if(y < miny) miny = y;
            P.insert(point(x, y));
        }
        cenx = (minx + maxx) / 2;
        ceny = (miny + maxy) / 2;
        x5 = y5 = 1;
        if((minx + maxx) % 2 == 0) x5 = 0;
        if((miny + maxy) % 2 == 0) y5 = 0;
        for(itr = P.begin(); itr != P.end(); ++ itr)
        {
            x = itr -> x;
            y = itr -> y;
            if(x > cenx) x = 2 * cenx - x + x5;
            else if(x < cenx) x = 2 * cenx - x + x5;
            if(y > ceny) y = 2 * ceny - y + y5;
            else if(y < ceny) y = 2 * ceny - y + y5;
            if(P.find(point(x, y)) == P.end()) break;
        }
        if(itr == P.end()) printf("yes\n");
        else               printf("no\n");
    }
    return 0;
}