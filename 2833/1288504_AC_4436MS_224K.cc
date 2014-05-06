#include<iostream>
#include<set>
#include<functional>
using namespace std;

int main()
{
    int n1, n2, n, t, i;
    long long sum;
    while(scanf("%d%d%d", &n1, &n2, &n) && n1 != 0)
    {
        multiset<int, less<int> > gs;
        multiset<int, greater<int> > ls;
        for(i = 0, sum = 0; i < max(n1, n2); ++i)
        {
            scanf("%d", &t);
            sum += t;
            if(gs.size() < n1) gs.insert(t);
            else
            {
                if(t > *gs.begin())
                {
                    gs.erase(gs.begin());
                    gs.insert(t);
                }
            }
            if(ls.size() < n2) ls.insert(t);
            else
            {
                if(t < *ls.begin())
                {
                    ls.erase(ls.begin());
                    ls.insert(t);
                }
            }
        }
        for(; i < n; ++i)
        {
            scanf("%d", &t);
            sum += t;
            if(t > *gs.begin())
            {
                gs.erase(gs.begin());
                gs.insert(t);
            }
            if(t < *ls.begin())
            {
                ls.erase(ls.begin());
                ls.insert(t);
            }
        }
        multiset<int, less<int> >::iterator itr = gs.begin();
        for(; itr != gs.end(); ++itr) sum -= *itr;
        multiset<int, greater<int> >::iterator itrr = ls.begin();
        for(; itrr != ls.end(); ++itrr) sum -= *itrr;
        printf("%.6f\n", double(sum) / (n - n1 - n2));
    }
    return 0;
}