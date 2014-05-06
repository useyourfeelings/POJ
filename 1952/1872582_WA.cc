#include<iostream>
using namespace std;

int price[5000];
int bestnum[5000];
int solutionnum[5000];

int main()
{
    int n, i, j, max, ans, ansnum, solutionsum;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i) scanf("%d", &price[i]);
    bestnum[n - 1] = solutionnum[n - 1] = 1;
    ans = 1;
    ansnum = 1;
    for(i = n - 2; i >= 0; -- i)
    {
        max = 0;
        solutionsum = 1;
        for(j = i + 1; j < n; ++ j)
        {
            if(price[i] > price[j])
            {
                if(bestnum[j] > max)
                {
                    max = bestnum[j];
                    solutionsum = solutionnum[j];
                }
                else if(bestnum[j] == max)
                {
                    solutionsum += solutionnum[j];
                }
            }
        }
        bestnum[i] = 1 + max;
        solutionnum[i] = solutionsum;
        if(bestnum[i] > ans)
        {
            ans = bestnum[i];
            ansnum = solutionnum[i];
        }
        else if(bestnum[i] == ans)
        {
            ansnum += solutionnum[i];
        }
    }
    printf("%d %d", ans, ansnum);
    return 0;
}