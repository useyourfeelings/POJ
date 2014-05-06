#include<iostream>
using namespace std;

int a[10000];
int k;
bool isDivisible(int id, int sum)
{
    if(id == 0)
    {
        if((sum + a[id]) % k == 0) return 1;
        if((sum - a[id]) % k == 0) return 1;
        return 0;
    }
    if(isDivisible(id - 1, sum + a[id])) return 1;
    if(isDivisible(id - 1, sum - a[id])) return 1;
    return 0;
}

int main()
{
    int n, i;
    cin>>n>>k;
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    if(isDivisible(n - 1, 0)) cout<<"Divisible"<<endl;
    else cout<<"Not divisible"<<endl;
    return 0;
}