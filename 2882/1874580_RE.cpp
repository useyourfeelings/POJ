#include<iostream>
using namespace std;

char space[101][101][101];

bool dfs(int x, int y, int z) // if it'is a hole    return true;
{
    space[x][y][z] = 'X';
    if(x == 1 || x == 100 || y == 1 || y == 100 ||
       z == 1 || z == 100) return false;
    bool ishole = 1;
    if(space[x - 1][y][z] == 0)
        if(!dfs(x - 1, y, z)) ishole = 0;
    if(space[x][y - 1][z] == 0)
        if(!dfs(x, y - 1, z)) ishole = 0;
    if(space[x][y][z - 1] == 0)
        if(!dfs(x, y, z - 1)) ishole = 0;
    if(space[x + 1][y][z] == 0)
        if(!dfs(x + 1, y, z)) ishole = 0;
    if(space[x][y + 1][z] == 0)
        if(!dfs(x, y + 1, z)) ishole = 0;
    if(space[x][y][z + 1] == 0)
        if(!dfs(x, y, z + 1)) ishole = 0;
    return ishole;
}

int main()
{
    int i, m, t, hole, x, y, z;
    scanf("%d", &t);
    while(t --)
    {
        for(x = 1; x < 101; ++ x)
            for(y = 1; y < 101; ++ y)
                for(z = 1; z < 101; ++ z) space[x][y][z] = 0;
        scanf("%d", &m);
        for(i = 0; i < m; ++ i)
        {
            scanf("%d%d%d", &x, &y, &z);
            space[x][y][z] = 'F';
        }
        hole = 0;
        for(x = 1; x < 101; ++ x)
            for(y = 1; y < 101; ++ y)
                for(z = 1; z < 101; ++ z)
                {
                    if(space[x][y][z] == 0)
                    {
                        if(dfs(x, y, z)) ++ hole;
                    }
                }
        printf("%d\n", hole);
    }
    return 0;
}