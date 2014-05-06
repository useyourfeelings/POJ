#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{   
    int n, i, num, k,  h, a;
    while(cin>>n && n != 0)
    {
        a = int(pow(2.0, n + 1));
        vector<int> f(a - 1);
        vector<int> high(a / 2 + 1);
        for(i = a - 2; i >= (a / 2 - 1); i--)
            f[i] = a - i - 1;
        for(; i >= 0; i--) cin>>f[i];
        high[f[0]] = 1;        
        for(i = 0; i < (a / 2 - 1); i ++)
        {
            if(f[i * 2 + 1] == f[i])
                 high[f[i * 2 + 2]] = high[f[i]] + 1;
            else high[f[i * 2 + 1]] = high[f[i]] + 1;
        }
        cin>>num;
        while(num --)
        {
            h = 0;
            cin>>k;
            i = a - k - 1;
            for(;;)
            {
                if(i % 2 == 0)
                {
                    if(f[(i - 2) / 2] != k) break;
                    i = (i - 2) / 2;
                    h ++;
                }
                else
                {
                    if(f[(i - 1) / 2] != k) break;
                    i = (i - 1) / 2;
                    h ++;
                }
            }
            cout<<"Player "<<k<<" can be ranked as high as "
                <<high[k]<<" or as low as "
                <<a / 2 - pow(2.0, h) + 1<<"."<<endl;
        }
        cout<<endl;
    }   
    return 0;
}