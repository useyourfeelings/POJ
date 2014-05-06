#include<iostream>
#include<set>
#include<string>
using namespace std;

char txt[100000];

int main()
{
    int n, i, nc, len, total = 0;
    scanf("%d%d", &n, &nc);
    scanf("%c", &txt[0]);
    scanf("%s", &txt);
    len = strlen(txt);
    set<string> dic;
    for(i = 0; i <= len - n; ++ i)
    {
        if(dic.find(string(txt + i, txt + i + n)) == dic.end())
        {
            dic.insert(string(txt + i, txt + i + n));
            ++ total;
        }
    }
    printf("%d\n", total);
    return 0;
}