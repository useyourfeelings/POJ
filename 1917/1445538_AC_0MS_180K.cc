#include<iostream>

char g[101], t[101];

int main()
{
    int i, s, f1, f2, f3, f4;
    scanf("%d", &s);
    getchar();
    while(s --)
    {
        gets(g);
        gets(t);
        for(i = 0; ; ++ i)
        {
            if(g[i] != '<') printf("%c", g[i]);
            else
            {
                f1 = ++ i;
                break;
            }
        }
        for(; ; ++ i)
        {
            if(g[i] != '>') printf("%c", g[i]);
            else
            {
                f2 = i ++;
                break;
            }
        }
        for(; ; ++ i)
        {
            if(g[i] != '<') printf("%c", g[i]);
            else
            {
                f3 = ++ i;
                break;
            }
        }
        for(; ; ++ i)
        {
            if(g[i] != '>') printf("%c", g[i]);
            else
            {
                f4 = i ++;
                break;
            }
        }
        for(; i < strlen(g); ++ i) printf("%c", g[i]);
        printf("\n");
        t[strlen(t) - 3] = 0;
        printf("%s", t);
        for(i = f3; i < f4; ++ i) printf("%c", g[i]);
        for(i = f2 + 1; i < f3 - 1; ++ i) printf("%c", g[i]);
        for(i = f1; i < f2; ++ i) printf("%c", g[i]);
        for(i = f4 + 1; i < strlen(g); ++ i) printf("%c", g[i]);
        printf("\n");
    }
    return 0;
}