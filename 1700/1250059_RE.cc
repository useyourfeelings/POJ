#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{   
    int t, n, i;
    cin>>t;
    while(t--)
    {
        int time = 0;
        cin>>n;
        vector<int> man;
        man.reserve(n);
        for(i = 0; i < n; i++) cin>>man[i];
        sort(man.begin(), man.end());
        if(n == 1)
        {
            cout<<man[0]<<endl;
            continue;
        }
        if(n == 2)
        {
            cout<<max(man[0], man[1])<<endl;
            continue;
        }
        time += man[1] + man[0];
        int k = man[0] + 2 * man[1];
        for(i = n - 1; ;)
        {
            time += max(man[i], man[i - 1]);
            i -= 2;
            if(i == 2 || i == 1) break;
            time += k;
        }
        if(i == 1) time += 2 * man[1];
        else time += k + man[2];
        cout<<time<<endl;
    }
    return 0;
}