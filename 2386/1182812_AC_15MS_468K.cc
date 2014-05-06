#include<iostream>
using namespace std;
int p[100][100];
int num = 1, x, y;
void go(int i, int j)
{
    if(p[i][j] != 0) return;
    p[i][j] = num;
    if(i > 0)                  go(i - 1, j);
    if(i < x - 1)              go(i + 1, j);
    if(j > 0)                  go(i, j - 1);
    if(j < y - 1)              go(i, j + 1);
    if(i > 0 && j > 0)         go(i - 1, j - 1);
    if(i > 0 && j < y - 1)     go(i - 1, j + 1);
    if(i < x - 1 && j > 0)     go(i + 1, j - 1);
    if(i < x - 1 && j < y - 1) go(i + 1, j + 1);
}
int main()
{
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
            go(i, j);
            num ++;
        }
    }
    cout<<num - 1<<endl;
    return 0;
}