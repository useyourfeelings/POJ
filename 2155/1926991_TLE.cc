#include<iostream>
using namespace std;

int tree[1500000];
char map[1001][1001];
int test, N, C, i, j, r1, r2, c1, c2;
char cmd;

void build()
{
    memset(tree, 0, sizeof(tree));
}

void flip(int a, int b, int c, int d, int pos)
{
    if(a > r2 || c < r1 || b > c2 || d < c1) return;
    if(a >= r1 && c <= r2 && b >= c1 && d <= c2)
    {
        if(tree[pos] == 0 || tree[pos] == 1)
        {
            tree[pos] = 1 - tree[pos];
            return;
        }
    }
    int p = pos * 4 + 1;
    flip(a, b, (a + c) / 2, (b + d) / 2, p);
    if(b != d) flip(a, (b + d) / 2 + 1, (a + c) / 2, d, p + 1);
    if(a != c) flip((a + c) / 2 + 1, b, c, (b + d) / 2, p + 2);
    if(b != d && a != c) flip((a + c) / 2 + 1,
                               (b + d) / 2 + 1, c, d, p + 3);
    if(tree[pos] == tree[p] && tree[pos] == tree[p + 1] &&
       tree[pos] == tree[p + 2] && tree[pos] == tree[p + 3])
        tree[pos] = tree[p];
    else tree[pos] = 2;
}

void query(int a, int b, int c, int d, int pos)
{
    if(a > r1 || c < r1 || b > c1 || d < c1) return;
    if(tree[pos] == 0 || tree[pos] == 1)
    {
        j = tree[pos];
        return;
    }
    int p = pos * 4 + 1;
    query(a, b, (a + c) / 2, (b + d) / 2, p);
    if(b != d) query(a, (b + d) / 2 + 1, (a + c) / 2, d, p + 1);
    if(a != c) query((a + c) / 2 + 1, b, c, (b + d) / 2, p + 2);
    if(b != d && a != c) query((a + c) / 2 + 1,
                               (b + d) / 2 + 1, c, d, p + 3);
}

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d%d", &N, &C);
        for(i = 1; i <= N; ++ i)
            for(j = 1; j <= N; ++ j) map[i][j] = 0;
        build();
        while(C --)
        {
            scanf("%c%c", &cmd, &cmd);
            if(cmd == 'C')
            {
                scanf("%d%d%d%d", &c1, &r2, &c2, &r1);
                r1 = N - r1 + 1;
                r2 = N - r2 + 1;
                flip(1, 1, N, N, 0);
            }
            else
            {
                scanf("%d%d", &c1, &r1);
                r1 = N - r1 + 1;
                query(1, 1, N, N, 0);
                printf("%d\n", j);
            }
        }
        printf("\n");
    }
    return 0;
}