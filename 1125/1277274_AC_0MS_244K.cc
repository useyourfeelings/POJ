#include<iostream>
using namespace std;

int g[101][101];
int d[101][101];
const int bad = 10000;

int main()
{   
    int n, i, j, k, num, v;
    while(cin>>n && n != 0)
    {
        for(i = 0; i <= n; i++)
            for(j = 1; j <= n; j++) g[i][j] = d[i][j] = bad;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &num);
            while(num --)
            {
                scanf("%d", &v);
                scanf("%d", &g[i][v]);
                d[i][v] = g[i][v];
            }
            d[i][i] = 0;
        }
        for (k = 1; k <= n; k++)
        {
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];
    	        }
            }
        }
        bool ok = 0;
        int minid = 1, mind = bad, maxd;
        for(i = 1; i <= n; i++)
        {
            maxd = -1;
            for(j = 1; j <= n; j++)
            {
                if(d[i][j] == bad) break;
                else if(d[i][j] > maxd) maxd = d[i][j];
            }
            if(j > n)
            {
                if(maxd < mind)
                {
                    mind = maxd;
                    minid = i;
                }
                ok = 1;
            }
        }
        if(!ok) cout<<"disjoint"<<endl;
        else cout<<minid<<" "<<mind<<endl;
    }
    return 0;
}