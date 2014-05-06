#include<iostream>
using namespace std;

char word[13][26];
int blank[13];

int main()
{
    int i, j, k, n, minb, t;
    while(scanf("%d", &n) && n!= 0)
    {
        getchar();
        minb = 25;
        for(i = 0; i < n; ++ i)
        {
            gets(word[i]);
            for(j = 1; j < 25; ++ j) if(word[i][j] == ' ') break;
            for(k = 23; k >= 0; -- k) if(word[i][k] == ' ') break;
            if(j <= k) t = k - j + 1;
            else t = 0;
            blank[i] = t;
            if(t < minb) minb = t;
        }
        for(i = t = 0; i < n; ++ i)
            t += (blank[i] - minb);
        printf("%d\n", t);
    }
    return 0;
}