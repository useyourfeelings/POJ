#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int man[10001], first[10001], second[10001], i, n, m, ftop, stop, fv, sv;
    bool flag;
    while(scanf("%d%d", &n, &m) && n != 0)
    {
        flag = 1;
        n *= m;
        ftop = stop = 0;
        fv = sv = -1;
        memset(man, 0, sizeof(man));
        for(i = 0; i < n; ++ i)
        {
            scanf("%d", &m);
            ++ man[m];
            if(man[m] > fv)
            {
                if(flag)
                {
                    flag = 0;
                    second[0] = m;
                    stop = ftop;
                    ftop = 1;
                    sv = fv;
                    fv = man[m];
                }
                else
                {
                    flag = 1;
                    first[0] = m;
                    stop = ftop;
                    ftop = 1;
                    sv = fv;
                    fv = man[m];
                }
            }
            else if(man[m] == fv)
            {
                if(flag) first[ftop ++] = m;
                else second[ftop ++] = m;
            }
            else if(man[m] > sv)
            {
                if(flag)
                {
                    second[0] = m;
                    stop = 1;
                    sv = man[m];
                }
                else
                {
                    first[0] = m;
                    stop = 1;
                    sv = man[m];
                }
            }
            else if(man[m] == sv)
            {
                if(flag) second[stop ++] = m;
                else first[stop ++] = m;
            }
        }
        if(flag)
        {
            sort(second, second + stop);
            for(i = 0; i < stop; ++ i) if(second[i] != first[0]) printf("%d ", second[i]);
            printf("\n");
        }
        else
        {
            sort(first, first + stop);
            for(i = 0; i < stop; ++ i) if(first[i] != second[0]) printf("%d ", first[i]);
            printf("\n");
        }
    }
    return 0;
}