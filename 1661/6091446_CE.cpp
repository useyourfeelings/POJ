#include<iostream>
using namespace std;

struct Bar
{
    int x1, x2, y;
};

bool operator<(const Bar &a, const Bar &b)
{
    return a.y > b.y;
}

Bar bar[1001];

int test, N, X, Y, SAFEY, MAX = 50000, ADD = 20001;
int rec[1001][40005]; // [bar][x]

void input()
{
    scanf("%d %d %d %d", &N, &X, &Y, &SAFEY);
    for(int i = 0; i < N; ++ i)
    {
        scanf("%d %d %d", &bar[i].x1, &bar[i].x2, &bar[i].y);
        bar[i].x1 += ADD;
        bar[i].x2 += ADD;
        if(bar[i].x1 > bar[i].x2)
            swap(bar[i].x1, bar[i].x2);
    }
    bar[N].x1 = 0;
    bar[N].x2 = MAX;
    bar[N].y  = 0;
    X += ADD;
}

void pre()
{
    sort(bar, bar + N + 1);
    for(int i = 0; i < 1001; ++ i)
        for(int j = 0; j < 40005; ++ j)
            rec[i][j] = -1;
}

int make(int b, int x)
{
    if(b == N) // ok
        return 0;
    if(rec[b][x] != -1)
        return rec[b][x];
    int L, R;
    int jumpx, jumpy = bar[b].y, i, fall;
    jumpx = bar[b].x1;   /////// left
    for(i = b + 1; ; ++ i)
    {
        if((fall = jumpy - bar[i].y) > SAFEY) // die
        {
            L = MAX;
            break;
        }
        if(bar[i].x1 <= jumpx && jumpx <= bar[i].x2) // we jump
        {
            L = x - jumpx + fall + make(i, jumpx);
            break;
        }
    }
    jumpx = bar[b].x2;   /////// right
    for(i = b + 1; ; ++ i)
    {
        if((fall = jumpy - bar[i].y) > SAFEY) // die
        {
            R = MAX;
            break;
        }
        if(bar[i].x1 <= jumpx && jumpx <= bar[i].x2) // we jump
        {
            R = jumpx - x + fall + make(i, jumpx);
            break;
        }
    }
    if(L > R) L = R;
    rec[b][x] = L;
        return L;
}

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        input();
        pre();
        int i;
        for(i = 0; i < N; ++ i) // find the first bar
        {
            if(bar[i].x1 <= X && X <= bar[i].x2)
                break;
        }
        printf("%d\n", make(i, X) + Y - bar[i].y);
    }
}
