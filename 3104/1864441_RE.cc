// 3104      Drying   01_06_2007

#include<iostream>
#include<vector>
using namespace std;

int n, i, k;
vector<int>water(100000);

bool canDry(int time)
{
    int i, t = time;
    for(i = 0; i < n; ++ i)
    {
        if(time < water[i])
        {
            t -= (water[i] - time) / (k - 1);
            if((water[i] - time) % (k - 1) != 0) -- t;
            if(t < 0) break;
        }
    }
    if(t < 0) return 0;
    return 1;
}

int find(int lt, int rt)
{
    if(lt > rt) return -1;
    if(lt == rt)
    {
        if(canDry(lt)) return lt;
        else return -1;
    }
    if(canDry((lt + rt) / 2))
    {
        int t = find(lt, (lt + rt) / 2 - 1);
        if(t != -1) return t;
        else return (lt + rt) / 2;
    }
    else return find((lt + rt) / 2 + 1, rt);
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(i = 0; i < n; ++ i) scanf("%d", &water[i]);
        scanf("%d", &k);
        
        printf("%d\n", find(1, 100000));
    }
    return 0;
}