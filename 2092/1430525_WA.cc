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
            if(man[m] > fv)
            {
                sv = fv;
                fv = man[m];
            }
            else if(sv < man[m] && man[m] < fv) sv = man[m];
        }
        for(i = 0; i < 10001; ++ i) if(man[i] == sv) printf("%d ", i);
        printf("\n");
    }
    return 0;
}