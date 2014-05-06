#include<iostream>
using namespace std;

bool g[101][101];

int main()
{
    int a, b, n, i, j, k, r, s, p, t, candidate, r1, r2, c1, c2;
    scanf("%d%d%d", &a, &b, &n);
    for(i = 1; i <= a; ++ i)
        for(j = 1; j <= b; ++ j) g[i][j] = 1;
    candidate = a * b;
    for(k = 0; k < n; ++ k)
    {
        scanf("%d%d%d%d", &r, &s, &p, &t);
        p = (p - 1) / 2;
        r1 = r - p;
        r2 = r + p;
        c1 = s - p;
        c2 = s + p;
        if(t == 1)
        {
            for(i = 1; i <= a; ++ i)
                for(j = 1; j <= b; ++ j)
                {
                    if(g[i][j] == 1 &&
                        !(r1 <= i && i <= r2 && c1 <= j && j <= c2))
                    {
                        g[i][j] = 0;
                        -- candidate;
                    }
                }
        }
        else
        {
            for(i = 1; i <= a; ++ i)
                for(j = 1; j <= b; ++ j)
                {
                    if(g[i][j] == 1 &&
                        r1 <= i && i <= r2 && c1 <= j && j <= c2)
                    {
                        g[i][j] = 0;
                        -- candidate;
                    }
                }
        }
    }
    printf("%d\n", candidate);
    return 0;
}