#include<iostream>
using namespace std;

int main()
{
    long long a, b;
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++ i)
    {
        scanf("%I64d%I64d", &a, &b);
        if(a > b) swap(a, b);
        if((a < 0 && b < 0) || (a > 0 && b > 0))
            printf("Scenario #%d:\n%I64d\n\n", i, (a + b) * (b - a + 1)/ 2);
        else
        {
            if(- a == b) printf("Scenario #%d:\n0\n\n", i);
            else if(- a > b)
                printf("Scenario #%d:\n%I64d\n\n", i,
                    (a - b -  1) * (- b - a) / 2);
            else printf("Scenario #%d:\n%I64d\n\n", i,
                     (a + b + 1) * (b - a) / 2);
        }
    }
    return 0;
}