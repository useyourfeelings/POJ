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
vector<string> ans;

int n, i, j, len;
string temp;
int best[101];

int make(int end)
{
    if(best[end] != -2) return best[end];
    if(end < 0) return 0; // -1 means no match , 0 means can match but...
    int i, min = 200, t;
    string str;
    for(i = end; i >= 0; -- i)
    {
        if(!MatchInRange[i][end].empty())
        {
            if((t = make(i - 1)) != -1)
            {
                if((++ t) < min)
                {
                    min = t;
                    str = dic.find(MatchInRange[i][end])->second;
                }
            }
        }
    }
    if(min == 200) return -1;
    best[end] = min;
    ans.push_back(str);
    return min;
}

int main()
{
    scanf("%s%d", PN, &n);
    scanf("%s", word);
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
    make(len - 1);
    if(ans.empty()) printf("No solution.");
    else
    {
        cout<<ans[0];
        for(i = 1; i < ans.size(); ++ i) cout<<" "<<ans[i];
    }
    return 0;
}