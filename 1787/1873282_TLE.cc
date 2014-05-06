#include<iostream>
using namespace std;

int best[4][10001];
int coin[4];
int value[4] = {1, 5, 10, 25};
int price;
int TotalFrom[4];
int coinnum[4];

int make(int pos, int remain)
{
    if(remain > TotalFrom[pos]) return -1;
    if(pos > 3) return -1;
    if(best[pos][remain] != -2) return best[pos][remain];
    int i, t;
    best[pos][remain] = -1;
    i = remain / value[pos];
    for(i = min(i, coin[pos]); i >= 0; -- i)
    {
        if(remain - i * value[pos] > 0)
        {
            if((t = make(pos + 1, remain - i * value[pos])) != -1)
            {
                best[pos][remain] = t + i;
                coinnum[pos] = i;
                return t + i;
            }
        }
        else if(remain - i * value[pos] == 0)
        {
            best[pos][remain] = i;
            coinnum[pos] = i;
            return i;
        }
    }
    return -1;
}

int main()
{
    int i, ans, t;
    while(scanf("%d%d%d%d%d", &price, &coin[0], &coin[1], &coin[2], &coin[3])
                && price != 0)
    {
        TotalFrom[3] = coin[3] * value[3];
        for(i = 2; i >= 0; -- i)
            TotalFrom[i] = TotalFrom[i + 1] + coin[i] * value[i];
        for(i = 0; i < 4; ++ i)
        {
            for(t = 0; t <= price; ++ t) best[i][t] = -2;
            coinnum[i] = 0;
        }
        ans = -1;
        for(i = 0; i < 4; ++ i)
        {
            if((t = make(i, price)) != -1)
            {
                ans = t;
                break;
            }
        }
        if(ans == -1) printf("Charlie cannot buy coffee.\n");
        else
        {
            printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",
                coinnum[0], coinnum[1], coinnum[2], coinnum[3]);
        }
    }
    return 0;
}