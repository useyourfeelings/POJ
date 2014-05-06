#include<iostream>
using namespace std;

int r, c, i, j, num;
char g[100][100];

void make(int i, int j)
{
    if(g[i][j] != '@') return;
    g[i][j] = '*';
    if(i > 0) make(i - 1, j);
    if(j > 0) make(i, j - 1);
    if(i < r - 1) make(i + 1, j);
    if(j < c - 1) make(i, j + 1);
    if(i > 0 && j > 0) make(i - 1, j - 1);
    if(i > 0 && j < c - 1) make(i - 1, j + 1);
    if(i < r - 1 && j > 0) make(i + 1, j - 1);
    if(i < r - 1 && j < c - 1) make(i + 1, j + 1);
}

int main()
{
    while(scanf("%d%d", &r, &c) && r != 0)
    {
        getchar();
        num = 0;
        for(i = 0; i < r; ++ i) gets(g[i]);
        for(i = 0; i < r; ++ i)
            for(j = 0; j < c; ++ j)
                if(g[i][j] == '@')
                {
                    ++ num;
                    make(i, j);
                }
        printf("%d\n", num);
    }
    return 0;
}