#include<iostream>
#include<list>
using namespace std;

struct point
{
    int id;
    float x, y;
    point(int i = 0, float xx = 0, float yy = 0):id(i),x(xx),y(yy){}
};

char done[1001];
point queue[1001];
int test, i, n, first, last, begin, end, newend, step;
float len, dis, x, y, lastx, lasty;

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d%d%d%f%f", &n, &first, &last, &len, &dis);
        list<point> nodes;
        list<point>::iterator itr;
        for(i = 1; i <= n; ++ i)
        {
            done[i] = 0;
            scanf("%f%f", &x, &y);
            if(i == first)
            {
                queue[0] = point(i, x, y);
                continue;
            }
            else if(i == last)
            {
                lastx = x;
                lasty = y;
            }
            nodes.push_back(point(i, x, y));
        }
        len += dis;
        done[first] = 1;
        begin = 0;
        end = 1;
        step = 1;
        while(begin < end)
        {
            newend = end;
            for(; begin < end; ++ begin)
            {
                for(itr = nodes.begin(); itr != nodes.end();)
                {
                    x = queue[begin].x - itr -> x;
                    y = queue[begin].y - itr -> y;
                    if((len * len) >= (x * x + y * y)) // could reach
                    {
                        if(itr -> id == last) goto OK;
                        if(!done[itr -> id]) // new
                        {
                            done[itr -> id] = 1;
                            queue[newend] = *itr;
                            itr = nodes.erase(itr);
                            ++ newend;
                            continue;
                        }
                    }
                    ++ itr;
                }
            }
            ++ step;
            end = newend;
        }
        OK:
        if(begin == end) printf("Impossible\n");
        else printf("%d\n", step);
    }
    return 0;
}