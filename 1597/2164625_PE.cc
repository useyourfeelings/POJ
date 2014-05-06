#include<iostream>
using namespace std;

int g(int a, int b)
{
    if(a < b) swap(a, b);
    int t;
    for(;;)
    {
        t = a % b;
        if(t == 0) return b;
        a = b;
        b = t;
    }
}

int main()
{
    int s, m;
    while(scanf("%d%d", &s, &m) != EOF)
    {
        printf("%10d%10d    ", s, m);
        if(g(s, m) == 1) printf("Good Choice\n");
        else             printf("Bad Choice\n");
    }
    return 0;
}