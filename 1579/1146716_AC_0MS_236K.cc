#include<iostream>
const int N = 20;
int fun(int a, int b, int c, int* pa)
{
    if(a < 1 || b < 1 || c < 1) return 1;
    int index = (a - 1) * N * N + (b - 1) * N + c - 1;
    if(pa[index] != 0) return pa[index];
    if(a < b && b < c)
    {
        pa[index] = fun(a, b    , c - 1, pa) +
                    fun(a, b - 1, c - 1, pa) -
                    fun(a, b - 1, c    , pa);
        return pa[index];
    }
    pa[index] = fun(a - 1, b    , c    , pa) +
                fun(a - 1, b - 1, c    , pa) +
                fun(a - 1, b    , c - 1, pa) -
                fun(a - 1, b - 1, c - 1, pa);
    return pa[index];
}

int main()
{
    int a, b, c, pa[8000];
    for(int i = 0; i < 8000; i++) pa[i] = 0;
    while(std::cin>>a>>b>>c)
    {
        if(a == -1 && b == -1 && c == -1) break;
        else if(a < 1 || b < 1 || c < 1)
            std::cout<<"w("<<a<<", "<<b<<", "<<c<<") = 1"<<std::endl;
        else if(a > 20 || b > 20 ||c > 20) 
            std::cout<<"w("<<a<<", "<<b<<", "<<c<<") = "
                     <<fun(20, 20, 20, pa)<<std::endl;
        else std::cout<<"w("<<a<<", "<<b<<", "<<c<<") = "
                      <<fun(a, b, c, pa)<<std::endl;
    }
    return 0;
}