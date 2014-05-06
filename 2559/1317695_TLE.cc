#include<iostream>
using namespace std;

int h[100000];
int leftd[100000];
int rightd[100000];

int main()
{
    int n, i, j;
    long long maxa;
    while(scanf("%d", &n) && n != 0)
    {
        for(i = 0; i < n; ++ i) scanf("%d", &h[i]);
        for(i = 0; i < n; ++ i)
        {
            for(j = i; j >= 0; -- j)
            {
                if(h[j] < h[i])
                {
                    leftd[i] = j;
                    break;
                }
            }
            if(j < 0) leftd[i] = -1;
            for(j = i; j < n; ++ j)
            {
                if(h[j] < h[i])
                {
                    rightd[i] = j;
                    break;
                }
            }
            if(j >= n) rightd[i] = n;
        }
        maxa = 0;
        for(i = 0; i < n; ++ i)
        {
            if((rightd[i] - leftd[i] - 1) * h[i] > maxa)
            {
                maxa = (rightd[i] - leftd[i] - 1) * h[i];
            }
        }
        printf("%I64d\n", maxa);
    }
    return 0;
}