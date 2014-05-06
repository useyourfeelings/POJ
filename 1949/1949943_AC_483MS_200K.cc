#include<iostream>
using namespace std;

int EndingTime[10001];
int Cost[10001];
int N, i, j, num, who, MaxEnding, ans;

int main()
{
    scanf("%d", &N);
    ans = 0;
    for(i = 1; i <= N; ++ i)
    {
        scanf("%d%d", &Cost[i], &num);
        for(j = MaxEnding = 0; j < num; ++ j)
        {
            scanf("%d", &who);
            if(EndingTime[who] > MaxEnding)
                MaxEnding = EndingTime[who];
        }
        EndingTime[i] = MaxEnding + Cost[i];
        if(EndingTime[i] > ans) ans = EndingTime[i];
    }
    printf("%d", ans);
    return 0;
}