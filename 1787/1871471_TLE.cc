//   1787
#include<iostream>
#include<limits>
using namespace std;

int best[4][10001][2];
int coin[4];
int value[4] = {1, 5, 10, 25};
int price;
int TotalFrom[4];

int make(int pos, int remain)
{
    if(remain > TotalFrom[pos]) return -1;
    if(pos > 3) return -1;
    if(best[pos][remain][0] != -2) return best[pos][remain][0];
    int max = INT_MIN, i, t, num;
    for(i = 0; i <= coin[pos]; ++ i)
    {
        if(remain - i * value[pos] > 0)
        {
            if((t = make(pos + 1, remain - i * value[pos])) != -1)
            {
                t += i;
                if(t > max)
                {
                    max = t;
                    num = i;
                }
            }
        }
        else if(remain - i * value[pos] == 0)
        {
            if(i > max)
            {
                max = i;
                num = i;
            }
        }
        else break;
    }
    if(max == INT_MIN) max = -1;
    else
    {
        best[pos][remain][1] = num;
    }
    best[pos][remain][0] = max;
    return max;
}

int main()
{
    int i, ans, t;
    while(scanf("%d%d%d%d%d", &price, &coin[0], &coin[1], &coin[2], &coin[3])
                && price != 0)
    {
        TotalFrom[3] = coin[3] * value[3];
        for(i = 2; i >= 0; -- i)
            TotalFrom[i] = TotalFrom[i + 1] += coin[i] * value[i];
        for(i = 0; i < 4; ++ i)
            for(t = 0; t <= price; ++ t) best[i][t][0] = -2;
        ans = INT_MIN;
        for(i = 0; i < 4; ++ i)
        {
            if((t = make(i, price)) != -1)
            {
                if(t > ans) ans = t;
            }
        }
        if(ans == INT_MIN) printf("Charlie cannot buy coffee.\n");
        else
        {
            for(i = 0; i < 4; ++ i)
            {
                coin[i] = best[i][price][1];
                price -= best[i][price][1] * value[i];
            }
            printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",
                coin[0], coin[1], coin[2], coin[3]);
        }
    }
    return 0;
}