#include<iostream>
using namespace std;

struct block
{
    block(){}
    block(int xx, int yy, int zz):x(xx),y(yy),z(zz){}
    int x; int y; int z;
};

block queue[1000000];
int start, end, newend, x, y, z, out, hole, a, b, c, aa, bb, cc;
char space[102][102][102];
int move[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0},
                  {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};

void bfs()
{
    out = 0;
    start = 0;
    end = 1;
    queue[0].x = x; queue[0].y = y; queue[0].z = z; //  push to queue
    space[x][y][z] = 1;                             //  fill
    while(start != end)
    {
        newend = end;
        for(; start < end; ++ start)
        {
            aa = queue[start].x;
            bb = queue[start].y;
            cc = queue[start].z;
            for(int i = 0; i < 6; ++ i)
            {
                a = aa + move[i][0];
                b = bb + move[i][1];
                c = cc + move[i][2];
                if(a < 1 || b < 1 || c < 1 || a > 100 || b > 100 || c > 100)// out
                    out = 1;
                else if(space[a][b][c] == 0)
                {
                    space[a][b][c] = 1;    // fill before push
                    queue[newend].x = a;   // push to queue
                    queue[newend].y = b;
                    queue[newend].z = c;
                    ++ newend;
                }
            }
        }
        end = newend;
    }
    if(!out) ++ hole;
}

int main()
{
    int test, num;
    scanf("%d", &test);
    while(test --)
    {
        for(x = 1; x < 101; ++ x)
            for(y = 1; y < 101; ++ y)
                for(z = 1; z < 101; ++ z) space[x][y][z] = 0;
        scanf("%d", &num);
        for(; num > 0; -- num)
        {
            scanf("%d%d%d", &x, &y, &z);
            space[x][y][z] = 1;
        }
        hole = 0;
        for(x = 1; x <= 100; ++ x)
            for(y = 1; y <= 100; ++ y)
                for(z = 1; z <= 100; ++ z)
                    if(space[x][y][z] == 0)
                        bfs();
        printf("%d\n", hole);
    }
    return 0;
}