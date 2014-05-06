#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n, k, i, j, t, d = 0;
    bool ok = 0;
    cin>>n>>k;
    vector<int> vi(n);
    for(i = 0; i < n; i++)
    {
        cin>>vi[i];
        d += vi[i];
    }
    if(d % k == 0)
    {
        cout<<"Divisible"<<endl;
        return 0;
    }
    
    vector<int> vm(n, 1);
                
    for(i = 1; i <= n; i++)
    {
        d = 0;
        for(j = 0; j < i; j++) vi[j] = -1;
        for(     ; j < n; j++) vi[j] = 1;
        for(t = 0; t < n; t++) d += vi[t] * vm[t];
        if(d % k == 0)
        {
            ok = 1;
            break;
        }
        for(;;)
        {
            if(next_permutation(vm.begin(), vm.end()))
            {
                for(t = 0; t < n; t++) d += vi[t] * vm[t];
                if(d % k == 0)
                {
                    ok = 1;
                    break;
                }
            }
            else break;
        }
        if(ok) break;
    }
    if(ok) cout<<"Divisible"<<endl;
    else cout<<"Not divisible"<<endl;
    return 0;
}