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
int K, i, j;

int make(int pos, int hi)
{
    if(pos >= K) return 0;
    if(rec[pos][hi] != -1) return rec[pos][hi];
    int max = 0, t, i, len, tail, here = 0;;
    tail = min((bricks[pos].a - hi) / bricks[pos].h, bricks[pos].q);
    for(i = 0; i <= tail; ++ i)
    {
        len = hi + i * bricks[pos].h;
        if(len > bricks[pos].a) break;
        if((t = make(pos + 1, len) + i * bricks[pos].h) > max)
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
    for(i = 0; i < K; ++ i)
        for(j = 0; j <= bricks[K - 1].a; ++ j) rec[i][j] = -1;
    make(0, 0);
    printf("%d", rec[0][0]);
    return 0;
}