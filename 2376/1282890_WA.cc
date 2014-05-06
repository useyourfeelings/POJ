#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct in
{
    in(int ss, int ee):s(ss),e(ee){}
    int s;
    int e;
};

bool comp(const in &a, const in &b)
{
    return a.s < b.s;
}

int main()
{   
    int n, t, i, a, b, maxe;
    bool ok;
    scanf("%d%d", &n, &t);
    vector<in> vi;
    vi.reserve(n);
    for(i = 0; i < n; ++i)
    {
        scanf("%d%d", &a, &b);
        vi.push_back(in(a, b));
    }
    sort(vi.begin(), vi.end(), comp);

    for(i = 0, b = 1, ok = 1, a = 0; ;)
    {
        maxe = -1;
        for(; i < n; ++ i)
        {
            if(vi[i].s <= b + 1)
            {
                if(vi[i].e > maxe) maxe = vi[i].e;
            }
            else break;
        }
        if(maxe == -1 || (i >= n && maxe < t))
        {
            ok = 0;
            break;
        }
        else if(maxe >= t)
        {
            ++ a;
            break;
        }
        b = maxe;
        ++ a;
    }
    if(ok) cout<<a<<endl;
    else cout<<"-1"<<endl;
    return 0;
}