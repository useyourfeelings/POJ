#include<iostream>
using namespace std;

char g[100][100];
char done[100];
char t;
int n, i, j, who, total;

void dfs(int now)
{
    ++ total;
    done[now] = 1;
    int i;
    for(i = 1; i <= n; ++ i)
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
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%c", &t);
        for(i = 1; i <= n; ++ i)
            for(j = 1; j <= n; ++ j) g[i][j] = 0;
        i = 1;
        for(;; ++ i)
        {
            scanf("%d", &j);
            if(j == 0)
            {
                scanf("%c", &t);
                break;
            }
            else
            {
                scanf("%c", &t);
                if(t == '\n') break;
                for(;;)
                {
                    scanf("%c", &t);
                    t -= 48;
                    g[j][t] = g[t][j] = 1;
                    scanf("%c", &t);
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