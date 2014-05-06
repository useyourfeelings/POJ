#include<iostream>
#include<cmath>
using namespace std;
bool is(int a)
{
    int b = sqrt(a);
    if(b * b == a) return 1;
    return 0;
}
int main()
{   
    int c, n, a, h, k;
    int p[100];
    p[0] = 0;
    p[1] = 0;
    for(c = 2; c < 100; c ++)
    {
        if(c % 2 == 0 || is(c)) p[c] = p[c - 1] + 2;
        else                    p[c] = p[c - 1] + 1;
    }
    cin>>c;
    while(c--)
    {
        cin>>n;
        if(n == 0)
        {
            cout<<"0"<<endl;
            continue;
        }
        a = ceil(pow(n, 1.0 / 3));
        h = n / (a * a);
        k = n % (a * a);
        cout<<a * a * 2 + a * h * 4 + k * 4 - p[k] * 2<<endl;
    }     
    return 0;
}
