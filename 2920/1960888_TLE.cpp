#include<iostream>
#include<vector>
using namespace std;

char map[300][300];
int i, j, n, test, Test, num, R, C, r, c, dangerous;
int move[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int main()
{
    scanf("%d", &Test);
    for(test = 1; test <= Test; ++ test)
    {
        scanf("%d%d", &n, &num);
        for(i = 1; i <= n; ++ i)
            for(j = 1; j <= n; ++ j) map[i][j] = 0;
        while(num --)
        {
            scanf("%d%d", &i, &j);
            map[i][j] = '*';
        }
        vector<vector<int> > q(2);
        num = 0;
        q[0].push_back(((n + 1) / 2) * 1001);
        for(;; num = 1 - num)
        {
            if(q[num].empty()) break;
            q[1 - num].resize(0);
            for(i = q[num].size() - 1; i >= 0; -- i)
            {
                R = q[num][i] / 1000;
                C = q[num][i] % 1000;
                dangerous = 0;
                for(j = 0; j < 8; ++ j)
                {
                    r = R + move[j][0];
                    c = C + move[j][1];
                    if(1 <= r && r <= n && 0 <= c && c <= n && map[r][c] == '*')
                    {
                        dangerous = 1;
                        break;
                    }
                }
                if(dangerous) map[R][C] = '#';
                else
                {
                    map[R][C] = '.';
                    for(j = 0; j < 8; ++ j)
                    {
                        r = R + move[j][0];
                        c = C + move[j][1];
                        if(1 <= r && r <= n && 0 <= c && c <= n && map[r][c] == 0)
                            q[1- num].push_back(r * 1000 + c);
                    }
                }
            }
        }
        printf("Scenario #%d:\n", test);
        for(i = 1; i <= n; ++ i)
        {
            for(j = 1; j <= n; ++ j)
            {
                if(map[i][j] == 0) printf("?");
                else               printf("%c", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}