#include<iostream>
#include<vector>
#include<string>
using namespace std;

char text[1000000];
int n, i, nc, len, total = 0, HASH = 99991;
vector<vector<string> > table(HASH);

int hashc(int pos)
{
    unsigned int h = 0, end = pos + n;
    
    for(; pos < end ; ++ pos) 
    {
        h = h * nc + text[pos];
    }

    return h % HASH;
}

void doit(int pos)
{
    int h = hashc(pos);

    if(table[h].empty()) // not found
    {
        ++ total;
        table[h].push_back(string(text + pos, text + pos + n));
    }
    else
    {
        int i;
        string temp = string(text + pos, text + pos + n);
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
        doit(i);
    }
    printf("%d\n", total);
    return 0;
}