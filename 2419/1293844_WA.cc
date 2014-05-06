#include<iostream>
#include<vector>
#include<list>
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
    count = p;
    for(int i = 1; i < p; i++)
    {
        int size = vsi[i].size();
        for(int j = i + 1; j <= p; j++)
        {
            if(size != vsi[j].size()) continue;
            else
            {
                list<int>::iterator itri, itrj, end = vsi[i].end();
                for(itri = vsi[i].begin(), itrj = vsi[j].begin();
                                itri != end; ++itri, ++itrj)
                    if(*itri != *itrj) break;
                if(itri == end) -- count;
            }
        }
    }
    printf("%d", count);
    return 0;
}