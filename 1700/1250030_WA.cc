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
        int k = man[1] + 2 * man[0];
        for(i = n - 1; ; i -= 2)
        {
            if(i == 2 || i == 3) break;
            time += k;
            time += max(man[i], man[i - 1]);
        }
        if(i == 3) time += max(man[3], man[2]) + 2 * man[1];
        else time += man[2];
        cout<<time<<endl;
    }
    return 0;
}