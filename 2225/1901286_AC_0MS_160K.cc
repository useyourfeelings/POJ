#include<iostream>
#include<list>
using namespace std;

int i, j, k, N, x, y, z, ans, size;
char space[10][10][10];// x y z
int move[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
char buff[7];

struct block
{
    block(int xx, int yy, int zz):x(xx),y(yy),z(zz){}
    int x; int y; int z;
};

list<block> todo[2];
list<block>::iterator itr;

int main()
{
    while(scanf("%s", buff) != EOF)
    {
        todo[0].clear();
        todo[1].clear();
        scanf("%d", &N);
        scanf("%c", &buff[0]);
        for(k = 0; k < N; ++ k)
        {
            for(j = 0; j < N; ++ j)
            {
                for(i = 0; i < N; ++ i)
                    scanf("%c", &space[i][j][k]);
                scanf("%c", &buff[0]);
            }
        }
        scanf("%d%d%d", &x, &y, &z);
        space[x][y][z] = 0;
        todo[0].push_back(block(x, y, z));
        scanf("%d%d%d", &x, &y, &z);
        space[x][y][z] = 1;
        todo[1].push_back(block(x, y, z));
        scanf("%c", &buff[0]);
        scanf("%s", buff);
        if(todo[0].begin() -> x == x && todo[0].begin() -> y == y &&
           todo[0].begin() -> z == z)
        {
            printf("%d 0\n", N);
            continue;
        }
        ans = 0;
        for(;;)
        {
            if(todo[0].empty() || todo[1].empty())
            {
                ans = -1;
                break;
            }
            ++ ans;
            for(k = 0; k < 2; ++ k)
            {
                size = todo[k].size();
                for(itr = todo[k].begin(); size > 0; -- size, ++ itr)
                {
                    for(j = 0; j < 6; ++ j)
                    {
                        x = itr -> x + move[j][0];
                        y = itr -> y + move[j][1];
                        z = itr -> z + move[j][2];
                        if(x >= 0 && x < N && y >= 0 && y < N && z >= 0 && z < N)
                        {
                            if(space[x][y][z] == 1 - k) // got
                            {
                                if(k == 0) ans = (ans - 1) * 2 + 1;
                                else       ans = ans * 2;
                                goto DONE;
                            }
                            else if(space[x][y][z] == 'O')
                            {
                                space[x][y][z] = k;
                                todo[k].push_back(block(x, y, z));
                            }
                        }
                    }
                }
                todo[k].erase(todo[k].begin(), itr);
            }
        }
        DONE :
        if(ans == -1) printf("NO ROUTE\n");
        else          printf("%d %d\n", N, ans);
    }
    return 0;
}