#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<limits>
using namespace std;

int t, n, x, y, maxh, i, x1, x2, h;

struct bar
{
    bar(int a, int b, int c):x1(a),x2(b),h(c){}
    int x1;
    int x2;
    int h;
};

struct pred
{
    bool operator()(const bar &a, const bar &b) const
    {
        return a.h > b.h;
    }
};

vector<bar> vb;

int make(int now, int x)
{
    if(now == vb.size() - 1) return 0;
    int len, i, h, Lmin = INT_MAX, Rmin = INT_MAX;

    len = x - vb[now].x1;       //   go left
    for(i = now + 1; ; ++ i)
        if(vb[i].x1 <= vb[now].x1 && vb[now].x1 <= vb[i].x2) break;
    if((h = vb[now].h - vb[i].h) <= maxh)
        Lmin = len + h + make(i, vb[now].x1);
        
    len = vb[now].x2 - x;       //   go right
    for(i = now + 1; ; ++ i)
        if(vb[i].x1 <= vb[now].x2 && vb[now].x2 <= vb[i].x2) break;
    if((h = vb[now].h - vb[i].h) <= maxh)
        Rmin = len + h + make(i, vb[now].x2);
    
    return min(Lmin, Rmin);
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        vb.clear();
        scanf("%d%d%d%d", &n, &x, &y, &maxh);
        for(i = 0; i < n; i++)
        {
            cin>>x1>>x2>>h;
            if(x1 > x2) swap(x1, x2);
            vb.push_back(bar(x1, x2, h));
        }
        vb.push_back(bar(-20001, 20001, 0));
        sort(vb.begin(), vb.end(), pred());
        
        for(i = 0; ; ++ i) if(vb[i].x1 <= x && x <= vb[i].x2) break;
        printf("%d\n", make(i, x) + y - vb[i].h);
    }
    return 0;
}