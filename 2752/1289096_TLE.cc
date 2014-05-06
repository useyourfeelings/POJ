#include<iostream>
using namespace std;

char g[400001];

int main()
{
    int i, j, t, sz;
    while(gets(g) && (sz = strlen(g)) != 0)
    {
        for(t = 0; t < sz - 1; ++ t)
        {
            for(i = t, j = sz - 1; i >= 0; --i, --j)
                if(g[i] != g[j]) break;
            if(i < 0) cout<<t + 1<<" ";
        }
        cout<<sz<<endl;
    }
    return 0;
}