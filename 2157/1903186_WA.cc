#include<iostream>
#include<list>
using namespace std;

struct pos
{
    pos(int rr, int cc):r(rr),c(cc){}
    int r;
    int c;
};

char map[20][20];
int R, C, i, j, size, a, b, r, c;
char t;
int KeyRemain[5];
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
list<pos>::iterator itr;

int main()
{
    while(scanf("%d%d", &R, &C) && R != 0)
    {
        scanf("%c", &t);
        list<pos> door[5];
        list<pos> todo;
        for(i = 0; i < 5; ++ i) KeyRemain[i] = 0;
        for(i = 0; i < R; ++ i)
        {
            for(j = 0; j < C; ++ j)
            {
                scanf("%c", &t);
                map[i][j] = t;
                if ('a' <= t && t <= 'e') ++ KeyRemain[t - 97];
                else if(t == 'S')
                {
                    todo.push_back(pos(i, j));
                    map[i][j] = 'X';
                }
            }
            scanf("%c", &t);
        }
        for(;;)
        {
            if(todo.empty())
            {
                R = -1;
                break;
            }
            size = todo.size();
            for(itr = todo.begin(); size > 0; -- size, ++ itr)
            {
                r = itr -> r;
                c = itr -> c;
                if('A' <= map[r][c] && map[r][c] <= 'E')
                    map[r][c] = 'X';
                for(i = 0; i < 4; ++ i)
                {
                    a = r + move[i][0];
                    b = c + move[i][1];
                    if(a >= 0 && a < R && b >= 0 && b < C)
                    {
                        t = map[a][b];
                        if('A' <= t && t <= 'E')
                        {
                            door[t - 65].push_back(pos(a, b));
                        }
                        if('a' <= t && t <= 'e')
                        {
                            -- KeyRemain[t - 97];
                            map[a][b] = 'X';
                            todo.push_back(pos(a, b));
                        }
                        else if(t == 'G') goto DONE;
                        else if(t == '.')
                        {
                            map[a][b] = 'X';
                            todo.push_back(pos(a, b));
                        }
                    }
                }
            }
            todo.erase(todo.begin(), itr);
            for(i = 0; i < 5; ++ i)
                if(KeyRemain[i] == 0) todo.splice(todo.end(), door[i]);
        }
        DONE :
        if(R == -1) printf("NO\n");
        else        printf("YES\n");
    }
    return 0;
}