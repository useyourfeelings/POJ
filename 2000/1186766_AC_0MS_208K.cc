#include<iostream>
#include<cmath>
using namespace std;
int main()
{   
    int day, p, sum, i;
    while(cin>>day && day != 0)
    {
        sum = 0;
        p = int(ceil(double(sqrt(1 + 8 * day) - 1) / 2));
        for(i = 1; i <= p; i ++) sum += i * i;
        sum -= (p * (p + 1) / 2 - day) * p;
        cout<<day<<" "<<sum<<endl; 
    }
    return 0;
}
