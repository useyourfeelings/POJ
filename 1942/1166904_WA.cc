#include<iostream>
using namespace std;
int main()
{
    int n, m;
    while(cin>>n>>m)
    {
        if(n == 0 && m == 0) break;
        __int64 a = 1, b = 1;
        if(n < m)
        {
            int t = n; n = m; m = t;
        }
        for(int i = n + m; i > n; i--) a *= i;
        for(int i = m    ; i > 1; i--) b *= i;
        cout<<a/b<<endl;
    }
    return 0;
}
