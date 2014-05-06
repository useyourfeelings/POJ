#include<iostream>
int fun(int a[], int b[], int r, int c, int id)
{
    if(b[id] != 0) return b[id];
    int max = 0, t;
    if(id / c > 0)
        if(a[id - c] < a[id])
            if((t = fun(a, b, r, c, id - c)) > max) max = t;
    if(id / c < r - 1)
        if(a[id + c] < a[id])
            if((t = fun(a, b, r, c, id + c)) > max) max = t;
    if(id % c > 0)
        if(a[id - 1] < a[id])
            if((t = fun(a, b, r, c, id - 1)) > max) max = t;
    if(id % c < c - 1)
        if(a[id + 1] < a[id])
            if((t = fun(a, b, r, c, id + 1)) > max) max = t;
    b[id] = max + 1;
    return b[id];
}
int main()
{    
    int R, C;
    std::cin>>R>>C;
    int size = R * C;
    int* pa = new int[size];
    int* pb = new int[size];
    for(int i = 0; i < size; i++)
    {
        std::cin>>pa[i];
        pb[i] = 0;
    }
    for(int i = 0; i < size; i++)
        fun(pa, pb, R, C, i);
    int max = 0;
    for(int i = 0; i < size; i++)
        if(pb[i] > max) max = pb[i];
    std::cout<<max;
    delete []pa;
    delete []pb;
    return 0;
}