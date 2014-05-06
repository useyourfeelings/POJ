#include<iostream>
#include<vector>
using namespace std;

int sum[33000], v[33000];
int c[16000];
const int N = 33000;

int lowbit(int x)
{
    return x & (- x);
}

void add(int pos, int d)
{
    while(pos <= N)
    {
        sum[pos] += d;
        pos += lowbit(pos);
    }
}

int getsum(int pos)
{
    int s = 0;
    while(pos > 0)
    {
        s += sum[pos];
        pos -= lowbit(pos);
    }
    return s;
}

int main()
{
    int n, x, y, i;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i)
    {
        scanf("%d%d", &x, &y);
        ++ x;
        ++ c[getsum(x)];
        add(x, 1);
    }
    for(i = 0; i < n; ++ i)
        printf("%d\n", c[i]);
    return 0;
}