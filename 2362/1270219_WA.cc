#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

bool taken[20];
int a[20];
int len, num = 4, n;

bool canfill(int tofill, int id)
{
    if(id >= n) return 0;
    for(int i = id; i < n; i++)
    {
        if(taken[i]) continue;
        if(a[i] == tofill)
        {
            taken[i] = 1;
            return 1;
        }
        if(a[i] < tofill)
        {
            for(int j = i; j < n; j ++)
            {
                taken[j] = 1;
                if(canfill(tofill - a[j], j + 1))
                {
                    return 1;
                }
                taken[j] = 0;
            }
        }
    }
    return 0;
}

bool canform()
{
    for(int i = 0; i < num; i++)
    {
        if(!canfill(len, 0)) return 0;
    }
    return 1;
}

int main()
{   
    int t, sum;
    cin>>t;
    while(t--)
    {
        sum = 0;
        cin>>n;
        for(len = 0; len < n; len++)
        {
            scanf("%d", &a[len]);
            sum += a[len];
        }
        if(sum % 4 != 0)
        {
            cout<<"no"<<endl;
            continue;
        }
        memset(taken, 0, sizeof(bool) * n);
        sort(a, a + n, greater<int>());
        len = sum / 4;
        if(canform()) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}