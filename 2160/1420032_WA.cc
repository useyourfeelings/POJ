#include<iostream>
using namespace std;

int main()
{
    int pal[6], i, w, h;
    for(i = 0; i < 6; ++ i)
    {
        scanf("%d%d", &w, &h);
        if(w <= h) pal[i] = 1000000 * w + 10 * h;
        else pal[i] = 1000000 * h + 10 * w;
    }
    for(i = 0; i < 6; ++ i)
    {
        if(pal[i] % 10 != 1)
        {
            for(h = 0; h < 6; ++ h)
            {
                if(pal[i] == pal[h])
                {
                    ++ pal[i];
                    ++ pal[h];
                    break;
                }
            }
            if(h == 6) break;
        }
    }
    if(i < 6) printf("IMPOSSIBLE");
    else printf("POSSIBLE");
    return 0;
}