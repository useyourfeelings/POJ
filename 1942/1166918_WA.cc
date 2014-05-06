#include<iostream>
using namespace std;
int main()
{
    long long n, m;
    while(cin>>n>>m && m + n > 0)
    {
        long long a = 1, b = 1;
        if(n < m)
        {
            long long t = n; n = m; m = t;
        }
        for(long long i = n + m; i > n; i--) a *= i;
        for(long long i = m    ; i > 1; i--) b *= i;
        cout<<a/b<<endl;
    }
    return 0;
}