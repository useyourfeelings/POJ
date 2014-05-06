#include<iostream>
#include<vector>
using namespace std;

int n, i, j, a, b, num, who, v, step;
char done[100000];
int dis[100000];
vector<vector<int> > g(100001);
vector<vector<int> > q(2);

int bfs()
{
    for(i = 0; i < n; ++ i) done[i] = 0;
    q[0].push_back(a);
    for(step = num = 0; ; num = 1 - num, ++ step)
    {
        q[1 - num].resize(0);
        for(i = q[num].size() - 1; i >= 0; -- i)
        {
            who = q[num][i];
            for(j = g[who].size() - 1; j >= 0; -- j)
            {
                v = g[who][j];
                if(v == b) return step;
                if(done[v]) continue;
                else
                {
                    done[v] = 1;
                    q[1 - num].push_back(v);
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    q[0].reserve(n);
    q[1].reserve(n);
    for(i = 0; i < n; ++ i)
    {
        scanf("%d%d", &who, &num);
        g[who].resize(num);
        for(j = 0; j < num; ++ j) scanf("%d", &g[i][j]);
    }
    scanf("%d%d", &a, &b);
    printf("%d %d %d", a, b, bfs());
    return 0;
}