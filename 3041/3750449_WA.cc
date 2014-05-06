#include<iostream>
using namespace std;

int matched[512], ylink[512];
int map[512][512];
int n, k, i, j, match;

int augment(int x)
{
    if(matched[x]) return 0;
    for(int y = 1; y <= n; ++ y)
    {
        if(map[x][y] && (ylink[y] == 0 || augment(ylink[y])))
        {
            ylink[y] = i;
            matched[x] = 1;
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d%d", &n, &k);
    while(k --)
    {
        scanf("%d%d", &i, &j);
        map[i][j] = 1;
    }
    for(i = 1; i <= n; ++ i)
        matched[i] = ylink[i] = 0;
    match = 0;
    for(i = 1; i <= n; ++ i)
    {
        if(augment(i)) ++ match;
    }
    printf("%d\n", match);
    return 0;
}