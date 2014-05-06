#include<iostream>
using namespace std;

int L, T, O, a, b, color, table, start, end;
char op;

struct node
{
    int color;
    int left;
    int table;
};

node tree[300001];

void build()
{
    tree[0].color = 1;
    tree[0].left = 1;
    tree[0].table = 2;
    int i = 1, j = 3 * L;
    for(; i < j; ++ i)
    {
        tree[i].color = 1;
        tree[i].left = i * 2 + 1;
        tree[i].table = 2;
    }
}

int CountColor()
{
    int count = 0, i;
    for(i = 1; i <= T; ++ i)
        if(table & (1 << i)) ++ count;
    return count;
}

void GetColor(int i, int j, int pos)
{
    if(tree[pos].color != -1 || (start <= i && j <= end))
    {
        table |= tree[pos].table;
        return;
    }
    if(j < start || i > end) return;
    int l = tree[pos].left, mid = (i + j) / 2;
    GetColor(i, mid, l);
    GetColor(mid + 1, j, l + 1);
}

void paint(int i, int j, int pos)
{
    if(j < start || i > end) return;
    if(tree[pos].table == table) return;
    if(start <= i && j <= end)
    {
        tree[pos].color = color;
        tree[pos].table = table;
        return;
    }
    int mid = (i + j) / 2, l = tree[pos].left;
    int r = l + 1;
    if(tree[pos].color != -1)
    {
        tree[l].color = tree[l + 1].color = tree[pos].color;
        tree[l].table = tree[l + 1].table = tree[pos].table;
    }
    paint(i, mid, l);
    paint(mid + 1, j, r);
    tree[pos].table = tree[l].table | tree[r].table;
    if(tree[l].color != -1 && tree[l].color == tree[r].color)
        tree[pos].color = tree[l].color;
    else tree[pos].color = -1;
}

int main()
{
    scanf("%d%d%d", &L, &T, &O);
    build();
    while(O --)
    {
        scanf("%c%c", &op, &op);
        scanf("%d%d", &start, &end);
        if(start > end) swap(start, end);
        if(op == 'C')
        {
            scanf("%d", &table);
            color = table;
            table = (1 << table);
            paint(1, L, 0);
        }
        else
        {
            table = 0;
            GetColor(1, L, 0);
            printf("%d\n", CountColor());
        }
    }
    return 0;
}