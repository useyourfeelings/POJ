#include<iostream>
using namespace std;

int tree[1001][1001];
int TEST, N, Q, x1, y1, x2, y2;
char query;

int getsum(int x, int y)
{
    int tempy, sum = 0;
    while(x > 0)
    {
        tempy = y;
        while(tempy > 0)
        {
            sum += tree[x][tempy];
            tempy -= tempy & (- tempy);//lowbit
        }
        x -= x & (- x);//lowbit
    }
    return sum;
}
void modify(int x, int y, int delta)
{
    int tempy;
    while(x <= N)
    {
        tempy = y;
        while(tempy <= N)
        {
            tree[x][tempy] += delta;
            tempy += tempy & (- tempy);//lowbit
        }
        x += x & (- x);//lowbit
    }
}

void go()
{
    scanf("%d %d\n", &N, &Q);
    for(int i = 1; i <= N; ++ i)
        for(int j = 1; j <= N; ++ j)
            tree[i][j] = 0;
    while(Q --)
    {
        scanf("%c", &query);
        if(query == 'C')
        {
            scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
            modify(x1    , y1    ,  1);
            modify(x2 + 1, y1    , -1);
            modify(x1    , y2 + 1, -1);
            modify(x2 + 1, y2 + 1,  1);
        }
        else   //  'Q'
        {
            scanf("%d %d\n", &x1, &y1);
            printf("%d\n", getsum(x1, y1) % 2);
        }
    }
    printf("\n");
}

int main()
{
    scanf("%d", &TEST);
    while(TEST --)
    {
        go();
    }
}