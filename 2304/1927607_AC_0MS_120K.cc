#include<iostream>
using namespace std;

int main()
{
    int d, a, b, c;
    while(scanf("%d%d%d%d", &d, &a, &b, &c) &&
          !(d == 0 && a == 0 && b == 0 && c == 0))
    {
        d = (d + 40 - a) % 40 + 120;
        d += (b + 40 - a) % 40;
        d += (b + 40 - c) % 40;
        printf("%d\n", d * 9);
    }
    return 0;
}