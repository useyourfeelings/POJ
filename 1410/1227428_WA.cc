#include<iostream>
using namespace std;
int main()
{   
    int Case, xs, ys, xe, ye, xl, yt, xr, yb;
    cin>>Case;
    while(Case--)
    {
        bool ok = 0;
        int y21, x12, a, b;
        cin>>xs>>ys>>xe>>ye>>xl>>yt>>xr>>yb;
        y21 = ye - ys;
        x12 = xs - xe;
        a = y21;
        b = xs * ye - xe * ys;
        if(((a * xl + y21 * yt) > b && (a * xl + y21 * yb) > b &&
            (a * xr + y21 * yt) > b && (a * xr + y21 * yb) > b) ||
           ((a * xl + y21 * yt) < b && (a * xl + y21 * yb) < b &&
            (a * xr + y21 * yt) < b && (a * xr + y21 * yb) < b))
            ok = 1;
        if(!ok)
        {
            if((xs < xl && xe < xl) || (xs > xr && xe > xr) ||
               (ys < yb && ye < yb) || (ys > yt && ye > yt))
                ok = 1;
        }
        if(ok) cout<<"F"<<endl;
        else   cout<<"T"<<endl;
    }
    return 0;
}