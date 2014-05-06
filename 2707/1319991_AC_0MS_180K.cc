#include<iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    while(scanf("%d%d%d%d", &a, &b, &c, &d) && a != 0)
    {
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        printf("%d%%\n", min(100, min(c * 100 / a, d * 100 / b)));
    }
    return 0;
}