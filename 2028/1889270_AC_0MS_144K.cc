#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int man, num, day, q, i, j, maxday;
    while(scanf("%d%d", &man, &q) && man != 0)
    {
        vector<int> g(100, 0);
        maxday = -1;
        for(i = 0; i < man; ++ i)
        {
            scanf("%d", &num);
            for(j = 0; j < num; ++ j)
            {
                scanf("%d", &day);
                ++ g[day];
                if(day > maxday) maxday = day;
            }
        }
        for(i = 1; i <= maxday; ++ i)
            if(g[i] >= q) break;
        if(i > maxday) printf("0\n");
        else
        {
            day = i;
            for(++ i; i <= maxday; ++ i)
                if(g[i] > g[day]) day = i;
            printf("%d\n", day);
        }
    }
    return 0;
}