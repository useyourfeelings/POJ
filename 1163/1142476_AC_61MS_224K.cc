#include<iostream>
#include<cmath>
int main()
{
    int N;
    std::cin>>N;
    int s = (N + 1) * N / 2, k;
    int *a = new int[s];
    for(int i = 0; i < s; i++)
        std::cin>>a[i];
    for(int i = s - 1 - N ; i >= 0; i--)
    {
        k = (-1 + int(sqrt(1 + 8 * i))) / 2;
        a[i] += ((a[i + k + 1] > a[i + k + 2]) ? a[i + k + 1] : a[i + k + 2]);
    }        
    std::cout<<a[0];
    return 0;
}