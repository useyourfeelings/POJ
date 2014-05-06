#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

char ctoi[] = "22233344115566070778889990";
             //abcdefghijklmnopqrstuvwxyz
char PN[101]; // phone number
char word[51];
char code[51];
map<string, string> dic;
map<string, string>::const_iterator itr;
char MatchInRange[101][101];
int n, i, j, len;
int best[101];
char cut[101];

int make(int begin)
{
    if(best[begin] != -2) return best[begin];
    if(begin >= len) return 0; // -1 means no match , 0 means can match but...
    int i, min = 200, t, gap;
    for(i = begin; i < len; ++ i)
    {
        if(MatchInRange[begin][i])
        {
            if((t = make(i + 1)) != -1)
            {
                if(++ t < min)
                {
                    gap = i;
                    min = t;
                }
            }
        }
    }
    if(min == 200) return -1;
    best[begin] = min;
    cut[begin] = gap;
    return min;
}

void display()
{
    int i, j;
    for(i = 0;;)
    {
        j = cut[i];
        cout<<dic.find(string(PN + i, PN + j + 1)) -> second<<" ";
        if(j == len - 1) break;
        i = j + 1;
    }
}

int main()
{
    scanf("%s%d", PN, &n);
    len = strlen(PN);
    for(i = 0; i < len; ++ i) best[i] = -2;
    for(i = 0; i < len; ++ i) cut[i] = 0;
    while(n --)
    {
        scanf("%s", word);
        for(i = 0; i < strlen(word); ++ i) code[i] = ctoi[word[i] - 97];
        code[i] = '\0';
        dic.insert(make_pair(code, word));
    }
    for(i = 0; i < len; ++ i)
    {
        for(j = i; j < len; ++ j)
        {
            if((itr = dic.find(string(PN + i, PN + j + 1))) != dic.end())
                MatchInRange[i][j] = 1;
        }
    }
    if(make(0) == -1) printf("No solution.");
    else              display();
    return 0;
}