#include<iostream>
using namespace std;

char cipher[71];
char pcode[71];
int key, len, i;

int main()
{
    while(scanf("%d", &key) && key != 0)
    {
        scanf("%c%s", &cipher[0], cipher);
        len = strlen(cipher);
        for(i = 0; i < len; ++ i)
        {
            if     (cipher[i] == '_') cipher[i] = 0;
            else if(cipher[i] == '.') cipher[i] = 27;
            else                      cipher[i] = cipher[i] - 96;
        }
        for(i = 0; i < len; ++ i)
            pcode[(key * i) % len] = (i + cipher[i]) % 28;
        for(i = 0; i < len; ++ i)
        {
            if     (pcode[i] == 0)   pcode[i] = '_';
            else if(pcode[i] == 27)  pcode[i] = '.';
            else                     pcode[i] = pcode[i] + 96;
        }
        printf("%s\n", pcode);
    }
    return 0;
}