#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
    int i, who, max, min, pre;
    char t;
    for(max = -1;; max = -1)
    {
        if(scanf("%c", &t) == EOF) break;
        vector<set<int> > vsi(51);
        vector<int> stack;
        while(scanf("%c", &t) && t != '\n')
        {
            if(t == ' ' || t == '(') continue;
            else if(t == ')')
            {
                if(!stack.empty()) stack.pop_back();
            }
            else
            {
                who = int(t) - 48;
                if(who > max) max = who;
                if(!stack.empty())
                {
                    pre = stack.back();
                    vsi[who].insert(stack.back());
                    vsi[stack.back()].insert(who);
                }
                stack.push_back(who);
            }
        }
        vector<int> done(max + 1, 0);
        for(i = 1; i < max; ++ i)
        {
            min = 64;
            for(who = 1; who <= max; ++ who)
            {
                if(!done[who] && vsi[who].size() == 1)
                    break;
            }
            done[who] = 1;
            printf("%d ", *vsi[who].begin());
                vsi[*vsi[who].begin()].erase(who);
        }
        printf("\n");
    }
    return 0;
}
