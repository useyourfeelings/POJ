#include<iostream>
using namespace std;
int main()
{
    int n, k, i;
    while(cin>>n>>k && n != 0)
    {
        if(k < n / 2) k = n - k;
        double a = 1;
        for(i = n; i >= k + 1; i --) a *= i;
        double b = 1;
        for(i = n - k; i >= 2; i --) b *= i;
        cout<<int(a / b)<<endl;
    }
    return 0;
}