#include<iostream>
#include<map>
using namespace std;

struct pb
{
    int price;
    int bond;
};

int t, i, bn, year, money;
pb g[10];
map<int, int> record;
map<int, int>::iterator itr;

int make(int re)
{
    if((itr = record.find(re)) != record.end()) return itr -> second;
    int k, t, bonus = 0;
    for(k = 0; k < bn; ++ k)
        if(re - g[k].price >= 0)
            if((t = make(re - g[k].price) + g[k].bond) > bonus)
                bonus = t;
    record.insert(make_pair(re, bonus));
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
        while(year --)
        {
            record.clear();
            money += make(money);
        }
        printf("%d\n", money);
    }
    return 0;
}