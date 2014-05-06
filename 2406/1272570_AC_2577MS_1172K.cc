#include<iostream>
using namespace std;

int size;
char a[1000000];

int main()
{   
    int n, i, j, num, s;
    bool ok;
    while(scanf("%s", &a) && a[0] != '.')
    {
        s = strlen(a);
        for(n = s; n >= 1; n--)
        {
            ok = 1;
            if(s % n != 0) continue;
            num = s / n;
            for(i = 0; i < num; i++)
            {
                for(j = 0; j < n - 1; j++)
                    if(a[j * num + i] != a[(j + 1) * num + i])
                    {
                        ok = 0;
                        break;
                    }
                if(!ok) break;
            }
            if(ok)
            {
                cout<<n<<endl;
                break;
            }
        }
    }
    return 0;
}