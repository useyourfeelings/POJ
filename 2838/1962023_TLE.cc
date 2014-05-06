#include<iostream>
using namespace std;

char map[1001][1001];
char cmd;
int i, n, num, j, a, b;
int done[1001];

bool OK(int now)
{
    if(now == b) return true;
    done[now] = 1;
    for(int i = 1; i <= n; ++ i)
    {
        if(!done[i] && map[now][i] == 1)
            if(OK(i)) return true;
    }
    return false;
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
            for(i = 1; i <= n; ++ i) done[i] = 0;
            if(OK(a)) printf("Y\n");
            else      printf("N\n");
        }
        scanf("%c", &cmd);
    }
    return 0;
}