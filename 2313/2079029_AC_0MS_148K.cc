#include<iostream>
#include<cmath>
using namespace std;

int A[100];

int main()
{
    int n, i, V, oldb, newb;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i) scanf("%d", &A[i]);
    if(n == 1) V = 0;
    else
    {
        oldb = A[0];
        V = 0;
        for(i = 1; i < n - 1; ++ i)
        {
            if(A[i] > A[i + 1])
            {
                if(oldb > A[i]) newb = A[i];
                else            newb = max(oldb, A[i + 1]);
            }
            else
            {
                if(oldb < A[i]) newb = A[i];
                else            newb = min(oldb, A[i + 1]);
            }
            V += (abs(A[i] - newb) + abs(newb - oldb));
            oldb = newb;
        }
        V += abs(A[n - 1] - oldb);
    }
    printf("%d", V);
    return 0;
}