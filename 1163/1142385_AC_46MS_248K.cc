#include<iostream>
#include<cmath>
int fun(int a[], int b[], int i, int N)
{
    if(b[i] != -1) return b[i];
    int k = (-1 + int(sqrt(1 + 8 * i))) / 2;
    int left = fun(a, b, i + k + 1, N);
    int right = fun(a, b, i + k + 2, N);
    if(left > right) b[i] = a[i] + left;
    else             b[i] = a[i] + right;
    return b[i];
}
int main()
{
    int N;
    std::cin>>N;
    int s = (N + 1) * N / 2;
    int *pa = new int[s];
    int *pb = new int[s];
    for(int i = 0; i < s; i++)
    {
        std::cin>>pa[i];
        if(i >= s - N) pb[i] = pa[i];
        else pb[i] = -1;
    }
    std::cout<<fun(pa, pb, 0, N);
    return 0;
}