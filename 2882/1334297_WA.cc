#include<iostream>
#include<algorithm>
using namespace std;

bool space[104][104][104];
int food[1000000][3];
bool killed[104][104][104];

int main()
{
    int i, m, t, hole;
    scanf("%d", &t);
    while(t --)
    {
        hole = 0;
        memset(space, 0, sizeof(bool) * 104 * 104 * 104);
        memset(killed, 0, sizeof(bool) * 104 * 104 * 104);
        scanf("%d", &m);
        for(i = 0; i < m; ++ i)
        {
            scanf("%d%d%d", &food[i][0], &food[i][1], &food[i][2]);
            ++ food[i][0]; ++ food[i][1]; ++ food[i][2];
            space[food[i][0]][food[i][1]][food[i][2]] = 1;
        }
        for(i = 0; i < m; ++ i)
        {
            if(!space[food[i][0] - 1][food[i][1]][food[i][2]] &&
               !killed[food[i][0] - 1][food[i][1]][food[i][2]])
            {
                if(space[food[i][0] - 2][food[i][1]][food[i][2]] &&
                   space[food[i][0] - 1][food[i][1] - 1][food[i][2]] &&
                   space[food[i][0] - 1][food[i][1] + 1][food[i][2]] &&
                   space[food[i][0] - 1][food[i][1]][food[i][2] - 1] &&
                   space[food[i][0] - 1][food[i][1]][food[i][2] + 1])
                {
                    ++ hole;
                    killed[food[i][0] - 1][food[i][1]][food[i][2]] = 1;
                }
            }
            if(!space[food[i][0] + 1][food[i][1]][food[i][2]] &&
               !killed[food[i][0] + 1][food[i][1]][food[i][2]])
            {
                if(space[food[i][0] + 2][food[i][1]][food[i][2]] &&
                   space[food[i][0] + 1][food[i][1] - 1][food[i][2]] &&
                   space[food[i][0] + 1][food[i][1] + 1][food[i][2]] &&
                   space[food[i][0] + 1][food[i][1]][food[i][2] - 1] &&
                   space[food[i][0] + 1][food[i][1]][food[i][2] + 1])
                {
                    ++ hole;
                    killed[food[i][0] + 1][food[i][1]][food[i][2]] = 1;
                }
            }
            if(!space[food[i][0]][food[i][1] - 1][food[i][2]] &&
               !killed[food[i][0]][food[i][1] - 1][food[i][2]])
            {
                if(space[food[i][0] - 1][food[i][1] - 1][food[i][2]] &&
                   space[food[i][0] + 1][food[i][1] - 1][food[i][2]] &&
                   space[food[i][0]][food[i][1] - 2][food[i][2]] &&
                   space[food[i][0]][food[i][1] - 1][food[i][2] - 1] &&
                   space[food[i][0]][food[i][1] - 1][food[i][2] + 1])
                {
                    ++ hole;
                    killed[food[i][0]][food[i][1] - 1][food[i][2]] = 1;
                }
            }
            if(!space[food[i][0]][food[i][1] + 1][food[i][2]] &&
               !killed[food[i][0]][food[i][1] + 1][food[i][2]])
            {
                if(space[food[i][0] - 1][food[i][1] + 1][food[i][2]] &&
                   space[food[i][0] + 1][food[i][1] + 1][food[i][2]] &&
                   space[food[i][0]][food[i][1] + 2][food[i][2]] &&
                   space[food[i][0]][food[i][1] + 1][food[i][2] - 1] &&
                   space[food[i][0]][food[i][1] + 1][food[i][2] + 1])
                {
                    ++ hole;
                    killed[food[i][0]][food[i][1] + 1][food[i][2]] = 1;
                }
            }
            if(!space[food[i][0]][food[i][1]][food[i][2] - 1] &&
               !killed[food[i][0]][food[i][1]][food[i][2] - 1])
            {
                if(space[food[i][0] - 1][food[i][1]][food[i][2] - 1] &&
                   space[food[i][0] + 1][food[i][1]][food[i][2] - 1] &&
                   space[food[i][0]][food[i][1] - 1][food[i][2] - 1] &&
                   space[food[i][0]][food[i][1] + 1][food[i][2] - 1] &&
                   space[food[i][0]][food[i][1]][food[i][2] - 2])
                {
                    ++ hole;
                    killed[food[i][0]][food[i][1]][food[i][2] - 1] = 1;
                }
            }
            if(!space[food[i][0]][food[i][1]][food[i][2] + 1] &&
               !killed[food[i][0]][food[i][1]][food[i][2] + 1])
            {
                if(space[food[i][0] - 1][food[i][1]][food[i][2] + 1] &&
                   space[food[i][0] + 1][food[i][1]][food[i][2] + 1] &&
                   space[food[i][0]][food[i][1] - 1][food[i][2] + 1] &&
                   space[food[i][0]][food[i][1] + 1][food[i][2] + 1] &&
                   space[food[i][0]][food[i][1]][food[i][2] + 2])
                {
                    ++ hole;
                    killed[food[i][0]][food[i][1]][food[i][2] + 1] = 1;
                }
            }
        }
        printf("%d\n", hole);
    }
    return 0;
}