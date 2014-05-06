#include<iostream>
using namespace std;
int main()
{   
    int n, i, j;
    long long sum = 0;
    int a[10000];
    cin>>n;
    cin>>a[0];
    for(i = 1; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i] - a[0];
    }
    for(i = 1; i < n - 1; i ++)
        for(j = i + 1; j < n; j++) sum += abs(a[j] - a[i]);
    cout<<2 * sum<<endl;
    return 0;
}