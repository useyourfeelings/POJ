#include<iostream>
using namespace std;

int move[4][2] = {{10, 0}, {0, 10}, {-10, 0}, {0, -10}};

int main()
{
    int i, x, y, dir;
    char cmd;
    while(scanf("%c", &cmd) != EOF)
    {
        x = 310;
        y = 420;
        dir = 0;
        if(cmd == 'V') dir = (dir + 1) % 4;
        else           dir = (dir + 3) % 4;
        x += move[dir][0];
        y += move[dir][1];
        printf("300 420 moveto\n310 420 lineto\n%d %d lineto\n", x, y);
        while(scanf("%c", &cmd) && (cmd == 'A' || cmd == 'V'))
        {
            if(cmd == 'V') dir = (dir + 1) % 4;
            else           dir = (dir + 3) % 4;
            x += move[dir][0];
            y += move[dir][1];
            printf("%d %d lineto\n", x, y);
        }
        printf("stroke\nshowpage\n");
    }
    return 0;
}