#include<iostream>
using namespace std;

int hi[90000];
int lo[90000];
int map[250][250];
int test, N, B, K, i, j, r1, r2, c1, c2;

int buildhi(int a, int b, int c, int d, int pos)
{
    int max;
    if(a == c && b == d) max = map[a][b];
    else
    {
        int t;
        max = buildhi(a, b, (a + c) / 2, (b + d) / 2, pos * 4 + 1);
        if(b != d)
            if((t = buildhi(a, (b + d) / 2 + 1, (a + c) / 2, d, pos * 4 + 2)) > max)
                max = t;
        if(a != c)
            if((t = buildhi((a + c) / 2 + 1, b, c, (b + d) / 2, pos * 4 + 3)) > max)
                max = t;
        if(b != d && a != c)
            if((t = buildhi((a + c) / 2 + 1, (b + d) / 2 + 1, c, d, pos * 4 + 4)) > max)
                max = t;
    }
    hi[pos] = max;
    return max;
}
int buildlo(int a, int b, int c, int d, int pos)
{
    int min;
    if(a == c && b == d) min = map[a][b];
    else
    {
        int t;
        min = buildlo(a, b, (a + c) / 2, (b + d) / 2, pos * 4 + 1);
        if(b != d)
            if((t = buildlo(a, (b + d) / 2 + 1, (a + c) / 2, d, pos * 4 + 2)) < min)
                min = t;
        if(a != c)
            if((t = buildlo((a + c) / 2 + 1, b, c, (b + d) / 2, pos * 4 + 3)) < min)
                min = t;
        if(b != d && a != c)
            if((t = buildlo((a + c) / 2 + 1, (b + d) / 2 + 1, c, d, pos * 4 + 4)) < min)
                min = t;
    }
    lo[pos] = min;
    return min;
}

void queryhi(int a, int b, int c, int d, int pos)
{
    if(a > r2 || c < r1 || b > c2 || d < c1) return;
    if(a >= r1 && c <= r2 && b >= c1 && d <= c2)
    {
        if(hi[pos] > i) i = hi[pos];
        return;
    }
    queryhi(a, b, (a + c) / 2, (b + d) / 2, pos * 4 + 1);
    if(b != d) queryhi(a, (b + d) / 2 + 1, (a + c) / 2, d, pos * 4 + 2);
    if(a != c) queryhi((a + c) / 2 + 1, b, c, (b + d) / 2, pos * 4 + 3);
    if(b != d && a != c) queryhi((a + c) / 2 + 1,
                               (b + d) / 2 + 1, c, d, pos * 4 + 4);
}

void querylo(int a, int b, int c, int d, int pos)
{
    if(a > r2 || c < r1 || b > c2 || d < c1) return;
    if(a >= r1 && c <= r2 && b >= c1 && d <= c2)
    {
        if(lo[pos] < j) j = lo[pos];
        return;
    }
    querylo(a, b, (a + c) / 2, (b + d) / 2, pos * 4 + 1);
    if(b != d) querylo(a, (b + d) / 2 + 1, (a + c) / 2, d, pos * 4 + 2);
    if(a != c) querylo((a + c) / 2 + 1, b, c, (b + d) / 2, pos * 4 + 3);
    if(b != d && a != c) querylo((a + c) / 2 + 1,
                               (b + d) / 2 + 1, c, d, pos * 4 + 4);
}

int main()
{
    scanf("%d%d%d", &N, &B, &K);
    for(i = 0; i < N; ++ i)
        for(j = 0; j < N; ++ j)
            scanf("%d", &map[i][j]);
    buildhi(0, 0, N - 1, N - 1, 0);
    buildlo(0, 0, N - 1, N - 1, 0);
    while(K --)
    {
        scanf("%d%d", &r1, &c1);
        -- r1, -- c1;
        r2 = r1 + B - 1;
        c2 = c1 + B - 1;
        i = 0;
        queryhi(0, 0, N - 1, N - 1, 0);
        j = 250;
        querylo(0, 0, N - 1, N - 1, 0);
        printf("%d\n", i - j);
    }
    return 0;
}