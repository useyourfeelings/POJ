#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

struct pp
{
    pp(char *s):party(s),poll(0){}
    string party;
    int poll;
};

int main()
{
    int i, j, n, maxp;
    char name[82], party[82];
    scanf("%d\n", &n);
    map<string, pp> spm;
    for(i = 0; i < n; ++ i)
    {
        gets(name);
        gets(party);
        spm.insert(make_pair(name, pp(party)));
    }
    scanf("%d\n", &n);
    for(i = 0; i < n; ++ i)
    {
        gets(name);
        map<string, pp>::iterator itr = spm.find(name);
        if(itr != spm.end())
            ++ (itr -> second.poll);
    }
    vector<pp> ppv;
    map<string, pp>::iterator itr = spm.begin();
    for(maxp = -1; itr != spm.end(); ++ itr)
    {
        if(itr -> second.poll >= maxp)
        {
            ppv.push_back(itr -> second);
            maxp = itr -> second.poll;
        }
    }
    
    if(ppv.size() == 1) cout<<ppv[0].party;
    else
    {
        if(ppv[ppv.size() - 1].poll == ppv[ppv.size() - 2].poll)
            cout<<"tie";
        else cout<<ppv[ppv.size() - 1].party;
    }
    return 0;
}