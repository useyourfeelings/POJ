#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int n, i, h, w, count = 0, a, b, c,
                   minh = 0x0FFFFFFF, minw = 0x0FFFFFFF;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    vector<int> hv(n);
    vector<int> wv(n);
    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &h, &w);
        hv[i] = h;
        wv[i] = w;
        if(h < minh) minh = h;
        if(w < minw) minw = w;
    }
    for(i = 0; i < n; i++)
    {
        if((a * (hv[i] - minh) + b * (wv[i] - minw)) <= c)
            ++ count;
    }
    cout<<count<<endl;
    return 0;
}