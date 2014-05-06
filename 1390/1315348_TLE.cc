#include<iostream>
#include<list>
using namespace std;

struct block
{
    block(int c, int q):color(c),quan(q){}
    int color;
    int quan;
};

int make(list<block> lb)
{
    if(lb.size() == 1) return lb.begin() -> quan * lb.begin() -> quan;
    int maxscore = 0, t;
    list<block>::iterator itr = lb.begin();
    list<block>::iterator end = lb.end();
    ++ itr;
    -- end;
    
    list<block> g(itr, lb.end());
    maxscore = lb.begin() -> quan * lb.begin() -> quan + make(g);
    
    list<block> gg(lb.begin(), end);
    t = lb.back().quan * lb.back().quan + make(gg);
    if(t > maxscore) maxscore = t;
    
    for(; itr != lb.end(); ++ itr)
    {
        list<block>::iterator itrr = itr;
        list<block> gg(lb.begin(), itrr);
        t = itrr -> quan * itrr -> quan;
        ++ itrr;
        if(itrr -> color == gg.back().color)
        {
            gg.back().quan += itrr -> quan;
            ++ itrr;
            gg.insert(gg.end(), itrr, lb.end());
        }
        else gg.insert(gg.end(), itrr, lb.end());
        t += make(gg);
        if(t > maxscore) maxscore = t;
    }
    return maxscore;
}

int main()
{
    int t, i, j, n, x, num, curr;
    scanf("%d", &t);
    for(i = 1; i <= t; ++ i)
    {
        list<block> lb;
        scanf("%d", &n);
        num = 1;
        scanf("%d", &x);
        curr = x;
        for(j = 1; j < n; ++ j)
        {
            scanf("%d", &x);
            if(x == curr) ++ num;
            else
            {
                lb.push_back(block(curr, num));
                num = 1;
                curr = x;
            }
        }
        lb.push_back(block(curr, num));
        printf("Case %d: %d\n", i, make(lb));
    }
    return 0;
}
