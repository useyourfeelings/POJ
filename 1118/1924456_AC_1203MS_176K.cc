#include<iostream>
#include<map>
using namespace std;

int x[700], y[700];

struct record
{
    int a, b;
};

bool operator <(const record& n, const record& m)
{
    if(m.a == n.a) return m.b < n.b;
    return m.a < n.a;
}

int gcd(int m, int n)
{
    int t;
    if(m < n) swap(m, n);
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
    map<record, int>::iterator itr;
    while(scanf("%d", &N) && N != 0)
    {
        count = 2;
        for(i = 0; i < N; i++)
            scanf("%d%d", &x[i], &y[i]);
        for(i = 0; i < N - 1; ++ i)
        {
            map<record, int> line;
            for(j = i + 1; j < N; ++ j)
            {
                record r;
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
                itr = line.find(r);
                if(itr == line.end())
                    line.insert(make_pair(r, 2));
                else
                {
                    t = ++ itr -> second;
                    if(t > count) count = t;
                }
            }
        }
        printf("%d\n", count);
    }    
    return 0;
}