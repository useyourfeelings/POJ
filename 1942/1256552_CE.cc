#include<iostream>
using namespace std;
int main()
{
    int n, m;
    while(cin>>n>>m && m != 0)
    {
        double a = 1, b = 1;
        if(n < m)
        {
            int t = n; n = m; m = t;
        }
        for(long long i = n + m; i > n; i--) a *= i;
        for(long long i = m    ; i > 1; i--) b *= i;
        cout<<int(a / b)<<endl;
    }
    return 0;
