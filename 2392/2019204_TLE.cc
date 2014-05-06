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

int rec[400][40000];
int K, i;

int make(int pos, int hi)
{
    if(pos >= K) return 0;
    if(rec[pos][hi] != 0) return rec[pos][hi];
    if(bricks[pos].a <= hi) return 0;
    int max = 0, t, i, len, tail, here;
    tail = min((bricks[pos].a - hi) / bricks[pos].h, bricks[pos].q);
    for(i = 0; i <= tail; ++ i)
    {
        here = i * bricks[pos].h;
        len = hi + here;
        if((t = here + make(pos + 1, len)) > max)
            max = t;
    }
    rec[pos][hi] = max;
    return max;
}

int main()
{
    scanf("%d", &K);
    for(i = 0; i < K; ++ i)
        scanf("%d%d%d", &bricks[i].h, &bricks[i].a, &bricks[i].q);
    sort(bricks, bricks + K);
    make(0, 0);
    printf("%d", rec[0][0]);
    return 0;
}