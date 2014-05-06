#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    char c;
    vector<char> vc;
    while(cin>>c) vc.push_back(c);
    sort(vc.begin(), vc.end());
    vector<char>::iterator itr = vc.begin();
    vector<char>::iterator end = vc.end();
    for(; itr != end; ++itr) cout<<*itr;
    cout<<endl;
    for(;;)
    {
        if(next_permutation(vc.begin(), vc.end()))
        {
            itr = vc.begin();
            end = vc.end();
            for(; itr != end; ++itr) cout<<*itr;
            cout<<endl;
        }
        else break;
    }
    return 0;
}