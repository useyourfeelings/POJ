#include<iostream>
#include<vector>
#include<list>
using namespace std;

int C, P, W, i, a, b, num, newend, who;
int in[1024], queue[1024], TotalCow[1024];
list<int>::iterator itr;

int main()
{
    scanf("%d%d%d", &C, &P, &W);
    vector<list<int> > map(P + 1);
    for(i = 1; i <= C; ++ i)
    {
        scanf("%d", &a);
        TotalCow[a] = 1;
    }
    for(i = 1; i <= W; ++ i)
    {
        scanf("%d%d", &a, &b);
        map[a].push_back(b);
        ++ in[b];
    }
    a = b = 0;
    for(i = 1; i <= P; ++ i)
    {
        if(in[i] == 0) queue[b ++] = i;
    }
    while(a < b)
    {
        newend = b;
        for(; a < b; ++ a)
        {
            who = queue[a];
            num = TotalCow[who];
            for(itr = map[who].begin(); itr != map[who].end();)
            {
                TotalCow[*itr] += num;
                -- in[*itr];
                if(in[*itr] == 0)
                {
                    queue[newend ++] = *itr;
                    itr = map[who].erase(itr);
                    continue;
                }
                ++ itr;
            }
        }
        b = newend;
    }
    num = 0;
    for(i = 1; i <= P; ++ i)
        if(TotalCow[i] == C) ++ num;
    printf("%d\n", num);
    return 0;
}