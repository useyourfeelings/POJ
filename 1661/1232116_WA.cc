#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxt = 0x2FFFFFFF;
int maxh;
struct bar
{
    bar(int a, int b, int c):x1(a),x2(b),h(c){}
    int x1;
    int x2;
    int h;
    int lmin;
    int rmin;
};
struct pred
{
    bool operator()(const bar &a, const bar &b) const
    {
        return a.h < b.h;
    }
};

int main()
{   
    int t, n, x, y, maxh, i, x1, x2, h;
    cin>>t;
    while(t--)
    {
        vector<bar> vb;
        cin>>n>>x>>y>>maxh;
        for(i = 0; i < n; i++)
        {
            cin>>x1>>x2>>h;
            vb.push_back(bar(x1, x2, h));
        }
        vb.push_back(bar(-20001, 20001, 0));
        sort(vb.begin(), vb.end(), pred());
        
        vector<bar>::iterator iup = vb.begin();
        ++ iup;
        for(; iup != vb.end(); ++iup)
        {
            vector<bar>::iterator idown = iup;
            -- idown;
            for(; ; idown --)
            {
                if(idown == vb.begin())
                {
                    if(iup -> h <= maxh) iup -> lmin = iup -> h;
                    else                 iup -> lmin = maxt;
                    break;
                }
                else if((idown -> x1 <= iup -> x1) && (iup -> x1 <= idown -> x2))
                {
                    if((iup -> h - idown -> h) > maxh) iup -> lmin = maxt;
                    else
                    {
                        iup -> lmin = (iup -> h - idown -> h) +
                            min(iup -> x1 - idown -> x1 + idown -> lmin,
                                idown -> x2 - iup -> x1 + idown -> rmin);
                        if(iup -> lmin > maxt) iup -> lmin = maxt;
                    }
                    break;
                }
            }
            idown = iup;
            -- idown;
            for(; ; idown --)
            {
                if(idown == vb.begin())
                {
                    if(iup -> h <= maxh) iup -> rmin = iup -> h;
                    else                 iup -> rmin = maxt;
                    break;
                }
                else if((idown -> x1 <= iup -> x2) && (iup -> x2 <= idown -> x2))
                {
                    if((iup -> h - idown -> h) > maxh) iup -> rmin = maxt;
                    else
                    {
                        iup -> rmin = (iup -> h - idown -> h) +
                            min(iup -> x2 - idown -> x1 + idown -> lmin,
                                idown -> x2 - iup -> x2 + idown -> rmin);
                        if(iup -> rmin > maxt) iup -> rmin = maxt;
                    }
                    break;
                }
            }
        }
        iup = vb.end();
        iup --;
        for(;; iup --)
        {
            if(iup -> x1 <= x && x <= iup -> x2)
            {
                cout<<(y - iup -> h + min(x - iup -> x1 + iup -> lmin,
                                          iup -> x2 - x + iup -> rmin))<<endl;
                break;
            }
        }
    }
    return 0;
}