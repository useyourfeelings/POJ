#include<iostream>
using namespace std;

int a[26], b[26];
char sa[1002], sb[1002];

int main()
{
    int i, j;
    char t;
    while(gets(sa) != 0)
    {
        gets(sb);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(i = 0; i < strlen(sa); ++ i) ++ a[sa[i] - 97];
        for(i = 0; i < strlen(sb); ++ i) ++ b[sb[i] - 97];
        for(i = 0; i < 26; ++ i)
            for(j = 0; j < min(a[i], b[i]); ++ j) printf("%c", i + 97);
        printf("\n");
    }
}