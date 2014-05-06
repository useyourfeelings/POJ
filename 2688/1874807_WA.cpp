#include<iostream>
#include<list>
using namespace std;

char map[20][20];
int R, C;
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void CleanTheMess()
{
    int i, j;
    for(i = 0; i < R; ++ i)
        for(j = 0; j < C; ++ j)
            if(map[i][j] == '?') map[i][j] = '.';
}


int main()
{
    int i, j, r, c, dirt, step, total, rr, cc;
    list<int>::iterator listitr;
    char t;
    bool failed, found;
    while(scanf("%d%d", &C, &R) && R != 0)
    {
        scanf("%c", &map[0][0]);
        failed = false;
        list<int> head;
        dirt = total = 0;
        for(i = 0; i < R; ++ i)
        {
            for(j = 0; j < C; ++ j)
            {
                scanf("%c", &map[i][j]);
                if(map[i][j] == 'o')
                {
                    head.push_back(i * 100 + j);
                    map[i][j] = '?';
                }
                else if(map[i][j] == '*') ++ dirt;
            }
            scanf("%c", &t);
        }
        for(;;) //   seach all dirt
        {
            if(dirt == 0) break;
            if(failed) break;
            found = false;
            step = 0;
            for(;;)  //    search a dirt
            {
                if(head.empty())
                {
                    failed = true; //  no dirt found, 
                    break;         //  because the robot can't reach it
                }
                ++ step;
                listitr = head.begin();
                for(i = head.size() - 1; i >= 0; -- i, ++ listitr)
                {
                    r = *listitr / 100;
                    c = *listitr % 100;
                    for(j = 0; j < 4; ++ j)
                    {
                        rr = r + move[j][0];
                        cc = c + move[j][1];
                        if(rr < 0 || rr >= R || cc < 0 || cc >= C) continue;
                        if(map[rr][cc] == '*') // found a dirt
                        {
                            total += step;
                            -- dirt;
                            head.clear();
                            head.push_back(rr * 100 + cc);
                            found = true;
                            CleanTheMess();
                            map[rr][cc] = '?';
                            break;
                        }
                        else if(map[rr][cc] == '.') // clean tile
                        {
                            map[rr][cc] = '?';
                            head.push_back(rr * 100 + cc);
                        }
                        //   else it's an obstacle or have been there
                    }
                    if(found) break;
                }
                if(!found) head.erase(head.begin(), listitr);
                else break;//  if found a dirt, break to seacher another
            } // end search a dirt
        } // end search all dirt
        if(failed) printf("-1\n");
        else       printf("%d\n", total);
    }
    return 0;
}