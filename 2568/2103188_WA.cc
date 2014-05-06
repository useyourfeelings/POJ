#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > vvi(52);

void display(int now)
{
    printf("(%d", now);
    for(int i = vvi[now].size() - 1; i >= 0 ; -- i)
    {
        printf(" ");
        display(vvi[now][i]);
    }
    printf(")", now);
}

int main()
{
    int i, j, who, max;
    char t;
    vector<int> code;
    code.reserve(51);
    for(;;)
    {
        if(scanf("%d", &who) == EOF) break;
        for(i = 0; i < 52; ++ i) vvi[i].resize(0);
        code.resize(0);
        code.push_back(who);
        max = who;
        for(;;)
        {
            scanf("%d%c", &who, &t);
            code.push_back(who);
            if(t == '\n') break;;
        }
        max = code.size() + 1;
        vector<int> done(max + 1, 0);
        for(i = 0; i < max - 1; ++ i)
        {
            for(who = 1; who < max; ++ who)
            {
                if(!done[who] && who != code[i])
                {
                    for(j = i + 1; j < max - 1; ++ j)
                        if(code[j] == who) break;
                    if(j >= max - 1) break; // ok
                }
            }
            done[who] = 1;
            vvi[code[i]].push_back(who);
        }
        display(max);
        printf("\n");
    }
    return 0;
}