#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

string name;
string lm("Li Ming");

int main()
{
    int n, i, j, k, t, s, ls;
    cin>>n;
    getline(cin, name, '\n');
    map<string, int> msi;
    for(i = 0; i < n; i++)
    {
        getline(cin, name, '\n');
        msi.insert(make_pair(name, 0));
    }
    cin>>t;
    for(i = 0; i < t; i++)
    {
        vector<int> rank;
        for(j = 0; j < n; j++)
        {
            scanf("%d%*c", &s);
            getline(cin, name, '\n');
            if(name == lm)
            {
                ls = (msi.find(name) -> second += s);
                rank.push_back(ls);
            }
            else rank.push_back(msi.find(name) -> second += s);
        }
        sort(rank.begin(), rank.end());
        for(k = rank.size() - 1; k >= 0; k --)
        {
            if(ls == rank[k])
            {
                cout<<n - k<<endl;
                break;
            }
        }
    }
    return 0;
}