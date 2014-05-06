#include<iostream>
using namespace std;
int num = 1;
void go(int i, int p[], int x, int y)
{
    
    if(p[i] != 0) return;
    p[i] = num;
    if(i >= x)                          go(i - x, p, x, y);
    if(i < x * y - x)                   go(i + x, p, x, y);
    if(i % x != 0)                      go(i - 1, p, x, y);
    if(i % x != x - 1)                  go(i + 1, p, x, y);
    if(i >= x && i % x != 0)            go(i - x - 1, p, x, y);
    if(i >= x && i % x != x - 1)        go(i - x + 1, p, x, y);
    if(i < x * y - x && i % x != 0)     go(i + x - 1, p, x, y);
    if(i < x * y - x && i % x != x - 1) go(i + x + 1, p, x, y);
}
int main()
{
    int x, y, *p;
    char c;
    cin>>y>>x;
    p = new int[x * y];
    for(int i = 0; i < x * y; i++)
    {
        cin>>c;
        if(c == 'W') p[i] = 0;
        else         p[i] = -1;
    }
    for(int i = 0; i < x * y; i++)
    {
        if(p[i] != 0) continue;
        go(i, p, x, y);
        num ++;    
    }
    cout<<num - 1<<endl;
    delete p;
    return 0;
}
