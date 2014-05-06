#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int i, j, n, max, ans = 1;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> b(n, 1);
    for(i = 0; i < n; ++ i) scanf("%d", &a[i]);
    for(i = n - 2; i >= 0; -- i)
    {
        max = 0;
        for(j = i + 1; j < n; ++ j)
        {
            if(a[j] > a[i])
            {
                if(b[j] > max) max = b[j];
            }
        }
        b[i] += max;
        if(b[i] > ans) ans = b[i];
    }
    printf("%d", ans);
    return 0;
}
