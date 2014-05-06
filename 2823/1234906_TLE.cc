#include<iostream>
#include<vector>
#include<deque>
#include<set>
using namespace std;

int main()
{   
    int n, k, t, i, minn, maxn;
    cin>>n>>k;
    vector<int> maxv;
    maxv.reserve(n - k + 1);
    deque<int> dying;
    multiset<int> msi;
    
    cin>>t;
    dying.push_back(t);
    msi.insert(t);
    
    for(i = 1; i < k; ++i)
    {
        cin>>t;
        msi.insert(t);
        dying.push_back(t);
    }
    
    cout<<*msi.begin()<<" ";
    maxv.push_back(*msi.rbegin());
    
    for(i = 1; i <= n - k; ++i)
    {
        cin>>t;
        msi.erase(dying.front());
        msi.insert(t);
        cout<<*msi.begin()<<" ";
        maxv.push_back(*msi.rbegin());
        dying.pop_front();
        dying.push_back(t);
    }
    
    vector<int>::iterator itr;
    cout<<endl;
    for(itr = maxv.begin(); itr != maxv.end(); ++itr) cout<<*itr<<" ";
    cout<<endl;
    
    return 0;
}