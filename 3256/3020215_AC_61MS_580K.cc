#include<iostream>
#include<vector>
#include<list>
using namespace std;

int C, P, W, i, a, b, num, TotalCow[1024], PosOfCow[128], done[1024];
vector<list<int> > map(1024);

void dfs(int pos)
{
    if(done[pos]) return;
    ++ TotalCow[pos];
    done[pos] = 1;
    list<int>::iterator itr = map[pos].begin(),
                        end = map[pos].end();
    for(; itr != end; ++ itr)
        dfs(*itr);
    return;
}

int main()
{
    scanf("%d%d%d", &C, &P, &W);
    for(i = 1; i <= C; ++ i)
    {
        scanf("%d", &a);
        PosOfCow[i] = a;
    }
    for(i = 1; i <= W; ++ i)
    {
        scanf("%d%d", &a, &b);
        map[a].push_back(b);
    }
    for(i = 1; i <= C; ++ i)
    {
        for(a = 1; a <= P; ++ a) done[a] = 0;
        dfs(PosOfCow[i]);
    }
    num = 0;
    for(i = 1; i <= P; ++ i)
        if(TotalCow[i] == C) ++ num;
    printf("%d\n", num);
    return 0;
}