#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int rank[100];
int p[100];

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void link(int a, int b)
{
    if(rank[a] > rank[b]) p[b] = a;
    else p[a] = b;
    if(rank[a] == rank[b]) ++ rank[b];
}

void unify(int x, int y)
{
    link(find(x), find(y));
}


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
    
    double total = 0;
    int n, i, j;
    scanf("%d", &n);
    if(n == 1)
    {
        printf("0.00");
        return 0;
    }
    for(i = 0; i < n; ++ i)
    {
        scanf("%lf %lf", &x[i], &y[i]);
        p[i] = i;
    }
    memset(rank, 0, sizeof(int) * n);
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
    j = 0;
    while(j < n - 1)
    {
        if(find(vl.back().a) != find(vl.back().b))
        {
            ++ j;
            total += vl.back().len;
            unify(vl.back().a, vl.back().b);
        }
        vl.pop_back();
    }
    printf("%.2lf", total);
    return 0;
}
