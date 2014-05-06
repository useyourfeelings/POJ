#include<iostream>
#include<vector>
using namespace std;

int con[21];

int main()
{
    int test = 1, i, curr, device, op, limit, MaxPower, who;
    while(scanf("%d%d%d", &device, &op, &limit) && device != 0)
    {
        vector<bool> IsOn(device + 1, 0);
        MaxPower = -1;
        curr = 0;
        for(i = 1; i <= device; ++ i) scanf("%d", &con[i]);
        for(i = 0; i < op; ++ i)
        {
            scanf("%d", &who);
            if(IsOn[who]) curr -= con[who];
            else
            {
                curr += con[who];
                if(curr > limit) break;
                if(curr > MaxPower) MaxPower = curr;
            }
            IsOn[who].flip();
        }
        if(i < op)
        {
            for(; i < op - 1; ++ i) scanf("%d", &who);
            printf("Sequence %d\nFuse was blown.\n\n", test);
        }
        else
        {
            printf("Sequence %d\nFuse was not blown.\n", test);
            printf("Maximal power consumption was %d amperes.\n\n", MaxPower);
        }
        ++ test;
    }
    return 0;
}
