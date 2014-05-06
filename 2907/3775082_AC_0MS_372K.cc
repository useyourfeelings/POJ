#include<iostream>
using namespace std;

int co[11][2], map[11][11], collected[11];
int test, n, i, j, best;

int search(int id, int step, int length)
{
    if(length > best) return best; // cut
    if(step == n) // all collected
    {
        return length + map[id][0];
    }
    int i, bestlen = 1024, t, k;
    for(i = 1; i <= n; ++ i)
    {
        if(!collected[i])
        {
            k = map[id][i];
            collected[i] = 1; // collected
            if((t = search(i, step + 1, k + length)) < bestlen)
                bestlen = t;
            collected[i] = 0; // recover
        }
    }
    return bestlen;
}

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        best = 1024;
        memset(map, 0, sizeof(map));
        memset(collected, 0, sizeof(collected));
        scanf("%d%d%d%d%d", &co[0][0], &co[0][0],
                            &co[0][0], &co[0][1], &n);
        for(i = 1; i <= n; ++ i)
            scanf("%d%d", &co[i][0], &co[i][1]);
        for(i = 0; i < n; ++ i)
            for(j = i + 1; j <= n; ++ j)
                map[i][j] = map[j][i] = abs(co[i][0] - co[j][0]) +
                                        abs(co[i][1] - co[j][1]);
        printf("The shortest path has length %d\n", search(0, 0, 0));
    }
    return 0;
}