#include<iostream>
#include<algorithm>
using namespace std;

struct Bar
{
    int x1, x2, y;
};

bool operator<(const Bar &a, const Bar &b)
{
    return a.y > b.y;
}

Bar bar[1002];

int test, N, X, Y, SAFEY, MAX = 50000;//, ADD = 20001;
int rec[1002][2]; // [bar][0 jump from left, 1 right]

void input()
{
    scanf("%d %d %d %d", &N, &X, &Y, &SAFEY);
    N += 2;
    for(int i = 1; i <= N - 2; ++ i)
    {
        scanf("%d %d %d", &bar[i].x1, &bar[i].x2, &bar[i].y);
        if(bar[i].x1 > bar[i].x2)
            swap(bar[i].x1, bar[i].x2);
    }
    bar[N - 1].x1 = -20001;
    bar[N - 1].x2 = 20001;
    bar[N - 1].y  = 0;
    bar[0].x1 = X;
    bar[0].x2 = X;
    bar[0].y  = Y;
}

void pre()
{
    sort(bar, bar + N);
    for(int i = 0; i < N; ++ i)
        rec[i][0] = rec[i][1] = -1;
}

int make(int b, int dir)
{
    if(rec[b][dir] != -1)
        return rec[b][dir];
    int jumpx, jumpy = bar[b].y, i, fall;
    if(dir == 0) jumpx = bar[b].x1;   /////// left
    else         jumpx = bar[b].x2;   /////// right
    for(i = b + 1; ; ++ i) // find next bar
    {
        if((fall = jumpy - bar[i].y) > SAFEY) // die
            return MAX;
        if(bar[i].x1 <= jumpx && jumpx <= bar[i].x2) // we jump
            break;
    }
    if(i == N - 1) return fall; // land
    int L = jumpx - bar[i].x1 + fall + make(i, 0); // left
    int R = bar[i].x2 - jumpx + fall + make(i, 1); // right
    if(L > R) L = R;
    rec[b][dir] = L;
        return L;
}

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        input();
        pre();
        int L = make(0, 0);
        int R = make(0, 1);
        if(L < R) printf("%d\n", L);
        else      printf("%d\n", R);
    }
}
