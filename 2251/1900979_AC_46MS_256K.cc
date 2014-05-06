#include<iostream>
#include<list>
using namespace std;

int i, j, k, X, Y, Z, x, y, z, ans, size;
char space[30][30][30];// x y z
int move[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};

struct block
{
    block(int xx, int yy, int zz):x(xx),y(yy),z(zz){}
    int x; int y; int z;
};

list<block> todo[2];
list<block>::iterator itr;

int main()
{
    char t;
    while(scanf("%d%d%d", &Z, &Y, &X) && Z != 0)
    {
        todo[0].clear();
        todo[1].clear();
        scanf("%c", &t);
        for(k = 0; k < Z; ++ k)
        {
            for(j = 0; j < Y; ++ j)
            {
                for(i = 0; i < X; ++ i)
                {
                    scanf("%c", &space[i][j][k]);
                    if(space[i][j][k] == 'S')
                    {
                        space[i][j][k] = 0;
                        todo[0].push_back(block(i, j, k));
                    }
                    else if(space[i][j][k] == 'E')
                    {
                        space[i][j][k] = 1;
                        todo[1].push_back(block(i, j, k));
                    }
                }
                scanf("%c", &t);
            }
            scanf("%c", &t);
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
                        if(x >= 0 && x < X && y >= 0 && y < Y && z >= 0 && z < Z)
                        {
                            if(space[x][y][z] == 1 - k) // got
                            {
                                if(k == 0) ans = (ans - 1) * 2 + 1;
                                else       ans = ans * 2;
                                goto DONE;
                            }
                            else if(space[x][y][z] == '.')
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
        if(ans == -1) printf("Trapped!\n");
        else          printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}