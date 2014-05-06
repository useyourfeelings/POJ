#include<iostream>
using namespace std;
int fun(bool a[], int start, int &count, int x, int y)
{
    if(start >= x)
        if(a[start - x])
        {
            a[start - x] = 0;
            count = 1 + fun(a, start - x, count, x, y);
        }
    if(start < x * y - x)
        if(a[start + x])
        {
            a[start + x] = 0;
            count = 1 + fun(a, start + x, count, x, y);
        }
    if(start % x != 0)
        if(a[start - 1])
        {
            a[start - 1] = 0;
            count = 1 + fun(a, start - 1, count, x, y);
        }
    if(start % x != (x - 1))
        if(a[start + 1])
        {
            a[start + 1] = 0;
            count = 1 + fun(a, start + 1, count, x, y);
        }
    return count;
}
int main()
{   
    int x, y, start, count;
    bool *p;
    char c;
    while(cin>>x>>y)
    {
        if(x == 0 || y == 0) break;
        count = 1;
        p = new bool[x * y];
        for(int i = 0; i < x * y; i++)
        {
            cin>>c;
            if(c == '.') p[i] = 1;
            else         p[i] = 0;              
            if(c == '@') start = i;
        }
        cout<<fun(p, start, count, x, y)<<endl;
        delete p;
    }
    return 0;
}
