#include<iostream>
using namespace std;

int price[5000];
int bestnum[5000];

int main()
{
    int n, i, j, max, num, ans, ansnum;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i)
    {
        scanf("%d", &price[i]);
        bestnum[i] = 1;
    }
    ans = 1;
    ansnum = n;
    for(i = 1; i <n; ++ i)
    {
        max = 0;
        for(j = 0; j < i; ++ j)
        {
            if(price[j] > price[i])
            {
                if(bestnum[j] > max)
                {
                    max = bestnum[j];
                    num = 1;
                }
                else if(bestnum[j] == max)
                {
                    ++ num;
                }
            }
        }
        bestnum[i] += max;
        if(bestnum[i] > ans)
        {
            ans = bestnum[i];
            ansnum = num;
        }
    }
    printf("%d %d", ans, ansnum);
    return 0;
}