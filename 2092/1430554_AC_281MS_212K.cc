#include<iostream>
using namespace std;

int main()
{
    int man[10001], i, n, m, fv, sv;
    while(scanf("%d%d", &n, &m) && n != 0)
    {
        n *= m;
        fv = sv = -1;
        memset(man, 0, sizeof(man));
        for(i = 0; i < n; ++ i)
        {
            scanf("%d", &m);
            ++ man[m];
        }
        for(i = 0; i < 10001; ++ i)
            if(man[i] > fv)
            {
                sv = fv;
                fv = man[i];
            }
            else if(sv < man[i] && man[i] < fv) sv = man[i];
        for(i = 0; i < 10001; ++ i) if(man[i] == sv) printf("%d ", i);
        printf("\n");
    }
    return 0;
}