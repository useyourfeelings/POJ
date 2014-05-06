#include<iostream>
using namespace std;

int a[26], b[26];

int main()
{
    int i, j;
    char t;
    for(;;)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        while(scanf("%c", &t) && t != '\n') ++ a[t - 97];
        while(scanf("%c", &t) && t != '\n' && t != EOF) ++ b[t - 97];
        for(i = 0; i < 26; ++ i)
            for(j = 0; j < min(a[i], b[i]); ++ j) printf("%c", i + 97);
        printf("\n");
        if(t == EOF) return 0;
    }
}