#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;
int main()
{   
    int p, t, a, b, count = 0;
    scanf("%d%d", &p, &t);
    vector<list<int> > vsi(p + 1);
    while(scanf("%d%d", &a, &b) != EOF) vsi[a].push_back(b);
    for(int i = 1; i <= p; i++)
    {
        vsi[i].sort();
        vsi[i].unique();
    }
    set<list<int> > s;
    for(int i = 1; i <= p; i++)
    {
        if(s.find(vsi[i]) == s.end())
        {
            s.insert(vsi[i]);
            ++ count;
        }
    }
    printf("%d", count);
    return 0;
}