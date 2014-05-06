#include<iostream>
using namespace std;

int a[10000];
int b[10000];

int fun(int tail)
{
    int j, k, max;
    for(j = tail - 1; j >= 0; j --) b[j] = 1;
    for(j = tail - 1; j >= 0; j --)
    {
        max = 0;
        for(k = j + 1; k < tail; k ++)
        {
            if(a[k] > a[j]) continue;
            if(b[k] > max) max = b[k];
        }
        b[j] += max;
    }
    max = 1;
    for(j = 0; j < tail; j ++)
    {
        cout << b[j]<<endl;
        if(b[j] > max) max = b[j];
    }
    return max;
}

int main()
{
    int i = 0, test = 1;
    for(;;)
    {
        scanf("%d", &a[i]);
        if(a[i] == -1) 
        {
            printf("Test #%d:\n  maximum possible interceptions: %d\n\n",
                test ++, fun(i));
            scanf("%d", &a[0]);
            if(a[0] == -1) break;
            else           i = 1;
        }
        else ++ i;
    }
    return 0;
}