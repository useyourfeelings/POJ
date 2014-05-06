#include<iostream>
using namespace std;

int rec[1001][102];

int make(int m, int pos)
{
    if(rec[m][pos] != -2) return rec[m][pos];
    int i, total, t;
    for(i = total = 0; ; ++ i)
    {
        if(m < pos * i) break;
        if(m == pos * i)
        {
            ++ total;
            continue;
        }
        if((t = make(m - pos * i, pos + 1)) != -1) total += t;
    }
    if(total == 0) total = -1;
    rec[m][pos] = total;
    return total;
}

int main()
{
    int i, j, n, k;
    scanf("%d%d", &n, &k);
    for(i = 0; i <= n; ++ i)
        for(j = 1; j <= k; ++ j)
        {
            if(i < j) rec[i][j] = -1;
            else rec[i][j] = -2;
        }
    for(i = 0; i <= n; ++ i) rec[i][k + 1] = -1;
    printf("%d", make(n, 1));
    return 0;
}