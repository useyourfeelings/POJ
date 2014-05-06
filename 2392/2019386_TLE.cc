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
int K, i, j;

int make(int pos, int hi)
{
    if(pos >= K || bricks[pos].a <= hi) return 0;
    if(rec[pos][hi] != -1) return rec[pos][hi];
    int max = 0, t, i, tail, here;
    tail = min((bricks[pos].a - hi) / bricks[pos].h, bricks[pos].q);
    for(i = 0; i <= tail; ++ i)
    {
        here = i * bricks[pos].h;
        if((t = here + make(pos + 1, hi + here)) > max)
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
        for(j = 0; j < 40001; ++ j) rec[i][j] = -1;
    printf("%d", make(0, 0));
    return 0;
}