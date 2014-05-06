#include<iostream>
#include<list>
using namespace std;

int main()
{
    int n, i, sz, j;
    list<int> g;
    scanf("%d%d", &n, &sz);
    for(i = 0; i < n; ++ i)
    {
        scanf("%d", &j);
        g.push_back(j);
    }
    g.sort();
    list<int>::iterator itr;
    j = 0;
    for(; !g.empty();)
    {
        itr = g.end();
        -- itr;
        while(*itr + g.front() > sz && itr != g.begin()) -- itr;
        if(itr == g.begin()) g.pop_front();
        else
        {
            g.erase(itr);
            g.pop_front();
        }
        ++ j;
    }
    printf("%d", j);
    return 0;
}