#include<iostream>
using namespace std;
const int N = 1000;
int fun(short a[], short i)
{
    short* pb = new short[i + 1];
    for(int j = 0; j <= i; j ++)
        pb[j] = 1;
    for(int j = i - 1; j >= 0; j --)
    {
        short max = -1;
        for(int k = j + 1; k <= i; k ++)
        {
            if(a[k] > a[j]) continue;
            if(pb[k] > max) max = pb[k];
        }
        pb[j] += max;
    }
    short max = pb[0];
    for(int j = 1; j <= i; j ++)
        if(pb[j] > max)
            max = pb[j];
    return max;
}
int main()
{
    short a[N];
    short x, i = 0, test = 1;
    while(cin>>x)
    {
        a[i++] = x;
        if(x == -1) 
        {
            cout<<"Test #"<<test<<":"<<endl
                <<"  maximum possible interceptions: "
                <<fun(a, i - 2)<<endl<<endl;
            test ++;
            i = 0;
            cin>>a[0];
            if(a[0] == -1) break;
            i ++;
        }        
    }
    return 0;
}