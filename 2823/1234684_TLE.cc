#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int n, k, t, i, minn, maxn, head;
    cin>>n>>k;
    vector<int> maxv;
    maxv.reserve(n - k + 1);
    vector<int> v(n);
    for(i = 0; i < n; ++i) cin>>v[i];
    for(head = 0; head <= n - k; ++head)
    {
        maxn = v[head];
        minn = v[head];    
        for(int i = head + 1; i < head + k; ++i)
        {
            if(v[i] >= maxn) maxn = v[i];
            else if(v[i] <= minn) minn = v[i];
        }
        cout<<minn<<" ";
        maxv.push_back(maxn);
    }
    
    vector<int>::iterator itr;
    cout<<endl;
    for(itr = maxv.begin(); itr != maxv.end(); ++itr) cout<<*itr<<" ";
    cout<<endl;
    return 0;
}