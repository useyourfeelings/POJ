#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct line
{
    line(double l, int aa, int bb):len(l),a(aa),b(bb){}
    double len;
    int a;
    int b;
};

double x[100];
double y[100];

bool comp(const line &a, const line &b)
{
    return a.len > b.len;
}

int main()
{
    
    double total = 0.0;
    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i)
        scanf("%lf %lf", &x[i], &y[i]);
    vector<line> vl;
    for(i = 0; i < n - 1; ++ i)
    {
        for(j = i + 1; j < n; ++ j)
        {
            vl.push_back(line(
                sqrt((x[i] - x[j]) * (x[i] - x[j]) +
                     (y[i] - y[j]) * (y[i] - y[j])), i, j));
        }
    }
    sort(vl.begin(), vl.end(), comp);
    vector<bool> done(n, 0);
    j = 0;
    while(j < n)
    {
        if(!(done[vl.back().a] && done[vl.back().b]))
        {
            if(!done[vl.back().a])
            {
                done[vl.back().a] = 1;
                ++ j;
            }
            if(!done[vl.back().b])
            {
                done[vl.back().b] = 1;
                ++ j;
            }
            total += vl.back().len;
        }
        vl.pop_back();
    }
    printf("%.2lf", total);
    return 0;
}
