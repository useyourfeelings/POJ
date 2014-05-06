#include<iostream>
#include<set>
using namespace std;

int price[5000];
int bestnum[5000];
int solutionnum[5000];
set<int> BigPicked;

int main()
{
    int n, i, j, max, ans, ansnum, solutionsum;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i)
    {
        scanf("%d", &price[i]);
    }
    bestnum[n - 1] = solutionnum[n - 1] = 1;
    ans = 1;
    ansnum = 1;
    for(i = n - 2; i >= 0; -- i)
    {
        set<int> picked;
        max = 0;
        solutionsum = 1;
        for(j = i + 1; j < n; ++ j)
        {
            if(price[i] <= price[j]) continue;
            if(bestnum[j] > max)
            {
                picked.clear();
                picked.insert(price[j]);
                max = bestnum[j];
                solutionsum = solutionnum[j];
            }
            else if(bestnum[j] == max)
            {
                if(picked.find(price[j]) == picked.end()) // not found
                {
                    picked.insert(price[j]);
                    solutionsum += solutionnum[j];
                }
            }
        }
        bestnum[i] = 1 + max;
        solutionnum[i] = solutionsum;
        if(bestnum[i] > ans)
        {
            BigPicked.clear();
            BigPicked.insert(price[i]);
            ans = bestnum[i];
            ansnum = solutionnum[i];
        }
        else if(bestnum[i] == ans)
        {
            if(BigPicked.find(price[i]) == BigPicked.end())
            {
                BigPicked.insert(price[i]);
                ansnum += solutionnum[i];
            }
        }
    }
    printf("%d %d", ans, ansnum);
    return 0;
}