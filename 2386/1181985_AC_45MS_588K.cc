#include<iostream>
using namespace std;
int p[100][100];
int num = 1;
void go(int i, int j, int x, int y)
{
    
    if(p[i][j] != 0) return;
    p[i][j] = num;
    if(i > 0)                  go(i - 1, j, x, y);
    if(i < x - 1)              go(i + 1, j, x, y);
    if(j > 0)                  go(i, j - 1, x, y);
    if(j < y - 1)              go(i, j + 1, x, y);
    if(i > 0 && j > 0)         go(i - 1, j - 1, x, y);
    if(i > 0 && j < y - 1)     go(i - 1, j + 1, x, y);
    if(i < x - 1 && j > 0)     go(i + 1, j - 1, x, y);
    if(i < x - 1 && j < y - 1) go(i + 1, j + 1, x, y);
}
int main()
{
    int x, y;
    char c;
    cin>>x>>y;
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            cin>>c;
            if(c == '.') p[i][j] = -1;
        }
    }
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            if(p[i][j] != 0) continue;
            go(i, j, x, y);
            num ++;
        }
    }
    cout<<num - 1<<endl;
    return 0;
}
