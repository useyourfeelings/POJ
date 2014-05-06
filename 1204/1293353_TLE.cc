#include<iostream>
using namespace std;

char g[1001][1001];
char word[1001];

bool ok;
int i, n, r, c, len, x, y;
char dir;             //  H A B
                      //  G   C
bool search()         //  F E D
{
    if(word[0] != g[y][x]) return 0;
    int a, b, j;
    if(y + 1 >= len)
    {
        for(a = x, b = y, j = 0; j < len; ++ j, -- b)
            if(g[b][a] != word[j]) break;
        if(j == len)
        {
            dir = 'A';
            return 1;
        }
    }
    if(c - x >= len)
    {
        for(a = x, b = y, j = 0; j < len; ++ j, ++ a)
            if(g[b][a] != word[j]) break;
        if(j == len)
        {
            dir = 'C';
            return 1;
        }
    }
    if(y + 1 >= len && c - x >= len)
    {
        for(a = x, b = y, j = 0; j < len; ++ j, -- b, ++ a)
            if(g[b][a] != word[j]) break;
        if(j == len)
        {
            dir = 'B';
            return 1;
        }
    }
    if(r - y >= len)
    {
        for(a = x, b = y, j = 0; j < len; ++ j, ++ b)
            if(g[b][a] != word[j]) break;
        if(j == len)
        {
            dir = 'E';
            return 1;
        }
    }
    if(r - y >= len && c - x >= len)
    {
        for(a = x, b = y, j = 0; j < len; ++ j, ++ b, ++ a)
            if(g[b][a] != word[j]) break;
        if(j == len)
        {
            dir = 'D';
            return 1;
        }
    }
    if(x + 1 >= len)
    {
        for(a = x, b = y, j = 0; j < len; ++ j, -- a)
            if(g[b][a] != word[j]) break;
        if(j == len)
        {
            dir = 'G';
            return 1;
        }
    }
    if(x + 1 >= len && r - y >= len)
    {
        for(a = x, b = y, j = 0; j < len; ++ j, -- a, ++ b)
            if(g[b][a] != word[j]) break;
        if(j == len)
        {
            dir = 'F';
            return 1;
        }
    }
    if(x + 1 >= len && y + 1 >= len)
    {
        for(a = x, b = y, j = 0; j < len; ++ j, -- b, -- a)
            if(g[b][a] != word[j]) break;
        if(j == len)
        {
            dir = 'H';
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin>>r>>c>>n;
    getchar();
    for(i = 0; i < r; ++ i) gets(g[i]);
    for(i = 0; i < n; ++ i)
    {
        ok = 0;
        gets(word);
        len = strlen(word);
        for(y = 0; y < r; ++ y)
        {
            for(x = 0; x < c; ++ x)
                if(search())
                { 
                    ok = 1;
                    break;
                }
            if(ok) break;
        }
        printf("%d %d %c\n", y, x, dir);
    }
    return 0;
}