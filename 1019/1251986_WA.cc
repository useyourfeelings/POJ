#include<iostream>
#include<cmath>
using namespace std;
int main()
{   
    long long i, t, j;
    cin>>t;
    while(t--)
    {
        cin>>i;
        j = (int(sqrt(8 * i - 3)) - 1) / 2;
        cout<<i - (j * (j + 1) / 2)<<endl;
    }
    return 0;
}