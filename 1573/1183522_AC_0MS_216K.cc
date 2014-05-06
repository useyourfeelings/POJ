#include<iostream>
using namespace std;
int a, b, start, pin, i, j;
char grid[10][10];
int path[100];
void fun(int r, int c)
{
    for(i = 0; i <= pin; i++)
    {
        if(path[i] == (r << 4 | c)) break;
    }
    if(i <= pin && pin != -1) return;
    path[++pin] = (r << 4 | c);
    if(grid[r][c] == 'N')
    {
        if(r > 0) fun(r - 1, c);
        else { i++; return;}
    }
    else if(grid[r][c] == 'S')
    {
        if(r < a - 1) fun(r + 1, c);
        else { i++; return;}
    }
    else if(grid[r][c] == 'W')
    {
        if(c > 0) fun(r, c - 1);
        else { i++; return;}
    }
    else
    {
        if(c < b - 1) fun(r, c + 1);
        else { i++; return;}
    }
}
int main()
{
    while(cin>>a>>b>>start && a != 0 && b != 0 && start != 0)
    {
        pin = -1;
        for(i = 0 ; i < a; i ++)
            for(j = 0 ; j < b; j ++) cin>>grid[i][j];
        start --;
        fun(0, start);
        if(i <= pin) cout<<i<<" step(s) before a loop of "
                         <<pin - i + 1<<" step(s)"<<endl;
        else cout<<pin + 1<<" step(s) to exit"<<endl;
    }
    return 0;
}