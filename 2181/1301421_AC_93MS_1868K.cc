#include<iostream>
using namespace std;

int p[150000];
int maxj[150000][2];

int main()
{
    int n, i, j, oddmax, evenmax;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i) scanf("%d", &p[i]);
    maxj[n - 1][0] = - p[n - 1];
    maxj[n - 1][1] = p[n - 1];
    oddmax = p[n - 1], evenmax = - p[n - 1];
    for(i = n - 2; i >= 0; -- i)
    {
        if(oddmax < 0) maxj[i][0] = - p[i];
        else maxj[i][0] = - p[i] + oddmax;
        if(evenmax < 0) maxj[i][1] = p[i];
        else maxj[i][1] = p[i] + evenmax;
        if(maxj[i][0] > evenmax) evenmax = maxj[i][0];
        if(maxj[i][1] > oddmax) oddmax = maxj[i][1];
    }
    printf("%d", oddmax);
    return 0;
}