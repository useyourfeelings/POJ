#include<iostream>
using namespace std;

struct pb
{
    int price;
    int bond;
};

int record[46000];
int t, i, bn, year, money;
pb g[10];

int make(int re)
{
    if(record[re / 1000] != -1) return record[re / 1000];
    int k, t, bonus = 0;
    for(k = 0; k < bn; ++ k)
        if(re - g[k].price >= 0)
            if((t = make(re - g[k].price) + g[k].bond) > bonus)
                bonus = t;
    record[re / 1000] = bonus;
    return bonus;
}

int main()
{
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d%d", &money, &year, &bn);
        for(i = 0; i < bn; ++ i)
            scanf("%d%d", &g[i].price, &g[i].bond);
        for(i = 0; i < 46000; ++ i) record[i] = -1;
        while(year --) money += make(money);
        printf("%d\n", money);
    }
    return 0;
}