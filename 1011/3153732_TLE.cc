#include<iostream>
#include<algorithm>
using namespace std;

int stick[64], total, len, num, n, over;
char done[64];

void rebuild(int id, int nowlen);

void go(int id)
{
    if(id > num)
    {
        over = 1;
        return;
    }
    rebuild(id, 0);
}

void rebuild(int id, int nowlen)
{
    if(nowlen == len)
    {
        go(id + 1);
        return;
    }
    int t;
    for(int i = id - 1; i < n; ++ i)
    {
        if(done[i]) continue;
        if((t = nowlen + stick[i]) <= len)
        {
            done[i] = 1;
            rebuild(id, t);
            if(over) return;
            done[i] = 0;
        }
    }
}

int main()
{
    int i, j;
    while(scanf("%d", &n) && n != 0)
    {
        for(total = i = 0; i < n; ++ i)
        {
            scanf("%d", &stick[i]);
            total += stick[i];
        }
        sort(stick, stick + n, greater<int>());
        for(i = stick[0]; i <= total; ++ i)
        {
            if(total % i == 0)
            {
                over = 0;
                memset(done,0,sizeof(done));
                num = total / i;
                len = i;
                go(1);
                if(over)
                {
                    printf("%d\n", len);
                    break;
                }
            }
        }
    }
    return 0;
}