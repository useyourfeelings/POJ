#include<iostream>
#include<cmath>
using namespace std;

int main()
{   
    int i, n, k, e, sum = 0;
    scanf("%d%d", &n, &e);
    for(i = 0; i < n; ++ i)
    {
        scanf("%d", &k);
        if(k == 0 || (k < 0 && e % 2 == 1)) continue;
        sum += pow(double(k), e);
    }
    printf("%d", sum);
    return 0;
}