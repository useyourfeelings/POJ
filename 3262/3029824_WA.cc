#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct info
{
    int t, d;
    info(int tt, int dd):t(tt),d(dd){}
};

bool comp(const info& a, const info& b)
{
    return double(a.d) / double(a.t) > double(b.d) / double(b.t);
}

long long damage[100000], total;
int i, n, d, t;

int main()
{
    scanf("%d", &n);
    vector<info> cow;
    cow.reserve(n);
    for(i = 0; i < n; ++ i)
    {
        scanf("%d%d", &t, &d);
        cow.push_back(info(t, d));
    }
    sort(cow.begin(), cow.end(), comp);
    damage[n - 1] = cow[n - 1].d;
    for(i = n - 2; i >= 0; -- i) damage[i] = damage[i + 1] + cow[i].d;
    total = 0;
    for(i = 0; i < n - 1; ++ i)
        total += cow[i].t * 2 * damage[i + 1];
    printf("%d", total);
    return 0;
}