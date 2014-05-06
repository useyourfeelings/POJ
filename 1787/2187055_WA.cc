#include<iostream>
using namespace std;

int best[4][10001];// most coins can use at pos 0 - 3
int coin[4];
int value[4] = {1, 5, 10, 25};
int price;
int TotalFrom[4];

int make(int pos, int remain)
{
    if(remain > TotalFrom[pos]) return -1;
    if(best[pos][remain] != -2) return best[pos][remain];
    int i;
    best[pos][remain] = -1;
    i = remain / value[pos];
    if(i > coin[pos]) i = coin[pos];
    if(i * value[pos] == remain)
    {
        best[pos][remain] = i;
        return i;
    }
    if(pos == 3) return -1;
    for(; i >= 0; -- i)
    {
        if(make(pos + 1, remain - i * value[pos]) != -1)
        {
            best[pos][remain] = i;
            return i;
        }
    }
    return -1;
}

int main()
{
    int i, ok, t;
    while(scanf("%d%d%d%d%d", &price, &coin[0], &coin[1], &coin[2], &coin[3])
                && price != 0)
    {
        TotalFrom[3] = coin[3] * value[3];
        for(i = 2; i >= 0; -- i)
            TotalFrom[i] = TotalFrom[i + 1] + coin[i] * value[i];
        for(i = 0; i < 4; ++ i)
            for(t = 0; t <= price; ++ t)
                best[i][t] = -2;
        for(i = ok = 0; i < 4; ++ i)
        {
            if((t = make(i, price)) != -1)
            {
                ok = 1;
                break;
            }
        }
        if(ok == 0) printf("Charlie cannot buy coffee.\n");
        else
        {
            for(i = 0; i < 4; ++ i)
            {
                coin[i] = best[i][price];
                price -= value[i] * coin[i];
                if(price == 0)
                {
                    for(++ i; i < 4; ++ i) coin[i] = 0;
                    break;
                }
            }
            printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",
                coin[0], coin[1], coin[2], coin[3]);
        }
    }
    return 0;
}