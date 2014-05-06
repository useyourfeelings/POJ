#include<iostream>
char gg[500][201];
int main()
{
    int i, j, N, D;
    while(scanf("%d%d", &N, &D) && N != 0 && D != 0)
    {
        gets(gg[0]);
        for(i = 0; i < D; ++ i) gets(gg[i]);
        for(j = N * 2 - 2; j >= 0; -- j)
        {
            for(i = 0; i < D; ++ i)
                if(gg[i][j] == '0') break;
            if(i >= D) break;
        }
        if(j >= 0) printf("yes\n");
        else       printf("no\n");
    }
    return 0;
}
