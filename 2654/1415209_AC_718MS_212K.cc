#include<iostream>
#include<vector>
using namespace std;
int main()
{
    char b1[9];
    char b2[9];
    int n, k, p1, p2, i;
    
    while(scanf("%d%d", &n, &k) && n != 0)
    {
        vector<int> win(n + 1, 0);
        vector<int> lose(n + 1, 0);
        for(i = 0; i < k * n * (n - 1) / 2; ++ i)
        {
            scanf("%d%s%d%s", &p1, &b1, &p2, &b2);
            if(b1[0] == b2[0]) continue;
            if(b1[0] == 'r')
            {
                if(b2[0] == 's')
                {
                    win[p1] ++;
                    lose[p2] ++;
                }
                else
                {
                    win[p2] ++;
                    lose[p1] ++;
                }
            }
            else if(b1[0] == 's')
            {
                if(b2[0] == 'p')
                {
                    win[p1] ++;
                    lose[p2] ++;
                }
                else
                {
                    win[p2] ++;
                    lose[p1] ++;
                }
            }
            else
            {
                if(b2[0] == 'r')
                {
                    win[p1] ++;
                    lose[p2] ++;
                }
                else
                {
                    win[p2] ++;
                    lose[p1] ++;
                }
            }
        }
        for(k = 1; k <= n; k++)
        {
            if((win[k] + lose[k]) == 0) printf("-\n");
            else printf("%.3lf\n", double(win[k]) / double(win[k] + lose[k]));
        }
        printf("\n");
    }
    return 0;
}