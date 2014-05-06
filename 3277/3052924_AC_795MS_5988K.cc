#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

int a, b, h, n;
long long s;

map<int, vector<pair<int, int> > > W;
map<int, vector<pair<int, int> > >::iterator mi;
vector<pair<int, int> >::iterator vi;
multiset<int, greater<int> > hight;

int main()
{
    scanf("%d", &n);
    while(n --)
    {
        scanf("%d%d%d", &a, &b, &h);
        W[a].push_back(make_pair(h, 0));
        W[b].push_back(make_pair(h, 1));
    }
    s = a = h = 0;
    for(mi = W.begin(); mi != W.end(); ++ mi)
    {
        for(vi = (mi -> second).begin(); vi != (mi -> second).end(); ++ vi)
        {
            if(vi -> second == 0) // left
                hight.insert(vi -> first);
            else hight.erase(hight.find(vi -> first));
        }
        s += (long long)h * (long long)(mi -> first - a);
        if(hight.empty()) h = 0;
        else h = *hight.begin();
        a = mi -> first;
    }
    cout<<s<<endl;
    return 0;
}