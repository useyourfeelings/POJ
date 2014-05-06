#include<iostream>
#include<list>
#include<set>
using namespace std;

int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char map[6][6];           //           0
set<int> cango[6][6];     //         3   1
int wall[3][4];           //           2

int main()
{
    int sx, sy, ex, ey, i, j, r, c, rr, cc;
    list<int>::iterator listitr;
    set<int>::iterator setitr;
    while(scanf("%d%d", &sx, &sy) && sx != 0 && sy != 0)
    {
        for(i = 0; i < 6; ++ i)
            for(j = 0; j < 6; ++ j)
            {
                cango[i][j].insert(0);
                cango[i][j].insert(1);
                cango[i][j].insert(2);
                cango[i][j].insert(3);
            }
        for(i = 0; i < 6; ++ i)
        {
            cango[0][i].erase(0);
            cango[5][i].erase(2);
            cango[i][0].erase(3);
            cango[i][5].erase(1);
        }
        scanf("%d%d", &ex, &ey);
        for(i = 0; i < 3; ++ i)
            for(j = 0; j < 4; ++ j) scanf("%d", &wall[i][j]);
        for(i = 0; i < 3; ++ i)
        {
            if(wall[i][0] == wall[i][2])  // vertical
            {
                if(wall[i][0] != 0 && wall[i][0] != 6)
                {
                    for(j = min(wall[i][1], wall[i][3]);
                        j < max(wall[i][1], wall[i][3]); ++ j)
                    {
                        cango[j][wall[i][0] - 1].erase(1);
                        cango[j][wall[i][0]].erase(3);
                    }
                }
            }
            else                 //   horizontal
            {
                if(wall[i][1] != 0 && wall[i][1] != 6)
                {
                    for(j = min(wall[i][0], wall[i][2]);
                        j < max(wall[i][0], wall[i][2]); ++ j)
                    {
                        cango[wall[i][1] - 1][j].erase(2);
                        cango[wall[i][1]][j].erase(0);
                    }
                }
            }
        }
        for(i = 0; i < 6; ++ i)
            for(j = 0; j < 6; ++ j) map[i][j] = '#';
        map[ey - 1][ex - 1] = 'G';
        list<int> head;
        head.push_back((ey - 1) * 10 + ex - 1);
        for(;;)
        {
            listitr = head.begin();
            for(i = 0; i < head.size(); ++ i, ++ listitr)
            {
                rr = *listitr / 10;
                cc = *listitr % 10;
                for(setitr = cango[rr][cc].begin();
                    setitr != cango[rr][cc].end(); ++ setitr)
                {
                    r = rr + move[*setitr][0];
                    c = cc + move[*setitr][1];
                    if(map[r][c] == '#')
                    {
                        map[r][c] = char(*setitr + 48);
                        if(r == sy - 1 && c == sx - 1) goto DONE;
                        head.push_back(r * 10 + c);
                    }
                }
            }
            head.erase(head.begin(), listitr);
        }
        DONE :
        while(map[r][c] != 'G')
        {
            if(map[r][c] == '0')
            {
                printf("S");
                ++ r;
            }
            else if(map[r][c] == '1')
            {
                printf("W");
                -- c;
            }
            else if(map[r][c] == '2')
            {
                printf("N");
                -- r;
            }
            else
            {
                printf("E");
                ++ c;
            }
        }
        printf("\n");
    }
    return 0;
}