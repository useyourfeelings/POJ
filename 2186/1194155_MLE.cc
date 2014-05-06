#include<iostream>
using namespace std;
bool p[10001][10001];
int main()
{   
    int n, m, i, j, k, max = 0;
    cin>>n>>m;
    while(m--)
    {
        cin>>j>>k;
        p[j][k] = 1;
    }
    for(i = 1; i <= n; i ++) p[i][i] = 1;
    for(i = 1; i <= n; i ++)
    {
        for(j = 1; j <= n; j ++)
        {
            if(p[j][i])
                for(k = 1; k <= n; k ++)
                    if(p[i][k]) p[j][k] = 1;
        }
    }
    m = 0;
    for(i = 1; i <= n; i ++)
    {
        k = 0;
        for(j = 1; j <= n; j ++) if(p[j][i]) k ++;
        if(k > max)
        {
            max = k;
            m = 1;
        }
        else if(k == max) m ++;
    }
    cout<<m;
    return 0;
}