#include<iostream>
using namespace std;
int peri, r, c, mr, mc;
bool g[21][21];
bool done[21][21];
void dfs(int i, int j)
{
    done[i][j] = 1;
    if(j > 1)
    {
        if(g[i][j - 1])
        {
            if(!done[i][j - 1]) dfs(i, j - 1);
        }
        else ++peri;
    }
    else ++peri;
    if(j < c)
    {
        if(g[i][j + 1])
        {
            if(!done[i][j + 1]) dfs(i, j + 1);
        }
        else ++peri;
    }
    else ++peri;
    if(i > 1)
    {
        if(g[i - 1][j])
        {
            if(!done[i - 1][j]) dfs(i - 1, j);
        }
        else ++peri;
    }
    else ++peri;
    if(i < r)
    {
        if(g[i + 1][j])
        {
            if(!done[i + 1][j]) dfs(i + 1, j);
        }
        else ++peri;
    }
    else ++peri;
    if(i > 1 && j > 1 && g[i - 1][j - 1] && !done[i - 1][j - 1]) dfs(i - 1, j - 1);
    if(i > 1 && j < c && g[i - 1][j + 1] && !done[i - 1][j + 1]) dfs(i - 1, j + 1);
    if(i < r && j > 1 && g[i + 1][j - 1] && !done[i + 1][j - 1]) dfs(i + 1, j - 1);
    if(i < r && j < c && g[i + 1][j + 1] && !done[i + 1][j + 1]) dfs(i + 1, j + 1);
}
int main()
{   
    int i, j;
    char x;
    while(cin>>r>>c>>mr>>mc && r != 0)
    {
        for(i = 1; i <= r; ++i)
        {
            for(j = 1; j <= c; ++j)
            {
                cin>>x;
                if(x == 'X')
                {
                    g[i][j] = 1;
                    done[i][j] = 0;
                }
                else g[i][j] = 0;
            }
        }
        peri = 0;
        dfs(mr, mc);
        cout<<peri<<endl;
    }
    return 0;
}