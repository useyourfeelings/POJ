#include<iostream>
using namespace std;

char a[500], b[500];

int gcd(int a, int b)
{
    if(a == 0 || b == 0) return 1;
    if(a < b) swap(a, b);
    int c;
    c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{   
    int j, ib, count, sb, sa, ia, max;
    while(cin>>a>>b && a[0] != '-')
    {
        max = -1;
        sb = strlen(b);
        sa = strlen(a);
        for(ib = sb - 1; ib >= 0; ib --)
        {
            count = 0;
            for(j = ib, ia = 0; j < sb && ia < sa; j ++, ia ++)
            {
                if(b[j] == a[ia]) count ++;
            }
            if(count > max) max = count;
        }
        for(ia = 1; ia < sa; ia ++)
        {
            count = 0;
            for(j = ia, ib = 0; j < sa && ib < sb; j ++, ib ++)
            {
                if(a[j] == b[ib]) count ++;
            }
            if(count > max) max = count;
        }
        if(2 * max == sa + sb)
        {
            cout<<"appx("<<a<<","<<b<<") = 1"<<endl;
            continue;
        }
        if(max == 0)
        {
            cout<<"appx("<<a<<","<<b<<") = 0"<<endl;
            continue;
        }
        j = gcd(2 * max, sa + sb);
        cout<<"appx("<<a<<","<<b<<") = "
            <<2 * max / j<<"/"<<(sa + sb) / j<<endl;
    }
    return 0;
}