#include<iostream>
using namespace std;

int a[20];
int b[20];

int main()
{
    int i, ac = 0, bc = 32;
    for(i = 0; i < 20; ++ i) scanf("%d", &a[i]);
    for(i = 0; i < 20; ++ i) b[i] = a[i];
    for(i = 0; i < 20; ++ i)
    {
        if(a[i] == 1)
        {
            if(i + 1 < 20)
            {
                ++ ac;
                a[i] = 0;
                a[i + 1] = 1 - a[i + 1];
                if(i + 2 < 20) a[i + 2] = 1 - a[i + 2];
            }
        }
    }
    if(b[0] == 1)
    {
        for(i = 0; i < 20; ++ i) if(a[i] == 1) break;
            if(i < 20) ac = 32;
        bc = 1;
        b[0] = 0;
        b[1] = 1 - b[1];

        for(i = 1; i < 20; ++ i)
        {
            if(b[i] == 1)
            {
                if(i + 1 < 20)
                {
                    ++ bc;
                    b[i] = 0;
                    b[i + 1] = 1 - b[i + 1];
                    if(i + 2 < 20) b[i + 2] = 1 - b[i + 2];
                }
            }
        }
        for(i = 0; i < 20; ++ i) if(b[i] == 1) break;
            if(i < 20) bc = 32;
    }
    printf("%d", min(ac, bc));
    return 0;
}