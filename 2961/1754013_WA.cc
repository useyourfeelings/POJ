#include<iostream>
using namespace std;

int main()
{
    int n, t, i, j, ii, jj, result, test, x, y, w, h;
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d%d%d%d%d", &n, &x, &y, &w, &h);
        for(i = y; i < y + h; ++ i)
        {
            for(j = x; j < x + w; ++ j)
            {
                t = n;
                result = 1;
                ii = i;
                jj = j;
                while(t > 1)
                {
                    if(ii >= (t / 2) && jj >= (t / 2))
                        result *= -1;
                    ii %= t / 2;
                    jj %= t / 2;
                    t /= 2;
                }
                printf("%d ", result);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}