#include<iostream>
using namespace std;

int i, n, limit, room, step;
int hi[10];
int final[10];

void fill(int pos, int diff)
{
    int i, cangive;
    for(i = 0; i < room; ++ i)
    {
        if((cangive = hi[i] - final[i]) > 0)
        {
            if(cangive == diff)
            {
                hi[i] -= cangive;
                step += cangive;
                break;
            }
            else if(cangive < diff)
            {
                hi[i] -= cangive;
                step += cangive;
                diff -= cangive;
            }
            else
            {
                hi[i] -= diff;
                step += diff;
                break;
            }
        }
    }
    hi[pos] = final[pos];
}

void cut(int pos, int diff)
{
    int i, need;
    for(i = 0; i < room; ++ i)
    {
        if((need = final[i] - hi[i]) > 0)
        {
            if(need == diff)
            {
                hi[i] += need;
                step += need;
                break;
            }
            else if(need < diff)
            {
                hi[i] += need;
                step += need;
                diff -= need;
            }
            else
            {
                hi[i] += diff;
                step += diff;
                break;
            }
        }
    }
    hi[pos] = final[pos];
}

int main()
{
    scanf("%d%d%d", &n, &limit, &room);
    for(i = 0; i < room; ++ i) scanf("%d", &hi[i]);
    for(i = 0; i < room; ++ i) scanf("%d", &final[i]);
    for(step = 0;;)
    {
        for(i = 0; i < room; ++ i)
            if(hi[i] != final[i]) break;
        if(i >= room) break; // done
        if(hi[i] < final[i]) fill(i, final[i] - hi[i]);
        else                 cut(i, hi[i] - final[i]);
    }
    printf("%d", step);
    return 0;
}