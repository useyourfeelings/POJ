#include<iostream>
using namespace std;

int test, R, C, TOMATCH;
int Lcon[1001][2];
int Rvisited[1001];
int Lmatch[1001], Rmatch[1001];
int tomatch[1001];

void preprocess()
{
    int a, b;
    scanf("%d %d", &R, &C);
    memset(Lmatch, 0, sizeof(Lmatch));
    memset(Rmatch, 0, sizeof(Rmatch));
    for(int i = 1; i <= C; ++ i)
    {
        scanf("%d %d", &a, &b);
        Lcon[i][0] = a;   // i -> a, b
        Lcon[i][1] = b;
        tomatch[a] = 1;
        tomatch[b] = 1;
    }
    TOMATCH = 0;
    for(int i = 1; i <= R; ++ i)
        if(tomatch[i]) ++ TOMATCH;
}

bool findPath(int Lid)
{
    int Rid;
    for(int i = 0; i < 2; ++ i)
    {
        Rid = Lcon[Lid][i];
        if(!Rvisited[Rid])
        {
            Rvisited[Rid] = 1;
            if(!Rmatch[Rid] || findPath(Rmatch[Rid])) // found
            {
                Lmatch[Lid] = Rid;
                Rmatch[Rid] = Lid;
                return true;
            }
        }
    }
    return false;
}

bool shoot()
{
    for(int i = 1; i <= C; ++ i)
    {
        if(Lmatch[i] == 0)
        {
            memset(Rvisited, 0, sizeof(Rvisited));
            if(findPath(i))
                -- TOMATCH;
            if(TOMATCH == 0) return true;
        }
    }
    return false;
}

void output()
{
    for(int i = 1; i <= C; ++ i)
    {
        if(Lmatch[i]) printf("%d ", Lmatch[i]);
        else          printf("%d ", Lcon[i][0]);
    }
    printf("\n");
}

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        preprocess();
        if(shoot()) output();
        else        printf("no\n");
    }
}