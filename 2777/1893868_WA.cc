#include<iostream>
using namespace std;

int L, T, O, a, b, color, start, end;
char op;

struct node
{
    bool fucked;
    int color;
    int left;
    int right;
};

node tree[200000];

void build(int i, int j, int pos)
{
    if(i == j)
    {
        tree[pos].color = 2;
        tree[pos].fucked = 0;
        return;
    }
    tree[pos].left = pos * 2 + 1;
    tree[pos].right = pos * 2 + 2;
    build(i, (i + j) / 2, pos * 2 + 1);
    build((i + j) / 2 + 1, j, pos * 2 + 2);
}

int CountColor()
{
    int count = 0, i;
    for(i = 1; i <= 32; ++ i)
        if(color & (1 << i)) ++ count;
    return count;
}

void GetColor(int i, int j, int pos)
{
    if(j < start || i > end) return;
    if(start <= i && j <= end)
    {
        color |= tree[pos].color;
        return;
    }
    int mid = (i + j) / 2, l = tree[pos].left, r = tree[pos].right;
    if (end <= mid) GetColor(i, mid, l);
    else if(start > mid) GetColor(mid + 1, j, r);
    else
    {
        GetColor(i, mid, l);
        GetColor(mid + 1, j, r);
    }
}

void paint(int i, int j, int pos)
{
    if(j < start || i > end) return;
    if(tree[pos].color == color) return;
    if(i == j)
    {
        tree[pos].color = color;
        tree[pos].fucked = 1;
        return;
    }
    int mid = (i + j) / 2, l = tree[pos].left, r = tree[pos].right;
    if (end <= mid) paint(i, mid, l);
    else if(start > mid) paint(mid + 1, j, r);
    else
    {
        paint(i, mid, l);
        paint(mid + 1, j, r);
    }
    if(tree[l].fucked || tree[r].fucked)
    {
        tree[pos].color = tree[l].color | tree[r].color;
        tree[l].fucked = tree[r].fucked = 0;
        tree[pos].fucked = 1;
    }
}

int main()
{
    scanf("%d%d%d", &L, &T, &O);
    build(1, L, 0);
    while(O --)
    {
        scanf("%c%c", &op, &op);
        if(op == 'C')
        {
            scanf("%d%d%d", &start, &end, &color);
            if(start > end) swap(start, end);
            color = (1 << color);
            paint(1, L, 0);
        }
        else
        {
            scanf("%d%d", &start, &end);
            if(start > end) swap(start, end);
            color = 0;
            GetColor(1, L, 0);
            printf("%d\n", CountColor());
        }
    }
    return 0;
}