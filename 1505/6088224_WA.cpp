#include<iostream>
using namespace std;

int test, B, S;
long long book[501];
long long rec[501][501][2]; // [bp][sn][0]->minvalue, [1]->'/'pos

void input()
{
    scanf("%d %d", &B, &S); // book, scriber
    for(int i = 1; i <= B; ++ i)
        scanf("%lld", &book[i]);
}

void preprocess()
{
    for(int i = 1; i <= B; ++ i)
        for(int j = 1; j <= S; ++ j)
            rec[i][j][0] = -1LL;
}

long long make(int bp, int sr) // book id, scriber remains
{
    if(rec[bp][sr][0] != -1)
        return rec[bp][sr][0];
    if(sr == 1)
    {
        long long sum = 0LL;
        for(int i = bp; i <= B; ++ i)
            sum += book[i];
        rec[bp][sr][0] = sum;
        rec[bp][sr][1] = B;
        return sum;
    }
    long long ret, job = 0LL, minvalue = 6000000000LL;
    int canpick = B - sr + 1, slash;
    for(int i = bp; i <= canpick; ++ i) // try
    {
        job += book[i];
        ret = make(i + 1, sr - 1);
        if(ret < job)  // get the bigger
            ret = job;
        if(ret < minvalue) // get the smaller
        {
            minvalue = ret;
            slash = i;
        }
    }
    rec[bp][sr][0] = minvalue;
    rec[bp][sr][1] = slash;
    return minvalue;
}

void output()
{
    int j;
    int end = rec[1][S][1];
    for(j = 1; j <= end; ++ j)
        printf("%d ", book[j]);
    for(int i = S - 1; i >= 1; -- i)
    {
        printf("/ ");
        end = rec[j][i][1];
        for(; j <= end; ++ j)
            printf("%d ", book[j]);
    }
    printf("\n");
}

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        input();
        preprocess();
        make(1, S);
        output();
    }
}