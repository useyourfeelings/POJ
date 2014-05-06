#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int pal[6], i, w, h;
    for(i = 0; i < 6; ++ i)
    {
        scanf("%d%d", &w, &h);
        if(w <= h) pal[i] = 100000 * w + h;
        else pal[i] = 100000 * h + w;
    }
    sort(pal, pal + 6);
    for(i = 0; i < 6; i += 2) if(pal[i] != pal[i + 1]) break;
    if(i == 6) printf("POSSIBLE");
    else printf("IMPOSSIBLE");
    return 0;
}