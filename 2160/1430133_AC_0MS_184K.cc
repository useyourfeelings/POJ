#include<iostream>
using namespace std;

int main()
{
    char check[8][12] = {0, 0, 2, 0, 0, 1, 4, 1, 2, 1, 4, 0,
                         0, 0, 2, 0, 0, 1, 4, 0, 2, 1, 4, 1,
                         0, 0, 2, 1, 0, 1, 4, 1, 2, 0, 4, 0,
                         0, 0, 2, 1, 0, 1, 4, 0, 2, 0, 4, 1,
                         0, 0, 4, 0, 0, 1, 2, 1, 4, 1, 2, 0,
                         0, 0, 4, 0, 0, 1, 2, 0, 4, 1, 2, 1,
                         0, 0, 4, 1, 0, 1, 2, 1, 4, 0, 2, 0,
                         0, 0, 4, 1, 0, 1, 2, 0, 4, 0, 2, 1};
    int pal[6][2], i, w, h;
    for(i = 0; i < 6; ++ i)
    {
        scanf("%d%d", &w, &h);
        if(w <= h) {pal[i][0] = w; pal[i][1] = h;}
        else {pal[i][0] = h; pal[i][1] = w;}
    }
    for(i = 0; i < 6; i += 2)
    {
        for(h = i + 1; h < 6; ++ h)
        {
            if(pal[i][0] == pal[h][0] && pal[i][1] == pal[h][1])
            {
                swap(pal[i + 1][0], pal[h][0]);
                swap(pal[i + 1][1], pal[h][1]);
                break;
            }
        }
        if(h == 6)
        {
            printf("IMPOSSIBLE");
            return 0;
        }
    }
    for(i = 0; i < 8; ++ i)
    {
        if(pal[check[i][0]][check[i][1]] == pal[check[i][2]][check[i][3]] &&
           pal[check[i][4]][check[i][5]] == pal[check[i][6]][check[i][7]] &&
           pal[check[i][8]][check[i][9]] == pal[check[i][10]][check[i][11]]) break;
    }
    if(i < 8) printf("POSSIBLE");
    else printf("IMPOSSIBLE");
    return 0;
}