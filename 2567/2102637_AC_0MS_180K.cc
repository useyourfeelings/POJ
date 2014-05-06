#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
    int i, who, max, pre, flag;
    char t;
    for(max = -1;; max = -1)
    {
        if(scanf("%c", &t) == EOF) break;
        vector<set<int> > vsi(52);
        vector<int> stack;
        for(flag = 1;;)
        {
            if(flag)
            {
                scanf("%d", &who);
                if(who > max) max = who;
                if(!stack.empty())
                {
                    pre = stack.back();
                    vsi[who].insert(pre);
                    vsi[pre].insert(who);
                }
                stack.push_back(who);
                flag = 0;
            }
            else
            {
                scanf("%c", &t);
                if(t == '\n') break;
                if(t == ' ') continue;
                else if(t == '(')
                {
                    flag = 1;
                    continue;
                }
                else if(t == ')')
                {
                    if(!stack.empty()) stack.pop_back();
                }
            }
            
        }
        vector<int> done(max + 1, 0);
        for(i = 1; i < max; ++ i)
        {
            for(who = 1; who <= max; ++ who)
                if(!done[who] && vsi[who].size() == 1)
                    break;
            done[who] = 1;
            pre = *vsi[who].begin();
            printf("%d ", pre);
            vsi[pre].erase(who);
        }
        printf("\n", who);
    }
    return 0;
}