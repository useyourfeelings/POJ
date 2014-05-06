#include<iostream>
#include<set>
using namespace std;

int main()
{
    int m, n, k, t, i, j, count;
    scanf("%d", &t);
    while(t --)
    {
        count = 0;
        set<int> stone;
        scanf("%d%d%d", &m, &n, &k);
        while(k --)
        {
            scanf("%d%d", &i, &j);
            stone.insert(1000000 * i + j);
        }
        for(i = 1; i <= m; ++ i)
        {
            for(j = 1; j <= n; ++ j)
            {
                if(stone.find(1000000 * i + j) == stone.end())
                {
                    if(j < n && stone.find(1000000 * i + j + 1) == stone.end())
                    {
                        ++ count;
                        while(stone.find(1000000 * i + j) == stone.end() && j <= n) ++ j;
                    }
                }
            }
        }
        for(j = 1; j <= n; ++ j)
        {
            for(i = 1; i <= m; ++ i)
            {
                if(stone.find(1000000 * i + j) == stone.end())
                {
                    if(i < m && stone.find(1000000 * (i + 1) + j) == stone.end())
                    {
                        ++ count;
                        while(stone.find(1000000 * i + j) == stone.end() && i <= m) ++ i;
                    }
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}