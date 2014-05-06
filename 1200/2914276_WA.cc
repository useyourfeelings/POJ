#include<iostream>
using namespace std;

char text[10000000];
int n, i, nc, len, total = 0;
char table[160000000];

int hashc(int pos)
{
    unsigned int h = 0, end = pos + n;
    
    for(; pos < end ; ++ pos) 
    {
        h = h * nc + text[pos];
    }

    return h;
}

void doit(int pos)
{
    int h = hashc(pos);

    if(table[h] == 0)
    {
        ++ total;
        table[h] = 1;
    }
}

int main()
{
    scanf("%d%d", &n, &nc);
    scanf("%c", &text[0]);
    scanf("%s", &text);
    len = strlen(text);
    for(i = 0; i < len; ++ i) text[i] -= 97;
    for(i = 0; i <= len - n; ++ i)
    {
        doit(i);
    }
    printf("%d\n", total);
    return 0;
}