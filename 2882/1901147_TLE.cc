#include<iostream>
#include<list>
using namespace std;

int i, m, t, hole, x, y, z, a, b, c, aa, bb, cc, ret, size;
char space[102][102][102];
int move[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0},
                  {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};

struct block
{
    block(int xx, int yy, int zz):x(xx),y(yy),z(zz){}
    int x; int y; int z;
};


list<block>::iterator itr;

int bfs()
{
    list<block> todo;
    todo.push_back(block(x, y, z));
    space[x][y][z] = 1;
    for(ret = 1; !todo.empty();)
    {
        size = todo.size();
        for(itr = todo.begin(); size > 0; -- size, ++ itr)
        {
            aa = itr -> x;
            bb = itr -> y;
            cc = itr -> z;
            space[aa][bb][cc] = 'X';
            for(i = 0; i < 6; ++ i)
            {
                a = aa + move[i][0];
                b = bb + move[i][1];
                c = cc + move[i][2];
                if(a == 0 || b == 0 || c == 0 || a == 101 || b == 101 || c == 101) ret = 0;
                else if(space[a][b][c] == 0)
                {
                    todo.push_back(block(a, b, c));
                    space[a][b][c] = 1;
                }
            }
        }
        todo.erase(todo.begin(), itr);
    }
    return ret;
}

int main()
{
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
            space[x][y][z] = 1;
        }
        hole = 0;
        for(x = 2; x < 100; ++ x)
            for(y = 2; y < 100; ++ y)
                for(z = 2; z < 100; ++ z)
                    if(space[x][y][z] == 0) hole += bfs();
        printf("%d\n", hole);
    }
    return 0;
}