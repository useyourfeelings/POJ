#include<iostream>
#include<algorithm>
using namespace std;
int man[1000];

int elapsed;
void make(int n)
{
    if(n == 1) elapsed += man[0];
    else if(n == 2) elapsed += man[1];
    else if(n == 3) elapsed += man[1] + man[0] + man[2];
    else 
    {
        if(2 * man[1] >= man[0] + man[n - 2])
        {
            elapsed += man[n - 1] + man[0];
            make(n - 1);
        }
        else
        {
            elapsed += man[0] + man[1] + man[n - 1] + man[1];
            make(n - 2);
        }
    }
}
int main()
{   
    int t, n, i;
    scanf("%d", &t);
    while(t--)
    {
        elapsed = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++) scanf("%d", &man[i]);
        sort(man, man + n);
        make(n);
        cout<<elapsed<<endl;
    }
    return 0;
}