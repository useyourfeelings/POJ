#include<iostream>
using namespace std;

int p[150000];

int main()
{
    int n, i, oddmax, evenmax, oddmaxj, t1, t2;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i) scanf("%d", &p[i]);
    oddmax = p[n - 1];
    evenmax = - p[n - 1];
    for(i = n - 2; i >= 0; -- i)
    {
        if(oddmax < 0) t1 = - p[i];
        else t1 = - p[i] + oddmax;
        if(evenmax < 0) t2 = p[i];
        else t2 = p[i] + evenmax;
        if(t1 > evenmax) evenmax = t1;
        if(t2 > oddmax) oddmax = t2;
    }
    printf("%d", oddmax);
    return 0;
}