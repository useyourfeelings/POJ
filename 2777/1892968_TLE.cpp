#include<iostream>
using namespace std;

struct node
{
    int a;
    int b;
    int c;
};

node tree[200000];

void build(int i, int j, int pos)
{
    tree[pos].c = 2;
    tree[pos].a = i;
    tree[pos].b = j;
    if(i == j) return;
    build(i, (i + j) / 2, pos * 2 + 1);
    build((i + j) / 2 + 1, j, pos * 2 + 2);
}

int CountColor(int c)
{
    int count = 0, i, temp = 1;;
    for(i = 1; i <= 32; ++ i)
        if(c & (temp << i)) ++ count;
    return count;
}

void GetColor(int i, int j, int &c, int pos)
{
    if(i == tree[pos].a && j == tree[pos].b)
    {
        c |= tree[pos].c;
        return;
    }
    if(j <= (tree[pos].a + tree[pos].b) / 2)
        GetColor(i, j, c, pos * 2 + 1);
    else if(i > (tree[pos].a + tree[pos].b) / 2)
        GetColor(i, j, c, pos * 2 + 2);
    else
    {
        GetColor(i, (tree[pos].a + tree[pos].b) / 2, c, pos * 2 + 1);
        GetColor((tree[pos].a + tree[pos].b) / 2 + 1, j, c, pos * 2 + 2);
    }
}

void paint(int i, int j, int c, int pos)
{
    if(tree[pos].a == tree[pos].b)
    {
        tree[pos].c = c;
        return;
    }
    if(j <= (tree[pos].a + tree[pos].b) / 2)
        paint(i, j, c, pos * 2 + 1);
    else if(i > (tree[pos].a + tree[pos].b) / 2)
        paint(i, j, c, pos * 2 + 2);
    else
    {
        paint(i, (tree[pos].a + tree[pos].b) / 2, c, pos * 2 + 1);
        paint((tree[pos].a + tree[pos].b) / 2 + 1, j, c, pos * 2 + 2);
    }
    tree[pos].c = tree[pos * 2 + 1].c | tree[pos * 2 + 2].c;
}

int main()
{
    int L, T, O, a, b, c;
    char op;
    scanf("%d%d%d", &L, &T, &O);
    build(1, L, 0);
    while(O --)
    {
        scanf("%c%c", &op, &op);
        if(op == 'C')
        {
            scanf("%d%d%d", &a, &b, &c);
            if(a > b) swap(a, b);
            c = (1 << c);
            paint(a, b, c, 0);
        }
        else
        {
            scanf("%d%d", &a, &b);
            if(a > b) swap(a, b);
            c = 0;
            GetColor(a, b, c, 0);
            printf("%d\n", CountColor(c));
        }
    }
    return 0;
}