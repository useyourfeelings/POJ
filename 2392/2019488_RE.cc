#include<iostream>
#include<algorithm>
using namespace std;

struct brick
{
    brick(){}
    int h, q, a;
};

bool operator<(const brick &x, const brick &y)
{
    return x.a < y.a;
}

brick bricks[400];
int rec[400][40001];
int N, i, num, base, maxhi, h, a, q, t, here;

int main()
{
    scanf("%d", &N);
    for(i = 0; i < N; ++ i)
        scanf("%d%d%d", &bricks[i].h, &bricks[i].a, &bricks[i].q);
    sort(bricks, bricks + N);
    for(i = N - 1; i >= 0; -- i)
    {
        h = bricks[i].h;
        a = bricks[i].a;
        q = bricks[i].q;
        for(base = 0; base <= 40000; ++ base)
        {
            if(a <= base) break;
            maxhi = 0;
            for(num = 0; num <= min(q, (a - base) / h); ++ num)
            {
                here = num * h;
                if((t = here + rec[i + 1][base + here]) > maxhi)
                    maxhi = t;
            }
            rec[i][base] = maxhi;
        }
    }
    printf("%d", rec[0][0]);
    return 0;
}