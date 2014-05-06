#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{   
    int m, n, count, t, lose, Case = 1;
    while(cin>>m>>n && m != 0 && n != 0)
    {
        vector<int> own(0);
        lose = 0;
        for(int i = 0; i < n; i ++)
        {
            cin>>t;
            own.push_back(t);
        }
        sort(own.begin(), own.end());
        vector<int> cantdo(own);
                
        t = 1;
        for(int k = 0; k < n; k ++)
        {
            for(count = own[k] + 1;; count++)
            {
                if(find(cantdo.begin(), cantdo.end(), count) == cantdo.end())
                {
                    cantdo.push_back(count);
                    break;
                }
                if(count >= m * n)
                {
                    count += 1;
                    break;
                }
            }
            if(count == m * n + 1) break;
            count = 0;
            for(; t <= n * m; t++)
            {
                if(find(cantdo.begin(), cantdo.end(), t) != cantdo.end()) continue;
                count ++;
                if(count >= m - 2)
                {
                    t ++;
                    break;
                }
            }
            lose ++;
        }        
        cout<<"Case "<<Case<<": "<<n - lose<<endl;
        Case ++;
    }
    return 0;
}