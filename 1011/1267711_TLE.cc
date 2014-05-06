#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

bool taken[64];
int a[64];
int len, num, n;

bool canfill(int tofill)
{
    for(int i = 0; i < n; i++)
    {
        if(taken[i]) continue;
        if(a[i] == tofill)
        {
            taken[i] = 1;
            return 1;
        }
        if(a[i] < tofill)
        {
            taken[i] = 1;
            if(canfill(tofill - a[i])) return 1;
            taken[i] = 0;
        }
    }
    return 0;
}

bool canform()
{
    for(int i = 0; i < num; i++)
    {
        if(!canfill(len)) return 0;
    }
    return 1;
}

int main()
{   
    while(cin>>n && n != 0)
    {
        int sum = 0;
        for(len = 0; len < n; len++)
        {
            scanf("%d", &a[len]);
            taken[len] = 0;
            sum += a[len];
        }
        sort(a, a + n, greater<int>());
        for(len = a[0]; len <= sum; len ++)
        {
            if(sum % len != 0) continue;
            num = sum / len;
            if(canform())
            {
                cout<<len<<endl;
                break;
            }
        }
    }
    return 0;
}