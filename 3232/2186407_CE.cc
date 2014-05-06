#include<iostream>
using namespace std;

int remain[100000];
int test, i, n, m, k, players, t;
long long hi, mid, lo, sum;

bool ok()
{
    for(sum = i = players = 0; i < n; ++ i)
    {
        if(remain[i] <= mid) continue;// always ok
        if(remain[i] > k * mid) return false;// no hope
        t = remain[i] - mid;
        if(t % (k - 1) != 0) sum += t / (k - 1) + 1;
        else                 sum += t / (k - 1);
        ++ players;
    }
    if(m > players) m = players;
    if(sum > mid * m) return false;
    return true;
}

int main()
{
    scanf(f, "%d", &test);
    while(test --)
    {
        scanf("%d", &n);
        for(hi = i = 0; i < n; ++ i)
        {
            scanf("%d", &remain[i]);
            if(remain[i] > hi) hi = remain[i];
        }
        scanf("%d%d", &m, &k);
        if(k == 1)
        {
            lo = 0;
            for(i = 0; i < n; ++ i)
                if(remain[i] > lo) lo = remain[i];
        }
        else
        {
            lo = 1;
            while(lo < hi)
            {
                mid = (lo + hi) / 2;
                if(ok()) hi = mid;
                else     lo = mid + 1;
            }
        }
        cout<<lo<<"\n";
    }
    return 0;
}