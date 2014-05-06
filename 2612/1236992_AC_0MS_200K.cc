#include<iostream>
using namespace std;
char g[10][10];
char gg[10][10];
int main()
{   
    char c;
    int i, j, n, sum;
    bool dead = 0;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin>>g[i][j];
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin>>c;
            if(c == 'x')
            {
                if(g[i][j] != '*')
                {
                    sum = 0;
                    if(i > 0)                  if(g[i - 1][j] == '*') sum++;
                    if(i < n - 1)              if(g[i + 1][j] == '*') sum++;
                    if(j > 0)                  if(g[i][j - 1] == '*') sum++;
                    if(j < n - 1)              if(g[i][j + 1] == '*') sum++;
                    if(i > 0 && j > 0)         if(g[i - 1][j - 1] == '*') sum++;
                    if(i > 0 && j < n - 1)     if(g[i - 1][j + 1] == '*') sum++;
                    if(i < n - 1 && j > 0)     if(g[i + 1][j - 1] == '*') sum++;
                    if(i < n - 1 && j < n - 1) if(g[i + 1][j + 1] == '*') sum++;
                    gg[i][j] =sum + 48;
                }
                else
                {
                    gg[i][j] = '*';
                    dead = 1;
                }
            }
            else gg[i][j] = '.';
        }
    }
    if(dead)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(g[i][j] == '*') gg[i][j] = '*';
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout<<gg[i][j];
        }
        cout<<endl;
    }
    return 0;
}