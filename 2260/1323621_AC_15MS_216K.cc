#include<iostream>
using namespace std;

int m[100][100];

int main()
{
    int n, i, j, r, c, x, y, sum;
    while(scanf("%d", &n) && n != 0)
    {
        for(i = 0; i < n; ++ i)
            for(j = 0; j < n; ++ j) scanf("%d", &m[i][j]);
        for(i = r = 0; i < n; ++ i)
        {
            for(sum = j = 0; j < n; ++ j) sum += m[i][j];
            if(sum % 2 != 0)
            {
                if(++ r > 1) break;
                y = i;
            }
        }
        if(r > 1)
        {
            printf("Corrupt\n");
            continue;
        }
        for(j = c = 0; j < n; ++ j)
        {
            for(sum = i = 0; i < n; ++ i) sum += m[i][j];
            if(sum % 2 != 0)
            {
                if(++ c > 1) break;
                x = j;
            }
        }
        if(c > 1 || c != r)
        {
            printf("Corrupt\n");
            continue;
        }
        if(c == 0) printf("OK\n");
        else printf("Change bit (%d,%d)\n", y + 1, x + 1);
    }
    return 0;
}