#include<iostream>
using namespace std;

char a[101];
char b[101];
char rec[101][101];
char how[101][101];
int lena, lenb;

int calc(int pa, int pb)
{
    if(pa < 0 || pb < 0) return 0;
    if(rec[pa][pb] != -1) return rec[pa][pb];
    int f, g;
    if(a[pa] == b[pb])
    {
        how[pa][pb] = '|';
        f = 1 + calc(pa - 1, pb - 1);
        rec[pa][pb] = f;
        return f;
    }
    f = calc(pa, pb - 1);
    g = calc(pa - 1, pb);
    how[pa][pb] = '/';
    if(f < g)
    {
        f = g;
        how[pa][pb] = '\\';
    }
    rec[pa][pb] = f;
    return f;
}

void build(int pa, int pb)
{
    if(pa < 0 || pb < 0) return;
    if(how[pa][pb] == '|')
    {
        a[pa] -= 32;
        b[pb] -= 32;
        build(pa - 1, pb - 1);
    }
    else if(how[pa][pb] == '\\') build(pa - 1, pb);
    else                         build(pa, pb - 1);
}

void print()
{
    int i = 0, j = 0;
    for(;;)
    {
        for(;; ++ i)
        {
            if(i == lena)
            {
                i = -1;
                break;
            }
            if(a[i] >= 'a') printf("%c", a[i]);
            else break;
        }
        for(;; ++ j)
        {
            if(j == lenb)
            {
                j = -1;
                break;
            }
            if(b[j] >= 'a') printf("%c", b[j]);
            else break;
        }
        if(i >= 0)
        {
            printf("%c", a[i] + 32);
            ++ i;
            ++ j;
        }
        else
        {
            if(j == -1) break;
        }
    }
    printf("\n");
}

int main()
{
    int i, j;
    while(scanf("%s", &a) != EOF)
    {
        scanf("%s", &b);
        lena = strlen(a);
        lenb = strlen(b);
        for(i = lena - 1; i >= 0; -- i)
            for(j = lenb - 1; j >= 0; -- j) rec[i][j] = -1;
        calc(lena - 1, lenb - 1);
        build(lena - 1, lenb - 1);
        print();
    }
    return 0;
}