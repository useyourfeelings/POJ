#include<iostream>
short fun(short a[], short b[], short r, short c, short id)
{
    if(b[id] != 0) return b[id];
    short max = 0, t;
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
    short R, C;
    std::cin>>R>>C;
    short size = R * C;
    short* pa = new short[size];
    short* pb = new short[size];
    for(short i = 0; i < size; i++)
    {
        std::cin>>pa[i];
        pb[i] = 0;
    }
    for(short i = 0; i < size; i++)
        if(pb[i] == 0)
            fun(pa, pb, R, C, i);
    short max = 0;
    for(short i = 0; i < size; i++)
        if(pb[i] > max) max = pb[i];
    std::cout<<max;
    delete []pa;
    delete []pb;
    system("pause");
    return 0;
}