#include<iostream>
using namespace std;

char END[] = "end";
char word[21];
bool isvow[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
                  0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

int main()
{
    int i, len, vow, con, havevow;
    while(scanf("%s", word) && strcmp(word, END) != 0)
    {
        havevow = con = vow = 0;
        len = strlen(word);
        if(isvow[word[0] - 97])
        {
            vow = 1;
            havevow = 1;
        }
        else con = 1;
        for(i = 1; i < len; ++ i)
        {
            if(word[i] == word[i - 1]) break;
            if(isvow[word[i] - 97])
            {
                havevow = 1;
                if(++ vow >= 3) break;
                con = 0;
            }
            else
            {
                if(++ con >= 3) break;
                vow = 0;
            }
        }
        if(i >= len && havevow) printf("<%s> is acceptable.\n", word);
        else printf("<%s> is not acceptable.\n", word);
    }
    return 0;
}