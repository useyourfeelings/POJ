#include<iostream>
using namespace std;

int coin[4]; // number of coin
int value[4] = {1, 5, 10, 25};
int TotalFrom[4]; // total money from pos
int coinnum[4];

int main()
{
    int i, ans, t, i0, i1, i2, i3, ok, p0, p1, p2, p3;
    while(scanf("%d%d%d%d%d", &p0, &coin[0], &coin[1], &coin[2], &coin[3])
                && p0 != 0)
    {
        ok = 0;
        coinnum[0] = coinnum[1] = coinnum[2] = coinnum[3] = 0;
        TotalFrom[3] = coin[3] * value[3];
        for(i = 2; i >= 0; -- i)
            TotalFrom[i] = TotalFrom[i + 1] + coin[i] * value[i];
        /////////////////////////
        i0 = p0 / value[0];
        for(i0 = min(i0, coin[0]); i0 >= 0; -- i0)
        {
            if(p0 == i0 * value[0])
            {
                ok = 1;
                coinnum[0] = i0;
                coinnum[1] = coinnum[2] = coinnum[3] = 0;
                goto OK;
            }
            if((p0 - i0 * value[0]) > TotalFrom[1]) break;
            coinnum[0] = i0;
            p1 = (p0 - i0 * value[0]);
            i1 = p1 / value[1];
            for(i1 = min(i1, coin[1]); i1 >= 0; -- i1)
            {
                if(p1 == i1 * value[1])
                {
                    ok = 1;
                    coinnum[1] = i1;
                    coinnum[2] = coinnum[3] = 0;
                    goto OK;
                }
                if((p1 - i1 * value[1]) > TotalFrom[2]) break;
                coinnum[1] = i1;
                p2 = (p1 - i1 * value[1]);
                i2 = p2 / value[2];
                for(i2 = min(i2, coin[2]); i2 >= 0; -- i2)
                {
                    if(p2 == i2 * value[2])
                    {
                        ok = 1;
                        coinnum[2] = i2;
                        coinnum[3] = 0;;
                        goto OK;
                    }
                    if((p2 - i2 * value[2]) > TotalFrom[3]) break;
                    coinnum[2] = i2;
                    p3 = (p2 - i2 * value[2]);
                    i3 = p3 / value[3];
                    for(i3 = min(i3, coin[3]); i3 >= 0; -- i3)
                    {
                        if(p3 == i3 * value[3])
                        {
                            ok = 1;
                            coinnum[3] = i3;
                            goto OK;
                        }
                    }
                }
            }
        }
        OK :
        if(!ok) printf("Charlie cannot buy coffee.\n");
        else printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",
                coinnum[0], coinnum[1], coinnum[2], coinnum[3]);
    }
    return 0;
}