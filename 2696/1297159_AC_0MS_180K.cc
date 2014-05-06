#include<iostream>
using namespace std;

int x[1001];

int main()
{
    int a, b, c, d, e, f, g, h, i, j, n;
    scanf("%d", &n);
    while(n --)
    {
        scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i);
        x[0] = a;
        x[1] = b;
        x[2] = c;
        for(j = 3; j <= i; ++ j)
        {
            if(j % 2 == 1)
            {
                x[j] = d * x[j - 1] + e * x[j - 2] - f * x[j - 3];
                if(x[j] % g == 0) x[j] = 0;
                else
                {
                    if(x[j] < 0) x[j] = g - (-x[j] % g);
                    else x[j] %= g;
                }
            }
            else
            {
                x[j] = f * x[j - 1] - d * x[j - 2] + e * x[j - 3];
                if(x[j] % h == 0) x[j] = 0;
                else
                {
                    if(x[j] < 0) x[j] = h - (-x[j] % h);
                    else x[j] %= h;
                }
            }
        }
        printf("%d\n", x[i]);
    }
    return 0;
}