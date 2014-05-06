#include<iostream>
using namespace std;

int main()
{
    int pal[6][2], i, w, h;
    for(i = 0; i < 6; ++ i)
    {
        scanf("%d%d", &w, &h);
        if(w <= h) {pal[i][0] = w * 10; pal[i][1] = h;}
        else {pal[i][0] = h * 10; pal[i][1] = w;}
    }
    for(i = 0; i < 6; ++ i)
    {
        if(pal[i][0] % 10 != 1)
        {
            for(h = 0; h < 6; ++ h)
            {
                if(h != i && pal[h][0] % 10 != 1)
                {
                    if(pal[i][0] == pal[h][0] && pal[i][1] == pal[h][1])
                    {
                        ++ pal[i][0];
                        ++ pal[h][0];
                        break;
                    }
                }
            }
            if(h == 6) break;
        }
    }
    if(h == 6) printf("IMPOSSIBLE");
    else printf("POSSIBLE");
    return 0;
}
