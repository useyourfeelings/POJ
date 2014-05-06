#include<iostream>
#include<vector>
using namespace std;
int a[600];
int fun(int i)
{
    vector<int> vb(i + 1, 1);
    for(int j = i - 1; j >= 0; j --)
    {
        int max = -1;
        for(int k = j + 1; k <= i; k ++)
        {
            if(a[k] > a[j]) continue;
            if(vb[k] > max) max = vb[k];
        }
        vb[j] += max;
    }
    int max = 0;
    for(int j = 0; j <= i; j ++) if(vb[j] > max) max = vb[j];
    return max;
}

int main()
{
    int x, i = 0, test = 1;
    while(cin>>x)
    {
        a[i++] = x;
        if(x == -1) 
        {
            cout<<"Test #"<<test ++<<":"<<endl
                <<"  maximum possible interceptions: "
                <<fun(i - 2)<<endl<<endl;
            cin>>a[0];
            if(a[0] == -1) break;
            i = 1;
        }
    }
    return 0;
}