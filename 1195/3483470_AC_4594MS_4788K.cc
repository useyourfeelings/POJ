#include<iostream>
#include<vector>
using namespace std;

int sum[1100][1100];
int N;

void add(int r, int pos, int d)
{
    while(pos <= N)
    {
        sum[r][pos] += d;
        pos += (pos & (- pos));
    }
}

int getsum(int r, int pos)
{
    int s = 0;
    while(pos > 0)
    {
        s += sum[r][pos];
        pos -= (pos & (- pos));
    }
    return s;
}

int main()
{
    int command, L, B, R, T, i, j, s;
    scanf("%d%d", &i, &N);
    while(scanf("%d", &command))
    {
        if(command == 3) break;
        else if(command == 1)
        {
            scanf("%d%d%d", &L, &B, &T);
            add(B, L + 1, T);
        }
        else
        {
            scanf("%d%d%d%d", &L, &B, &R, &T);
            ++ R;
            s = 0;
            for(j = B; j <= T; ++ j)
            {
                s += getsum(j, R);
                if(L != 0) s -= getsum(j, L);
            }
            printf("%d\n", s);
        }
    }
    return 0;
}