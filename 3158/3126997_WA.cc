#include<iostream>
using namespace std;

char A[128], B[128], la, lb;
int record[128][128];

int dp(int i, int j)
{
    if(i < 0 || j < 0) return 0;
    if(record[i][j] != -1) return record[i][j];
    int maxl, t;
    if(A[i] + B[j] < 100) maxl = 1 + dp(i - 1, j - 1);
    else                  maxl = dp(i - 1, j - 1);
    if((t = dp(i - 1, j)) > maxl) maxl = t;
    if((t = dp(i, j - 1)) > maxl) maxl = t;
    record[i][j] = maxl;
    return maxl;
}

int main()
{
    int i, j, k;
    for(i = 0; i < 100; ++ i)
        for(j = 0; j < 100; ++ j)
            record[i][j] = -1;
    scanf("%s", A);
    scanf("%s", B);
    la = strlen(A);
    lb = strlen(B);
    k = dp(la - 1, lb - 1);
    if(k == la || k == lb) k = la + lb - k; // ok
    else
    {
        for(i = la - k + 1, j = 0; i < la; ++ i, ++ j)
            if(A[i] + B[j] >= 100) break;
        if(i >= la) k = la + lb - k; // ok
        else
        {
            for(i = 0, j = lb - k + 1; j < lb; ++ i, ++ j)
                if(A[i] + B[j] >= 100) break;
            if(j >= lb) k = la + lb - k; // ok
            else k = la + lb;
        }
    }
    printf("%d", k);
    return 0;
}