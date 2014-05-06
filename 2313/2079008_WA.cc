#include<iostream>
#include<cmath>

int A[100];

int main()
{
    int n, i, V, oldb, newb;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i) scanf("%d", &A[i]);
    if(n == 1) V = 0;
    else
    {
        oldb = (A[0] + A[1]) / 2;
        V = abs(A[0] - oldb);
        for(i = 1; i < n - 1; ++ i)
        {
              newb = (oldb + A[i] + A[i + 1]) / 3;
              V += (abs(A[i] - newb) + abs(newb - oldb));
              oldb = newb;
        }
        V += abs(A[n - 1] - oldb);
    }
    printf("%d", V);
    return 0;
}
