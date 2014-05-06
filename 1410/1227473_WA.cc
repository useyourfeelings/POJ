#include<iostream>
using namespace std;
int main()
{   
    int Case, xs, ys, xe, ye, xl, yt, xr, yb;
    cin>>Case;
    while(Case--)
    {
        bool ok = 0;
        int y21, x12, b;
        cin>>xs>>ys>>xe>>ye>>xl>>yt>>xr>>yb;
        if(xl > xr)
        {
            swap(xl, xr);
            swap(yt, yb);
        }
        y21 = ye - ys;
        x12 = xs - xe;
        b = xs * ye - xe * ys;
        if(((y21 * xl + x12 * yt) > b && (y21 * xl + x12 * yb) > b &&
            (y21 * xr + x12 * yt) > b && (y21 * xr + x12 * yb) > b) ||
           ((y21 * xl + x12 * yt) < b && (y21 * xl + x12 * yb) < b &&
            (y21 * xr + x12 * yt) < b && (y21 * xr + x12 * yb) < b))
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