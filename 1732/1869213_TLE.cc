#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

char ctoi[] = "22233344115566070778889990";
             //abcdefghijklmnopqrstuvwxyz
char PN[101];
char word[51];
char code[51];
map<string, string> dic;
string MatchInRange[101][101];

int n, i, j, len;
int best[101];
int bestfrom[101];

int make(int end)
{
    if(best[end] != -2) return best[end];
    if(end < 0) return 0; // -1 means no match , 0 means can match but...
    int i, min = 200, t, gap;
    for(i = end; i >= 0; -- i)
    {
        if(!MatchInRange[i][end].empty())
        {
            if((t = make(i - 1)) != -1)
            {
                if((++ t) < min)
                {
                    gap = i;
                    min = t;
                }
            }
        }
    }
    if(min == 200) return -1;
    best[end] = min;
    bestfrom[end] = gap;
    return min;
}

int main()
{
    scanf("%s%d", PN, &n);
    len = strlen(PN);
    for(i = 0; i < len; ++ i) best[i] = -2;
    while(n --)
    {
        scanf("%s", word);
        for(i = 0; i < strlen(word); ++ i) code[i] = ctoi[int(word[i]) - 97];
        code[i] = '\0';
        dic.insert(make_pair(code, word));
    }
    for(i = 0; i < len; ++ i)
    {
        for(j = i; j < len; ++ j)
        {
            string temp(PN + i, PN + j + 1);
            map<string, string>::const_iterator itr;
            if((itr = dic.find(temp)) != dic.end())
                MatchInRange[i][j] = temp;
        }
    }
    if(make(len - 1) == -1) printf("No solution.");
    else
    {
        vector<string> ans;
        for(j = len - 1; ;)
        {
            i = bestfrom[j];
            ans.push_back(dic.find(string(PN + i, PN + j + 1)) -> second);
            if(i == 0) break;
            j = i - 1;
        }
        cout<<ans[ans.size() - 1];
        for(i = ans.size() - 2; i >= 0; -- i) cout<<" "<<ans[i];
    }
    return 0;
}