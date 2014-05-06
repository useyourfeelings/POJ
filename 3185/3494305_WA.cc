#include<iostream>
using namespace std;

int a[20], b[20];

int get(int x[20])
{
    int c = 0;
    for(int i = 0; i <= 17; ++ i)
    {
        if(x[i] == 1)
        {
            x[i + 1] = 1 - x[i + 1];
            x[i + 2] = 1 - x[i + 2];
            ++ c;
        }
    }
    if(x[18] == 0 && x[19] == 0) return c;
    if(x[18] == 1 && x[19] == 1) return c + 1;
    return 10000;
}

int main()
{
    int i, c, q;
    for(i = 0; i < 20; ++ i) scanf("%d", &a[i]);
    if(a[0] == 1)
    {
        for(i = 0; i < 20; ++ i) b[i] = a[i];
        a[0] = 0;   // flip a[0];
        a[1] = 1 - a[1];
        c = get(a);
        b[0] = 0;   // flip b[1];
        b[1] = 1 - b[1];
        b[2] = 1 - b[2];
        if((q = get(b)) < c)
            c = q;
        ++ c;
    }
    else
    {
        c = get(a);
    }
    printf("%d", c);
    return 0;
}