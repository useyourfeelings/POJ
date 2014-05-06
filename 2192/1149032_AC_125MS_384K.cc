#include<iostream>
using namespace std;
char a[200], b[200], c[400];
int t[201][201];
bool canform(int ai, int bi, int as, int bs)
{
    if(t[ai][bi] != -1) return t[ai][bi];
    if(ai == as && bi == bs) return 1;
    bool cando = 0;
    if(bi >= bs)
    {
        if(a[ai] == c[ai + bi]) cando |= canform(ai + 1, bi, as, bs);
    }
    else if(ai >= as)
    {
        if(b[bi] == c[ai + bi]) cando |= canform(ai, bi + 1, as, bs);
    }
    else
    {
        if(a[ai] == c[ai + bi])
        {
            if(canform(ai + 1, bi, as, bs)) return t[ai][bi] = 1; 
        }
        if(b[bi] == c[ai + bi])
        {
            if(canform(ai, bi + 1, as, bs)) return t[ai][bi] = 1; 
        }
    }
    return t[ai][bi] = cando;    
}
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a>>b>>c;
        for(int j = 0 ; j < 201; j++) 
            for(int k = 0 ; k < 201; k++) t[j][k] = -1;
        if(canform(0, 0, strlen(a), strlen(b)))
        {
            cout<<"Data set "<<i<<": yes"<<endl;
            continue;
        }
        cout<<"Data set "<<i<<": no"<<endl;
    }
    return 0;
}