#include<iostream>
using namespace std;

int rec[10001][4][2]; // [price][index][0] total, [][][1] here
int num[4];
int value[4] = {1, 5, 10, 25};
int total[4];
int PRICE, FAIL = -1;

bool input()
{
    scanf("%d", &PRICE);
    if(PRICE == 0) return false;
    for(int i = 0; i < 4; ++ i)
        scanf("%d", &num[i]);
    return true;
}

void pre()
{
    for(int i = 0; i <= PRICE; ++ i)
        for(int j = 0; j < 4; ++ j)
            rec[i][j][0] = -2;
    total[3] = value[3] * num[3];
    for(int i = 2; i >= 0; -- i) // money left
        total[i] = value[i] * num[i] + total[i + 1];
    for(int i = 0; i < 4; ++ i) // enough money
    {
        int j;
        for(j = 0; j <= PRICE; ++ j)
            if(j > total[i]) break;
        for(; j <= PRICE; ++ j)
            rec[j][i][0] = FAIL;
    }
    for(int i = 0; i <= PRICE; ++ i)
    {
        if(i <= total[3] && i % 25 == 0) rec[i][3][0] = rec[i][3][1] = i / 25;
        else                             rec[i][3][0] = FAIL; // no solution
    }
    for(int i = 0; i < 4; ++ i)
        rec[0][i][0] = rec[0][i][1] = 0;
}

int MaxCoins(int price, int index)
{
    if(rec[price][index][0] != -2) return rec[price][index][0];
    int maxcoin = FAIL, pickmoney = 0, pickcoin, t;
    for(int i = 0; i <= num[index]; ++ i, pickmoney += value[index])
    {
        if(pickmoney > price) break; // no hope
        t = MaxCoins(price - pickmoney, index + 1);
        if(t == FAIL) continue; // fail
        t += i;
        if(t > maxcoin)
        {
            maxcoin = t;
            pickcoin = i;
        }
    }
    rec[price][index][0] = maxcoin;
    rec[price][index][1] = pickcoin;
    return maxcoin;
}

void output()
{
    for(int i = 0; i < 3; ++ i)
    {
        num[i] = rec[PRICE][i][1];
        PRICE -= rec[PRICE][i][1] * value[i];
    }
    num[3] = PRICE / value[3];
    printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",
        num[0], num[1], num[2], num[3]);
}

int main()
{
    while(input())
    {
        pre();
        if(MaxCoins(PRICE, 0) == -1)
            printf("Charlie cannot buy coffee.\n");
        else output();
    }
}