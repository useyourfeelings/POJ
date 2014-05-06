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
    int c, n, a, h, k, t, p, q, r;
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
        t = (h > 0) ? (a * a * 2) : (k * 2);
        r = 0;
        if(k != 0)
        {
            p = floor(sqrt(k));
            q = k - pow(double(p), 2);
            if(q > p)       r = p * 4 + 4;
            else if (q > 0) r = p * 4 + 2;
            else            r = p * 4;
        }
        cout<<t + a * h * 4 + r<<endl;
    }     
    return 0;
}
