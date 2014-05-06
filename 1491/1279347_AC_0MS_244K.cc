#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int gdc(int a, int b)
{
    if(a < b) swap(a, b);
    int t = a % b;
    while(t != 0)
    {
        a = b;
        b = t;
        t = a % b;
    }
    return b;
}

int main()
{   
    cout<<setiosflags(ios::fixed)<<setprecision(6);
    int g[50], i, t, ok, j;
    while(cin>>t && t != 0)
    {
        for(i = 0; i < t; i++) cin>>g[i];
        ok = 0;
        for(i = 0; i < t - 1; i++)
        {
            for(j = i; j < t; j++)
            {
                if(gdc(g[i], g[j]) == 1) ++ ok;
            }
        }
        if(ok == 0) cout<<"No estimate for this data set."<<endl;
        else cout<<sqrt(double((t * (t - 1)) / 2) * 6 / ok)<<endl;
    }
    return 0;
}