#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct pos
{
    pos(int rr, int cc):r(rr),c(cc){}
    int r, c;
};

bool comp_1(const pos &a, const pos &b)
{
    if(a.r != b.r) return a.r < b.r;
    return a.c < b.c;
}

bool comp_2(const pos &a, const pos &b)
{
    if(a.c != b.c) return a.c < b.c;
    return a.r < b.r;
}

int main()
{
    int m, n, k, t, i, j, count;
    scanf("%d", &t);
    while(t --)
    {
        vector<pos> vp;
        count = 0;
        scanf("%d%d%d", &m, &n, &k);
        vp.reserve(k + 2 * m + 2 * n);
        while(k --)
        {
            scanf("%d%d", &i, &j);
            vp.push_back(pos(i, j));
        }
        for(j = 1; j <= m; ++ j)
        {
            vp.push_back(pos(j, 0));
            vp.push_back(pos(j, n + 1));
        }
        sort(vp.begin(), vp.end(), comp_1);
        for(i = 1; i < vp.size(); ++ i)
        {
            if(vp[i].r == vp[i - 1]. r)
                if(vp[i].c - vp[i - 1].c > 2) ++ count;
        }
        for(j = 1; j <= n; ++ j)
        {
            vp.push_back(pos(0, j));
            vp.push_back(pos(m + 1, j));
        }
        sort(vp.begin(), vp.end(), comp_2);
        for(i = 1; i < vp.size(); ++ i)
        {
            if(vp[i].c == vp[i - 1]. c)
                if(vp[i].r - vp[i - 1].r > 2) ++ count;
        }
        printf("%d\n", count);
    }
    return 0;
}