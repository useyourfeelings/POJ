#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{   
    double gx, gy, dx, dy, hx, hy;
    bool ok = 0;
    cin>>gx>>gy>>dx>>dy;
    while(cin>>hx>>hy)
    {
        if(4 * (pow(gx - hx, 2) + pow(gy - hy, 2)) <
               (pow(dx - hx, 2) + pow(dy - hy, 2)))
        {
            cout<<setprecision(3)<<setiosflags(ios::fixed)
                <<"The gopher can escape through the hole at ("<<hx<<","<<hy<<")."<<endl;
            ok = 1;
            break;
        }
    }
    if(!ok) cout<<"The gopher cannot escape."<<endl;
    return 0;
}