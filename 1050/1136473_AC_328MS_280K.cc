#include<iostream>

struct Item
{
    bool known;
    int val;
};

int dp(int, int, int, int, int*, Item*);

int fun(int N, int* pa)
{
    Item item[N];
    int max = pa[0], dpmax = pa[0], k;
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            for(k = 0; k < N; k++)
            {
                item[k].known = 0;
            }
            dp(i, j, N - 1 , N, pa, item);
            for(k = 0; k < N; k++)
            {
                if(item[k].val > dpmax)
                dpmax = item[k].val;
            }
            
            if(dpmax > max)
            max = dpmax;            
        }
    }
    return max;
}

int dp(int i, int j, int a, int N, int* pa, Item item[])
{
    if(item[a].known) return item[a].val;
    int max , t, old = pa[a * N + i];
    for(int n = i; n < j; n++)
    {
        old += pa[a * N + n + 1];
    }
    max = old;
    for(int m = a; m >= 0; m --)
    {
        if(a >= 1)
        {
            if((t = dp(i, j, a - 1, N, pa, item) + old) > max)
            max = t;
        }
    }
    item[a].val = max;
    item[a].known = 1;
    return max;
}

int main()
{    
    int N;
    std::cin>>N;
    int* pa = new int[N * N];
    for(int i = 0; i < N*N; i++)
    {
        std::cin>>pa[i];
    }
    std::cout<<fun(N, pa);
    delete []pa;
    system("pause");
    return 0;
}
