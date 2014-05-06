#include<iostream>
using namespace std;

int treats[2000], n;
int record[2000][2000];

int dp(int i, int j)
{
    if(record[i][j] != -1) return record[i][j];
    int maxt = treats[i] * (n - j + i) + dp(i + 1, j);
    int t;
    if((t = treats[j] * (n - j + i) + dp(i, j - 1)) > maxt) maxt = t;
    record[i][j] = maxt;
    return maxt;
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i) scanf("%d", &treats[i]);
    for(i = 0; i < n; ++ i)
        for(j = 0; j < n; ++ j)
            record[i][j] = -1;
    for(i = 0; i < n; ++ i) record[i][i] = treats[i] * n;
    printf("%d", dp(0, n - 1));
    return 0;
}