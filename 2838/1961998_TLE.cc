#include<iostream>
#include<vector>
using namespace std;

char map[1001][1001];
char cmd;
int i, n, num, j, a, b, f, who;
int done[1001];
vector<vector<int> > q(2);

bool OK()
{
    for(i = 1; i <= n; ++ i) done[i] = 0;
    
    q[0].resize(0);
    q[1].resize(0);
    q[0].push_back(a);
    done[a] = 1;
    for(f = 0; ; f = 1 - f)
    {
        if(q[f].empty()) return false;
        q[1 - f].resize(0);
        for(i = q[f].size() - 1; i >= 0; -- i)
        {
            who = q[f][i];
            for(j = 1; j <= n; ++ j)
            {
                if(done[j] == 0 && map[who][j] == 1)
                {
                    if(j == b) return true;
                    else
                    {
                        done[j] = 1;
                        q[1 - f].push_back(j);
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%c", &n, &num, &cmd);
    for(i = 1; i <= n; ++ i)
        for(j = 1; j <= n; ++ j) map[i][j] = 0;
    while(num --)
    {
        scanf("%c%d%d", &cmd, &a, &b);
        if(cmd == 'I') map[a][b] = map[b][a] = 1;
        else if(cmd == 'D') map[a][b] = map[b][a] = 0;
        else
        {
            if(a == b || OK()) printf("Y\n");
            else               printf("N\n");
        }
        scanf("%c", &cmd);
    }
    return 0;
}