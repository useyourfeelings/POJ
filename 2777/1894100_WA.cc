#include<iostream>
using namespace std;

int L, T, O, a, b, color, start, end;
char op[32];

struct node
{
    bool fucked;
    int color;
    int left;
    int right;
};

node tree[320000];

void build(int pos)
{
    if(pos > 2 * L) return;
    tree[pos].color = 2;
    tree[pos].fucked = 0;
    tree[pos].left = pos * 2 + 1;
    tree[pos].right = pos * 2 + 2;
    build(tree[pos].left);
    build(tree[pos].right);
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
    int mid = (i + j) / 2, l = tree[pos].left, r = tree[pos].right;
    GetColor(i, mid, l);
    GetColor(mid + 1, j, r);
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
    paint(i, mid, l);
    paint(mid + 1, j, r);
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
    build(0);
    while(O --)
    {
        gets(op);
        scanf("%c", &op[0]);
        scanf("%d%d", &start, &end);
        if(start > end) swap(start, end);
        if(op[0] == 'C')
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