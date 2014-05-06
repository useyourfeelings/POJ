#include<iostream>
#include<vector>
#include<string>
using namespace std;

char text[100000000];
int n, i, nc, len, total = 0, HASH = 160000;
vector<vector<string> > table(HASH);

unsigned int hasha(char*key){
     unsigned long h=0;
     for(int i = 0; i < n; ++ i){
        h=(h<<4)+*key++;
        unsigned long g=h&0xf0000000L;
        if(g)h^=g>>24;
         h&=~g;
     }
     return h % HASH;
 }

void doit(char *txt)
{
    int h = hasha(txt);

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