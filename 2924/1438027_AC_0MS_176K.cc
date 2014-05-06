#include<iostream>
int main()
{
    long long a, b;
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++ i)
    {
        scanf("%I64d%I64d", &a, &b);
        printf("Scenario #%d:\n%I64d\n\n", i, (a + b) * (b - a + 1)/ 2);
    }
    return 0;
}