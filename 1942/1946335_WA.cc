#include<iostream>
using namespace std;
long long C(long long a, long long b)
{
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b > (a >> 1)) return C(a, a - b);
    return C(a - 1, b - 1) * a / b;
}
int main()
{
    long long a, b;
    while(cin>>a>>b && a != 0 && b != 0)
        cout<<C(a + b, a)<<endl;
    return 0;
}
