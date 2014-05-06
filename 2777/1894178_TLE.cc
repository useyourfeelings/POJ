#include<iostream>
using namespace std;

int L, T, O, a, b, color, start, end;
char op;

struct node
{
    bool fucked;
    int color;
    int left;
};

node tree[300001];

void build(int pos)
{
    if(pos > 3 * L) return;
    tree[pos].color = 2;
    tree[pos].left = pos * 2 + 1;
    build(pos * 2 + 1);
    build(pos * 2 + 2);
}

int CountColor()
{
    int count = 0, i;
    for(i = 1; i <= T; ++ i)
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
    int l = tree[pos].left;
    GetColor(i, (i + j) / 2, l);
    GetColor((i + j) / 2 + 1, j, l + 1);
}

void paint(int i, int j, int pos)
{
    if(j < start || i > end) return;
    if(tree[pos].color == color)
    {
        tree[pos].fucked = 0;
        return;
    }
    if(i == j)
    {
        tree[pos].color = color;
        tree[pos].fucked = 1;
        return;
    }
    int mid = (i + j) / 2, l = tree[pos].left, r = l + 1;
    paint(i, mid, l);
    paint(mid + 1, j, r);
    if(tree[l].fucked || tree[r].fucked)
    {
        tree[pos].color = tree[l].color | tree[r].color;
        tree[pos].fucked = 1;
    }
}

int main()
{
    scanf("%d%d%d", &L, &T, &O);
    build(0);
    while(O --)
    {
        scanf("%c%c", &op, &op);
        scanf("%d%d", &start, &end);
        if(start > end) swap(start, end);
        if(op == 'C')
        {
            scanf("%d", &color);
            color = (1 << color);
            paint(1, L, 0);
        }
        else
        {
            color = 0;
            GetColor(1, L, 0);
            printf("%d\n", CountColor());
        }
    }
    return 0;
}