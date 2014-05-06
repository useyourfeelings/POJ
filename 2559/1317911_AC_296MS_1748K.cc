#include<iostream>
using namespace std;

long long h[100002];
int leftd[100002];
int rightd[100002];

int main()
{
    int n, i, j, t;
    long long maxa;
    h[0] = -1;
    while(scanf("%d", &n) && n != 0)
    {
        for(i = 1; i <= n; ++ i) scanf("%I64d", &h[i]);
        h[n + 1] = -1;
        for(i = 1; i <= n; ++ i)
        {
            t = i - 1;
            while(h[t] >= h[i]) t = leftd[t];
            leftd[i] = t;
        }
        for(i = n; i >= 1; -- i)
        {
            t = i + 1;
            while(h[t] >= h[i]) t = rightd[t];
            rightd[i] = t;
        }
        maxa = 0;
        for(i = 1; i <= n; ++ i)
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