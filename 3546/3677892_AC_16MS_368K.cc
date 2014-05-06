#include<iostream>
using namespace std;

char map[10][11];
int num[5], fit[] = {0, 4, 3, 2, 1};
int pattern[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int diag[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int main()
{
    int i, j, k, p, q, pp, qq, iscorrect = 0, dir, size;
    for(i = 0; i < 10; ++ i)
        scanf("%s", map[i]);
    for(i = 0; i < 10; ++ i)
        if(map[0][i] == '1') goto over;
    for(i = 0; i < 10; ++ i)
        if(map[9][i] == '1') goto over;
    for(i = 0; i < 10; ++ i)
        if(map[i][0] == '1') goto over;
    for(i = 0; i < 10; ++ i)
        if(map[i][9] == '1') goto over;
    for(i = 0; i < 10; ++ i)
    {
        for(j = 0; j < 10; ++ j)
        {
            if(map[i][j] == '2') continue;
            if(map[i][j] == '1')
            {
                dir = -1;
                for(k = 0; k < 4; ++ k)
                {
                    p = i + pattern[k][0];
                    q = j + pattern[k][1];
                    if(map[p][q] == '1')
                    {
                        if(dir != -1) goto over;
                        dir = k;
                    }
                } // end for      got dir
                p = i;
                q = j;
                for(size = 0;;)
                {
                    if(map[p][q] != '1') break;
                    ++ size;
                    for(k = 0; k < 4; ++ k) // diag
                    {
                        pp = p + diag[k][0];
                        qq = q + diag[k][1];
                        if(map[pp][qq] != '.') goto over;
                    }
                    map[p][q] = '2';
                    p += pattern[dir][0];
                    q += pattern[dir][1];
                }
                if(size > 4) goto over;
                if(++ num[size] > fit[size]) goto over;
            }
        }
    }
    if(i != 10 || j != 10) goto over;
    for(i = 1; i <= 4; ++ i) if(num[i] != fit[i]) goto over;
    iscorrect = 1;
    over:
    if(iscorrect) printf("correct\n");
    else          printf("incorrect\n");
    return 0;
}