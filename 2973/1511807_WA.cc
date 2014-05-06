#include<iostream>
using namespace std;

char dic[1001][8];
int record[27];
int r[27];

int main()
{
    int n, i, j, count;
    while(scanf("%d", &n) && n != 0)
    {
        getchar();
        count = 0;
        for(i = 1; i <= n; ++ i) gets(dic[i]);
        gets(dic[0]);
        for(i = 0; i < strlen(dic[0]); ++ i)
        {
            if(dic[0][i] == '_') ++ r[26];
            else ++ r[dic[0][i] - 65];
        }
        for(i = 1; i <= n; ++ i)
        {
            for(j = 0; j <= 26; ++ j) record[j] = r[j];
            for(j = 0; j < strlen(dic[i]); ++ j)
            {
                if(record[dic[i][j] - 65] > 0) -- record[dic[i][j] - 65];
                else
                {
                    if(record[26] > 0) -- record[26];
                    else break;
                }
            }
            if(j >= strlen(dic[i])) ++ count;
        }
        printf("%d\n", count);
    }
    return 0;
}