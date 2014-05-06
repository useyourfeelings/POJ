#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int p, t, a, b, count = 0;
    cin>>p>>t;
    vector<vector<int> > vsi(p + 1);
    while(cin>>a>>b) vsi[a].push_back(b);
    for(int i = 1; i <= p; i++) sort(vsi[i].begin(), vsi[i].end());
    for(int i = 1; i < p; i++)
    {
        int size = vsi[i].size();
        for(int j = i + 1; j <= p; j++)
        {
            if(size != vsi[j].size()) count ++;
            else
            {
                vector<int>::iterator itri, itrj, end = vsi[i].end();
                for(itri = vsi[i].begin(), itrj = vsi[j].begin();
                                itri != end; ++itri, ++itrj)
                    if(*itri != *itrj)
                    {
                        count++;
                        break;
                    }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}