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
    for(i = n - 2; i >= 0; -- i)
    {
        oddmax = evenmax = -1;
        for(j = i + 1; j < n; ++ j)
        {
            if(maxj[j][0] > evenmax) evenmax = maxj[j][0];
            if(maxj[j][1] > oddmax) oddmax = maxj[j][1];
        }
        if(oddmax < 0) maxj[i][0] = - p[i];
        else maxj[i][0] = - p[i] + oddmax;
        if(evenmax < 0) maxj[i][1] = p[i];
        else maxj[i][1] = p[i] + evenmax;
    }
    oddmax = maxj[0][1];
    for(i = 1; i < n; ++ i)
        if(maxj[i][1] > oddmax) oddmax = maxj[i][1];
    printf("%d", oddmax);
    return 0;
}