#include<iostream>
using namespace std;

int sum[1300000];
int map[1024][1024];
int test, N, i, j, r1, r2, c1, c2, cmd, add;

int Add(int a, int b, int c, int d, int pos)
{
    if(r1 < a || r1 > c || c1 < b || c1 > d) return 0;
    int total;
    if(a == c && b == d)
    {
        map[a][b] += add;
        total = map[a][b];
    }
    else
    {
        int p = pos * 4;
        total = Add(a, b, (a + c) / 2, (b + d) / 2, p + 1);
        if(b != d) total += Add(a, (b + d) / 2 + 1, (a + c) / 2, d, p + 2);
        if(a != c) total += Add((a + c) / 2 + 1, b, c, (b + d) / 2, p + 3);
        if(b != d && a != c) total += Add((a + c) / 2 + 1, (b + d) / 2 + 1,
                                        c, d, p + 4);
    }
    sum[pos] = total;
    return total;
}

void query(int a, int b, int c, int d, int pos)
{
    if(a > r2 || c < r1 || b > c2 || d < c1) return;
    if(a >= r1 && c <= r2 && b >= c1 && d <= c2)
    {
        j += sum[pos];
        return;
    }
    query(a, b, (a + c) / 2, (b + d) / 2, pos * 4 + 1);
    if(b != d) query(a, (b + d) / 2 + 1, (a + c) / 2, d, pos * 4 + 2);
    if(a != c) query((a + c) / 2 + 1, b, c, (b + d) / 2, pos * 4 + 3);
    if(b != d && a != c) query((a + c) / 2 + 1,
                               (b + d) / 2 + 1, c, d, pos * 4 + 4);
}

int main()
{
    memset(sum, 0, sizeof(sum));
    scanf("%d%d", &N, &N);
    while(scanf("%d", &cmd) && cmd != 3)
    {
        if(cmd == 1)
        {
            scanf("%d%d%d", &c1, &r1, &add);
            r1 = N - r1 - 1;
            Add(0, 0, N - 1, N - 1, 0);
        }
        else
        {
            scanf("%d%d%d%d", &c1, &r2, &c2, &r1);
            r1 = N - r1 - 1, r2 = N - r2 - 1;
            j = 0;
            query(0, 0, N - 1, N - 1, 0);
            printf("%d\n", j);
        }
    }
    return 0;
}