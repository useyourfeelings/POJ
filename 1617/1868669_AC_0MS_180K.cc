#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

char keyword[11];
char ciphertext[101];
char plaintext[101];

int main()
{
    int ColNo, Len, i, j, k;
    while(scanf("%s", keyword) && strcmp(keyword, "THEEND") != 0)
    {
        scanf("%s", ciphertext);
        ColNo = strlen(keyword);
        Len = strlen(ciphertext);
        string temp(keyword);
        sort(temp.begin(), temp.end());
        vector<bool> picked(ColNo, 0);
        for(i = 0; i < ColNo; ++ i)
        {
            for(j = 0; j < ColNo; ++ j)
            {
                if(temp[i] == keyword[j] && !picked[j])
                {
                    picked[j] = 1;
                    for(k = i * (Len / ColNo); j < Len; j += ColNo, ++ k)
                    {
                        plaintext[j] = ciphertext[k];
                    }
                    break;
                }
            }
        }
        plaintext[Len] = '\0';
        printf("%s\n", plaintext);
    }
    return 0;
}