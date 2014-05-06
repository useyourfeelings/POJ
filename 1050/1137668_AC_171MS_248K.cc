#include<iostream>
int funfun(int i, int j, int a[], int k)
{
    int b[k];
    b[0] = a[i];
    for(int m = i; m < j; m++)
        b[0] += a[m + 1];
    for(int m = 1; m < k; m++)
    {
        int x = a[m * k + i];
        for(int n = i; n < j; n++)
            x += a[m * k + n + 1];
        if(b[m - 1] <= 0) b[m] = x;
        else              b[m] = x + b[m - 1];
    }
    int max = b[0];
    for(int m = 1; m < k; m++)
        if(b[m] > max) max = b[m];
    return max;
}
int main()
{    
    int N;
    std::cin>>N;
    int* pa = new int[N * N];
    for(int i = 0; i < N*N; i++)
        std::cin>>pa[i];
    int max = pa[0], t, k;
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++)
            if((t = funfun(i, j, pa, N)) > max) max = t;            
    std::cout<<max;
    delete []pa;
    return 0;
}
