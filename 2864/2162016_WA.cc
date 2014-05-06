#include<iostream>
using namespace std;
char gg[100][1001];
int main()
{
    int i, j, N, D;
    while(scanf("%d%d", &N, &D) && N != 0 && D != 0)
    {
        for(i = 0; i < D; ++ i)
        {
            gets(gg[i]);
            printf("%s", gg[i]);
        }
        for(i = 0; i < D; ++ i)
        {
            for(j = N * 2 - 2; j >= 0; -- j)
                if(gg[i][j] == '0') break;
            if(j < 0) break;
        }
        if(i < D) printf("yes\n");
        else      printf("no\n");
    }
    return 0;
}