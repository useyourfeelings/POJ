#include <iostream>
using namespace std;

int n, mid, i, j, maxh = -1, minh = 111, l, r;

short g[100][100];
short t[100][100];

void dfs(int i, int j)
{
    t[i][j] = 2;
    if(i > 0) if(t[i - 1][j] == 1) dfs(i - 1, j);
    if(j > 0) if(t[i][j - 1] == 1) dfs(i, j - 1);
    if(i < n - 1) if(t[i + 1][j] == 1) dfs(i + 1, j);
    if(j < n - 1) if(t[i][j + 1] == 1) dfs(i, j + 1);
}

bool ok()
{
    int a, b;
    for(a = minh; a <= maxh - mid; ++ a)
    {
        b = a + mid;
        for(int p = 0; p < n; ++ p)
        {
            for(int q = 0; q < n; ++ q)
            {
                if(g[p][q] < a || g[p][q] > b) t[p][q] = 0;
                else t[p][q] = 1;
            }
        }
        if(t[0][0] == 1) dfs(0, 0);
        if(t[n - 1][n  - 1] == 2) return 1;
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    for(i = 0; i < n; ++ i)
    {
        for(j = 0; j < n; ++ j)
        {
            scanf("%d", &g[i][j]);
            if(g[i][j] > maxh) maxh = g[i][j];
            else if(g[i][j] < minh) minh = g[i][j];
        }
    }
    r = maxh - minh;
    l = 0;
    while(l <= r)
    {
        mid = (r + l) / 2;
        if(ok())
        {
            j = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    printf("%d", j);
    return 0;
}