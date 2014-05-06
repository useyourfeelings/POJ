#include<iostream>
using namespace std;

char W[10002], T[1000002];
int pi[10001];

void getpi()
{
    int wl = strlen(W + 1);
    pi[1] = 0;
    int i = 0, j;
    for(j = 2; j <= wl; ++ j)
    {
        while(i > 0 && W[i + 1] != W[j])
            i = pi[i];
        if(W[i + 1] == W[j]) ++ i;
        pi[j] = i;
    }
}

void match()
{
    int wl = strlen(W + 1);
    int tl = strlen(T + 1);
    int i, j = 0, total = 0;
    for(i = 1; i <= tl; ++ i)
    {
        while(j > 0 && W[j + 1] != T[i])
            j = pi[j];
        if(W[j + 1] == T[i]) ++ j;
        if(j == wl)
        {
            ++ total;
            j = pi[j];
        }
    }
    printf("%d\n", total);
}

int main()
{
    int test;
    scanf("%d", &test);
    while(test --)
    {
        scanf("%s%s", W + 1, T + 1);
        getpi();
        match();
    }
    return 0;
}