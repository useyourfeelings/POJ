#include<iostream>
#include<list>
using namespace std;

int x[700], y[700];

struct record
{
    int a, b, c;
};

bool operator ==(const record& m, const record& n)
{
    return m.a == n.a && m.b == n.b;
}

int gcd(int m, int n)
{
    int t;
    if(m < n)
    {
        t = m; m  = n; n = t;
    }
    t = m % n;
    while(t != 0)
    {
        m = n;
        n = t;
        t = m % n;
    }
    return n;
}

int main()
{   
    int N, t, count, a, b, i, j;
    while(scanf("%d", &N) && N != 0)
    {
        count = 2;
        for(i = 0; i < N; i++)
            scanf("%d%d", &x[i], &y[i]);
        for(i = 0; i < N - 1; ++ i)
        {
            list<record> lr;
            for(j = i + 1; j < N; ++ j)
            {
                record r;
                r.c = 2;
                if(x[i] == x[j])
                {
                    r.a = 1;
                    r.b = 0;
                }
                else if(y[i] == y[j])
                {
                    r.a = 0;
                    r.b = 1;
                }
                else
                {
                    a = y[j] - y[i];
                    b = x[j] - x[i];
                    if(a < 0) {a = -a; b = -b;}
                    t = gcd(a, b);
                    r.a = a / t;
                    r.b = b / t;
                }
                list<record>::iterator itr = lr.begin();
                for(; itr != lr.end(); ++ itr)
                {
                    if(*itr == r)
                    {
                        if(++(itr -> c) > count) count++;
                        itr ++;
                        break;
                    }
                }
                if(itr == lr.end()) lr.push_back(r);
            }
        }
        printf("%d\n", count);
    }    
    return 0;
}