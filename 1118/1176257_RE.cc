#include<iostream>
#include<list>
using namespace std;
int x[699], y[699];
struct record
{
    record(int aa, int bb):a(aa),b(bb),c(2){}
    int a, b, c;
};
bool operator ==(const record& m, const record& n)
{
    return (m.a == n.a) && (m.b == n.b);
}
int gdc(int m, int n)
{
    int t;
    if(m < n)
    {
        t = m; m  = n; n = t;
    }
    for(;;)
    {
        t = m;
        m = n;
        if((n = t % n) == 0) return m;
    }
}
int main()
{   
    int N, t, count, a, b;
    while(cin>>N && N != 0)
    {
        list<record> lr;
        count = 1;
        for(int i = 0; i < N; i++) cin>>x[i]>>y[i];
        for(int i = 0; i < N - 1; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                a = x[j] - x[i];
                b = y[j] - y[i];
                if(a < 0){a = -a; b = -b;}
                t = gdc(a, b);
                record r(a / t, b / t);
                cout<<r.a<<" "<<r.b<<endl;
                list<record>::iterator itr = lr.begin();
                while(itr != lr.end())
                {
                    if(*itr == r)
                    {
                        if(++(itr -> c) > count) count++;
                        itr ++;
                        continue;
                    }
                    itr++;
                }
                lr.push_back(r);
            }
            list<record>::iterator itr = lr.begin();
            while(itr != lr.end())
            {
                itr -> c = 2;
                itr++;
            }    
        }
        cout<<count<<endl;
    }
    return 0;
}