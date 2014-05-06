#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;
struct point
{
    point(int xx, int yy):x(xx),y(yy){}
    int x;
    int y;
};
struct xless
{
    bool operator ()(const point &a, const point &b)
    {
        return a.x < b.x;
    }
};
int main()
{   
    int n, x, y, i, count;
    while(cin>>n && n != 0)
    {
        count = 0;
        vector<point> pv;
        pv.reserve(n);
        for(i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            pv.push_back(point(x, y));
        }
        sort(pv.begin(), pv.end(), xless());
        int maxy = INT_MIN;
        int kingy = INT_MIN;
        int xc = pv.rbegin() -> x;
        vector<point>::reverse_iterator itr = pv.rbegin();
        vector<point>::reverse_iterator end = pv.rend();
        for(; itr != end; ++itr)
        {
            if(itr -> x != xc)
            {
                if(maxy > kingy)
                {
                    count ++;
                    kingy = maxy;
                }
                xc = itr -> x;
                maxy = itr -> y;
            }
            else
            {
                if(itr -> y > maxy) maxy = itr -> y;
            }
        }
        if(maxy > kingy) count++;
        cout<<count<<endl;
    }
    return 0;
}