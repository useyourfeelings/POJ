#include<iostream>
using namespace std;

int N, K, i, j, a, b, L, R = -1;
char t;
int cable[100000];

int test(int len)
{
    int total = 0;
    for(int i = 0; i < N; ++ i)
    {
        total += cable[i] / len;
        if(total >= K) ;return 1;
    }
    return 0;
}

int main()
{
    scanf("%d%d", &N, &K);
    for(i = 0; i < N; ++ i)
    {
        scanf("%d.%d", &a, &b);
        cable[i] = j = a * 100 + b;
        if(j > R) R = j;
    }
    for(L = 1;;)
    {
        if(L + 1 == R)
        {
            if(test(R)) j = R;
            else
            {
                if(test(L)) j = L;
                else j = 0;
            }
            break;
        }
        j = (L + R) / 2;
        if(test(j)) L = j;
        else        R = j;
    }
    printf("%d.%02d", j / 100, j % 100);
    return 0;
}