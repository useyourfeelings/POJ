#include<iostream>
#include<vector>
#include<string>
using namespace std；

char text[1000000];
int n, i, nc, len, total = 0, HASH = 160000;
vector<vector<string> > table(HASH);

int hash(char *txt)
{
    register int h = 0; 

    for(int i = 0; i < n ; ++ txt, ++ i) 
        h = 31 * h + *txt; 

    return h % HASH; 
}

void doit(char *txt)
{
    int h = hash(txt);

    if(table[h].empty()) // not found
    {
        ++ total;
        table[h].push_back(string(txt, txt + n));
    }
    else
    {
        int i;
        string temp = string(txt, txt + n);
        for(i = table[h].size() - 1; i >= 0; -- i)
            if(table[h][i] == temp) break;

        if(i < 0)// not found
        {
            ++ total;
            table[h].push_back(temp);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &nc);
    scanf("%c", &text[0]);
    scanf("%s", &text);
    len = strlen(text);
    for(i = 0; i <= len - n; ++ i)
    {
        doit(text + i);
    }
    printf("%d\n", total);
    return 0;
}