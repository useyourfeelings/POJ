//   1787
#include<iostream>
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
    int i, t;
    best[pos][remain][0] = -1;
    for(i = coin[pos]; i >= 0; -- i)
    {
        if(remain - i * value[pos] > 0)
        {
            if((t = make(pos + 1, remain - i * value[pos])) != -1)
            {
                best[pos][remain][0] = t + i;
                best[pos][remain][1] = i;
                break;
            }
        }
        else if(remain - i * value[pos] == 0)
        {
            best[pos][remain][0] = i;
            best[pos][remain][1] = i;
            break;
        }
    }
    return best[pos][remain][0];
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