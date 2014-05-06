#include<iostream>
using namespace std;

int g[100][100];
int done[100];
char t;
int n, i, j, who, total;

void dfs(int now)
{
    ++ total;
    done[now] = 1;
    for(int i = 1; i <= n; ++ i)
        if(!done[i] && g[i][now] != 0 && i != who) dfs(i);
}

bool IsCritical()
{
    for(i = 1; i <= n; ++ i) done[i] = 0;
    total = 0;
    if(who == 1) dfs(2);
    else         dfs(1);
    if(total == n - 1) return false;
    return true;
}

int main()
{
    for(;;)
    {
        scanf("%d%c", &n, &t);
        if(n == 0) break;
        for(i = 1; i <= n; ++ i)
            for(j = 1; j <= n; ++ j) g[i][j] = 0;
        for(;;)
        {
            scanf("%d%c", &j, &t);
            if(j == 0 || t == '\n') break;
            else
            {
                for(;;)
                {
                    scanf("%d%c", &i, &t);
                    g[j][i] = g[i][j] = 1;
                    if(t == '\n') break;
                }
            }
        }
        j = 0;
        for(who = 1; who <= n; ++ who)
            if(IsCritical()) ++ j;
        printf("%d\n", j);
    }
    return 0;
}
