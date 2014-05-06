#include<iostream>
using namespace std;

char org[9][10];
char anti[8][9];
char op[10];
char end[] = "ENDOFINPUT";

int main()
{
    int R, C, i, j;
    while(scanf("%s", op) && strcmp(op, end) != 0)
    {
        scanf("%d%d", &R, &C);
        scanf("%c", &org[0][0]);
        for(i = 0; i < R; ++ i) scanf("%s", org[i]);
        for(i = 0; i < R; ++ i)
            for(j = 0; j < C; ++ j) org[i][j] -= 48;
        for(i = 0; i < R - 1; ++ i)
        {
            for(j = 0; j < C - 1; ++ j)
            {
                anti[i][j] = (org[i][j] + org[i + 1][j] +
                              org[i][j + 1] + org[i + 1][j + 1]) / 4 + 48;
            }
            anti[i][j] = 0;
        }
        for(i = 0; i < R - 1; ++ i) printf("%s\n", anti[i]);
        scanf("%s", op);
    }
    return 0;
}