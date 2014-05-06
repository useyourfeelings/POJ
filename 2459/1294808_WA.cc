#include<iostream>
using namespace std;

int con[2001];

int main()
{
    int c, f1, f2, d, i, j, s, e;
    scanf("%d%d%d%d", &c, &f1, &f2, &d);
    memset(con, 0, sizeof(int) * (d + 1));
    con[0] = 1000001;
    for(i = 0; i < c; ++ i)
    {
        scanf("%d%d", &s, &e);
        for(j = s; j <= min(e, d); ++ j) ++ con[j];
    }
    f2 += con[d];
    if(f2 >= f1)
    {
        printf("%d", d);
        return 0;
    }
    for(;; -- d)
    {
        f2 += con[d - 1];
        if(f2 > f1) break;
    }
    printf("%d", d);
    return 0;
}