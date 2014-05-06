#include<iostream>
using namespace std;

int test, color, start, end;
short tree[40000001];
char visible[10001];

void build()
{
    int i;
    for(i = 0; i < 40000001; ++ i) tree[i] = 0;
    for(i = 1; i <= color; ++ i) visible[i] = 0;
}

void CountPost(int i, int j, int pos)
{
    if((start = tree[pos]) == 0) return;
    if(start != -1)
    {
        if(visible[start] == 0)
        {
            ++ color;
            visible[start] = 1;
        }
        return;
    }
    int l = pos * 2 + 1, mid = (i + j) / 2;
    CountPost(i, mid, l);
    CountPost(mid + 1, j, l + 1);
}

void post(int i, int j, int pos)
{
    if(j < start || i > end) return;
    if(tree[pos] == color) return;
    if(start <= i && j <= end)
    {
        tree[pos] = color;
        return;
    }
    int mid = (i + j) / 2, l = pos * 2 + 1;
    int r = l + 1;
    if(tree[pos] != -1) tree[l] = tree[r] = tree[pos];
    post(i, mid, l);
    post(mid + 1, j, r);
    if(tree[l] != -1 && tree[l] == tree[r]) tree[pos] = tree[l];
    else tree[pos] = -1;
}

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d", &color);
        build();
        while(color)
        {
            scanf("%d%d", &start, &end);
            post(1, 10000000, 0);
            -- color;
        }
        CountPost(1, 10000000, 0);
        printf("%d\n", color);
    }
    return 0;
}