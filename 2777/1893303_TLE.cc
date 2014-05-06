#include<iostream>
#include<cmath>
using namespace std;

int L, T, O, a, b, c;
char op;

unsigned int tree[200000];

int CountColor(int c)
{
    int count = 0, i, temp = 1;
    for(i = 1; i <= 32; ++ i)
        if(c & (temp << i)) ++ count;
    return count;
}

void GetColor(int i, int j, int &c, int pos, int posi, int posj)
{
    if(i == posi && j == posj)
    {
        c |= tree[pos];
        return;
    }
    int m = (posi + posj) / 2;
    if    (j <= m) GetColor(i, j, c, pos * 2 + 1, posi, m);
    else if(i > m) GetColor(i, j, c, pos * 2 + 2, m + 1, posj);
    else
    {
        GetColor(i, m, c, pos * 2 + 1, posi, m);
        GetColor(m + 1, j, c, pos * 2 + 2, m + 1, posj);
    }
}

void paint(int i, int j, int c, int pos, int posi, int posj)
{
    if(posi == posj)
    {
        tree[pos] = c;
        return;
    }
    int m = (posi + posj) / 2;
    if    (j <= m) paint(i, j, c, pos * 2 + 1, posi, m);
    else if(i > m) paint(i, j, c, pos * 2 + 2, m + 1, posj);
    else
    {
        paint(i, m, c, pos * 2 + 1, posi, m);
        paint(m + 1, j, c, pos * 2 + 2, m + 1, posj);
    }
    tree[pos] = tree[pos * 2 + 1] | tree[pos * 2 + 2];
}

int main()
{
    scanf("%d%d%d", &L, &T, &O);
    L = int(pow(2.0, int(log2(L - 1)) + 1));
    for(a = 0; a < 2 * L; ++ a) tree[a] = 2;
    while(O --)
    {
        scanf("%c%c", &op, &op);
        if(op == 'C')
        {
            scanf("%d%d%d", &a, &b, &c);
            if(a > b) swap(a, b);
            c = (1 << c);
            paint(a, b, c, 0, 1, L);
        }
        else
        {
            scanf("%d%d", &a, &b);
            if(a > b) swap(a, b);
            c = 0;
            GetColor(a, b, c, 0, 1, L);
            printf("%d\n", CountColor(c));
        }
    }
    return 0;
}
