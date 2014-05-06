#include<iostream>
using namespace std;

char a[9][10];

int main()
{   
    int i = 0, j, k, sa, sb, t, set = 0;
    bool ok;
    while(cin>>a[i])
    {
        if(a[i][0] != '9')
        {
            i ++;
            continue;
        }
        set ++;
        for(j = 0; j < i - 1; j++)
        {
            sa = strlen(a[j]);
            for(k = j + 1; k < i; k++)
            {
                ok = 0;
                sb = strlen(a[k]);
                for(t = 0; t < sa && t < sb; t++)
                {
                    if(a[j][t] != a[k][t])
                    {
                        ok = 1;
                        break;
                    }
                }
                if(!ok) break; 
            }
            if(!ok) break;
        }
        if(ok) cout<<"Set "<<set<<" is immediately decodable"<<endl;
        else cout<<"Set "<<set<<" is not immediately decodable"<<endl;
        i = 0;
    }
    return 0;
}