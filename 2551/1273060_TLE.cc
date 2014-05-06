#include<iostream>
using namespace std;
int main()
{   
    int n, i;
    long long d;
    while(cin>>n)
    {
        for(i = 1, d = 1;; i++, d = d * 10 + 1)
        {
            if(d < n) continue;
            if(d % n == 0)
            {
                cout<<i<<endl;
                break;
            }

        }
    }
    return 0;
}