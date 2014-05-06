#include<iostream>
using namespace std;

int a, b, p, i, j, k;
int ma[1000], mb[1000];
short rec[100][100][1000];

void input()
{
    scanf("%d%d", &b, &p);
    for(i = 0; i < a; ++ i)
        for(j = 0; j < b; ++ j)
            for(k = 0; k < p; ++ k) rec[i][j][k] = -1;
    for(i = 0; i < p; ++ i)
        scanf("%d%d%d", &a, &ma[i], &mb[i]);
}

int make(int a, int b, int pos)
{
    if(pos >= p) return 0;
    if(rec[a][b][pos] != -1) return rec[a][b][pos];
    int sa, sb;
    if(ma[pos] == a || mb[pos] == b)
        sa = make(a, b, pos + 1);
    else
    {
        sa = 1 + make(ma[pos], b, pos + 1);
        sb = 1 + make(a, mb[pos], pos + 1);
        if(sa > sb) sa = sb;
    }
    rec[a][b][pos] = sa;
    return sa;
}

int main()
{
    while(scanf("%d", &a) && a != 0)
    {
        input();
        printf("%d\n", make(0, 0, 0));
    }
    return 0;
}