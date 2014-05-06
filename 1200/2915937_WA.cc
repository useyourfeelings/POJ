#include<iostream>
#include<vector>
using namespace std;

char text[160000000];
int n, i, nc, len, total = 0, HASH = 99991;
vector<vector<int> > table(HASH);

int hashc(int pos)
{
    unsigned int h = 0, end = pos + n, pro = 1;
    
    for(; pos < end ; ++ pos) 
    {
        h += text[pos] * pro;
        
        pro *= nc;
    }

    return h % HASH;
}

void doit(int pos)
{
    int h = hashc(pos);

    if(table[h].empty()) // not found
    {
        ++ total;
        table[h].push_back(pos);
    }
    else
    {
        int i, j, end, p;
        for(i = table[h].size() - 1; i >= 0; -- i)
        {
            j = table[h][i];
            end = j + n;
            p = pos;
            for(; j < end; ++ j, ++ p)
            {
                if(text[j] != text[p]) break;
            }
            if(j < end) // not found
            {
                ++ total;
                table[h].push_back(pos);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &nc);
    scanf("%c", &text[0]);
    scanf("%s", &text);
    len = strlen(text);
    for(i = 0; i < len; ++ i) text[i] -= 97;
    for(i = 0; i <= len - n; ++ i)
    {
        doit(i);
    }
    printf("%d\n", total);
    return 0;
}