#include<iostream>
using namespace std;
long long C(unsigned int a, unsigned int b)
{
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b > (a >> 1)) return C(a, a - b);
    return C(a - 1, b - 1) * a / b;
}
int main()
{
    unsigned int a, b;
    while(scanf("%d%d", &a, &b) && a != 0)
        printf("%d\n", C(a + b, a));
    return 0;
}